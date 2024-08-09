WITH min AS (
    SELECT min(year) AS MIN_YEAR, min(round) AS MIN_ROUND
    FROM races
),
gp_target as (
    SELECT gpId, country
    FROM min
    JOIN races r ON year = MIN_YEAR and round = MIN_ROUND
    JOIN circuits c ON r.circuitId = c.circuitId
)

SELECT name AS "GP", country AS "Pais"
FROM gp_target t
JOIN gps g ON t.gpId = g.gpId