**Section 1. Basketball**

2.  Return the id of the player who in 1997 scored more than 1000 points and in 1996 played for Chicago Bulls and got more than 350 rebounds. (Difficulty : Hard)
-  most difficult question in the lab, if you can navigate it, you will be ready for the exam
(Hint: You could need to join the same table twice. You need to obtain the players’ ID list matching the requirements for 1997, and the list for 1996. The inner join will give you the final player. You need to join again with another table to ensure the correct name of the team.
```sql
-- id -> 1997
-- pts -> 1000
-- team -> chicago bulls
-- rebounds -> 350 but in the year 1996

select pt1.playerID, pt1.points from pt1.players_teams pt1, teams t, players_teams pt2
where pt1.points > 1000 and 
pt1.year = 1997 and pt1.playerID = pt2.playerID and pt2.rebounds > 350
and t.tmID = pt2.tmID and t.year=pt2.year
and t.year = 1996 and t.name = 'Chicago Bulls';
```

other way to do it
```sql
-- id -> 1997
-- pts -> 1000
-- team -> chicago bulls
-- rebounds -> 350 but in the year 1996

select pt1.playerID, pt1.points from pt1.players_teams pt1, teams t, players_teams pt2
where pt1.points > 1000 and 
pt1.year = 1997 and pt1.playerID = pt2.playerID 
and pt2.rebounds > 350 and pt2.year = 1996
and t.tmID = pt2.tmID and t.year=pt2.year
and t.name = 'Chicago Bulls';
```

-  in the exam - display the first 5 rows
-  keep `LIMIT` in mind - not mentioned in the slides
```sql
select * from teams
LIMIT 5;
```

