WITH circuits_2020 AS (
    SELECT c.circuitId, year, round, lat, lng
    FROM circuits c
    JOIN races r
    ON c.circuitId = r.circuitId
    WHERE year = 2020
),
entre_circuits AS (
    SELECT 
        a.lat AS A_LAT, 
        b.lat AS B_LAT, 
        a.lng AS A_LNG, 
        b.lng AS B_LNG
    FROM circuits_2020 a
    JOIN circuits_2020 b
    ON a.round+1 = b.round
),
distancia_entre_circuits AS (
    SELECT abs(A_LAT - B_LAT) + abs(A_LNG - B_LNG) AS DIST_BETWEEN
    FROM entre_circuits
)

SELECT round( sum(DIST_BETWEEN), 4 ) AS DIST
FROM distancia_entre_circuits