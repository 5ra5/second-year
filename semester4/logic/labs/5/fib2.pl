% fib relation from last lab improved to use cuts

fib(1, 1).
fib(0, 1).

% calculate recursively
fib(X, Y) :-
    X > 1,
    X1 is X - 1,
    X2 is X - 2,
    fib(X1, F1),
    fib(X2, F2),
    Y is F1 + F2, !.