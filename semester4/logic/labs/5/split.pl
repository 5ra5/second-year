% splitting numbers
% split(Numbers, Positive, Negative)

split([], [], []).
split([X|XTail], [X|PTail], N) :-
    X >= 0,
    !,
    split(XTail, PTail, N).

split([X|XTail], P, [X|NTail]) :-
    X < 0,
    !,
    split(XTail, P, NTail).