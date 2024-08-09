WITH corridas_2015 AS (
    SELECT *
    FROM results
    NATURAL JOIN races
    WHERE year = 2015
),
equipes_pontuacao AS (
    SELECT constructorId, sum(points) AS Points
    FROM corridas_2015
    GROUP BY constructorId
),
pontos_por_rodada AS (
    SELECT raceId, constructorId, round, sum(points) AS Points
    FROM corridas_2015
    GROUP BY raceId, constructorId, round
),
numero_corridas AS (
    SELECT count(DISTINCT raceID) AS NUMBER_RACES
    FROM corridas_2015
),
table_with_standings AS (
    SELECT constructorId, sum(points) AS Points,
        GROUP_CONCAT(
            CASE
                WHEN Points = 0 THEN '**'
                ELSE LPAD(Points, 2, '0') 
            END
        SEPARATOR ' | ') AS "Standings"
    FROM pontos_por_rodada
    GROUP BY constructorId
    ORDER BY Points DESC
),
table_with_pos AS (
    SELECT *, RANK() OVER (ORDER BY Points DESC) AS Pos
    FROM table_with_standings
)

SELECT Pos, name AS 'Team', Points, Standings
FROM table_with_pos t
JOIN constructors c
ON t.constructorId = c.constructorId