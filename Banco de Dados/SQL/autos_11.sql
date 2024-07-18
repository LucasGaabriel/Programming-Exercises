WITH todasRevendedoras as (
    SELECT DISTINCT cgc
    FROM revendedoras
),
revendedorasComNegocios as (
    SELECT DISTINCT cgc
    FROM negocios
),
nenhumNegocio as (
    SELECT cgc
    FROM todasRevendedoras
    EXCEPT (
        SELECT cgc
        FROM revendedorasComNegocios
    )
)
SELECT *
FROM nenhumNegocio
NATURAL JOIN revendedoras 