SELECT name FROM SONGS
WHERE artist_id = (SELECT id FROM artists WHERE name = "Post Malone");