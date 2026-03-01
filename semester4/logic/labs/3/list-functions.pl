% true if X is an element of a list
myElem(X, [X|_]).
myElem(X, [_|Tail]) :-
    myElem(X, Tail).

% true if X is a head of a list
myHead(X, [X|_]).

% true if X is the last element of a list
myLast(X, [X]).
myLast(X, [_|Tail]) :-
    myLast(X, Tail).

% true if X is the tail of a list
myTail(X, [_|X]).

% true if list C is list B appended to list A
myAppend([], B, B).
myAppend([A|ATail], B, [A|C]) :-
    myAppend(ATail, B, C).

% true if list A is the reverse of list B
myReverse([], []).
myReverse([X|A], R) :- myReverse(A, R1), myAppend(R1, [X], R).

% true if list B is list A with the first occurrence of X removed
myDelete(X, [X|Tail], Tail).
myDelete(X, [Head|A], [Head|B]) :- myDelete(X, A, B).