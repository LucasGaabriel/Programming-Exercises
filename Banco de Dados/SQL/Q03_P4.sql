WITH
    WriteBeforeCommit AS (
        SELECT
            s1.`#t`,
            s1.attr
        FROM
            `Schedule` AS s1
            JOIN `Schedule` AS s2 ON s1.attr = s2.attr
            AND s1.`#t` != s2.`#t`
            AND s1.time < s2.time
            AND s1.op = 'write_item'
            AND s2.op IN ('read_item', 'write_item')
            AND NOT EXISTS (
                SELECT
                    1
                FROM
                    `Schedule` AS s3
                WHERE
                    s3.`#t` = s1.`#t`
                    AND s3.op = 'commit'
                    AND s3.time < s2.time
                    AND s3.time > s1.time
            )
    )
SELECT
    CASE
        WHEN EXISTS (SELECT 1 FROM `WriteBeforeCommit`) 
        THEN 0
        ELSE 1
    END AS RESP;