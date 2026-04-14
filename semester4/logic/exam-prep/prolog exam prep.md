## list predicates

**inlist(A,B)** is true if the element A is contained in list B.
```prolog
inlist(A, [A|_]).

inlist(A, [_|BTail]) :-
    inlist(A, BTail).
```

**length(X, L)**: calculate the length of a list
```prolog
length([], 0).

length([_|Tail], Length) :-
    length(Tail, TailLength),
    Length is TailLength + 1.
```

**nodups(X, Y)** is true if the elements of Y are the elements of list X without any duplicate members for example: nodups(`[1, 3, 2, 3, 4, 1, 5]`,` [2, 3, 4, 1, 5]`) is true.
```prolog
nodups([], []).

nodups([Head|Tail], Result) :-
    inlist(Head, Tail),
    nodups(Tail, Result).

nodups([Head|Tail], [Head|ResultTail]) :-
    \+ inlist(Head, Tail),
    nodups(Tail, ResultTail).
    
inlist(A, [A|_]).

inlist(A, [_|BTail]) :-
    inlist(A, BTail).
```

same implementation:
**append(A, B, C)**: append list A to list B to produce list C
**concat(A, B, C)** is true if string C is the concatenation of strings A and B
```prolog
append([], B, B).

append([Head|Tail], B, [Head|ResultTail]) :-
    append(Tail, B, ResultTail).
```

**reverse(A, B)** is true if string B is the reverse of string A.
```prolog
reverse([], []).

reverse([Head|Tail], Reversed) :-
    reverse(Tail, TailReversed),
    concat(TailReversed, [Head], Reversed).
```

**myDelete(X,Y,Z)** is true when the list Z is the result of deleting an occurrence of the element X from the list Y, e.g. myDelete(3, `[1,2,3,4,3,2,1]`, `[1,2,4,3,2,1]`) is true
```prolog
myDelete(Element, [Element|Tail], Tail).

myDelete(Element, [Head|Tail], [Head|ResultTail]) :-
    Element \= Head,
    myDelete(Element, Tail, ResultTail).
```

**sum(L, S)**: sum the elements of a list of integers
```prolog
sumlist([], 0).
sumlist([Head|Tail], Sum) :-
	sumlist(Tail, SumTail),
	Sum is Head + SumTail.
```

**maxlist(L, Max)**: find the maximum of a list of integers
```prolog
max(X, Y, X) :-
	X >= Y.
max(X, Y, Y) :-
	X < Y.

% maximum of a single-element list
maxlist([X], X).

% at least two elements in list
maxlist([X, Y|Tail], Max) :-
	maxlist([Y|Tail], MaxTail),
	max(X, MaxTail, Max). % Max is greater of X and MaxTail
```

**split(N, Positive, Negative)** is true if all the positive numbers (including 0) in the list N are in the list Positive, and all the negative numbers in the list N are in the list Negative.
```prolog
split([], [], []).

split([Head|Tail], [Head|Positive], Negative) :-
    Head >= 0,
    split(Tail, Positive, Negative).

split([Head|Tail], Positive, [Head|Negative]) :-
    Head < 0,
    split(Tail, Positive, Negative).
```

### odd(square) sum

**oddsquaresum(X, S)** is true when S is the sum of the square of all the odd numbers in the list X. Note that the list X can contain any atom, e.g. `[4,oranges,5,2,7,apples,1]`. Hence, `oddsquaresum([4,oranges,5,2,7,apples,1], 75)` is true.
```prolog
oddsquaresum([], 0).

oddsquaresum([Head|Tail], Sum) :-
    oddsquaresum(Tail, TailSum),
    ( number(Head), Head mod 2 =:= 1 ->
        Sum is TailSum + Head * Head
    ;
        Sum = TailSum
    ).
```

**oddsum(X, S)** is true when S is the sum of all the odd integers in the list X. Note that the list X can contain any atom, e.g. `[4,oranges,5,2,7,apples,1]`. Hence, oddsum(`[4,oranges,5,2,7,apples,1]`, 13) is true.
```prolog
oddsum([], 0).

oddsum([Head|Tail], Sum) :-
    oddsum(Tail, TailSum),
    ( number(Head), Head mod 2 =:= 1 ->
        Sum is TailSum + Head
    ;
        Sum = TailSum
    ).
```

### union/intersection

**union(A,B,C)** is true if the list C contains only even numbers in either lists A or B
**intersection(A,B,C)** is true if the list C contains only even numbers in both lists A and B
```prolog
union(A, B, C) :-
    evens(A, EvensA),
    evens(B, EvensB),
    unionset(EvensA, EvensB, C).

evens([], []).

evens([Head|Tail], [Head|EvensTail]) :-
    Head mod 2 =:= 0,
    evens(Tail, EvensTail).

evens([Head|Tail], EvensTail) :-
    Head mod 2 =\= 0,
    evens(Tail, EvensTail).

unionset([], B, B).

unionset([Head|Tail], B, Result) :-
    member(Head, B),
    unionset(Tail, B, Result).

unionset([Head|Tail], B, [Head|ResultTail]) :-
    \+ member(Head, B),
    unionset(Tail, B, ResultTail).


intersection([], _, []).

intersection([Head|Tail], B, [Head|ResultTail]) :-
    Head mod 2 =:= 0,
    member(Head, B),
    \+ member(Head, Tail),
    intersection(Tail, B, ResultTail).

intersection([Head|Tail], B, Result) :-
    ( Head mod 2 =\= 0
    ; \+ member(Head, B)
    ; member(Head, Tail)
    ),
    intersection(Tail, B, Result).
```

**union(A,B,C)** is true if the list C contains only elements in either lists A or B
**intersection(A,B,C)** is true if the list C contains only elements in both lists A and B.
```prolog
union([], B, B).

union([Head|Tail], B, Result) :-
    member(Head, B),
    union(Tail, B, Result).

union([Head|Tail], B, [Head|ResultTail]) :-
    \+ member(Head, B),
    union(Tail, B, ResultTail).
    
intersection([], _, []).

intersection([Head|Tail], B, [Head|ResultTail]) :-
    member(Head, B),
    intersection(Tail, B, ResultTail).

intersection([Head|Tail], B, Result) :-
    \+ member(Head, B),
    intersection(Tail, B, Result).
```
## directions

given: 
nextsouth(X,Y) is true if X is the immediate south point of Y, e.g. nextsouth(m,i).
nexteast(X,Y) is true if X is the immediate east point of Y, e.g. nexteast(g,f)
write: 
**south(X, Y)** is true if X can be reached from Y by only travelling directly south
**east(X,Y)** is true if X can be reached from Y by only travelling directly east.
**southoreast(X,Y)** is true if X can be reached from Y by only travelling directly south or east.
```prolog
south(X, Y) :- nextsouth(X, Y).
south(X, Y) :-
    nextsouth(Z, Y),
    south(X, Z).
    
east(X, Y) :- nexteast(X, Y).
east(X, Y) :-
	nexteast(Z, Y),
	east(X, Z).
	
southoreast(X, Y) :-
    (nextsouth(X, Y) ; nexteast(X, Y)).
southoreast(X, Y) :-
    (nextsouth(Z, Y) ; nexteast(Z, Y)),
    southoreast(X, Z).
```

## family
always given:
parent(X,Y) is true if X is the parent of Y,
male(X) is true if X is male
female(X) is true if X is female

write: 
**uncle(X,Y)** is true if X is an uncle of Y
**greatuncle(X,Y)** is true if X is the uncle of a parent of Y
**ancestor(X,Y)** is true if X is a direct ancestor of Y
```prolog
uncle(X, Y) :-
    male(X),
    parent(Z, Y),
    parent(W, Z),
    parent(W, X),
    X \= Z.
    
greatuncle(X, Y) :-
    parent(Z, Y),
    uncle(X, Z).
    
ancestor(X, Y) :-
    parent(X, Y).

ancestor(X, Y) :-
    parent(X, Z),
    ancestor(Z, Y).
```

write:
**brother(X,Y)** is true if X is the brother of Y
**uncle(X,Y)** is true if X is an uncle of Y
```prolog
brother(X, Y) :-
	parent(Z, X),
	parent(Z, Y),
	male(X),
	X \= Y.
	
uncle(X, Y) :-
	parent(Z, Y),
	brother(X, Z).
```

write:
**sister(X,Y)** is true if X is the sister of Y
**aunt(X,Y)** is true if X is an aunt of Y
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

write:
**grandmother(X,Y)** is true if X is the grandmother of Y,
**aunt(X,Y)** is true if X is an aunt of Y
**ancestor(X,Y)** is true if X is a direct ancestor of Y. 
```prolog
grandmother(X, Y) :-
	parent(X, Z),
	parent(Z, Y),
	female(X).
	
aunt(X, Y) :-
	parent(Z, Y),
	parent(W, Z),
	parent(W, X),
	female(X)
	X \= Z.

ancestor(X, Y) :-
	parent(X, Y).
ancestor(X, Y) :-
	parent(X, Z),
	ancestor(Z, Y).
```
## bus timetable

Let a bus timetable be represented by a list of routes where each route is represented by Start/End/DepatureTime/ArrivalTime. Both DepartureTime and ArrivalTime are represented by a relation time(Hour,Minutes). Write a Prolog relation **journey(Start, End)** that is true if there is a route in the timetable that can get a passenger from Start to End directly or with one intermediate stop where there is at least 10 minutes between the arrival at an intermediate point the departure to the destination of the journey. Assume the clock is a 24 hour clock and all departure and arrival times occur within the same day
```prolog
journey(Start, End) :-
    timetable(Timetable),
    member(Start/End/_DepartureTime/_ArrivalTime, Timetable).

journey(Start, End) :-
    timetable(Timetable),
    member(Start/Intermediate/_Departure1/Arrival1, Timetable),
    member(Intermediate/End/Departure2/_Arrival2, Timetable),
    enough_time(Arrival1, Departure2).

enough_time(time(Hour1, Minute1), time(Hour2, Minute2)) :-
    ArrivalMinutes is Hour1 * 60 + Minute1,
    DepartureMinutes is Hour2 * 60 + Minute2,
    DepartureMinutes - ArrivalMinutes >= 10.
```


Let a bus timetable be represented by a list of routes where each route is represented by Start/End/DepatureTime/ArrivalTime. Both DepartureTime and ArrivalTime are represented by a relation time(Hour,Minutes). Write a Prolog relation **journey(Start, End)** that is true if there is a route in the timetable that can get a passenger from Start to End directly or any number of intermediate stops where there is at least 10 minutes between the arrival at an intermediate point before the departure of the next leg of the journey. Assume the clock is a 24 hour clock and all departure and arrival times occur within the same day.
```prolog
journey(Start, End) :-
    timetable(Timetable),
    member(Start/End/_DepartureTime/_ArrivalTime, Timetable).

journey(Start, End) :-
    timetable(Timetable),
    member(Start/Intermediate/DepartureTime/ArrivalTime, Timetable),
    continue_journey(Intermediate, End, ArrivalTime, Timetable).

continue_journey(Start, End, PreviousArrivalTime, Timetable) :-
    member(Start/End/DepartureTime/_ArrivalTime, Timetable),
    enough_time(PreviousArrivalTime, DepartureTime).

continue_journey(Start, End, PreviousArrivalTime, Timetable) :-
    member(Start/Intermediate/DepartureTime/ArrivalTime, Timetable),
    enough_time(PreviousArrivalTime, DepartureTime),
    continue_journey(Intermediate, End, ArrivalTime, Timetable).
    
enough_time(time(Hour1, Minute1), time(Hour2, Minute2)) :-
    ArrivalMinutes is Hour1 * 60 + Minute1,
    DepartureMinutes is Hour2 * 60 + Minute2,
    DepartureMinutes - ArrivalMinutes >= 10.
```

## road

always given: road(A,B,N)

write:
**routen(X,Y,N)** is true if there exists a route of length N, with zero or more inter- mediate towns, between X and Y.
**toofar(X,Y)** is true if there is a route between X and Y and the total distance is more than 6 km.
**canwalk(X,Y)** is true if there is a route between X and Y and the total distance is less than or equal to 4 km.
```prolog
routen(A,B,N) :- road(A,B,N).
routen(A,B,N) :- road(A,X,N1), routen(X,B,N2), N is N1+N2.

toofar(X, Y) :-
	routen(X,Y,N), N > 6.
	
canwalk(X, Y) :-
	routen(X,Y,N), N =< 4.
```


