## 2025 resit

**nexteast(X,Y) is true if X is the immediate east point of Y, e.g. nexteast(g,f).**
**nextsouth(X,Y) is true if X is the immediate south point of Y, e.g. nextsouth(m,i).**
**south(X,Y) is true if X can be reached from Y by only travelling directly south. 
east(X,Y) is true if X can be reached from Y by only travelling directly east.**
**southoreast(X,Y) is true if X can be reached from Y by only travelling directly south or east.**

**sum the elements of a list of integers**
**find the maximum of a list of elements**

**Describe cuts in Prolog. Why are cuts used? Illustrate your answer with examples.**

## 2025

**split(N, Positive, Negative) is true if all the positive numbers (including 0) in the list N are in the list Positive, and all the negative numbers in the list N are in the list Negative.**

**oddsquaresum(X, S) is true when S is the sum of the square of all the odd numbers in the list X. Note that the list X can contain any atom, e.g. [4,oranges,5,2,7,apples,1]. Hence, oddsquaresum([4,oranges,5,2,7,apples,1], 75) is true.**

Describe cuts in Prolog. Why are cuts used? Illustrate your answer with examples.

## 2024

**oddsum(X, S) is true when S is the sum of all the odd integers in the list X. Note that the list X can contain any atom, e.g. [4,oranges,5,2,7,apples,1]. Hence, oddsum([4,oranges,5,2,7,apples,1], 13) is true.**

split(N, Positive, Negative) is true if all the positive numbers (including 0) in the list N are in the list Positive, and all the negative numbers in the list N are in the list Negative.

**Describe the procedural interpretation of a Prolog program. Provide a sample Prolog query and show how this procedural interpretation evaluates the query.**

# 2023 resit

**union(A,B,C) is true if the list C contains only even numbers in either lists A or B**
**intersection(A,B,C) is true if the list C contains only even numbers in both lists A and B.**

oddsquaresum(X, S) is true when S is the sum of the square of all the odd numbers in the list X. Note that the list X can contain any atom, e.g. [4,oranges,5,2,7,apples,1]. Hence, oddsquaresum([4,oranges,5,2,7,apples,1], 75) is true.

Describe cuts in Prolog. Why are cuts used? Illustrate your answer with examples.

# 2023

**Given the following Prolog relations: ** 
**parent(X,Y) is true if X is the parent of Y, ** 
**male(X) is true if X is male,**
**female(X) is true if X is female**
**write the following Prolog relations: ** 
**uncle(X,Y) is true if X is an uncle of Y, ** 
**greatuncle(X,Y) is true if X is the uncle of a parent of Y, ** 
**ancestor(X,Y) is true if X is a direct ancestor of Y.**

**Let a bus timetable be represented by a list of routes where each route is represented by Start/End/DepatureTime/ArrivalTime. Both DepartureTime and ArrivalTime are represented by a relation time(Hour,Minutes). Write a Prolog relation journey(Start, End) that is true if there is a route in the timetable that can get a passenger from Start to End directly or with one intermediate stop where there is at least 10 minutes between the arrival at an intermediate point the departure to the destination of the journey. Assume the clock is a 24 hour clock and all departure and arrival times occur within the same day**

Describe the procedural interpretation of a Prolog program.

## 2022 resit

**calculate the length of a list**
**append list A to list B to produce list C**

**Given the following Prolog relations: ** 
**parent(X,Y) is true if X is the parent of Y, **
**male(X) is true if X is male,** 
**female(X) is true if X is female**
**write the following Prolog relations: ** 
**brother(X,Y) is true if X is the brother of Y, ** 
**uncle(X,Y) is true if X is an uncle of Y,**

Give a detailed description, in your own words, of the procedural interpretation of a Prolog program.

## 2022

sum the elements of a list of integers
find the maximum of a list of positive integers.

split(N, Even, Odd) that is true if all the even numbers (including 0) in the list N are in the list Even, and all the odd numbers in the list N are in the list Odd

Give a detailed description, in your own words, of the procedural interpretation of a Prolog program.

## 2021

union(A,B,C) is true if the list C contains only even numbers in either lists A or B
intersection(A,B,C) is true if the list C contains only even numbers in both lists A and B

**Let a bus timetable be represented by a list of routes where each route is repre- sented by Start/End/DepatureTime/ArrivalTime. Both DepartureTime and ArrivalTime are represented by a relation time(Hour,Minutes). Write a Prolog relation journey(Start, End) that is true if there is a route in the timetable that can get a passenger from Start to End directly or any number of intermediate stops where there is at least 10 minutes between the arrival at an intermediate point before the departure of the next leg of the journey. Assume the clock is a 24 hour clock and all departure and arrival times occur within the same day.**

Describe cuts in Prolog. Why are cuts used? Illustrate your answer with examples.

## 2020

split(N, Positive, Negative) that is true if all the positive numbers (including 0) in the list N are in the list Positive, and all the negative numbers in the list N are in the list Negative

oddsquaresum(X, S) that is true when S is the sum of the square of all the odd numbers in the list X. Note that the list X can contain any atom, e.g. [4,oranges,5,2,7,apples,1]. Hence, oddsquaresum([4,oranges,5,2,7,apples,1], 75) is true.

Describe cuts in Prolog. Why are cuts used? Illustrate your answer with examples.

## 2019 resit

calculate the length of a list;
append list A to list B to produce list C.

oddsquaresum(X, S) that is true when S is the sum of the square of all the odd numbers in the list X. Note that the list X can contain any atom, e.g. [4,oranges,5,2,7,apples,1]. Hence, oddsquaresum([4,oranges,5,2,7,apples,1], 75) is true.

Describe the procedural interpretation of a Prolog program.

## 2019

nexteast(X,Y) is true if X is the immediate east point of Y, e.g. nexteast(g,f).
nextsouth(X,Y) is true if X is the immediate south point of Y, e.g. nextsouth(m,i). 
Given these relations, write the following Prolog relations:
south(X,Y) is true if X can be reached from Y by only travellling directly south. 
east(X,Y) is true if X can be reached from Y by only travellling directly east.
southoreast(X,Y) is true if X can be reached from Y by only travellling directly south or east.

sum the elements of a list of integers
find the maximum of a list of elements.

Describe cuts in Prolog. Why are cuts used? Illustrate your answer with examples.

## 2018 resit

**Given the following Prolog relations:**
**parent(X,Y) is true if X is the parent of Y**
**male(X) is true if X is male**
**female(X) is true if X is female**
**write the following Prolog relations:**
**sister(X,Y) is true if X is the sister of Y**
**aunt(X,Y) is true if X is an aunt of Y**

```prolog
sister(X, Y) :-
	parent(Z, X),
	parent(Z, Y),
	female(X),
	X \= Y.
	
aunt(X, Y) :-
	parent(Z, Y),
	sister(X, Z).
```

Let a bus timetable be represented by a list of routes where each route is repre- sented by Start/End/DepatureTime/ArrivalTime. Both DepartureTime and ArrivalTime are represented by a relation time(Hour,Minutes). Write a Prolog relation journey(Start, End) that is true if there is a route in the timetable that can get a passenger from Start to End directly or with one intermediate stop where there is at least 10 minutes between the arrival at an intermediate point the departure to the destination of the journey. As- sume the clock is a 24 hour clock and all departure and arrival times occur within the same day

**Describe what negation as failure means in Prolog. Why is negation problematical in Prolog? Illustrate your answer with examples.**

# 2018

uncle(X,Y) is true if X is an uncle of Y
greatuncle(X,Y) is true if X is the uncle of a parent of Y
ancestor(X,Y) is true if X is a direct ancestor of Y.

**concat(A, B, C) is true if string C is the concatenation of strings A and B.**
**reverse(A, B) is true if string B is the reverse of string A.**

Describe the procedural interpretation of a Prolog program.

## 2017 resit

myReverse(X,Y) that is true when the list Y is the reverse of list X.
**myDelete(X,Y,Z) that is true when the list Z is the result of deleting an occurrence of the element X from the list Y, e.g. myDelete(3, [1,2,3,4,3,2,1], [1,2,4,3,2,1]) is true.**

oddsquaresum(X, S) that is true when S is the sum of the square of all the odd numbers in the list X. Note that the list X can contain any atom, e.g. [4,oranges,5,2,7,apples,1]. Hence, oddsquaresum([4,oranges,5,2,7,apples,1], 75) is true.

Describe cuts in Prolog. Why are cuts used? Illustrate your answer with examples.

## 2017

**given:
parent(X,Y) is true if X is the parent of Y,
male(X) is true if X is male
female(X) is true if X is female
write:
grandmother(X,Y) is true if X is the grandmother of Y,
aunt(X,Y) is true if X is an aunt of Y
ancestor(X,Y) is true if X is a direct ancestor of Y. 

**given:**
**road(A,B,N)**
**write:**
**routen(X,Y,N) is true if there exists a route of length N, with zero or more inter- mediate towns, between X and Y.**
**toofar(X,Y) is true if there is a route between X and Y and the total distance is more than 6 km.**

Describe what negation as failure means in Prolog. Why is negation problematical in Prolog? Illustrate your answer with examples.

## 2016 resit

**union(A,B,C) is true if the list C contains only elements in either lists A or B**
**intersection(A,B,C) is true if the list C contains only elements in both lists A and B.**

**inlist(A,B) is true if the element A is contained in list B.**
myappend(A,B,C) is true if list C is list B appended to list A
mydelete(A,B,C) is true if list C is list B with the element A removed.

**With the aid of examples, explain the difference between red and green cuts.**

## 2016

Describe cuts in Prolog. Why are cuts used? Illustrate your answer with examples.

split(N, Positive, Negative) that is true if all the positive numbers (including 0) in the list N are in the list P ositive, and all the negative numbers in the list N are in the list Negative

union(A,B,C) is true if the list C contains all the elements in either lists A or B.
intersection(A,B,C) is true if the list C contains all the elements in both lists A and B.

## 2014 resit

**given:**
**road(A,B,N)**
**write:**
**routen(X,Y,N) is true if there exists a route of length N, with zero or more intermediate towns, between X and Y.**
**canwalk(X,Y)  is true if there is a route between X and Y and the total distance is less than or equal to 4 km.**

inlist(A,B) is true if the element A is contained in list B
myappend(A,B,C) is true if list C is list B appended to list A
mydelete(A,B,C) is true if list C is list B with the element A removed


Describe what negation as failure means in Prolog. Why is negation problematical in Prolog? Illustrate your answer with examples.