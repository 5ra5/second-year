between(N1, N2, N1) :-
    N1 =< N2.

between(N1, N2, X) :-
    N1 < N2,
    NewN1 is N1 + 1,
    between(NewN1, N2, X).