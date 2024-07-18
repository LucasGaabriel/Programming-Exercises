SELECT a1.codigo as codigo_auto1, a1.ano as ano_auto1, a2.codigo as codigo_auto2, a2.ano as ano_auto2
FROM automoveis as a1, automoveis as a2
WHERE a1.fabricante = a2.fabricante and 
        a1.modelo = a2.modelo and 
        a1.codigo != a2.codigo and
        a1.preco_tabela - a2.preco_tabela > 1000