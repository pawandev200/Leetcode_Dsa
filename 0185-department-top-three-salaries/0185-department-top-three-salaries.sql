# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary 
from employee as e
left join Department as d 
on e.departmentId  = d.id
where (
    select count(distinct(e2.salary)) from employee as e2 
    where e2.salary > e.salary and e2.departmentId = e.departmentId
) < 3

-- checking each salary, will it comes to top 3 of it's dept 
-- by counting how many salary in their dept is > curr salary 