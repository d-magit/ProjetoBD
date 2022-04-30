class Pais:
    ## Initialize repository
    def __init__(self, SQLManager):
        self.__sqlManager = SQLManager

    def ListPaises(self):
        return self.__sqlManager.SelectQuery(f"SELECT * FROM Pais")