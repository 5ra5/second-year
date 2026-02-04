hobbies1 :- [football, golf, poker].

myElem(X, A) :-
    myElem(X, [H|T]),
    X \= H,
    !,
    myElem(X, T).