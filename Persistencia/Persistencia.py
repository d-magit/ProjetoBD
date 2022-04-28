import mysql.connector
from mysql.connector import Error

class Persistencia:
    ## Initialize Persistence layer by connecting to the host and creating the database and tables
    def __init__(self):
        ## Connection variables
        self.__db_host = "localhost"
        self.__db_user = "Davi"
        self.__db_pass = "vhxto8$^L$6$6o"
        self.__db_name = "ProjetoDB"
        ## Creating and connecting to DB
        print("MySQL: Connecting to MySQL host...")
        self.__connection = self.__db_connect()
        ## Creating initial DB and tables
        print("MySQL: Creating initial DB and tables...")
        self.__init_db()
        ## Connecting to DB
        print("MySQL: Connecting to database...")
        self.__connection = self.__db_connect(self.__db_name) ## Connects to the main DB.
        ##
    
    ## Function to connect to MySQL
    def __db_connect(self, database = None):
        # Initialize variables
        args = {'host': self.__db_host, 'user': self.__db_user, 'passwd': self.__db_pass}
        if database != None:
            args['database'] = database
        __connection = None
        # Attempt to connect and return connection, or raise exception if the attempt fails.
        try:
            __connection = mysql.connector.connect(**args)
        except Error as err:
            print(f"MySQL: Connection failed! Error: '{err}'")
        return __connection
    ##

    ## Function to initialize the database
    def __init_db(self):
        with open('Persistencia/ProjetoBD.sql', 'r') as query_file:
            ProjetoDB = query_file.read()
        self.execute_query(ProjetoDB, getResult=False, multiple=True)
    ##

    ## Function to execute a query
    def execute_query(self, query, isbuffered = False, getResult = True, multiple = False):
        cursor = self.__connection.cursor(buffered = isbuffered)
        try:
            cursor.execute(query, multi = multiple)
            self.__connection.commit()
        except Error as err:
            print(f"MySQL: Executing query failed! Error: '{err}'")
        return cursor.fetchall() if getResult else None
    ##

    ## Function to search query for specific time interval
    def select_query(self, query):
        return self.execute_query(query, True)
    ##