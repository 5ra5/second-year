% membership
% X is the head of L
member(X, [X | Tail]).

% X is a member of the tail of L
member(X, [Head|Tail]) :-
    member(X, Tail).

% concatenate two lists
conc([], L, L).
conc([X|L1], L2, [X|L3]) :-
	conc(L1, L2, L3).

% member using conc
member1(X, L) :-
    conc(_, [X|_], L).

% last element of a list
last(Item,[Item]).
last(Item, [First|Rest]) :-
    last(Item, Rest)

% last element using conc
last(Item, List) :-
    conc(_, [Item], List).

% delete head of the list
del(X, [X|Tail], Tail).

% delete from tail
del(X, [Y|Tail], [Y|Tail1]) :- 
    del(X, Tail, Tail1).

% insert X at any place in some list
insert(X, List, BiggerList) :-
    del(X, BiggerList, List).

% member using del
member2(X, List) :-
    del(X, List, _).

% sublist
sublist(S, L) :-
    append(_, L2, L), % L2 is some suffix of L
    append(S, _, L2). % S is some prefix of L2

% permutations
permutation([], []).
permutation([X|L], P) :-
    permutation(L, L1),
    insert(X, L1, P).

% alternative permutations
permutation2([], []).
permutation2(L, [X|P]) :-
    del(X, L, L1),
    permutation2(L1, P).

% true if length is even
evenlength([]).
evenlength([First|Rest]) :-
    oddlength(Rest).

% true if length is odd
oddlength([First|Rest]) :-
    evenlength(Rest).

% reverse a list
reverse([], []).
reverse([First|Rest], Reversed) :-
    reverse(Rest, ReversedRest),
    conc(ReversedRest, [First], Reversed).

% palindrome using reverse
palindrome(List) :-
    reverse(List, List).

% palindrome without using reverse
palindrome1([]).
palindrome1([_]).
palindrome1(List) :-
    conc([First|Middle], [First], List),
    palindrome1(Middle).