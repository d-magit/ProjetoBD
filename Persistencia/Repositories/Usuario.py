class Usuario:
    ## Initialize repository
    def __init__(self, SQLManager):
        self.__sqlManager = SQLManager
    
    def CreateUser(self, user):
        values = f"'{user['Nome']}', '{user['Senha']}', '{user['Email']}', 0x{user['Foto']}"
        self.__sqlManager.ExecuteQuery(f"INSERT INTO Usuario(Nome, Senha, Email, Foto) VALUES ({values})")
    
    def GetUser(self, name):
        return next(iter(self.__sqlManager.SelectQuery(f"SELECT * FROM Usuario WHERE nome = '{name}'")), None)
    
    def UpdateUser(self, user):
        values = f"Senha = '{user['Senha']}', Email = '{user['Email']}'"
        self.__sqlManager.ExecuteQuery(f"UPDATE Usuario SET {values} WHERE Nome = {user['Nome']}")
    
    def DeleteUser(self, name):
        self.__sqlManager.ExecuteQuery(f"DELETE FROM Usuario WHERE Nome = {name}")