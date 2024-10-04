WITH
    Arestas AS (
        -- Regra 2: read_item depois de write_item
        SELECT
            S1.`#t` AS from_t,
            S2.`#t` AS to_t
        FROM
            `Schedule` AS S1
            JOIN `Schedule` AS S2 ON S1.attr = S2.attr
            AND S1.op = 'write_item'
            AND S2.op = 'read_item'
            AND S1.time < S2.time
            AND S1.`#t` != S2.`#t`

        UNION ALL

        -- Regra 3: write_item depois de read_item
        SELECT
            S1.`#t` AS from_t,
            S2.`#t` AS to_t
        FROM
            `Schedule` AS S1
            JOIN `Schedule` AS S2 ON S1.attr = S2.attr
            AND S1.op = 'read_item'
            AND S2.op = 'write_item'
            AND S1.time < S2.time
            AND S1.`#t` != S2.`#t`

        UNION ALL

        -- Regra 4: write_item depois de write_item
        SELECT
            S1.`#t` AS from_t,
            S2.`#t` AS to_t
        FROM
            `Schedule` AS S1
            JOIN `Schedule` AS S2 ON S1.attr = S2.attr
            AND S1.op = 'write_item'
            AND S2.op = 'write_item'
            AND S1.time < S2.time
            AND S1.`#t` != S2.`#t`
    ),
    CiclosRecursivos AS (
        -- Ponto de partida: todas as arestas
        SELECT from_t, to_t, CAST(from_t AS VARCHAR(255)) AS path
        FROM Arestas
        
        UNION ALL
        
        -- Recursão: continua o caminho
        SELECT c.from_t, a.to_t, CONCAT(c.path, ',', a.to_t)
        FROM CiclosRecursivos c
        JOIN Arestas a ON c.to_t = a.from_t
        WHERE c.path NOT LIKE CONCAT('%', a.to_t, '%')  -- Evita loops infinitos
    ),
    Ciclos AS (
        -- Identifica ciclos quando o nó final é igual ao inicial
        SELECT DISTINCT from_t
        FROM CiclosRecursivos
        WHERE from_t = to_t
    )
SELECT
    CASE
        WHEN EXISTS (SELECT 1 FROM `Ciclos`)
        THEN 0
        ELSE 1
    END AS RESP;