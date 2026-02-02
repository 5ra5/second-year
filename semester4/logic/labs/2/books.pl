book(illiad, homer, study, 500).
book(c, richie, study, 150).
book(nt_bible, sams, reference, 480).
book(monty_python, cleese, comedy, 300).
book(pride_and_prejudice, austen, drama, 250).
book(kite_runner, hosseini, drama, 371).
book(heated_rivalry, reid, fiction, 372).
book(np_bible, marc, referece, 180).

buildLibrary(Lib) :- findall(book(Title, Author, Genre, Size), book(Title, Author, Genre, Size), Lib).

literary(book(Title, Author, Genre, Size), _) :-
    book(Title, Author, Genre, Size),
    Genre = drama.

holidays(book(Title, Author, Genre, Size), _) :-
    book(Title, Author, Genre, Size),
    Size < 400,
    \+ (Genre = study; Genre = reference).

revision(book(Title, Author, Genre, Size), _) :-
    book(Title, Author, Genre, Size),
    (Genre = study; Genre = reference, Size > 300).

leisure(book(Title, Author, Genre, Size), _) :-
    book(Title, Author, Genre, Size),
    (Genre = comedy; Genre = fiction).