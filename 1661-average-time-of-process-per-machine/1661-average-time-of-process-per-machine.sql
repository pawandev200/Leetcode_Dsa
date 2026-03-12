# Write your MySQL query statement below

select l.machine_id, round(avg(r.timestamp - l.timestamp), 3) as processing_time
from Activity l
join Activity r 
on l.machine_id=r.machine_id and l.process_id=r.process_id
and l.activity_type='start' and r.activity_type='end'
group by l.machine_id