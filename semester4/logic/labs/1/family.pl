/* FACTS */

/*second and third parameter are the parents of the first one*/
parents(david, george, noreen).
parents(jennifer, george, noreen).
parents(georgejr, george, noreen).
parents(scott, george, noreen).
parents(joanne, george, noreen).
parents(jessica, david, edel).
parents(clara, david, edel).
parents(michael, david, edel).
parents(laura, georgejr, susan).
parents(anna, scott, siobhan).

/* Relationships */
father(X, Y) :- parents(Y, X, _).
male(X) :- father(X, _).

mother(X, Y) :- parents(Y, _, X).
female(X) :- mother(X, _).

grandfather(X, Y) :- father(X, Z), father(Z, Y).
grandfather(X, Y) :- father(X, Z), mother(Z, Y).

grandmother(X, Y) :- mother(X, Z), mother(Z, Y).
grandmother(X, Y) :- mother(X, Z), father(Z, Y).

brother(X, Y) :- male(X), father(Z, X), father(Z, Y).

sister(X, Y) :- father(Z, X), father(Z, Y).

uncle(X, Y) :- male(X), brother(X, Z), father(Z, Y).
uncle(X, Y) :- male(X), brother(X, Z), mother(Z, Y).

aunt(X, Y) :- sister(X, Z), father(Z, Y).
aunt(X, Y) :- sister(X, Z), mother(Z, Y).

cousin(X, Y) :- grandfather(Z, X), grandfather(Z, Y).
cousin(X, Y) :- grandmother(Z, X), grandmother(Z, Y). 