# Write your MySQL query statement below
SELECT 
-- *
q1.person_name
FROM Queue as q1 
JOIN Queue as q2 
ON q1.turn >= q2.turn
group by q1.turn              -- group all q2 rows per q1 person
having sum(q2.weight) <= 1000 -- keep only where cumulative weight fits
order by sum(q2.weight) desc  -- highest valid total comes first
limit 1  -- that's our last person

-- For each person, need sum of weights of all people who boarded before them (including themselves)