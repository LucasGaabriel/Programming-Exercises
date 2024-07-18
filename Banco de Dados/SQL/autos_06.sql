SELECT nome, sobrenome, cgc
FROM consumidores c
LEFT JOIN negocios n
ON c.cpf = n.cpf