WITH MinMax AS (
    SELECT 
        MIN(LAT_N) AS min_lat_n,
        MIN(LONG_W) AS min_long_w,
        MAX(LAT_N) AS max_lat_n,
        MAX(LONG_W) AS max_long_w
    FROM STATION
)

SELECT
    ROUND(SQRT(POW(max_lat_n - min_lat_n, 2) + POW(max_long_w - min_long_w, 2)), 4) AS DIST_EUCLIDES
FROM MinMax;