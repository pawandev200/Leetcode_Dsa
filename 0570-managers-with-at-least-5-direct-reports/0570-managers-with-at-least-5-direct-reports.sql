# Write your MySQL query statement below
-- self join or subquery 
-- select name from Employee 
-- where id in (
--     select managerId from Employee 
--     group by managerId 
--     having count(*)>=5 ) 

-- Using join: 

select l.name 
from employee as l 
join employee as r 
on l.id = r.managerId
having count(r.managerId)>=5;

