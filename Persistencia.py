import mysql.connector
from mysql.connector import Error

db_host = "localhost"
db_user = "Davi"
db_pass = "vhxto8$^L$6$6o"
db_name = "ProjetoDB"
## Function to connect to MySQL
def db_connect(database = None):
    # Initialize variables
    args = {'host': db_host, 'user': db_user, 'passwd': db_pass}
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
def init_db():
    with open('ProjetoBD.sql', 'r') as query_file:
        ProjetoDB = query_file.read()
    execute_query(ProjetoDB, getResult=False, multiple=True)
##

## Function to search query for specific time interval
def select_query(query):
    return execute_query(query, True)
##

## Creating and connecting to DB
print("MySQL: Connecting to MySQL host...")
connection = db_connect()
## Creating initial DB and tables
print("MySQL: Creating initial DB and tables...")
init_db()
## Connecting to DB
print("MySQL: Connecting to database...")
connection = db_connect(db_name) ## Connects to the main DB.
##

# ## Analytic query for: "Quais as 10 operadoras que mais tiveram despesas com "EVENTOS/ SINISTROS CONHECIDOS OU AVISADOS  DE ASSISTÊNCIA A SAÚDE MEDICO HOSPITALAR" no último trimestre?"
# print("MySQL: Running analytic query for: \"Quais as 10 operadoras que mais tiveram despesas com \"EVENTOS/ SINISTROS CONHECIDOS OU AVISADOS  DE ASSISTÊNCIA A SAÚDE MEDICO HOSPITALAR\" no último trimestre?")
# print("MySQL: Result of the search", search_query(connection, 3), sep="\n")
# ##

# ## Analytic query for: "Quais as 10 operadoras que mais tiveram despesas com "EVENTOS/ SINISTROS CONHECIDOS OU AVISADOS  DE ASSISTÊNCIA A SAÚDE MEDICO HOSPITALAR" no último ano?"
# print("MySQL: Running analytic query for: \"Quais as 10 operadoras que mais tiveram despesas com \"EVENTOS/ SINISTROS CONHECIDOS OU AVISADOS  DE ASSISTÊNCIA A SAÚDE MEDICO HOSPITALAR\" no último ano?")
# print("MySQL: Result of the search", search_query(connection, 12), sep="\n")
# ##