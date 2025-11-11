- Read and attach The Simpsons data file
- See the column names in the file

1) What’s the mean of rating? (imdb_rating)
2) What’s the standard deviation of rating? (imdb_rating)
3) Plot the distribution (on a histogram) of the imdb_rating for all episodes
4) Plot the distribution (on a histogram) of the imdb_rating for all episodes from seasons 1 to 10. Directly below it, plot the distribution (on a histogram) of the imdb_rating for all episodes from season 10 to 20. The x-axis on both plots should be aligned. There should be 5 bins on the x-axis corresponding to an imdb_rating of 5 through to 10 e.g. 5,6,7,8,9,10
5) Similar to questions 4, except there should be 10 bins between 5 and 10 (each .5 wide)
6) Show a boxplot for the imdb ratings across all episodes. Label the y-axis.
7) Show a boxplot for the imdb ratings for season 10. Set the y limit to be from 6.5 to 8.5 (hint: use ylim)
8) Plot how the average imdb_rating per Simpson’s season has changed over time i.e. from season 1 to season 28. ( hint: avg_per_season[i] = mean( imdb_rating[seas…. )
9) Using your code for 8), modify it to show the average imdb_rating (in green) for episodes 1-10 of each season (1-20). On the same plot, also show the average imdb_rating for episodes 10-20 of each season (in red).
10) Show boxplots (side by side) for IMDB Ratings from Season 5-10 and for Seasons 10-15. What can you interpret from the two boxplots?
11) Use a scatterplot to determine if there is a relationship between us_viewers_in_millions and the episode number for season 2. Is there? Explain?
12)  Use a boxplot to visualise the relationship between “imdb_rating” and “season” Hint: you must use two parameters in your command separated by ~ (Examples: boxplot(data1 ~ data2))
13) Use which.max() to see which season had the highest imdb_rating. Which was it?
14) Calculate the probabilities below:

- What’s the proportion of ratings (imdb_rating) less or equal than 6?
- What’s the proportion of ratings (imdb_rating) greater than 9?
- What’s the proportion of ratings (imdb_rating) between 7 and 8?
- What’s the proportion of episodes with viewers (us_viewers_in_millions) greater than 30?
- What’s the proportion of episodes with viewers(us_viewers_in_millions) less than 10?
- What’s the proportion of episodes with viewers(us_viewers_in_millions) between 10 and 20?