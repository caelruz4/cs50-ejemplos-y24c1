-- 1. Seleccionar los títulos de las series y sus géneros
SELECT title, genre
FROM shows
JOIN genres ON shows.id = genres.show_id

-- 2: Obtener el nombre y la fecha de nacimiento de todas las personas que han escrito para un programa de televisión
SELECT DISTINCT p.name, p.birth
FROM people p
JOIN writers w ON p.id = w.person_id;

-- 3. Obtener el título de las series que ha participado Zendaya
SELECT s.title
FROM shows s
JOIN stars st ON s.id = st.show_id
JOIN people p ON st.person_id = p.id
WHERE p.name = 'Zendaya';

-- 4. Obtener el título de las series que han sido estrenadas a partir de 2017 y sus géneros.
SELECT DISTINCT s.title, r.rating, g.genre
FROM shows s
JOIN genres g ON s.id = g.show_id
JOIN ratings r ON s.id = r.show_id
WHERE s.year > 2017
ORDER BY r.rating DESC;

-- 5. Obtener el nombre de las coestrellas de Millie Bobby Brown y en que serie han actuado
SELECT DISTINCT p.name, s.title
FROM shows s
JOIN stars st ON s.id = st.show_id
JOIN people p ON st.person_id = p.id
WHERE s.title IN (
    SELECT s2.title
    FROM shows s2
    JOIN stars st2 ON s2.id = st2.show_id
    JOIN people p2 ON st2.person_id = p2.id
    WHERE p2.name = 'Millie Bobby Brown'
)
AND p.name != 'Millie Bobby Brown' order by s.title desc;

-- 6. Obtener el promedio de calificación de Will Smith
SELECT round(AVG(r.rating), 2)AS avg_rating
FROM shows s
JOIN stars st ON s.id = st.show_id
JOIN people p ON st.person_id = p.id
JOIN ratings r ON s.id = r.show_id
WHERE p.name = 'Will Smith';

-- 7. Obtener el título de las series que han sido estrenadas a partir de 2018 y tienen una calificación mayor a 7.0
SELECT s.title, s.year, AVG(r.rating) AS avg_rating
FROM shows s 
JOIN ratings r ON s.id = r.show_id
where s.year > 2018 and r.rating > 7.0
GROUP BY s.title, s.year;
-- 8. JOINS
SELECT p.name AS person_name, s.title AS show_title, r.rating
FROM people p
FULL JOIN writers w ON p.id = w.person_id
FULL JOIN shows s ON w.show_id = s.id
FULL JOIN ratings r ON s.id = r.show_id
limit 10;