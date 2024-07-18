SELECT *
FROM consumidores
EXCEPT (
  SELECT cpf, nome, sobrenome, cidade, estado
  FROM consumidores NATURAL JOIN negocios
)