SELECT c.nome as nome_c, c.sobrenome as sobrenome_c, r.nome as nome_r, fabricante, modelo, data, preco
FROM negocios n
NATURAL JOIN automoveis a
NATURAL JOIN consumidores c
JOIN revendedoras r
ON n.cgc = r.cgc