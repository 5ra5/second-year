% classifying numbers
class(0, zero) :-
    !.
    
class(X, negative) :-
    X < 0,
    !.

class(X, positive) :-
    X > 0,
    !.
