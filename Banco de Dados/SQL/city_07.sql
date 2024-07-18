SELECT
    CITY.NAME
FROM
    CITY
INNER JOIN
    COUNTRY ON CITY.countrycode = COUNTRY.code
WHERE continent = 'Africa'