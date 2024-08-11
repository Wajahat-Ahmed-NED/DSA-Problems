-- To find Average Selling Price
select p.product_id, ifnull(round(sum(p.price*u.units)/sum(u.units),2),0) as average_price from Prices p left join UnitsSold u 
on p.product_id=u.product_id and u.purchase_date between p.start_date and p.end_date group by p.product_id


-- Project Employees I
select p.project_id, round(avg(e.experience_years),2) as average_years from Project p inner join Employee e on p.employee_id=e.employee_id group by p.project_id


-- Percentage of Users Attend the Contest
select r.contest_id, round((count(r.user_id)/(Select count(*) from Users))*100,2) as percentage from Users u inner join Register r on u.user_id=r.user_id group by r.contest_id order by percentage desc, r.contest_id asc;


-- Monthly Transactions I
/* Write your T-SQL query statement below */
SELECT
    FORMAT(trans_date , 'yyyy-MM') AS month, country, count(*) as trans_count,
    SUM(CASE when state = 'approved' Then 1 else 0 end) as approved_count,
    SUM(amount) AS trans_total_amount, SUM(case  when state = 'approved' then amount else 0 end) as approved_total_amount 
FROM
    Transactions 
GROUP BY
    country,FORMAT(trans_date , 'yyyy-MM');

-- Queries Quality and Percentage

SELECT 
    q.query_name, 
    ROUND(SUM(q.rating / q.position) / COUNT(*), 2) AS quality,
    IFNULL(ROUND((SELECT COUNT(*) FROM Queries sub_q 
                  WHERE sub_q.query_name = q.query_name AND sub_q.rating < 3) 
                  / COUNT(*) * 100, 2), 0) AS poor_query_percentage
FROM 
    Queries q 

WHERE q.query_name is NOT NULL

GROUP BY 
    q.query_name;



-- Immediate Food Delivery II

select 
round(avg(order_date=customer_pref_delivery_date)*100,2) as immediate_percentage
from delivery
where(customer_id, order_date) in (
    select customer_id, min(order_date)
    from delivery
    group by customer_id
)