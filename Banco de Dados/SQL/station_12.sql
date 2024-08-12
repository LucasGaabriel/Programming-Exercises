WITH table_with_line AS (
    SELECT *, ROW_NUMBER() OVER() AS line
    FROM STATION
    ORDER BY LAT_N
),
qtd_lines AS (
    SELECT ceiling(count(*) / 2) AS line_mediana
    FROM STATION
)

SELECT LAT_N
FROM table_with_line
JOIN qtd_lines
ON line_mediana = line
