SELECT AVG(energy) FROM SONGS WHERE artist_id = (SELECT id FROM artists WHERE name LIKE "drake");
