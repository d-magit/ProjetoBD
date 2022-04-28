class Usuario:
    ## Initialize repository
    def __init__(self, SQLManager):
        self.__sqlManager = SQLManager
    
    def GetByName(self, name):
        userEntity = self.__sqlManager.SelectQuery(f"SELECT * FROM Usuario WHERE nome = '{name}'")
        return userEntity