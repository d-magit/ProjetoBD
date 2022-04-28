class Negocio:
    ## Initialize Business layer
    def __init__(self, persistence):
        print("Business: Initializing!")
        self.__persistence = persistence

    def Authenticate(self, user):
        _user = self.__persistence.GetUsuarioRepository().GetByName(user.Name)
        if (_user == None):
            return None
        if (_user.Password == user.Password):
            return _user
        return None

# usuarioRepository = persistence.GetUsuarioRepository()
# avaliacaoRepository = persistence.GetAvaliacaoRepository()
# politicosRepository = persistence.GetPoliticosRepository()