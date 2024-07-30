WITH _root AS (

    SELECT N
    FROM BST
    WHERE P IS NULL

),

_leaf AS (

    SELECT N
    FROM BST
    WHERE N NOT IN (
        SELECT P
        FROM BST
        WHERE P IS NOT NULL
    )

),

_inner AS (

    SELECT N
    FROM BST
    WHERE N NOT IN (
        SELECT *
        FROM _root
    ) AND N NOT IN (
        SELECT *
        FROM _leaf
    )

)

SELECT N, "Root" AS T
FROM _root 

UNION 

SELECT N, "Leaf" AS T
FROM _leaf 

UNION 

SELECT N, "Inner" AS T
FROM _inner

ORDER BY N