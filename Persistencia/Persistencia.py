from Persistencia.Database.SQLManager import SQLManager
from Persistencia.Repositories.Usuario import Usuario
from Persistencia.Repositories.Politico import Politico
from Persistencia.Repositories.Avaliacao import Avaliacao

class Persistencia:
    __politicosRepository, __avaliacaoRepository, __usuarioRepository = None, None, None
    
    ## Initialize Persistence layer by instantiating SQLManager
    def __init__(self):
        print("Persistency: Initializing!")
        self.__sqlManager = SQLManager()

    def GetPoliticosRepository(self):
        if (self.__politicosRepository == None):
            self.__politicosRepository = Usuario(self.__sqlManager)
        return self.__politicosRepository

    def GetAvaliacaoRepository(self):
        if (self.__avaliacaoRepository == None):
            self.__avaliacaoRepository = Avaliacao(self.__sqlManager)
        return self.__avaliacaoRepository

    def GetUsuarioRepository(self):
        if (self.__usuarioRepository == None):
            self.__usuarioRepository = Politico(self.__sqlManager)
        return self.__usuarioRepository