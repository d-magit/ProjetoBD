class Negocio:
    ## Initialize Business layer
    def __init__(self, persistence):
        print("Business: Initializing!")
        self.__persistence = persistence

    def Authenticate(self, user):
        _user = self.__persistence.GetUsuarioRepository().GetByName(user[0])
        if (_user == None):
            return None
        if (_user.Password == user[1]):
            return _user
        return None

    def CreateUser(self,user):
        newuser = {'Nome':user[0],'Email':user[1],'Senha';user[2]}
        self.__persistence.GetAvaliacaoRepository().CreateUser(newuser)

    def CreateEvalutaion(self,evaluation):
        newevaluation = {'Usuario_Nome':evaluation[0],'Politico_ID':evaluation[1],'Nota':evaluation[2],'Comentario':evaluation[3]}
        self.__persistence.GetAvaliacaoRepository().CreateEvalutaion(newevaluation)
    
    def ListUserEvaluations(self,userid)
        return self.__persistence.GetAvaliacaoRepository().ListUserEvaluations(userid)

    def UpdateEvaluation(self, evaluation):
        newevaluation = {'Usuario_Nome':evaluation[0],'Politico_ID':evaluation[1],'Nota':evaluation[2],'Comentario':evaluation[3], 'Numero_Aval':evaluation[4]}
        self.__persistence.GetAvaliacaoRepository().UpdateEvaluation(newevaluation)
    
    def DeleteEvaluation(self, evalId):
        self.__persistence.GetAvaliacaoRepository().DeleteEvaluation(evalId)




    

# usuarioRepository = persistence.GetUsuarioRepository()
# avaliacaoRepository = persistence.GetAvaliacaoRepository()
# politicosRepository = persistence.GetPoliticosRepository()