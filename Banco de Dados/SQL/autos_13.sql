SELECT r.cgc, nome, cpf
FROM revendedoras r
LEFT JOIN negocios n
ON r.cgc = n.cgc

UNION

SELECT r.cgc, nome, cpf
FROM revendedoras r
RIGHT JOIN negocios n
ON r.cgc = n.cgc