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