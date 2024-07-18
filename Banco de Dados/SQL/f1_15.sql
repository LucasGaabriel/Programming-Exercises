WITH gps_occ AS (
    SELECT `gpId`, COUNT(*) AS `num_ocorrencias`
    FROM `races`
    GROUP BY `gpId`
),
gps_max_occ AS (
    SELECT MAX(`num_ocorrencias`) AS `max_occ`
    FROM gps_occ
)
SELECT `name` as `GP`, `num_ocorrencias` AS `Ocorrencias`
FROM gps_occ JOIN gps_max_occ
                ON `num_ocorrencias` = `max_occ`
NATURAL JOIN `gps`;