WITH salario_total as (
    SELECT *, salary * months AS salario_total
    FROM Employee
),
salario_total_max as (
    SELECT max(salario_total) AS salario_max
    FROM salario_total
), qtd_max as (
    SELECT count(*) AS qtd
    FROM salario_total_max
    JOIN salario_total
    ON salario_total = salario_max
)
SELECT concat(salario_max, ' ', qtd)
FROM salario_total_max
JOIN qtd_max
