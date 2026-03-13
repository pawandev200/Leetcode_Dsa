# Write your MySQL query statement below

-- select r.contest_id, round((count(r.user_id)/count(u.user_name))*100, 2) as percentage
-- from Users as u
-- left join Register as r 
-- on u.user_id = r.user_id 
-- group by r.contest_id

select 
contest_id, 
round(count( user_id) * 100 /(select count(user_id) from Users) ,2) as percentage
from  Register
group by contest_id
order by percentage desc,contest_id