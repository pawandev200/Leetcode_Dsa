# Write your MySQL query statement below

-- SELECT product_name AS pn FROM Product AS r RIGHT JOIN 
-- Sales as l ON 

--  Best approach: 
SELECT p.product_name, s.year, s.price
FROM Sales AS s LEFT JOIN Product as p ON s.product_id = p.product_id