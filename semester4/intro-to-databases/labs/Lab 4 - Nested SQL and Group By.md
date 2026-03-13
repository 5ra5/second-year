difficulty level of questions in the exam

**Section 1. Basketball**

1.  Return the year and the average wins of the NBA teams after the 1990 season only when this average is less than 40 (Hint: Group By required)
-  if you use group by, you can't use where after it, you have to use having to compare results
```sql
select year, avg(won) from teams
where year > 1990 group by year
having avg(won) < 40;
```

2.   Find all the basketball coach IDs with more than 900 of wins, order by ascending number of losses (Hint: Group By required)
-  example: in the exam you will have to create a dummy column total wins out of won and post_wins
```sql
select coachID, sum(won) from coaches
group by coachID
having sum(won) > 900;
```

3.  Print the players (playerID) of the Miami 1998 team with over 1200 minutes played. Use a nested query in your answer.
```sql
select playerID from players_teams
where year = 1998 and minutes > 1200
and tmID in
(select tmID from teams where name like '%miami%');
```

(Challenge: Can you display the player names as well?)
-  link playerID with player name
```sql
select firstname, lastName, playerID from players where playerID in
(
select playerID from players_teams
where year = 1998 and minutes > 1200
and tmID in
(select tmID from teams where name like '%miami%');
);
```