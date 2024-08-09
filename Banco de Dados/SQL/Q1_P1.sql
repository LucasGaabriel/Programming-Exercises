WITH id_michael AS (
    SELECT driverId
    FROM drivers
    WHERE forename = 'Michael' AND surname = 'Schumacher'
),
id_ferrari AS (
    SELECT constructorId
    FROM constructors
    WHERE name = 'Ferrari'
),
corridas_michael_ferrari AS (
    SELECT distinct raceId
    FROM results
    WHERE driverId IN (SELECT driverId FROM id_michael) 
    AND constructorId IN (SELECT constructorId FROM id_ferrari)
),
companheiros AS (
    SELECT DISTINCT driverId
    FROM results
    WHERE raceId IN (SELECT raceId FROM corridas_michael_ferrari)
    AND constructorId IN (SELECT constructorId FROM id_ferrari)
    AND driverId NOT IN (SELECT driverId FROM id_michael)
)

SELECT concat(forename, ' ', surname) AS 'Piloto'
FROM companheiros
JOIN drivers
ON drivers.driverId = companheiros.driverId;
