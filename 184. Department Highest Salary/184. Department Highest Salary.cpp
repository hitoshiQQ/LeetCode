# Write your MySQL query statement below
SELECT department.Name AS Department,
employee.Name as Employee,
employee.Salary AS Salary
FROM Department department
LEFT JOIN Employee employee
ON department.Id = employee.DepartmentId
WHERE(department.Id, employee.Salary) IN(
    SELECT employee.DepartmentId, max(employee.Salary) FROM Employee employee GROUP BY employee.DepartmentId
);