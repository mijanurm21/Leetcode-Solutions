# Write your MySQL query statement below
select unique_id, name from Employees e
left join EmployeeUNI emp
on Emp.id = e.id