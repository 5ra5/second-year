https://github.com/kyrilkhaletsky/CA208-Logic/tree/master/Prolog
https://github.com/VincentAchukwu/CollegeWork/tree/master/Year2/CA208_Prolog
## overview

-  declarative programming language that is suited to symbolic, non-numeric computations
-  consists of: clauses, facts, rules and procedures
-  it describes a program in terms of the properties of the solution
-  result is always either True of False

## facts

facts define relations between symbols and then submit one or more queries to the prolog run-time system to determine which values of the query variables are defined relations true
 facts can be written as relations
```prolog
parent(tom, bob).
```

-  a relation called parent
-  two arguments tom and bob
-  tom and bob are symbols or atoms - they begin with a lower case letter (a-z)
-  a fact must end in a full stop

**querying previous program**
```prolog
?- parent(tom, bob).
```
output: true.

```prolog
?- parent(ann, jim).
```
output: false.

**using a variable instead of a symbol**
-  variables need to start with an uppercase letter
```prolog
?- parent(X, liz).
X = tom.
```

**multiple answers**
```prolog
?- parent(bob, C)
C = ann
```

-  by typing ; we can get the next possible solution
```prolog
?- parent(bob, C).
C = ann ;
C = mary.
```

-  if there is a lot of answers, we can press the return key to terminate
-  if the answer has a full stop at the end it's the last answer, otherwise it's not

we can also ask
```prolog
?- parent(X, Y).
```

**more complicated queries**
who are Jim's grandparents
```prolog
?- parent(Y, jim), parent(X, Y).
```

who are tom's grandchildren
```prolog
?- parent(tom, X), parent(X, Y).
```

**, means AND**
**; means OR**

## rules

-  a fact is something that is unconditionally true, a rule is true only if some condition is true based on other rules or facts
 
 defining a rule
 ```prolog
 child(X, Y) :- parent (Y, X)
 ```

"for all X an Y, if X is the parent of Y then X has a child"
```prolog
hasChild(X) :- parent(X, Y)
```

-  it is helpful to draw a diagram to keep track of all conditions and relations

-  rules can be **recursive**
-  they have 2 components: a base case and recursive case
-  a base case always goes first

```prolog
predecessor(X, Y) :- parent(X, Y)
predecessor(X, Y) :- parent(X, Z), predecessor(Z, Y)
```

## loading a file

first way - use double quotes
```
?- ["test.pl"].
```

second way - use single quotes
```
?- consult('test.pl').
```

## data objects in prolog

**atoms** = it's a value that's composed of strings of letters, digits, underscore characters, starting with a lower-case character
-  it is also composed of special characters, but you can't use some sequences like `:-` because it's already reserved by prolog
-  it is composed of strings enclosed in single quotes

**numbers** = can be integers or floating-point numbers

**a variable** = a string of letters, digits or underscore characters that start with either upper-case character or an underscore
**anonymous variable** = `_` we use it when a variable is used only once in the script, so it can be replaced
**scope of a variable** = clause in which it is mentioned, therefore the variable student in two different clauses are not the same variable

**structures** = objects that have several components that are made of other structures or variables
-  composed of a functor that names the structure and
-  a set of components

the principle functor here is triangle
```prolog
triangle(point(1,2, 3), point(6, 3, 7), (point(4, 5, 8)))
```

-  a point with 2 arguments is different than a point with 3 arguments
- **arity** = the number of components/arguments
- **name** = atom

**principle functor** = the first functor

## declarative meaning

**instantiation** = goals separated by a comma `Q :- R, S, T `
**disjunction** = goals separated by a semicolon `Q :- R;S`

when expressing disjunction, it is better to use new lines instead of semicolons for a better readability
```
Q :- R;S

equivalent to

Q :- R.
Q :- S.
```

## procedural meaning

```
big(bear)
big(elephant)
small(cat)

brow(bear)
black(cat)
grey(elephant)

dark X is true if black X is true
dark X is true if brown X is true

dark(X) :- black(X)
dark(X) :- brown(X)
```

if we run the query `dark(X), big(X)`:
-  prolog searches from top to bottom of the code for a clause whose head matches the first goal in the goal list
-  if there is no such clause, return failure
-  otherwise rename the variables
-  it will keep doing this recursively until the goal list is empty, when it returns success

# lists

-  a recursive data structure
-  the list is the only structure that is built into prolog, unlike trees, graphs etc.
-  it is a sequence of any number of prolog atoms
```prolog
[tom, football, golf, harry, poker]
```

a linked list has 2 forms:
-  it is either empty, `[]`, or
-  it consists of a **head** (first term) and a **tail** (rest of the list)

the head and tail are combined by a special functor
```prolog
.(Head, Tail)
```

this is how prolog internally stores the list from above
```prolog
.(tom, .(football, .(golf .(poker, []))))
```

-  what you get for free in prolog are inverse functions and predicates
 `true` = prolog can find an answer
 `false` = prolog can't find an answer

## adding and deleting an element

adding an element
```prolog
add(X, L, [X|L]).
```

```prolog
add(5, [1, 2], [5, 1, 2]).
-> true
```

```prolog
add(5, [1, 2], [1, 2, 5]).
-> false
```

deleting an element has 2 cases:
-  the item to be deleted is the head of the list
-  the item to be deleted is the tail

```prolog
delete(X, [X|L], L).
```

```prolog
delete(X, [Y|Tail], [Y|Tail1]) :-
	delete(X, Tail, Tail1).
```

**delete is non-deterministic** = there is more than one possible answer

```prolog
insert(X, List, BiggerList) :-
	delete(X, BiggerList, List).
```

## sublist

S is a sublist of L if:
-  L can be split into two lists L1 and L2
-  L2 can be split into two lists S and L3.

```prolog
sublist(S, L) :-
	conc(L1, L2, L),
	conc(S, L3, L2).
```

-  it is helpful to draw diagrams

## permutations

a permutation of a list is a reordering of the elements in the list

-  a relation is true if the second list is a reordering of the firs list and is defined by considering two cases of the first list
-  base case = if the first list is empty, then the second list must also be empty
-  recursive case: the first list has the form `[X|L]` then permute L to form a new list L1 and then insert X into L1.

```prolog
permutation([], []).

permutation([X|L], P) :-
	permutation(L, L1),
	insert(X, L1, P).
```


what list that permutated gives you list a, b, c
the problem here is that insert uses delete and delete is non-deterministic so that means that there is multiple possible answers
sometimes when you call a non-deterministic predicate, prolog gets lost in the process of trying to find an answer so it will take a long time- this is true for a large list
```
(L, [a, b, c])
```

## operator notation

-  *infix*, a+b
-  *prefix*, +(a, b)
-  *postfix*, a b +

`a b c * + = a + (b * c)'
`a b + c * = (a + b) * c`

prolog internally uses *prefix* notation, but we can make our own operators

prolog has special clauses called *directives*. the **op** directive has the following syntax

```prolog
:-op(precedence, type, name).
```

the operator's name is an atom and becomes the **functor** of the operator
the precedence of the operator is usually between 0 and 1200 (we use the one that goes up to 800)

types of operators:
-  infix xfx, xfy, yfx
-  prefix fx, fy
-  postfix xf, yf

f = operator
x = argument whose precedence must be less than the precedence of the operator
y = argument whose precedence is less than or equal to the precedence of the operator
yfx = left-to-right evaluation

example:
`a - b - c = (a - b) - c` NOT `a - (b - c)`

we define minus as:
```prolog
:- op(500, yfx, -).
```

very important laws: **DeMorgan's laws**

not(A & B) = not A & not B
not(A|B) = not A | not B

in prolog:
```prolog
equivalence(not(and(A, B)), or(not(A), not(B))).

:− op ( 8 0 0 , x f x , <===>).
:− op ( 7 0 0 , x f y , v ).
:− op ( 6 0 0 , x f y , &).
:− op ( 5 0 0 , f y , ˜ ) 
```

## arithmetic

prolog is a symbolic language so if you query this
```prolog
?- X = 1 + 2.
```

X will be 1 + 2, not 3
-  prolog will not evaluate terms unless you force it to

to force
```prolog
?- X is 1 + 2.
X = 3
```

predefined arithmetic operators:
`+` addition
`*` multiplication
`**` power
`mod` remained after integer division
`-` subtraction
`/` division
`//` integer division

```prolog
length1([], 0).

length1([_|Tail], N) :-
	length1(Tail, N1),
	N is N1 + 1.
	
?- length1([a, b, c, d], N).
N = 4.
```

```
length1([a, b, c, d], N)
length1([a]|[b, c, d], N)
	length1([b, c, d], N1)
	length1([c, d], N2)
	length1([d], N3)
	length1([], N4)
```

```
N4 = 0
N3 = N4 + 1 = 1
N2 = N3 + 1 = 2
N1 = N2 + 1 = 3
N = N1 + 1 = 4
```

`length2` one doesn't use **is**, doesn't enforce evaluation
```
length2([], 0).

length2([_|Tail], N) :-
	length2(Tail, N1),
	N = N1 + 1.
	
?- length2([a, b, c, d], N).
N = 0+1+1+1+1
```

### comparison operators

`X = Y` match
`X == Y` structured equivalence
`X =:= Y` arithmetic equality (enforces evaluation for us - evaluates X, evaluates Y, and then checks if they are equal)

examples:
1.  `1 + 2 = 2 + 1` this would be false

2.  `1 + 2 == 2 + 1` this would be false 

3.  internal version of 2. `+(1, 2) == +(2, 1)` this would be false

4.  `1 + 2 =:= 2 + 1` this would be true

## structures

### binary trees

2 cases:
-  an empty tree
-  subtree that has its own root, X, and a left subtree, L, and a right subtree, R.

we represent these by an atom `nil` and a functor `bt`

make sure there is no space between `bt` and brackets or else Prolog complains
```prolog
bt(L, X, R).
```

**to test if X is in a binary tree:**
we pass a value and a binary tree
```prolog

is X the root of the tree?
in(X, bt(_, X, _)).

if X is less or equal to the root of the tree, search the left subtree of X
in(X, bt(L, Y, _) :-
	X =< Y, in(X, L).
	
search the right subtree
in(X,  bt(_, _, R)) :-
	in(X, R).
```

a search of an empty tree will fail