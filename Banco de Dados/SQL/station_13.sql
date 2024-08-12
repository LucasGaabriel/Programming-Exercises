WITH cities_length AS (
    SELECT 
        name, 
        CHAR_LENGTH(name) AS length
    FROM CITY
    ORDER BY name
),
min_max_length AS (
    SELECT min(length) AS MIN, max(length) AS MAX
    FROM cities_length
),
nomes_menores AS (
    SELECT *, ROW_NUMBER() OVER(PARTITION BY length ORDER BY name) AS line
    FROM cities_length
    WHERE length IN (SELECT MIN FROM min_max_length)
),
nomes_maiores AS (
    SELECT *, ROW_NUMBER() OVER(PARTITION BY length ORDER BY name) AS line
    FROM cities_length
    WHERE length IN (SELECT MAX FROM min_max_length)
),
menor_target AS (
    SELECT name AS NOME_MENOR, length AS TAM_MENOR
    FROM nomes_menores
    WHERE line = 1
),
maior_target AS (
    SELECT name AS NOME_MAIOR, length AS TAM_MAIOR
    FROM nomes_maiores
    WHERE line = 1
)

SELECT NOME_MENOR, NOME_MAIOR, TAM_MENOR, TAM_MAIOR
FROM menor_target
JOIN maior_target