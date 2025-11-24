# Binomial

- _Simulate 10 trials per experiment, each with success probability p = 0.3. Count successes._

```R
simulate_binomial <- function(n_trials = 10, p = 0.3, n_sim = 10000) {
  results <- numeric(n_sim)
  
  for (i in 1:n_sim) {
    trials <- runif(n_trials) < p  # success if random < p
    results[i] <- sum(trials)      # count successes
  }
  
  return(mean(results == 4))  # example: estimate P(X = 4)
}

simulate_binomial()

```

# Geometric

 - _Stop only when the **first success** appears. Record number of trials._

```R
simulate_geometric <- function(p = 0.3, n_sim = 10000) {
  results <- numeric(n_sim)
  
  for (i in 1:n_sim) {
    count <- 0
    repeat {
      count <- count + 1
      if (runif(1) < p) break   # first success
    }
    results[i] <- count
  }
  
  return(mean(results == 5))  # example: P(X = 5)
}

simulate_geometric()

```

# Hypergeometric 

- Example: Population of 20 items, 6 are defective. Draw 5 items (no replacement). Count number of defectives.

```R
simulate_hypergeometric <- function(N = 20, K = 6, n_draw = 5, n_sim = 10000) {
  results <- numeric(n_sim)
  
  for (i in 1:n_sim) {
    population <- c(rep(1, K), rep(0, N - K)) # 1 = defective, 0 = good
    sample_draw <- sample(population, n_draw, replace = FALSE)
    results[i] <- sum(sample_draw)  # count defectives
  }
  
  return(mean(results == 2))  # example: P(X = 2)
}

simulate_hypergeometric()

```
