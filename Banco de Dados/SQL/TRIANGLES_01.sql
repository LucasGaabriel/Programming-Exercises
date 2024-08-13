SELECT 
    CASE 
        WHEN A + B <= C OR A + C <= B OR B + C <= A THEN "Nao Eh Triangulo"
        WHEN A = B AND B = C THEN "Equilatero"
        WHEN A = B OR B = C OR A = C THEN "Isosceles"
        ELSE "Escaleno"
    END AS TIPO_TRIANGULO
FROM TRIANGLES;