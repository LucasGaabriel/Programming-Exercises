WITH simetricos_repetidos AS (
    SELECT f1.X, f1.Y
    FROM Functions f1
    JOIN Functions f2
        ON f1.X = f2.Y AND f2.X = f1.Y
)

SELECT X, Y
FROM simetricos_repetidos
WHERE X < Y OR X = Y
ORDER BY X, Y;