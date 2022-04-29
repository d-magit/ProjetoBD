class Usuario:
    ## Initialize repository
    def __init__(self, SQLManager):
        self.__sqlManager = SQLManager
    
    def CreateUser(self, user):
        self.__sqlManager.ExecuteQuery(f"INSERT INTO Usuario(Nome, Email, Senha) VALUES ('{user['Nome']}', '{user['Email']}', '{user['Senha']}')")
    
    def GetUser(self, name):
        return self.__sqlManager.SelectQuery(f"SELECT * FROM Usuario WHERE nome = '{name}'")[0]