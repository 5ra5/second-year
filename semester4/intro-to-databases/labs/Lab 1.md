## Section 2: Query Practice#

**Q1.**
query:
```sql
SELECT * FROM sakila.actor where first_name = "michael";
```

output:
Error: #1142 - SELECT command denied to user sartorp2db'@'136.206.218.24 for table 'sakila'.'actor'

**Q2.**
query:
```sql
SELECT * FROM City where ID = 15;
```

output:
All information about one city that has an ID of 15.

**Q3.**
query:
```sql
SELECT Name, ID FROM City where ID = 15;
```

output:
Just the name and ID of a city which has an ID of 15.
