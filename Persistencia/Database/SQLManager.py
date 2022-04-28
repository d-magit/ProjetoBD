
import os
import json
import mysql.connector
from mysql.connector import Error

class SQLManager:
    ## Initialize by connecting to the host and creating the database and tables
    def __init__(self):
        ## Get current folder
        self.__this_folder = os.path.dirname(os.path.abspath(__file__))
        ## Getting DB config
        with open(f'{self.__this_folder}/DBConfig.json', 'r') as config_file:
            self.__config = json.load(config_file)
        ## Creating and connecting to DB
        print("MySQL: Connecting to MySQL host...")
        self.__connection = self.__db_connect()
        ## Creating initial DB and tables
        print("MySQL: Creating initial DB and tables...")
        self.__init_db()
        ## Connecting to DB
        print("MySQL: Connecting to database...")
        self.__connection = self.__db_connect(self.__config['db']) ## Connects to the main DB.
        ##
    
    ## Function to connect to MySQL
    def __db_connect(self, database = None):
        # Initialize variables
        args = {'host': self.__config['host'], 'user': self.__config['user'], 'passwd': self.__config['pass']}
        if database != None:
            args['database'] = database
        __connection = None
        # Attempt to connect and return connection, or raise exception if the attempt fails.
        try:
            __connection = mysql.connector.connect(**args)
        except Error as err:
            print(f"MySQL: Connection failed! Error: '{err}'")
            exit()
        return __connection
    ##

    ## Function to initialize the database
    def __init_db(self):
        with open(f'{self.__this_folder}/ProjetoBD.sql', 'r') as query_file:
            ProjetoDB = query_file.read()
        self.ExecuteQuery(ProjetoDB, getResult=False, multiple=True)
    ##

    ## Function to execute a query
    def ExecuteQuery(self, query, isbuffered = False, getResult = True, multiple = False):
        cursor = self.__connection.cursor(buffered = isbuffered)
        try:
            cursor.execute(query, multi = multiple)
            self.__connection.commit()
        except Error as err:
            print(f"MySQL: Executing query failed! Error: '{err}'")
            exit()
        return cursor.fetchall() if getResult else None
    ##

    ## Function to search query for specific time interval
    def SelectQuery(self, query):
        return self.ExecuteQuery(query, True)
    ##