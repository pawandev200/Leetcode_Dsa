# Write your MySQL query statement below
-- self join or subquery 
select name from Employee 
where id in (
    select managerId from Employee 
    group by managerId 
    having count(*)>=5 ) 


