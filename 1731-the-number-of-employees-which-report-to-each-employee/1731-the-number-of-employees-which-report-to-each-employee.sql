# Write your MySQL query statement below

select l.employee_id, l.name, count(l.employee_id) as reports_count, 
round(avg(r.age)) as average_age
from Employees as l
inner join Employees as r 
on l.employee_id = r.reports_to 
group by l.employee_id 
order by l.employee_id 