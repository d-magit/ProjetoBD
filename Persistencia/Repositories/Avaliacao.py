class Avaliacao:
    ## Initialize repository
    def __init__(self, SQLManager):
        self.__sqlManager = SQLManager
    
    def CreateEvaluation(self, evaluation):
        values = f"'{evaluation['Usuario_Nome']}', {evaluation['Politico_ID']}, {evaluation['Nota']}, '{evaluation['Comentario']}'"
        self.__sqlManager.ExecuteQuery(f"INSERT INTO Avaliacao(Usuario_Nome, Politico_ID, Nota, Comentario) VALUES ({values})")
    
    def ListUserEvaluations(self, username):
        return self.__sqlManager.SelectQuery(f"SELECT * FROM Avaliacao WHERE Usuario_Nome = '{username}'")
    
    def UpdateEvaluation(self, evaluation):
        values = f"Usuario_Nome = '{evaluation['Usuario_Nome']}', Politico_ID = {evaluation['Politico_ID']}, Nota = {evaluation['Nota']}, Comentario = '{evaluation['Comentario']}'"
        self.__sqlManager.ExecuteQuery(f"UPDATE Avaliacao SET {values} WHERE Numero_Aval = {evaluation['Numero_Aval']}")
    
    def DeleteEvaluation(self, evalId):
        self.__sqlManager.ExecuteQuery(f"DELETE FROM Avaliacao WHERE Numero_Aval = {evalId}")