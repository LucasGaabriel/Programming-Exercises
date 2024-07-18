SELECT nome, sobrenome, cgc
FROM consumidores c 
INNER JOIN negocios n 
ON c.cpf = n.cpf