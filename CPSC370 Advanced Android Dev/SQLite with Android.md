# SQLite with Android

```sql
SELECT <attr_names> FROM <table_name>;

SELECT * FROM Customers WHERE Country='Spain'

... WHERE CustomerID BETWEEN 10 and 50
... WHERE CustomerID IN (10,5,3)
... WHERE Country LIKE '%land'
... WHERE Country LIKE '%r%' # anything that has an 'r' (not case-sensitive)

<base_statement> ORDER BY <attribute_name> <ASC|DESC>
# ASC by default

UPDATE Customers
SET Country='United Kingdom' , City='Santa Ana', Country='USA'
WHERE Country='Mexico'

DELETE FROM Customers WHERE ContactName='Ryan Burns'
# Usually deleted flag is used

Inner Join joins tables on a matching column

SELECT o.OrderID, e.FirstName AS EmpFirstName, e.LastName AS EmpLastName FROM Orders AS o # which table to select?
INNER JOIN Customers AS c # which table to join?
ON c.CustomerID = o.CustomerID # see matching customerIDs and match the rows

INNER JOIN Employees AS e
ON e.EmployeeID = o.EmployeeID

WHERE c.CustomerName LIKE 'M%'; # where statement

LEFT OUTER JOIN
The result is NULL on the right side when there is no match

NULL, INTEGER, REAL, TEXT, BLOB

INSERT INTO Positions VALUES(2,'Assistant to the Regional Manager',6)

SELECT p.PositionName, e.LastName
FROM Positions as p
INNER JOIN Employees AS e
ON p.EmployeeID = e.EmployeeID

```

