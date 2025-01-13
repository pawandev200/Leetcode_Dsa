# Write your MySQL query statement below
SELECT l.name, r.bonus FROM Employee AS l LEFT JOIN 
Bonus AS r on l.empId = r.empId WHERE bonus IS NULL OR bonus < 1000