WITH RECURSIVE seq AS (
    SELECT 1 AS n
    UNION ALL
    SELECT n + 1
    FROM seq
    WHERE n < 20
)
SELECT REPEAT('* ', n) AS pattern
FROM seq;