-- Função de união das entidades Politico, Governador, UF e País. Retorna na view Join_Gov_UF_Pais a tabela final.
DROP PROCEDURE IF EXISTS Get_Join_Gov_UF_Pais;
CREATE PROCEDURE Get_Join_Gov_UF_Pais()
BEGIN
    START TRANSACTION;
    DROP VIEW IF EXISTS Join_Gov_UF_Pais;
    
    DROP VIEW IF EXISTS Join_Pol_Gov;
    CREATE VIEW Join_Pol_Gov AS
        SELECT po.*, Gov.Unidade_Federativa_Codigo as UF_Codigo
        FROM Politico AS po INNER JOIN Governador AS Gov WHERE po.ID = Gov.Politico_ID;
    
    DROP VIEW IF EXISTS Join_Gov_UF;
    CREATE VIEW Join_Gov_UF AS
        SELECT Gov.*, uf.Nome as UF_Nome, uf.Regiao, uf.Extensao_Territorial as UF_Extensao_Territorial, uf.Pais_Codigo 
        FROM Join_Pol_Gov AS Gov INNER JOIN Unidade_Federativa AS uf WHERE Gov.UF_Codigo = uf.Codigo;
    
    CREATE VIEW Join_Gov_UF_Pais AS
        SELECT Gov.*, p.Nome AS Pais, p.Continente, p.PIB as PIB_Pais 
        FROM Join_Gov_UF AS Gov INNER JOIN Pais AS p WHERE Gov.Pais_Codigo = p.Codigo;

    SELECT * FROM Join_Gov_UF_Pais;
    COMMIT;
END
--$$
-- Função de união das entidades Politico, Deputado, UF e País. Retorna na view Join_Dep_UF_Pais a tabela final.
DROP PROCEDURE IF EXISTS Get_Join_Dep_UF_Pais;
CREATE PROCEDURE Get_Join_Dep_UF_Pais()
BEGIN
    START TRANSACTION;
    DROP VIEW IF EXISTS Join_Dep_UF_Pais;
    
    DROP VIEW IF EXISTS Join_Pol_Dep;
    CREATE VIEW Join_Pol_Dep AS
        SELECT po.*, Dep.Unidade_Federativa_Codigo as UF_Codigo
        FROM Politico AS po INNER JOIN Deputado AS Dep WHERE po.ID = Dep.Politico_ID;
    
    DROP VIEW IF EXISTS Join_Dep_UF;
    CREATE VIEW Join_Dep_UF AS
        SELECT Dep.*, uf.Nome as UF_Nome, uf.Regiao, uf.Extensao_Territorial as UF_Extensao_Territorial, uf.Pais_Codigo 
        FROM Join_Pol_Dep AS Dep INNER JOIN Unidade_Federativa AS uf WHERE Dep.UF_Codigo = uf.Codigo;
    
    CREATE VIEW Join_Dep_UF_Pais AS
        SELECT Dep.*, p.Nome AS Pais, p.Continente, p.PIB as PIB_Pais 
        FROM Join_Dep_UF AS Dep INNER JOIN Pais AS p WHERE Dep.Pais_Codigo = p.Codigo;
    
    SELECT * FROM Join_Dep_UF_Pais;
    COMMIT;
END
--$$
-- Função de união das entidades Politico, Ministro, Ministério e País. Retorna na view Join_Min_Mis_Pais a tabela final.
DROP PROCEDURE IF EXISTS Get_Join_Min_Mis_Pais;
CREATE PROCEDURE Get_Join_Min_Mis_Pais()
BEGIN
    START TRANSACTION;
    DROP VIEW IF EXISTS Join_Min_Mis_Pais;
    
    DROP VIEW IF EXISTS Join_Pol_Min;
    CREATE VIEW Join_Pol_Min AS
        SELECT po.*, Min.Ministerio_Acronimo as Mis_Acronimo
        FROM Politico AS po INNER JOIN Ministro AS Min WHERE po.ID = Min.Politico_ID;
    
    DROP VIEW IF EXISTS Join_Min_Mis;
    CREATE VIEW Join_Min_Mis AS
        SELECT Min.*, Mis.Nome as Mis_Nome, Mis.Area as Mis_Area, Mis.Pais_Codigo 
        FROM Join_Pol_Min AS Min INNER JOIN Ministerio AS Mis WHERE Min.Mis_Acronimo = Mis.Acronimo;
    
    CREATE VIEW Join_Min_Mis_Pais AS
		SELECT Min.*, p.Nome AS Pais, p.Continente, p.PIB as PIB_Pais 
        FROM Join_Min_Mis AS Min INNER JOIN Pais AS p WHERE Min.Pais_Codigo = p.Codigo;
	
    SELECT * FROM Join_Min_Mis_Pais;
    COMMIT;
END
--$$
-- Função de união das entidades Político, Presidente e País. Retorna na view Join_Pres_Pais a tabela final.
DROP PROCEDURE IF EXISTS Get_Join_Pres_Pais;
CREATE PROCEDURE Get_Join_Pres_Pais()
BEGIN
    START TRANSACTION;
    DROP VIEW IF EXISTS Join_Pres_Pais;
    
    DROP VIEW IF EXISTS Join_Pol_Pres;
    CREATE VIEW Join_Pol_Pres AS
        SELECT po.*, pr.Inicio_Mandato, pr.Pais_Codigo 
        FROM Politico AS po INNER JOIN Presidente AS pr WHERE po.ID = pr.Politico_ID;
    
    CREATE VIEW Join_Pres_Pais AS
		SELECT Pres.*, p.Nome AS Pais, p.Continente, p.PIB as PIB_Pais 
        FROM Join_Pol_Pres AS Pres INNER JOIN Pais AS p WHERE Pres.Pais_Codigo = p.Codigo;
	
    SELECT * FROM Join_Pres_Pais;
    COMMIT;
END
--$$
-- Função de calcular a média salária dos Políticos de um país.
DROP PROCEDURE IF EXISTS Get_Media_Salarial;
CREATE PROCEDURE Get_Media_Salarial(IN Pais_Codigo varchar(45))
BEGIN
    START TRANSACTION;
    CALL Get_Join_Gov_UF_Pais();
    CALL Get_Join_Dep_UF_Pais();
    CALL Get_Join_Min_Mis_Pais();
    CALL Get_Join_Pres_Pais();
    SET @Gov_AVG = (SELECT AVG(Salario) FROM Join_Gov_UF_Pais WHERE Pais_Codigo = Pais_Codigo);
    SET @Dep_AVG = (SELECT AVG(Salario) FROM Join_Dep_UF_Pais WHERE Pais_Codigo = Pais_Codigo);
    SET @Min_AVG = (SELECT AVG(Salario) FROM Join_Min_Mis_Pais WHERE Pais_Codigo = Pais_Codigo);
    SET @Pres_AVG = (SELECT AVG(Salario) FROM Join_Pres_Pais WHERE Pais_Codigo = Pais_Codigo);
    SET @Media_Salarial := ((@Gov_AVG + @Dep_AVG + @Min_AVG + @Pres_AVG) / 4);
	SELECT @Media_Salarial;
    COMMIT;
END