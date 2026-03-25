# Write your MySQL query statement below

-- select employee_id, department_id 
-- from Employee 
-- group by employee_id 
-- having primary_flag='Y' or COUNT(employee_id) = 1 

select employee_id, department_id 
from Employee 
where primary_flag='Y'  -- since only one y for a employee
 or employee_id in (
    select employee_id from Employee 
    group by employee_id 
    having count(employee_id) = 1
 ) 
