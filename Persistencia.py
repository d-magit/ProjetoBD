import mysql.connector
from mysql.connector import Error

## Function to connect to MySQL
def create_server_connection(host, user, passwd, database = None):
    # Initialize variables
    args = {'host': host, 'user': user, 'passwd': passwd}
    if database != None:
        args['database'] = database
    connection = None
    # Attempt to connect and return connection, or raise exception if the attempt fails.
    try:
        connection = mysql.connector.connect(**args)
    except Error as err:
        print(f"MySQL: Connection failed! Error: '{err}'")
    return connection
##

## Function to execute a query
def execute_query(query, isbuffered = False, getResult = True, multiple = False):
    cursor = connection.cursor(buffered = isbuffered)
    try:
        cursor.execute(query, multi = multiple)
        connection.commit()
    except Error as err:
        print(f"MySQL: Executing query failed! Error: '{err}'")
    return cursor.fetchall() if getResult else None
##

## Function to initialize the database
def initialize_database():
    with open('ProjetoBD.sql', 'r') as query_file:
        ProjetoDB = query_file.read()
    execute_query(ProjetoDB, getResult=False, multiple=True)
##

## Function to search query for specific time interval
def select_query(query):
    return execute_query(query, True)
##

db_user = "Davi" ## Davi DB user
db_pass = "vhxto8$^L$6$6o" ## Password for MySQL Davi
main_db_name = "ProjetoBD" ## DB name
## Creating and connecting to DB
print("MySQL: Connecting to MySQL and creating database...")
connection = create_server_connection("localhost", db_user, db_pass)
## Creating initial DB and tables
print("MySQL: Creating initial DB and tables...")
initialize_database()
## Connecting to DB
connection = create_server_connection("localhost", db_user, db_pass, main_db_name) ## Connects to the main DB.
##

# ## Analytic query for: "Quais as 10 operadoras que mais tiveram despesas com "EVENTOS/ SINISTROS CONHECIDOS OU AVISADOS  DE ASSISTÊNCIA A SAÚDE MEDICO HOSPITALAR" no último trimestre?"
# print("MySQL: Running analytic query for: \"Quais as 10 operadoras que mais tiveram despesas com \"EVENTOS/ SINISTROS CONHECIDOS OU AVISADOS  DE ASSISTÊNCIA A SAÚDE MEDICO HOSPITALAR\" no último trimestre?")
# print("MySQL: Result of the search", search_query(connection, 3), sep="\n")
# ##

# ## Analytic query for: "Quais as 10 operadoras que mais tiveram despesas com "EVENTOS/ SINISTROS CONHECIDOS OU AVISADOS  DE ASSISTÊNCIA A SAÚDE MEDICO HOSPITALAR" no último ano?"
# print("MySQL: Running analytic query for: \"Quais as 10 operadoras que mais tiveram despesas com \"EVENTOS/ SINISTROS CONHECIDOS OU AVISADOS  DE ASSISTÊNCIA A SAÚDE MEDICO HOSPITALAR\" no último ano?")
# print("MySQL: Result of the search", search_query(connection, 12), sep="\n")
# ##