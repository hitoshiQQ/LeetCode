# Write your MySQL query statement below
SELECT
department.Name AS Department,
employee.Name AS Employee,
employee.Salary FROM(
    SELECT Id, Salary, Name, departmentId, dense_rank()
    OVER(partition by departmentId order by salary desc) rnk_salary
    FROM Employee) employee,
    Department department

    WHERE employee.departmentId = department.Id
    AND rnk_salary <= 3
    ORDER BY department.Name;

