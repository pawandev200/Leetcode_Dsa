# Write your MySQL query statement below

-- select num as ConsecutiveNums
-- from Logs 
-- group by num
-- having count(id) >=3

-- for consecutive number: id, id+1, id+2  since id is primary key 
select distinct(l1.num) as ConsecutiveNums
from Logs l1 
inner join Logs l2 on l1.id = l2.id -1 
inner join Logs l3 on l2.id = l3.id -1 
where l1.num = l2.num and l2.num = l3.num 