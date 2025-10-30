___________________________________________________________
# LAB 3

Simple Calculator (lab3-calculator.c)
- input: first argument is a string, the second and third arguments are two floating numbers

Reverse a string (lab3-string-reverse.c)
- input: one argument as an input string

Find the max number in an array (lab3-findMax.c)
- input: array of integers
- output: largest element

Search X (lab3-search-number.c)
- find a number in an array, assume no duplicates
- input: first argument is the number which needs to search, the following arguments (from the 2nd argument) are elements in the array
- output (if you find the number): "Found `<value> `at `<index>`"

Find duplicated number (lab3-duplicated-number.c)
- input: array of positive integers
- output: duplicated number (if any)

Sorting an Array (lab3-is-sorted.c)
- input: array of integers
- sort the array in ascending order - bubble sort
- output: sorted array elements line by line

Find longest words in a sentence (lab3-find-longest-word.c)
- input: sentence (example: "My college is DCU")
- output: longest word in a sentence (assume there is only one)
___________________________________________________________
# LAB 4

Counting a character (lab4-count-character.c)
- input: first argument is a string, second one is a character
- assume that lowercase and uppercase are different
- output: number of occurrences of the character in the string

Find the most frequent character (lab4-find-most-character.c)
- input: string
- output: character which has the most number of appearance

Matrix Diagonal Sum (lab4-matrix-diagonal-sum.c)
- input: first int is a dimension of a matrix, the following n * n arguments correspond to all elements of the matrix respectively
- output: sum of the matrix main diagonal

Find a word in a sentence (lab4-search-sub-string.c)
- input: first argument is a string, second argument is a smaller length string
- check if the first string contains the second string
- output: positions of the first and last character of the second string in the first string
___________________________________________________________
# LAB 5

Calculate everything (lab5-cal-everything.c)
- input: two non-zero integer numbers a and b
- output: result of the various calculations

Select your sorting (lab5-sort-numbers.c)
- input: the number of integers (`argv[1]`), list of integers, sorting order (string)
- output: sorted array of integers in descending or ascending order

Read data of a country from command lines and print out (lab5-get-a-country.c)
- input: name (string), capital(string), population (float), size(int)
- output: information about the country

Read data of a list of countries from command lines and print all (lab5-get-countries.c)
- input: multiple countries - name (string), capital(string), population (float), size(int)
- output: information about countries in columns (\t\t\t)

Calculate the average population of all input countries (lab5-average-population.c)
- input: multiple countries - name (string), capital(string), population (float), size(int)
- output: see the labsheet for format, at the end print average
___________________________________________________________

# LAB 6

Find a country (lab6-find-country.c)
- input: multiple countries -  name (string), capital(string), population (float), size(int)
- print: all countries whose size is smaller than 100000

Sorting the list of countries based on population (lab6-sort-countries.c)

Find a largest city of countries (lab6-countries-cities.c)
- input: multiple country - `<country1> <city1> <size1> <city2> <size2> <city3> <size3>`
- output: `<country> : <largest city>`
