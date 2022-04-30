class Politico:
    ## Initialize repository
    def __init__(self, SQLManager):
        self.__sqlManager = SQLManager
    
    def __process_politico(self, politico):
        return {
            'ID': politico['ID'], 
            'Nome': politico['Nome'], 
            'Pais_Codigo': politico['Pais_Codigo'],
            'Partido_Acronimo': politico['Partido_Acronimo'],
            'Salario': politico['Salario']
        }
    
    def GetMediaSalarial(self, countryCode):
        return self.__sqlManager.ExecuteProcedure("Get_Media_Salarial", [countryCode])[-1][0]['@Media_Salarial']

    def ListPoliticos(self, countryCode):
        govs = [self.__process_politico(i) for i in self.__sqlManager.ExecuteProcedure("Get_Join_Gov_UF_Pais")[0]]
        deps = [self.__process_politico(i) for i in self.__sqlManager.ExecuteProcedure("Get_Join_Dep_UF_Pais")[0]]
        mins = [self.__process_politico(i) for i in self.__sqlManager.ExecuteProcedure("Get_Join_Min_Mis_Pais")[0]]
        pres = [self.__process_politico(i) for i in self.__sqlManager.ExecuteProcedure("Get_Join_Pres_Pais")[0]]
        result = sorted([i for i in govs + deps + mins + pres if i['Pais_Codigo'] == countryCode], key=lambda x: x['ID'])
        return result