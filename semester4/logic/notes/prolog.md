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
?- consult('test.pl).
```