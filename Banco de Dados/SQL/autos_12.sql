SELECT c.nome, c.sobrenome, n.cgc
FROM consumidores c
LEFT JOIN negocios n
ON c.cpf = n.cpf

UNION

SELECT c.nome, c.sobrenome, n.cgc
FROM consumidores c
RIGHT JOIN negocios n
ON c.cpf = n.cpf