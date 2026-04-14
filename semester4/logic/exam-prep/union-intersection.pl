evens([], []).

evens([Head|Tail], [Head|EvensTail]) :-
    Head mod 2 =:= 0,
    evens(Tail, EvensTail).

evens([Head|Tail], EvensTail) :-
    Head mod 2 =\= 0,
    evens(Tail, EvensTail).
    
union(A, B, C) :-
    evens(A, EvensA),
    evens(B, EvensB),
    append(EvensA, EvensB, C).

intersection([], _, []).

intersection([Head|InputTail], B, [Head|OutputTail]) :-
    Head mod 2 =:= 0,
    member(Head, B),
    intersection(InputTail, B, OutputTail).

intersection([Head|InputTail], B, Output) :-
    ( Head mod 2 =\= 0
    ; \+ member(Head, B)
    ),
    intersection(InputTail, B, Output).