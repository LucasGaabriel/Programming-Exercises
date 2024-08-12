WITH nomes_tams AS (
    SELECT CITY, CHAR_LENGTH(CITY) AS TAM
    FROM STATION
),
max_min AS (
    SELECT MAX(TAM) AS MAX_TAM, MIN(TAM) AS MIN_TAM
    FROM nomes_tams
),
maior AS (
    SELECT CITY AS NOME_MAIOR, TAM AS TAM_MAIOR
    FROM nomes_tams
    WHERE TAM IN (SELECT MAX_TAM FROM max_min)
    ORDER BY CITY
    LIMIT 1
),
menor AS (
    SELECT CITY AS NOME_MENOR, TAM AS TAM_MENOR
    FROM nomes_tams
    WHERE TAM IN (SELECT MIN_TAM FROM max_min)
    ORDER BY CITY
    LIMIT 1
)

SELECT NOME_MENOR, NOME_MAIOR, TAM_MENOR, TAM_MAIOR
FROM maior
JOIN menor