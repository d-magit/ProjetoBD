-- Partido
INSERT INTO Partido(Acronimo, Nome) VALUES ('PT', 'Partido dos Trabalhadores');
INSERT INTO Partido(Acronimo, Nome) VALUES ('PSOL', 'Partido Socialismo e Liberdade');
INSERT INTO Partido(Acronimo, Nome) VALUES ('PCdoB', 'Partido Comunista do Brasil');
INSERT INTO Partido(Acronimo, Nome) VALUES ('PCO', 'Partido da Causa Operária');
INSERT INTO Partido(Acronimo, Nome) VALUES ('UNIAO', 'Uniao Brasil');
INSERT INTO Partido(Acronimo, Nome) VALUES ('PL', 'Partido Liberal');
INSERT INTO Partido(Acronimo, Nome) VALUES ('DP', 'Democratic Party');
INSERT INTO Partido(Acronimo, Nome) VALUES ('PCCh', '中國共產黨');
INSERT INTO Partido(Acronimo, Nome) VALUES ('сукаблять', 'Коммунистическая Партия Российской Федерации');
INSERT INTO Partido(Acronimo, Nome) VALUES ('日本共産党', 'Nihon Kyōsantō');
-- Pais
INSERT INTO Pais(Codigo, Nome, Continente, PIB) VALUES ('BR', 'Brasil', 'América do Sul', 1.445);
INSERT INTO Pais(Codigo, Nome, Continente, PIB) VALUES ('EUA', 'Estados Unidos da América', 'América do Norte', 20.94);
INSERT INTO Pais(Codigo, Nome, Continente, PIB) VALUES ('CN', 'China', 'Asia', 14.72);
INSERT INTO Pais(Codigo, Nome, Continente, PIB) VALUES ('RU', 'Rússia', 'Europa', 1.483);
INSERT INTO Pais(Codigo, Nome, Continente, PIB) VALUES ('JP', 'Japão', 'Asia', 5.065);
-- Presidente
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Jair Messias Bolsonaro', 6200.78, NULL);
INSERT INTO Presidente(Inicio_Mandato, Politico_ID, Pais_Codigo) VALUES ('2016-01-01', 1, 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Joe Biden', 33333.1, 'DP');
INSERT INTO Presidente(Inicio_Mandato, Politico_ID, Pais_Codigo) VALUES ('2016-01-02', 2, 'EUA');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Xi Jinping', 564345.7, 'PCCh');
INSERT INTO Presidente(Inicio_Mandato, Politico_ID, Pais_Codigo) VALUES ('2016-01-03', 3, 'CN');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Vladimir Putin', 11666.3, 'сукаблять');
INSERT INTO Presidente(Inicio_Mandato, Politico_ID, Pais_Codigo) VALUES ('2016-01-04', 4, 'RU');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Fumio Kishida', 21224.4, '日本共産党');
INSERT INTO Presidente(Inicio_Mandato, Politico_ID, Pais_Codigo) VALUES ('2016-01-05', 5, 'JP');
-- Ministerio
INSERT INTO Ministerio(Acronimo, Nome, Area, Pais_Codigo) VALUES ('MS', 'Ministerio da Saude', 'Saude', 'BR');
INSERT INTO Ministerio(Acronimo, Nome, Area, Pais_Codigo) VALUES ('MJSP', 'Ministerio da Justica', 'Legislativo', 'BR');
INSERT INTO Ministerio(Acronimo, Nome, Area, Pais_Codigo) VALUES ('MC', 'Ministerio da Cidadania', 'Civico', 'BR');
INSERT INTO Ministerio(Acronimo, Nome, Area, Pais_Codigo) VALUES ('ME', 'Ministerio da Economia', 'Economia', 'BR');
INSERT INTO Ministerio(Acronimo, Nome, Area, Pais_Codigo) VALUES ('MCTI', 'Ministério da Ciencia', 'Ciencia', 'BR');
-- Ministro
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Marcelo Queiroga', 3185.2, NULL);
INSERT INTO Ministro(Ministerio_Acronimo, Formacao_Academica, Politico_ID, Presidente_Politico_ID) VALUES ('MS', 'Doutorado em Medicina', 6, 1);
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Anderson Torres', 2890.1, 'UNIAO');
INSERT INTO Ministro(Ministerio_Acronimo, Formacao_Academica, Politico_ID, Presidente_Politico_ID) VALUES ('MJSP', 'Doutorado em Direito', 7, 1);
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Joao Roma', 3541.8, 'PL');
INSERT INTO Ministro(Ministerio_Acronimo, Formacao_Academica, Politico_ID, Presidente_Politico_ID) VALUES ('MC', 'Doutorado em Sociologia', 8, 1);
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Paulo Guedes', 3310.5, NULL);
INSERT INTO Ministro(Ministerio_Acronimo, Formacao_Academica, Politico_ID, Presidente_Politico_ID) VALUES ('ME', 'Doutorado em Economia', 9, 1);
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Marcos Pontes', 2810.7, 'PL');
INSERT INTO Ministro(Ministerio_Acronimo, Formacao_Academica, Politico_ID, Presidente_Politico_ID) VALUES ('MCTI', 'Doutorado em FISICA QUIMICA ASTRONAUTA', 10, 1);
-- UF
INSERT INTO Unidade_Federativa(Codigo, Nome, Regiao, Pais_Codigo, Extensao_Territorial) VALUES ('DF', 'Distrito Federal', 'Centro-Oeste', 'BR', 5.802);
INSERT INTO Unidade_Federativa(Codigo, Nome, Regiao, Pais_Codigo, Extensao_Territorial) VALUES ('GO', 'Goias', 'Centro-Oeste', 'BR', 340.1);
INSERT INTO Unidade_Federativa(Codigo, Nome, Regiao, Pais_Codigo, Extensao_Territorial) VALUES ('MG', 'Minas Gerais', 'Centro-Oeste', 'BR', 586.53);
INSERT INTO Unidade_Federativa(Codigo, Nome, Regiao, Pais_Codigo, Extensao_Territorial) VALUES ('RJ', 'Rio de Janeiro', 'Sudeste', 'BR', 43.7);
INSERT INTO Unidade_Federativa(Codigo, Nome, Regiao, Pais_Codigo, Extensao_Territorial) VALUES ('SP', 'Sao Paulo', 'Sudeste', 'BR', 248.21);
-- Deputado
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Jose Maria da Penha', 3185.2, 'UNIAO');
INSERT INTO Deputado(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (11, 'DF', 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Joaquim Souza da Silva', 2890.1, 'PL');
INSERT INTO Deputado(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (12, 'GO', 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Fabiano Honorato', 3541.4, 'PT');
INSERT INTO Deputado(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (13, 'MG', 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Fernando Sabino', 3310.2, 'PSOL');
INSERT INTO Deputado(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (14, 'RJ', 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Machado de Assis', 2810.1, 'PCCh');
INSERT INTO Deputado(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (15, 'SP', 'BR');
-- -- Lei_Aprovada
INSERT INTO Lei_Aprovada(Codigo_Lei, Deputado_Politico_ID) VALUES ('L012', 15);
INSERT INTO Lei_Aprovada(Codigo_Lei, Deputado_Politico_ID) VALUES ('L123', 15);
INSERT INTO Lei_Aprovada(Codigo_Lei, Deputado_Politico_ID) VALUES ('L234', 15);
INSERT INTO Lei_Aprovada(Codigo_Lei, Deputado_Politico_ID) VALUES ('L345', 15);
INSERT INTO Lei_Aprovada(Codigo_Lei, Deputado_Politico_ID) VALUES ('L456', 15);
-- Governador
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Jose Lima', 8725.9, 'PT');
INSERT INTO Governador(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (16, 'GO', 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Maristela Terto de Holanda', 9723.7, 'PT');
INSERT INTO Governador(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (17, 'DF', 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Elis Regina', 6753.3, 'PSOL');
INSERT INTO Governador(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (18, 'RJ', 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Carlos Chaga', 7552.4, 'PCdoB');
INSERT INTO Governador(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (19, 'SP', 'BR');
INSERT INTO Politico(Nome, Salario, Partido_Acronimo) VALUES ('Ana Maria Machado', 6787.5, 'PCCh');
INSERT INTO Governador(Politico_ID, Unidade_Federativa_Codigo, Unidade_Federativa_Pais_Codigo) VALUES (20, 'SP', 'BR');
-- -- Obra_Terminada
INSERT INTO Obra_Terminada(Nome_Obra, Governador_Politico_ID) VALUES ('Escolinha', 17);
INSERT INTO Obra_Terminada(Nome_Obra, Governador_Politico_ID) VALUES ('Faculzinha', 17);
INSERT INTO Obra_Terminada(Nome_Obra, Governador_Politico_ID) VALUES ('Igrejinha', 17);
INSERT INTO Obra_Terminada(Nome_Obra, Governador_Politico_ID) VALUES ('Inha', 17);
INSERT INTO Obra_Terminada(Nome_Obra, Governador_Politico_ID) VALUES ('I', 17);
-- Usuario
INSERT INTO Usuario (Nome, Senha, Email) VALUES ('Davi', 'davivilovesyou<3', 'davizinh@gmail.com');
INSERT INTO Usuario (Nome, Senha, Email) VALUES ('Vini', 'meganwordfword', 'meganwordfword@hotmail.com');
INSERT INTO Usuario (Nome, Senha, Email) VALUES ('a', 'b', 'c@d.com');
INSERT INTO Usuario (Nome, Senha, Email) VALUES ('b', 'c', 'd@e.com');
INSERT INTO Usuario (Nome, Senha, Email) VALUES ('c', 'd', 'e@f.com');
-- Avaliacao
INSERT INTO Avaliacao (Usuario_Nome, Politico_ID, Nota, Comentario) VALUES ('Davi', 17, 10, 'Aprovado! Professora muito legal, linda e maravilhosa!!');
INSERT INTO Avaliacao (Usuario_Nome, Politico_ID, Nota, Comentario) VALUES ('Vini', 17, 999, 'MUITO LEGAL!!! ÉEE, ISSO AI.');
INSERT INTO Avaliacao (Usuario_Nome, Politico_ID, Nota, Comentario) VALUES ('a', 3, 1, 'awa');
INSERT INTO Avaliacao (Usuario_Nome, Politico_ID, Nota, Comentario) VALUES ('b', 2, 2, 'owo');
INSERT INTO Avaliacao (Usuario_Nome, Politico_ID, Nota, Comentario) VALUES ('c', 1, 3, 'uwu');