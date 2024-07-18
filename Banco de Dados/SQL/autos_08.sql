SELECT count(modelo)
FROM automoveis
WHERE fabricante LIKE 'fiat'
GROUP BY 'modelo'