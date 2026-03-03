myElem(X, [X|_]).
myElem(X, [_|Tail]) :-
    myElem(X, Tail).

myHead(X, [X|_]).

myLast(X, [X]).
myLast(X, [_|Tail]) :-
    myLast(X, Tail).

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
myReverse([X|L1], _) :-
    myReverse(L1, R),
    myAppend(R, [X], _).

evenlength([]).
evenlength([_|Tail]) :-
    oddlength(Tail).

oddlength([_|Tail]) :-
    evenlength(Tail).

palindrome(L) :-
    myReverse(L, _),
    !.

shift([], []).
shift([Head|Tail], L2) :-
    myAppend(Tail, [Head], L2).

means(1, one).
means(2, two).
means(3, three).
means(4, four).
means(5, five). 

translate([], []).
translate([Head|Tail], [Head1|Tail1]) :-
    means(Head, Head1),
    translate(Tail, Tail1).

flatten([], []).
flatten(List, FlatList) :-
    myAppend([_|Tail], List, FlatList),
    flatten(Tail, FlatList).