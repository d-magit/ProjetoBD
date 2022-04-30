class Negocio:
    ## Initialize Business layer
    def __init__(self, persistence):
        print("Business: Initializing!")
        self.__persistence = persistence
        
    ## Handle exceptions
    def __ex_wrapper(self,f):
        try:
            f()
        except:
            return False
        return True
    ## Politico
    #def ListPais
    def ListPais(self):
        return self.__persistence.GetPaisRepository().ListPaises()

    #def ListPoliticos
    def GetPolitico(self, pais):
        return self.__persistence.GetPoliticoRepository().ListPoliticos(pais[0])

    def GetMediaSalarial(self,pais):
        return str(round(self.__persistence.GetPoliticoRepository().GetMediaSalarial(pais[0]),2))

    ## Usuario
    def CreateUser(self,user):
        with open('resources/'+user[3], 'rb') as f:
            foto = f.read().hex().upper()
        newuser = {'Nome':user[0],'Senha':user[1],'Email':user[2],'Foto':foto}
        return self.__ex_wrapper(lambda: self.__persistence.GetUsuarioRepository().CreateUser(newuser))

    def Authenticate(self,user):
        _user = self.__persistence.GetUsuarioRepository().GetUser(user[0])
        if (_user == None):
            return None
        if (_user['Senha'] == user[1]):
            return _user
        return None

    def UpdateUser(self, user):
        newuser = {'Nome':user[0],'Senha':user[1],'Email':user[2]}
        return self.__ex_wrapper(lambda: self.__persistence.GetUsuarioRepository().UpdateUser(newuser))
    
    def DeleteUser(self, nome):
        return self.__ex_wrapper(lambda: self.__persistence.GetAvaliacaoRepository().DeleteUser(nome))

    ## Avaliacao
    def CreateEvaluation(self,evaluation):
        newevaluation = {'Usuario_Nome':evaluation[0],'Politico_ID':evaluation[1],'Nota':evaluation[2],'Comentario':evaluation[3]}
        return self.__ex_wrapper(lambda: self.__persistence.GetAvaliacaoRepository().CreateEvaluation(newevaluation))
        
    def ListUserEvaluations(self,userid):
        return self.__persistence.GetAvaliacaoRepository().ListUserEvaluations(userid)

    def UpdateEvaluation(self, evaluation):
        newevaluation = {'Numero_Aval':evaluation[0], 'Nota':evaluation[1],'Comentario':evaluation[2]}
        return self.__ex_wrapper(lambda: self.__persistence.GetAvaliacaoRepository().UpdateEvaluation(newevaluation))
    
    def DeleteEvaluation(self, evalId):
        return self.__ex_wrapper(lambda: self.__persistence.GetAvaliacaoRepository().DeleteEvaluation(evalId[0]))



    

# usuarioRepository = persistence.GetUsuarioRepository()
# avaliacaoRepository = persistence.GetAvaliacaoRepository()
# politicosRepository = persistence.GetPoliticosRepository()