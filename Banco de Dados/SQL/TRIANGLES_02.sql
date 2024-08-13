WITH RECURSIVE seq AS (
    SELECT 20 AS n
    UNION ALL
    SELECT n - 1
    FROM seq
    WHERE n > 1
)
SELECT REPEAT('* ', n) AS pattern
FROM seq;