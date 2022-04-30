
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
        ## Inserting initial data
        print("MySQL: Inserting initial data...")
        self.__init_data()
        ## Initializing procedures
        print("MySQL: Initializing procedures...")
        self.__init_procedures()
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

    ## Initialize data
    def __init_data(self):
        with open(f'{self.__this_folder}/SQL/Inserts.sql', 'r') as query_file:
            Inserts = query_file.read()
        self.ExecuteQuery(Inserts)
    ##

    ## Initialize procedures
    def __init_procedures(self):
        with open(f'{self.__this_folder}/SQL/Procedures.sql', 'r') as query_file:
            Procedures = query_file.read().split('--$$')
        for i in Procedures:
            self.ExecuteQuery(i)
    ##

    ## Execute query (returns cursor)
    def ExecuteQuery(self, query, isbuffered = False):
        cursor = self.__connection.cursor(buffered = isbuffered)
        try:
            try:
                list(cursor.execute('\n'.join([i for i in query.split('\n') if i[:2] != '--']), multi=True))
            except RuntimeError as err:
                if 'StopIteration' in err.args[0]: pass
                else: raise
            self.__connection.commit()
        except Error as err:
            print(f"MySQL: Executing query failed! Error: '{err}'")
            exit()
        return cursor
    ##

    ## Processes Select into Dict
    def __process_select(self, cursor):
        if not cursor.with_rows: return None
        columns, results = ([i[0] for i in cursor.description], cursor.fetchall())
        objs = []
        for i in results:
            obj_dict = {}
            for j in range(len(columns)):
                obj_dict[columns[j]] = i[j]
            objs.append(obj_dict)
        return objs

    ## Execute procedure (returns list of lists of object dicts (Select Results))
    def ExecuteProcedure(self, proc_name, args = ()):
        cursor = self.__connection.cursor(buffered = True)
        try:
            cursor.callproc(proc_name, args)
            self.__connection.commit()
        except Error as err:
            print(f"MySQL: Executing query failed! Error: '{err}'")
            exit()
        stored_results = []
        for result in cursor.stored_results():
            obj = self.__process_select(result)
            if obj != None: stored_results.append(obj)
        return stored_results
    ##

    ## Select query (returns list of object dicts (Select Results))
    def SelectQuery(self, query):
        return self.__process_select(self.ExecuteQuery(query, True))
    ##