Die is rolled once.
P(even number) = ?
```
sum[dice[c(2, 4, 6)]]
```

Class of 25 students. s = 3
P(specific 3 students are chosen) = ?
```
1 / choose(25, 3)
```

Class of 30 students.
P(everyone has a different birthday)  = ?
```
prod(365:(365-30+1))/(365^30)
-> prod(365:336)/(365^30)
```

Box has 8 red balls, 12 blue balls, s = 3, no replacement
P(all balls red) = ?
```
choose(8,3)/ choose(20,3)
```

Deck of cards
P(King or a Heart) = ?
```
((sum(deck$rank == "King") + sum(deck$suit == "Heart") - sum(deck$rank == "King" & deck$suit == "Heart")) / nrow(deck))

```

Dice is rolled once.
P(2 < n < 5) = ?
```
sum(dice[3:4])
```

Dice rolled twice
P(both rolls show a 4)
```
prod(rep(1/6, 2))
```

5 red balls, 7 blue balls, s = 4
P(2 balls are red) = ?
```
(choose(5,2) * choose(7, 2)/choose(12,4)
```

```
tosses <- numeric(10)

for(i in 1:10){
	if(runif(1) < 0.7) tosses[i] <- 1 else tosses[i] <- 0
}
```