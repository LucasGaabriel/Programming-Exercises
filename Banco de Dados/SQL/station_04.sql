SELECT count(city) - count(DISTINCT city) AS DIFF
FROM STATION