parent(carol, paul).
parent(carol, jane).
parent(harry, tom).
parent(harry, mary).
parent(jim, tom).
parent(jim, mary).
parent(ann, tom).
parent(ann, mary).
parent(tim, harry).
parent(tim, carol).
parent(george, harry).
parent(george, carol).
parent(jenny, harry).
parent(jenny, carol).
parent(david, jim).
parent(david, joan).
parent(kate, jim).
parent(kate, joan).
parent(susan, dominic).
parent(susan, ann).

male(paul).
male(tom).
male(harry).
male(jim).
male(dominic).
male(tim).
male(george).
male(david).

female(jane).
female(mary).
female(carol).
female(joan).
female(ann).
female(jenny).
female(kate).
female(susan).

% Q1
mother(X, Y) :- female(X), parent(X, Y).
father(X, Y) :- male(X), parent(X, Y).

sibling(X, Y) :- 
    mother(Z, X), mother(Z, Y);
    father(Z, X), father(Z, Y).

uncle(X, Y) :- male(X), sibling(X, Z), parent(Z, Y).

% Q2
cousin(X, Y) :- parent(Z, Y), uncle(Z, X).
parentalgrandmother(X, Y) :- mother(X, Z), father(Z, Y).

% Q3
