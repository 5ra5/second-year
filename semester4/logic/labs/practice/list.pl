myElem(X, [X|_]).
myElem(X, [_|Tail]) :-
    myElem(X, Tail).

myHead(X, [X|_]).

myLast(X, [X]).
myLast(X, [_|Tail]) :-
    myLast(X, Tail).

conc([], L, L).
conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).

myTail(X, [_|X]).

myAppend([], L, L).
myAppend([X|Tail], L, [X|L1]) :-
    myAppend(Tail, L, L1).

% removing anything from an empty list gives an empty list
% myDelete(_, [_], []).

myDelete(X, [X|L1], L1).
myDelete(X, [Y|Tail], [Y|Tail1]) :-
    delete(X, Tail, Tail1).

myReverse([], []).
myReverse([X|L1], L2) :-
    myReverse(L1, R),
    myAppend(R, [X], Y).