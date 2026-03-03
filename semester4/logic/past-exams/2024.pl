road(northbog, westhome, 3).
road(oldtown, westhome, 4).
road(oldtown, poshville, 5).
road(villanua, oldtown, 2).
road(eastwick, poshville, 2).
road(poshville, northbog, 3).
road(westpark, villanua, 2).
road(westpark, southfork, 7).
road(southfork, eastwick, 2).

% Q1
between(X, Y, Z) :-
    road(X, Y, _),
    road(Y, Z, _).

closeTo(X, Y) :-
    road(X, Y, D),
    D =< 3.

% Q2
route(A, B) :- road(A, B, _).
route(A, B) :-
    road(A, C, _),
    route(C, B).

% Q3
sum(0, []).
sum(X, [Head|Tail]) :-
    sum(XS, Tail),
    X is XS + Head.

max(X, Y, X) :-
    X > Y.

max(X, Y, Y) :-
    Y > X.

maximum(0, []).
maximum(X, [Head1, Head2|Tail]) :-
    maximum(XS, [Head2|Tail]),
    max(Head1, XS, Tail).