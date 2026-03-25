# Write your MySQL query statement below

-- need most recent price before 2019-08-16 
-- products that have no rows after step 1 → assign price = 10

select l.product_id, coalesce(r.new_price, 10) as price 
from (select distinct product_id from Products) as l 
left join (
    select product_id, new_price from Products 
    where (product_id, change_date) in (
        select product_id, MAX(change_date) from Products
        where change_date <= '2019-08-16'
        group by product_id
    )
) as r 
on l.product_id = r.product_id