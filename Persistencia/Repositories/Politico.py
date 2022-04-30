class Politico:
    ## Initialize repository
    def __init__(self, SQLManager):
        self.__sqlManager = SQLManager
        
    def GetMediaSalarial(self, countryCode):
        return self.__sqlManager.ExecuteProcedure("Get_Media_Salarial", (countryCode, 0.0))[-1][0]['Media_Salarial']