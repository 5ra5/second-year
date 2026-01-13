# SIMULATION WITH REPLACEMENT - BINOMIAL
balls <- c(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1)
black_balls_r <- 0
for (i in 0:10000)
{
  black_balls_r[i] <- sum(sample(balls, 5, replace=T))
}

# SIMULATION WITHOUT REPLACEMENT - HYPERGEOMETRIC
balls <- c(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1)
black_balls_nor <- 0
for (i in 0:10000)
{
  black_balls_nor[i] <- sum(sample(balls, 5, replace=F))
}

par(mfrow=c(2, 1))

# WITH REPLACEMENT
plot(table(black_balls_r), main="Binomial simulation", xlab="Black balls picked", ylab="")

# TRUE BINOMIAL DISTRIBUTION
x <- 0:5
points(x, dbinom(x, 5, 0.25)*10000, col="red")

# WITHOUT REPLACEMENT
plot(table(black_balls_nor), main="Hypergeometric simulation", xlab="Black balls picked", ylab="")

# TRUE HYPERGEOMETRIC DISTRIBUTION
x <- 0:5
points(x, dhyper(x, 5, 15, 5)*10000, col="red")