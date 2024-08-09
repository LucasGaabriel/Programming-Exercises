WITH corridas_2012 AS (
    SELECT *
    FROM races
    NATURAL JOIN results
    WHERE year = 2012
),
equipes_nao_pontuaram AS (
    SELECT constructorId
    FROM corridas_2012
    GROUP BY raceId, constructorId
    HAVING SUM(points) = 0
),
todas_equipes_que_pontuaram AS (
    SELECT constructorId
    FROM corridas_2012
    WHERE constructorId NOT IN (
        SELECT constructorId
        FROM equipes_nao_pontuaram
    )
),
equipes_target AS (
    SELECT c.name AS "Equipe"
    FROM todas_equipes_que_pontuaram e
    NATURAL JOIN constructors c
)

SELECT distinct Equipe
FROM equipes_target