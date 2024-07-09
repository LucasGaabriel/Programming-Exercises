SELECT CONCAT(forename, ' ', surname) AS `Piloto`
FROM drivers
WHERE driverId NOT IN (
  SELECT DISTINCT driverId
  FROM results
);