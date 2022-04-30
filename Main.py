from Persistencia.Persistencia import Persistencia
from Apresentacao.Apresentacao import Apresentacao
from Negocio.Negocio import Negocio

persistence = Persistencia()
persistence.GetPoliticosRepository().ListPoliticos('BR')
business = Negocio(persistence)
Apresentacao(business)