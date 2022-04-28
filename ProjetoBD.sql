DROP SCHEMA IF EXISTS ProjetoDB;
CREATE SCHEMA IF NOT EXISTS ProjetoDB;
USE ProjetoDB;

DROP TABLE IF EXISTS Partido;
CREATE TABLE IF NOT EXISTS Partido (
  Acrônimo VARCHAR(45) NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  PRIMARY KEY (Acrônimo));

DROP TABLE IF EXISTS Político;
CREATE TABLE IF NOT EXISTS Político (
  ID INT NOT NULL,
  Nome VARCHAR(45) NULL,
  Salário FLOAT NULL,
  Partido_Acrônimo VARCHAR(45) NOT NULL,
  PRIMARY KEY (ID),
  FOREIGN KEY (Partido_Acrônimo) REFERENCES Partido (Acrônimo));

DROP TABLE IF EXISTS País;
CREATE TABLE IF NOT EXISTS País (
  Código VARCHAR(45) NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  Continente VARCHAR(45) NOT NULL,
  PIB FLOAT NULL,
  Constituição LONGBLOB NULL,
  PRIMARY KEY (Código));

DROP TABLE IF EXISTS Presidente;
CREATE TABLE IF NOT EXISTS Presidente (
  Início_Mandato DATE NULL,
  Político_ID INT NOT NULL,
  País_Código VARCHAR(45) NOT NULL,
  PRIMARY KEY (Político_ID, País_Código),
  FOREIGN KEY (Político_ID) REFERENCES Político (ID),
  FOREIGN KEY (País_Código) REFERENCES País (Código));

DROP TABLE IF EXISTS Ministério;
CREATE TABLE IF NOT EXISTS Ministério (
  Acrônimo VARCHAR(45) NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  Área VARCHAR(45) NOT NULL,
  País_Código VARCHAR(45) NOT NULL,
  PRIMARY KEY (Acrônimo),
  FOREIGN KEY (País_Código) REFERENCES País (Código));

DROP TABLE IF EXISTS Ministro;
CREATE TABLE IF NOT EXISTS Ministro (
  Ministério_Acrônimo VARCHAR(45) NOT NULL,
  Formação_Acadêmica VARCHAR(45) NULL,
  Político_ID INT NOT NULL,
  Presidente_Político_ID INT NOT NULL,
  PRIMARY KEY (Político_ID),
  FOREIGN KEY (Ministério_Acrônimo) REFERENCES Ministério (Acrônimo),
  FOREIGN KEY (Político_ID) REFERENCES Político (ID),
  FOREIGN KEY (Presidente_Político_ID) REFERENCES Presidente (Político_ID));

DROP TABLE IF EXISTS Unidade_Federativa;
CREATE TABLE IF NOT EXISTS Unidade_Federativa (
  Código VARCHAR(45) NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  Região VARCHAR(45) NOT NULL,
  País_Código VARCHAR(45) NOT NULL,
  Extensão_Territorial FLOAT NOT NULL,
  PRIMARY KEY (Código, País_Código),
  FOREIGN KEY (País_Código) REFERENCES País (Código));

DROP TABLE IF EXISTS Deputado;
CREATE TABLE IF NOT EXISTS Deputado (
  Político_ID INT NOT NULL,
  Unidade_Federativa_Código VARCHAR(45) NOT NULL,
  Unidade_Federativa_País_Código VARCHAR(45) NOT NULL,
  PRIMARY KEY (Político_ID),
  FOREIGN KEY (Político_ID) REFERENCES Político (ID),
  FOREIGN KEY (Unidade_Federativa_Código, Unidade_Federativa_País_Código) REFERENCES Unidade_Federativa (Código, País_Código));

DROP TABLE IF EXISTS Governador;
CREATE TABLE IF NOT EXISTS Governador (
  Político_ID INT NOT NULL,
  Unidade_Federativa_Código VARCHAR(45) NOT NULL,
  Unidade_Federativa_País_Código VARCHAR(45) NOT NULL,
  PRIMARY KEY (Político_ID),
  FOREIGN KEY (Político_ID) REFERENCES Político (ID),
  FOREIGN KEY (Unidade_Federativa_Código, Unidade_Federativa_País_Código) REFERENCES Unidade_Federativa (Código, País_Código));

DROP TABLE IF EXISTS Usuário;
CREATE TABLE IF NOT EXISTS Usuário (
  Username VARCHAR(45) NOT NULL,
  Email VARCHAR(45) NULL,
  Senha VARCHAR(45) NULL,
  PRIMARY KEY (Username));

DROP TABLE IF EXISTS Obra_Terminada;
CREATE TABLE IF NOT EXISTS Obra_Terminada (
  Nome_Obra VARCHAR(45) NOT NULL,
  Governador_Político_ID INT NOT NULL,
  PRIMARY KEY (Nome_Obra, Governador_Político_ID),
  FOREIGN KEY (Governador_Político_ID) REFERENCES Governador (Político_ID));

DROP TABLE IF EXISTS Lei_Aprovada;
CREATE TABLE IF NOT EXISTS Lei_Aprovada (
  Código_Lei VARCHAR(45) NOT NULL,
  Deputado_Político_ID INT NOT NULL,
  PRIMARY KEY (Código_Lei, Deputado_Político_ID),
  FOREIGN KEY (Deputado_Político_ID) REFERENCES Deputado (Político_ID));

DROP TABLE IF EXISTS Avaliação;
CREATE TABLE IF NOT EXISTS Avaliação (
  Usuário_Username VARCHAR(45) NOT NULL,
  Político_ID INT NOT NULL,
  Nota INT NOT NULL,
  Comentário VARCHAR(45) NOT NULL,
  Numero_Aval VARCHAR(45) NOT NULL,
  PRIMARY KEY (Numero_Aval),
  FOREIGN KEY (Usuário_Username) REFERENCES Usuário (Username),
  FOREIGN KEY (Político_ID) REFERENCES Político (ID));