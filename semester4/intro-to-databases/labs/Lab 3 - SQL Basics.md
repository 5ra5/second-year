**Section 1. Basketball**

1. List the ID of the players who won an award in 1989. (Challenge : Don’t display duplicate ID’s)
```sql
select Distinct playerID, year from awards_players
where year = 1989;
```

-  (exam type question) list the player name and the team they played for when they won an award

2.  List the ID of the players who scored more than 400 points in less than 900 minutes played during the season 1998
```sql
select playerID, minutes, points, year from players_teams
where points > 400
and minutes < 900
and year = 1998;
```

3.   Return the name and the number of wins at home of the teams with ‘Chicago' in their name during the season 1994. (this difficulty of questions in the exam)
```sql
select name, year, homeWon, awayWon from teams
where name LIKE '%Chicago%'
and year = 1994;
```

(Challenge : Return the name of the teams with ‘C’ in their name during the season 1994 where they won more games at home than away) 
-  LIKE will come up in the exam
```sql
select name, year, homeWon, awayWon from teams
where name LIKE '%C%'
and year = 1994
and homeWon > awayWon;
```

**Section 2: Sakila**

4.  Show all films with rating 'PG' or 'PG-13', ordered by length (shortest first) and then title.
-  you can also do this with LIKE instead of IN - `where rating like '%PG%';`
```sql
select title, rating, length from film
where rating in ('PG', 'PG-13')
Order by length, title;
```

5.  List all distinct film ratings in the database, sorted alphabetically.
-  this will not work (rating is enum, not alphabetical)
```sql
select distinct rating from file order by rating;
```

6.  List all films whose title starts with 'THE', ordered by title.
```sql
select title from film
where title like 'The%'
order by title;
```

-  this will give you all films that contain the anywhere in the name
```sql
where title like '%The%'
```

**Section 3. World**

7.  Get a list of cities in 'USA' where the city name contains the letter sequence 'New', ordered by name. (Hint : use country code in city table)
```sql
select name from city where CountryCode Like 'USA'
and name like '%New%' order by name;
```

-  you can also use
```sql
select name from city where CountryCode = 'USA'
and name like '%New%' order by name;
```

8.  Find all cities whose name ends with ‘burg’ , ordered by population descending.
```sql
select name from city where name like '%burg'
order by population;
```

9.  Which distinct languages represent the majority language in at least one country? Display ordered by percentage descending. (Hint: Use ‘countrylanguage’ table
```sql
select distinct language, CountryCode, percentage from countrylanguage
where percentage > 50
order by percentage Desc;
```