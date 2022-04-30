DROP SCHEMA IF EXISTS ProjetoBD;
CREATE SCHEMA IF NOT EXISTS ProjetoBD;
USE ProjetoBD;

DROP TABLE IF EXISTS Partido;
CREATE TABLE IF NOT EXISTS Partido (
  Acronimo VARCHAR(45) NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  PRIMARY KEY (Acronimo));

DROP TABLE IF EXISTS Politico;
CREATE TABLE IF NOT EXISTS Politico (
  ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
  Nome VARCHAR(45) NULL,
  Salario FLOAT NULL,
  Partido_Acronimo VARCHAR(45) NULL,
  PRIMARY KEY (ID),
  FOREIGN KEY (Partido_Acronimo) REFERENCES Partido (Acronimo));

DROP TABLE IF EXISTS Pais;
CREATE TABLE IF NOT EXISTS Pais (
  Codigo VARCHAR(45) NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  Continente VARCHAR(45) NOT NULL,
  PIB FLOAT NULL,
  PRIMARY KEY (Codigo));

DROP TABLE IF EXISTS Presidente;
CREATE TABLE IF NOT EXISTS Presidente (
  Inicio_Mandato DATE NULL,
  Politico_ID INT UNSIGNED NOT NULL,
  Pais_Codigo VARCHAR(45) NOT NULL,
  PRIMARY KEY (Politico_ID, Pais_Codigo),
  FOREIGN KEY (Politico_ID) REFERENCES Politico (ID),
  FOREIGN KEY (Pais_Codigo) REFERENCES Pais (Codigo));

DROP TABLE IF EXISTS Ministerio;
CREATE TABLE IF NOT EXISTS Ministerio (
  Acronimo VARCHAR(45) NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  Area VARCHAR(45) NOT NULL,
  Pais_Codigo VARCHAR(45) NOT NULL,
  PRIMARY KEY (Acronimo),
  FOREIGN KEY (Pais_Codigo) REFERENCES Pais (Codigo));

DROP TABLE IF EXISTS Ministro;
CREATE TABLE IF NOT EXISTS Ministro (
  Ministerio_Acronimo VARCHAR(45) NOT NULL,
  Formacao_Academica VARCHAR(45) NULL,
  Politico_ID INT UNSIGNED NOT NULL,
  Presidente_Politico_ID INT UNSIGNED NOT NULL,
  PRIMARY KEY (Politico_ID),
  FOREIGN KEY (Ministerio_Acronimo) REFERENCES Ministerio (Acronimo),
  FOREIGN KEY (Politico_ID) REFERENCES Politico (ID),
  FOREIGN KEY (Presidente_Politico_ID) REFERENCES Presidente (Politico_ID));

DROP TABLE IF EXISTS Unidade_Federativa;
CREATE TABLE IF NOT EXISTS Unidade_Federativa (
  Codigo VARCHAR(45) NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  Regiao VARCHAR(45) NOT NULL,
  Pais_Codigo VARCHAR(45) NOT NULL,
  Extensao_Territorial FLOAT NOT NULL,
  PRIMARY KEY (Codigo, Pais_Codigo),
  FOREIGN KEY (Pais_Codigo) REFERENCES Pais (Codigo));

DROP TABLE IF EXISTS Deputado;
CREATE TABLE IF NOT EXISTS Deputado (
  Politico_ID INT UNSIGNED NOT NULL,
  Unidade_Federativa_Codigo VARCHAR(45) NOT NULL,
  Unidade_Federativa_Pais_Codigo VARCHAR(45) NOT NULL,
  PRIMARY KEY (Politico_ID),
  FOREIGN KEY (Politico_ID) REFERENCES Politico (ID),
  FOREIGN KEY (Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) REFERENCES Unidade_Federativa (Codigo, Pais_Codigo));

DROP TABLE IF EXISTS Governador;
CREATE TABLE IF NOT EXISTS Governador (
  Politico_ID INT UNSIGNED NOT NULL,
  Unidade_Federativa_Codigo VARCHAR(45) NOT NULL,
  Unidade_Federativa_Pais_Codigo VARCHAR(45) NOT NULL,
  PRIMARY KEY (Politico_ID),
  FOREIGN KEY (Politico_ID) REFERENCES Politico (ID),
  FOREIGN KEY (Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) REFERENCES Unidade_Federativa (Codigo, Pais_Codigo));

DROP TABLE IF EXISTS Usuario;
CREATE TABLE IF NOT EXISTS Usuario (
  Nome VARCHAR(45) NOT NULL,
  Email VARCHAR(45) NULL,
  Senha VARCHAR(45) NULL,
  Foto LONGBLOB NULL,
  PRIMARY KEY (Nome));

DROP TABLE IF EXISTS Obra_Terminada;
CREATE TABLE IF NOT EXISTS Obra_Terminada (
  Nome_Obra VARCHAR(45) NOT NULL,
  Governador_Politico_ID INT UNSIGNED NOT NULL,
  PRIMARY KEY (Nome_Obra, Governador_Politico_ID),
  FOREIGN KEY (Governador_Politico_ID) REFERENCES Governador (Politico_ID));

DROP TABLE IF EXISTS Lei_Aprovada;
CREATE TABLE IF NOT EXISTS Lei_Aprovada (
  Codigo_Lei VARCHAR(45) NOT NULL,
  Deputado_Politico_ID INT UNSIGNED NOT NULL,
  PRIMARY KEY (Codigo_Lei, Deputado_Politico_ID),
  FOREIGN KEY (Deputado_Politico_ID) REFERENCES Deputado (Politico_ID));

DROP TABLE IF EXISTS Avaliacao;
CREATE TABLE IF NOT EXISTS Avaliacao (
  Usuario_Nome VARCHAR(45) NOT NULL,
  Politico_ID INT UNSIGNED NOT NULL,
  Nota INT NOT NULL,
  Comentario VARCHAR(255) NOT NULL,
  Numero_Aval INT UNSIGNED NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (Numero_Aval),
  FOREIGN KEY (Usuario_Nome) REFERENCES Usuario (Nome),
  FOREIGN KEY (Politico_ID) REFERENCES Politico (ID));