# Write your MySQL query statement below

-- select class, count(student) from Courses
-- group by class 
-- having count(students) >=5
-- where (student, class) in (
--     select student, class from Courses 
--     group by class
-- )

select class from (
    select class, count(student) as st from Courses
    group by class 
) as t 
where st>=5