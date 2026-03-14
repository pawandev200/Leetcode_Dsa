# Write your MySQL query statement below

(select u.name as results 
from Users as u
inner join MovieRating as mr 
on u.user_id = mr.user_id
group by mr.user_id 
order by count(distinct(mr.movie_id)) desc, u.name
limit 1 )

union all

(select m.title as results
from Movies as m
inner join MovieRating mr
on m.movie_id = mr.movie_id 
where mr.created_at between '2020-02-01' and '2020-02-29'
group by mr.movie_id 
order by avg(mr.rating) desc, m.title
limit 1)
