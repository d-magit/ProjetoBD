
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
        self.__connection = self.__sql_connect()
        ## Creating initial DB and tables
        print("MySQL: Creating initial DB and tables...")
        self.__init_db()
        ## Connecting to DB
        print("MySQL: Connecting to database...")
        self.__connection = self.__sql_connect(self.__config['db']) ## Connects to the main DB.
        ##
    
    ## Connect to host and/or database
    def __sql_connect(self, database = None):
        # Initialize variables
        args = {'host': self.__config['host'], 'user': self.__config['user'], 'passwd': self.__config['pass']}
        if database != None:
            args['database'] = database
        # Attempt to connect and return connection, or raise exception if the attempt fails.
        try:
            __connection = mysql.connector.connect(**args)
        except Error as err:
            print(f"MySQL: Connection failed! Error: '{err}'")
            exit()
        return __connection
    ##

    ## Initialize database
    def __init_db(self):
        with open(f'{self.__this_folder}/SQL/ProjetoBD.sql', 'r') as query_file:
            ProjetoBD = query_file.read()
        self.ExecuteQuery(ProjetoBD)
    ##

    ## Execute query (returns cursor)
    def ExecuteQuery(self, query, isbuffered = False):
        cursor = self.__connection.cursor(buffered = isbuffered)
        try:
            try:
                list(cursor.execute(query, multi=True))
            except RuntimeError as err:
                if 'StopIteration' in err.args[0]: pass
                else: raise
            self.__connection.commit()
        except Error as err:
            print(f"MySQL: Executing query failed! Error: '{err}'")
            exit()
        return cursor
    ##

    ## Select query (returns list of object dicts)
    def SelectQuery(self, query):
        cursor = self.ExecuteQuery(query, True)
        if cursor.with_rows:
            columns, results = ([i[0] for i in cursor.description], cursor.fetchall())
            objs = []
            for i in results:
                obj_dict = {}
                for j in range(len(columns)):
                    obj_dict[columns[j]] = i[j]
                objs.append(obj_dict)
            return objs
        else:
            return None
    ##