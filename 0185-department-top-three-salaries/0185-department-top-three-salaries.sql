# Write your MySQL query statement below

select d.name as Department, e.name as Employee, e.salary as Salary 
from Employee as e 
inner join Department as d 
on e.departmentId = d.id 
where (
    select count(distinct(e2.salary)) from Employee as e2
    where e.salary < e2.salary and e.departmentId = e2.departmentId 
) < 3; 
