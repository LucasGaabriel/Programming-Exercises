WITH p1 AS (
    SELECT min(LAT_N) AS min_LAT_N, min(LONG_W) AS min_LONG_W
    FROM STATION
),
p2 AS (
    SELECT max(LAT_N) AS max_LAT_N, max(LONG_W) AS max_LONG_W
    FROM STATION
)

SELECT abs(min_LAT_N - max_LAT_N) + abs(min_LONG_W - max_LONG_W) AS DIST_MANHATTAN
FROM p1 JOIN p2