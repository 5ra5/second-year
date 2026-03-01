## 3.1 Representation of lists

**list** = a sequence of any number of items

external appearance of lists (they are actually structured as binary trees in prolog)
```prolog
[ann, tennis, tom, skiing]
```

2 cases: a list is either empty or non-empty
empty = written as a prolog atom `[]`
non-empty = consists of two things
1.  head of the list (the first item)
2.  tail of the list (remaining part)

`ann` = head
`[tennis, tom, skiing]` = tail

-  head can be anything (any prolog object e.g. tree or a variable)
-  tail has to be a list

head and tail are combined into a structure by a special functor
```prolog
.(Head, Tail)
```

`Tail` is a list, so it's either empty or it has its own head and tail
```prolog
.ann(,.(tennis,.(tom,.(skiing,[]))))
```

example:
```prolog
?- List1 = [a, b, c].
List1 = [a, b, c].

?- List2 = [a | [b | [c | []]]].
List2 = [a, b, c].
```

example:
```prolog
?- Hobbies1 = [tennis | [music | []]],     
   Hobbies2 = [skiing, food],
   L = [ann, Hobbies1, tom, Hobbies2].

Hobbies1 = [tennis, music],
Hobbies2 = [skiing, food],
L = [ann, [tennis, music], tom, [skiing, food]].
```

example: vertical bar notation to separate tail and head
```prolog
?- L = [a, b, c],
   L = [a | Tail].

L = [a, b, c],
Tail = [b, c].
```

the alternative way to write this list
```prolog
[a, b, c] = [a|[b, c]] = [a, b | [c]] = [a, b, c | []]
```

## 3.2 Some operations on lists

we can use lists to represent sets
-  order matters in lists, it does not matter in sets
-  duplicates allowed in lists, not allowed in sets

most common operations on lists:
-  checking if an object is an element of the list
-  concatenation of two lists
-  adding and deleting objects

### 3.2.1 Membership

```prolog
member(X, L)
```

X = object
L = list
goal = true if X occurs in L

example: true
```prolog
member(b, [a, b, c])
```

example: not true
```prolog
member(b, [a, [b, c]])
```

example: true
```prolog
member([b, c], [a, [b, c]])
```

program for the membership relation:
X is a member of L if either:
1.  X is the head of L
2.  X is a member of the tail of L

```prolog
myElem(X, [X|_]).
myElem(X, [_|Tail]) :-
	myElem(X, Tail).
```

### 3.2.2 Concatenation

L1 and L2 are lists
L3 is their concatenation
```prolog
conc(L1, L2, L3)
```

example: true
```prolog
conc([a, b], [c, d], [a, b, c, d])
```

example: false
```prolog
conc([a, b], [c, d], [a, b, a, c, d])
```

definition of `conc`:
1.  if the first argument is the empty list then the second and the third arguments must be the same list (call it L)
```prolog
conc([], L, L)
```

2.  if the first argument of `conc` is a non-empty list then it has a head and a tail and must look like this
```prolog
[X|L1]
```

example: concatenate L1 and L2 into L3
```prolog
conc([X|L1], L2, [X|L3]) :-
	conc(L1, L2, L3).
```

concatenate:
```prolog
?- conc([a,b,c],[1,2,3],L).

L = [a, b, c, 1, 2, 3].
```

decompose a list:
```prolog
?- conc(L1, L2, [a,b,c]).

L1 = [],
L2 = [a, b, c] ;
L1 = [a],
L2 = [b, c] ;
L1 = [a, b],
L2 = [c] ;
L1 = [a, b, c],
L2 = [] ;
false.
```

example: splitting the list in 2: before and after may
```prolog
5 ?- conc(Before, [may|After],
  [jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec]).
  
Before = [jan, feb, mar, apr],
After = [jun, jul, aug, sep, oct, nov, dec] ;
```

example: find immediate predecessor and successor of may
```prolog
?- conc(_,[Month1,may,Month2|_],
   [jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec]).
   
Month1 = apr,
Month2 = jun ;
```

example: delete from some list L1, everything that follows three successive occurrences of z in L1 together with three z's
```prolog
?- L1 = [a,b,z,z,c,z,z,z,d,e],
   conc(L2,[z,z,z|_],L1).
   
L1 = [a, b, z, z, c, z, z, z, d|...],
L2 = [a, b, z, z, c] ;
false.
```

example: member using conc
X is a member of list L if L can be decomposed into two lists so that the second one has X as its head
```prolog
member1(X, L) :-
	conc(L1, [X|L2], L).
```

using anonymous variables:
```prolog
member1(X, L) :-
	conc(_, [X|_], L).
```

exercise: delete the last three elements of L and return L1
```prolog
L = [a,b,z,z,c,z,z,z,d,e],
    conc(L1,[_,_,_], L).
    
L = [a, b, z, z, c, z, z, z, d|...],
L1 = [a, b, z, z, c, z, z] ;
```

exercise: delete the first and last three elements of L and return L2
Find lists L2 and `[_,_,_]` such that `[_,_,_|L2]` concatenated with `[_,_,_]` equals L
```prolog
?- L = [a,b,z,z,c,z,z,z,d,e],
   conc([_,_,_|L2],[_,_,_],L).
   
L = [a, b, z, z, c, z, z, z, d|...],
L2 = [z, c, z, z] ;
```

### 3.2.3 Adding an item

put the new item in front of the list so that it becomes the new head
X = new item
L = list
`[X|L]` = resulting list

no explicit procedure, can be expressed as a fact
```prolog
add(X, L, [X|L]).
```

appending:
```prolog
% true if list C is list B appended to list A
myAppend([], B, B).
myAppend([A|ATail], B, [A|C]) :- myAppend(ATail, B, C).

% explanation
myAppend([original list head | original list tail], list to append, [original list head | final list]) :- myAppend(original list tail, list to append, new list).
```

### 3.2.4 Deleting an item

item X, list L
L1  = L after X is removed
```prolog
del(X, L, L1)
```

two cases:
1.  if x is the head of the list then the result after the deletion is the tail of the list
2.  if x is in the tail then it is deleted from there

example: delete a
we get 3 cases
```prolog
?- del(a, [a,b,a,a],L).

L = [b, a, a] ;
L = [a, b, a] ;
L = [a, b, a] ;
```

example: add an item using `del`
we get 4 cases
```prolog
del(a, L, [1,2,3]).

L = [a, 1, 2, 3] ;
L = [1, a, 2, 3] ;
L = [1, 2, a, 3] ;
L = [1, 2, 3, a] ;
```

example: member using `del`
```prolog
member2(X, List) :-
	del(X, List, _).
```

### 3.2.5 Sublist

list L, sublist S which appears in L

example: true
```prolog
sublist([c,d,e],[a,b,c,d,e,f])
```

example: false
```prolog
sublist([c,e],[a,b,c,d,e,f])
```

formula:
1.  L can be decomposed into two lists, L1 and L2
2.  L2 can be decomposed into two lists, S and some L3

```prolog
% sublist
sublist(S, L) :-
	append(_, L2, L), % L2 is some suffix of L
	append(S, _, L2). % S is some prefix of L2
```

example: find all sublists of a list
```prolog
?- sublist(S, [a,b,c]).

S = [] ;
S = [a] ;
S = [a, b] ;
S = [a, b, c] ;
S = [] ;
S = [b] ;
S = [b, c] ;
S = [] ;
S = [c] ;
S = [] ;
false.
```

### 3.2.6 Permutations

`permutation` relation:
-  2 arguments
-  arguments are lists
-  one is a permutations of the other
generate permutations of a list through backtracking using the permutation procedure

two cases:
1.  if the first list is empty then the second list must also be empty
2.  if the first list is not empty then it has the form `[X|L]`, first permute L obtaining L1 and then insert X at any position into L1

alternative way:
-  delete an element X from the first list
-  permute the rest of it obtaining a list P
-  add X in front of P
```prolog
permutation2([], []).
	permutation2(L, [X|P]) :-
	del(X, L, L1),
	permutation2(L1, P).
```

example:
```prolog
?- permutation([red,blue,green],P).

P = [red, blue, green] ;
P = [blue, red, green] ;
P = [blue, green, red] ;
P = [red, green, blue] ;
P = [green, red, blue] ;
P = [green, blue, red] ;
false.
```