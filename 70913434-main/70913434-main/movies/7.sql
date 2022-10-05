SELECT TITLE, R.RATING FROM MOVIES
LEFT JOIN RATINGS AS R
ON R.MOVIE_ID = ID AND YEAR = 2010
WHERE R.RATING LIKE "%%"
ORDER BY R.RATING DESC, TITLE ASC;