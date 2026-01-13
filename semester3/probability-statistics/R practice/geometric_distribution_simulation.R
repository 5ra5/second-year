# number of iterations for our simulation
n_iterations=10000

# we are using this to keep track for each iteration how many times we inspect before we find the first defective.
first_defective <- 0
for (i in c(1:n_iterations) )
{
  j <- 1
  while (TRUE)
  {
    if (runif(1) <= .2)
    {
      first_defective[i] <- j
      break
    }
    j <- j+1
  }
}

# The estimated probability that the first defective will be found on the 5th item can be found using:
prob <- length(first_defective[first_defective==5])/n_iterations
prob

