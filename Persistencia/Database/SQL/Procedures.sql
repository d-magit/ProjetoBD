-- Função de união das entidades Governador, UF e País. Retorna na view Join_Gov_UF_Pais a tabela final.
DROP PROCEDURE IF EXISTS Get_Join_Gov_UF_Pais;
CREATE PROCEDURE Get_Join_Gov_UF_Pais()
BEGIN
    START TRANSACTION;
    DROP VIEW IF EXISTS Join_Pol_Gov;
    CREATE VIEW Join_Pol_Gov AS
        SELECT po.*, gov.Unidade_Federativa_Codigo as UF_Codigo
        FROM Politico AS po NATURAL JOIN Governador AS gov;
    
    DROP VIEW IF EXISTS Join_Gov_UF;
    CREATE VIEW Join_Gov_UF AS
        SELECT gov.*, uf.Nome as UF_Nome, uf.Regiao, uf.Extensao_Territorial as UF_Extensao_Territorial, uf.Pais_Codigo 
        FROM Join_Pol_Gov AS gov NATURAL JOIN Unidade_Federativa AS uf;
    
    SELECT gov.*, p.Nome AS Pais, p.Continente, p.PIB as PIB_Pais FROM Join_Gov_UF AS gov NATURAL JOIN Pais AS p;
    DROP VIEW IF EXISTS Join_Pol_Gov;
    DROP VIEW IF EXISTS Join_Gov_UF;
    COMMIT;
END
--$$ 
-- Função de união das entidades Presidente e Político. Retorna na view Join_Presidente_Politico a tabela final.
DROP PROCEDURE IF EXISTS Get_Join_Presidente_Politico;
CREATE PROCEDURE Get_Join_Presidente_Politico()
BEGIN
    START TRANSACTION;
    SELECT po.*, pr.Inicio_Mandato, pr.Pais_Codigo FROM Politico AS po NATURAL JOIN Presidente AS pr;
    COMMIT;
END