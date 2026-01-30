## part 1

```prolog
book('c reference', 'thompson', reference, 250).
book('life of brian', 'gillan', comedy, 290).
```

use `findall()`
how it works - it takes 3 arguments
```prolog
findall(SearchTemplate, GeneratedTemplate, List)
```

a book has a title T, author A, genre G, size S
```
book(T, A, G, S)
```

so, we can give up one of the arguments since our book has 4
```prolog
SearchTemplate = book(T, A, G, S)
GeneratedTemplate = book(T, A, G, S)
GeneratedTemplate = book (T, A, G)
```


```prolog
litery(L, book(T, A, G, _)) :- L = ([book(T; A; G; _) | Tail]),
								G = drama.
```

```prolog
litery(L, book(T, A, G, _)) :- L = litery(Tail, book(T, A, G, S)).
```

this would build a library and query it
```prolog
?- findall(book(T, A, G, S), book(T, A, G, S), L), litery(L, B).
```

### holiday

book should be less than 400 pages and not be a study or reference book
```
size < 400 & not(study|reference)
```

how would we negate this? - we use a vertical bar over `(study|reference)`

```
NOT(A|B) is NOT A & NOT B
```