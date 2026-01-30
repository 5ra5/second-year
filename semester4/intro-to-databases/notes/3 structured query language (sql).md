# simple queries

-  SQL is a declarative language where the user specifies what the result is to be and **not** how to compute it
-  SQL has a Data Manipulation Language (DML) and a Data Definition Language (DDL) component

`SELECT` = to query data in the database
`INSERT` = to insert data into a table
`UPDATE` = to update data in a table
`DELETE` = to delete data from a table

 NOTE: **when you delete something, you can get it back , but when you drop it you can't**

the sequence of processing in a SELECT statement is:
```sql
FROM specifies the table or tables to be used
WHERE filters the rows subject to some condition
GROUP BY forms groups of rows with the same column value
HAVING filters the groups subject to some condition
SELECT specifies which columns are to appear in the output
ORDER BY specifies the order of the output
```

-  The order of the clauses in the SELECT statement cannot be changed.
-  The only two mandatory clauses are the first two: SELECT and FROM; the remainder are optional.

**if you make a database a default schema, you don't have to specify the name of the database before the row or column name when making a query**

example 1: List full details of all staff
```sql
SELECT staffNo, fName, lName, position, sex, DOB, salary, branchNo
FROM Staff;
```

simpler way:
```sql
SELECT *
FROM Staff;
```

example 2: produce a list of salaries for all staff, showing only the staff number, the first and last names, and the salary details
```sql
SELECT staffNo, fName, lName, salary
FROM Staff;
```

example 3:  list the property numbers of all properties that have been viewed
```sql
SELECT propertyNo FROM
PropertyForRent ;
```

```sql
SELECT DISTINCT propertyNo
FROM PropertyForRent;
```


example 4: produce a list of monthly salaries for all staff, showing the staff number, the first and last names, and the salary details
```sql
SELECT staffNo, fName, lName, salary/12
FROM Staff;
```

using a calculated field (computed/derived field)
```sql
SELECT staffNo, fName, lName, salary/12 AS monthlySalary
FROM Staff;
```

-  A SQL View is a virtual table created from the result of a SELECT query. It does not store data physically but displays data stored in underlying tables. Views help simplify complex queries, enhance security, and present data in a cleaner, customised format.

example 5: list all staff with salary greater than 10000
```sql
SELECT staffNo, fName, lName, position, salary
FROM Staff
WHERE salary > 10000;
```

a view is created here - a temporary table that holds data we're looking for

usual rules apply for comparison
-  an expression is evaluated left to right
-  subexpressions in brackets are evaluated first
-  **NOTs are evaluated before ANDs and ORs**
-  **ANDs are evaluated before ORs**

the use of parentheses is always recommended in order to remove any ambiguities

example 6: list the addresses of all branch offices in London or Glasgow
```sql
SELECT *
FROM Branch
WHERE city = ’London’ OR city = ’Glasgow’;
```

example 7: List all staff with a salary between 20,000 and 30,000
```sql
SELECT staffNo, fName, lName, position, salary
FROM Staff
WHERE salary BETWEEN 20000 AND 30000;
```

example 8: List all managers and supervisors
```sql
SELECT staffNo, fName, lName, position
FROM Staff
WHERE position IN (’Manager’, ’Supervisor’)
```

```sql
SELECT staffNo, fName, lName, position
FROM Staff
WHERE position = ’Manager’ OR
position = ’Supervisor’;
```

-  the IN test provides a more efficient way of expressing the search condition, particularly if the set contains many values

example 9: find all owners with the string 'Glasgow' in their address
```sql
SELECT ownerNo, fName, lName, address, telNo
FROM PrivateOwner
WHERE address LIKE ’%Glasgow%’;
```

-  % percent character represents any sequence of zero or more characters (wildcard).
-  _ underscore character represents any single character.
-  if you want only the addresses which start with Glasgow, then remove the first percentage `'Glasgow%'`
-  the same applies for addresses which end with Glasgow `'%Glasgow'`

## sorting results

example 10: produce a list of salaries for all staff, arranged in descending order of salary
```sql
SELECT staffNo, fName, lName, salary
FROM Staff
ORDER BY salary DESC;
```

example 11: produce an abbreviated list of properties arranged in order of property type
```sql
SELECT propertyNo, type, rooms, rent
FROM PropertyForRent
ORDER BY type;
```

properties arranged in order by property type and rent
```sql
SELECT propertyNo, type, rooms, rent
FROM PropertyForRent
ORDER BY type, rent DESC;
```