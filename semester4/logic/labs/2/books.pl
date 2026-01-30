book(illiad, homer, leisure, 500).
book(c, richie, study, 150).
book(nt_bible, sams, reference, 480).
book(monty_python, cleese, comedy, 300).

buildLibrary(Lib) :- findall(book(Title, Author, Genre, Size), book(Title, Author,
Genre, Size), Lib).

holiday(L, book(T, A, G, _)) :- L = holiday(Tail, book(T, A, G, S)).