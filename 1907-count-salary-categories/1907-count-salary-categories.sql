# Write your MySQL query statement below

-- select category, count(category) as accounts_count
-- from (
--     select account_id, income, 
--         case 
--             when income < 20000 then "Low Salary"
--             when income >= 20000 and income <= 50000 then "Average Salary"
--             when income > 50000 then "High Salary"
--         end as category
--         from Accounts 
--     ) as t 
-- group by category

-- on the fly a column creation with certain row in output

SELECT 'Low Salary' AS category,
 count(case when income < 20000 then "Low Salary" end ) as accounts_count
FROM Accounts

union 

SELECT 'Average Salary' AS category,
 count(case when income >= 20000 and income <= 50000 then "Average Salary" end ) as accounts_count
FROM Accounts

union 

SELECT 'High Salary' AS category,
 count(case when income > 50000 then "High Salary" end ) as accounts_count
FROM Accounts
