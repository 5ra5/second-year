n_iterations <- 100000
defective_in_first5 <- rep(FALSE, n_iterations)

for (i in 1:n_iterations) {
  
  # check the first 5 inspections only
  for (inspection in 1:5) {
    
    # defective product?
    if (runif(1) <= 0.2) {
      defective_in_first5[i] <- TRUE
      break   # stop early if defective found
    }
  }
}

# Estimated probability
mean(defective_in_first5)
