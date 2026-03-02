book(illiad, homer, study, 500).
book(c, richie, study, 150).
book(nt_bible, sams, reference, 480).
book(monty_python, cleese, comedy, 300).
book(pride_and_prejudice, austen, drama, 250).
book(kite_runner, hosseini, drama, 371).
book(heated_rivalry, reid, fiction, 372).
book(np_bible, marc, referece, 180).

buildLibrary(Lib) :- findall(book(Title, Author, Genre, Size), book(Title, Author, Genre, Size), Lib).

holiday(_, []).
holiday(book(T, A, _, _), [book(Title, Author, Genre, Size)|_]) :-
    T = Title,
    A = Author,
    Size < 400,
    Genre \= study,
    Genre \= reference.

holiday(B, [book(_,_,_,_)|Tail]) :-
    holiday(B, Tail).

revision(_, []).
revision(book(T, A, _, _), [book(Title, Author, Genre, Size)|_]) :-
    T = Title,
    A = Author,
    Size > 300,
    (Genre = reference; Genre = study).

revision(B, [book(_,_,_,_)|Tail]) :-
    revision(B, Tail).

literary(_, []).
literary(book(T, A, _, _), [book(Title, Author, Genre, _)|_]) :-
    T = Title,
    A = Author,
    Genre = drama.

literary(B, [book(_,_,_,_)|Tail]) :-
    literary(B, Tail).

leisure(_, []).
leisure(book(T, A, _, _), [book(Title, Author, Genre, _)|_]) :-
    T = Title,
    A = Author,
    (Genre = comedy; Genre = fiction).

leisure(B, [book(_,_,_,_)|Tail]) :-
    leisure(B, Tail).

