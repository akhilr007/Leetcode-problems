# Write your MySQL query statement below
SELECT name AS Customers
FROM customers
LEFT JOIN orders
ON orders.customerId = customers.id
WHERE orders.customerId IS NULL