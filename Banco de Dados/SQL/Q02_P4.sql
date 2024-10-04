WITH
    TransactionOperations AS (
        SELECT `#t`,
               MIN(CASE WHEN op IN ('read_lock', 'write_lock') THEN time END) AS first_lock_time,
               MAX(CASE WHEN op = 'unlock' THEN time END) AS last_unlock_time,
               MAX(CASE WHEN op IN ('commit', 'rollback') THEN time END) AS commit_rollback_time
        FROM `Schedule`
        GROUP BY `#t`
    ),
    ViolatingTransactions AS (
        SELECT `#t`
        FROM TransactionOperations
        WHERE last_unlock_time < commit_rollback_time OR commit_rollback_time IS NULL
    )
SELECT
    CASE
        WHEN EXISTS (SELECT 1 FROM ViolatingTransactions)
        THEN 0
        ELSE 1
    END AS RESP;