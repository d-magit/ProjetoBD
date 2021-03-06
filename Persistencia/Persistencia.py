from Persistencia.Database.SQLManager import SQLManager
from Persistencia.Repositories.Pais import Pais
from Persistencia.Repositories.Usuario import Usuario
from Persistencia.Repositories.Politico import Politico
from Persistencia.Repositories.Avaliacao import Avaliacao

class Persistencia:
    __paisRepository, __politicoRepository, __avaliacaoRepository, __usuarioRepository = None, None, None, None
    
    ## Initialize Persistence layer by instantiating SQLManager
    def __init__(self):
        print("Persistency: Initializing!")
        self.__sqlManager = SQLManager()

    def GetPaisRepository(self):
        if (self.__paisRepository == None):
            self.__paisRepository = Pais(self.__sqlManager)
        return self.__paisRepository

    def GetPoliticoRepository(self):
        if (self.__politicoRepository == None):
            self.__politicoRepository = Politico(self.__sqlManager)
        return self.__politicoRepository

    def GetAvaliacaoRepository(self):
        if (self.__avaliacaoRepository == None):
            self.__avaliacaoRepository = Avaliacao(self.__sqlManager)
        return self.__avaliacaoRepository

    def GetUsuarioRepository(self):
        if (self.__usuarioRepository == None):
            self.__usuarioRepository = Usuario(self.__sqlManager)
        return self.__usuarioRepository