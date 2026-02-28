## 2.1 Data objects

variables = start with upper-case letters
atoms = start with lower-case letters
### 2.1.1 Atoms and numbers

atoms can be constructed in three ways:
(1) strings of letters, digits and the underscore character `_`, starting with a lower-case letter
-  anna
-  nil
-  x25
-  x_25
-  x_25AB
-  x_
-  x___y
-  alpha_beta_procedure
-  miss_Jones
-  sarah_jones

(2) strings of special characters
-  <-->
- =====>
-  ...
-  .:.
-  ::=
note: be careful because some special characters already have a predefined meaning (example :-)

(3) strings of characters enclosed in single quotes
useful if we want an atom that starts with a capital letter
-  'Tom'
-  'South_America'
-  'Sarah Jones'

integer numbers: 1, 1313, 0, -97
real numbers (not heavily used): 3.14, -0.0035, 100.2

### 2.1.2 Variables

variables = strings of letters, digits and underscore characters
they start with an upper-case letter or an underscore character
-  X
-  Result
-  `Object2`
-  Participant_list
-  `ShoppingList`
-  `_x23`
-  `_23`

anonymous variable = used when a variable appears only once in a clause, and we don't have to invent a name for a variable

example:

rule: for all X, X has a child if X is a parent of some Y
```prolog
hasachild(X) :- parent(X, Y).
```
-  we can use an anonymous variable here because the `hasachild` property does not depend on the name of the child (Y)

so we rewrite this as 
```prolog
hasachild(X) :- parent(X, _).
```


each time a single underscore character occurs in a clause it represents a new anonymous variable
example:
```prolog
somebody_has_child :- parent(_,_).

% equivalent to 

somebody_has_child :- parent(X, Y).
```

if the anonymous variable appears in a question clause then its value is not output when prolog answers the question

example: we are interested in people who have children, but not in the names of the children
```prolog
?- parent(X, _).
```

**lexical scope of variable names is one clause** = if the name X15 occurs in two clauses, it is two different variables, but each occurrence of X15 within the same clause means the same variable
**the same atom means the same object in any clause - through the whole program**

### 2.1.3 Structures

**structures** = objects that have several components
-  can even be structures or variables themselves
-  treated as single objects

example: date
date = 3 components: day, month, year

**functor** = used to combine the components into a single object

example: date
date is a functor and 1, may and 2001 are arguments
-  all components are constants (2 integers and one atom)
```prolog
% 1 May 2001
date(1, may, 2001)
```

generalised: any day in may
-  Day = variable (can be instantiated to any object at some later point in the execution)
```prolog
date(Day, may, 2001)
```

syntactically, all data objects in prolog are **terms**
example:
`may` and `date(1, may, 2001)` are terms

example: representing geometric objects

`point` = point in 2D space = defined by 2 coordinates
`seg` = line segment = defined by 2 points
`triangle` = triangle = defined by 3 points

```prolog
P1 = point(1, 1).
P2 = point(2, 3).
S = seg(P1, P2) = seg(point(1, 1), point(2, 3))
T = triangle(point(4, 2), point(6, 4), point(7, 1))
```

if we think of structures as trees, the functor is the root of the tree and the arguments are leafs - if some structures hold other structures, then those are subtrees
**principal functor** = functor at the root of the tree

`point(X1, Y1)` and `point(X, Y, Z)` are 2 different functors because they have a different number of arguments

functor is defined by 2 things
(1) the name, whose syntax is that of atoms;
(2) the arity - that is, the number of arguments

exercise:
a. Diana = variable
b. diana = atom
c. 'Diana' = atom
d. `_diana` = variable
e. 'Diana goes south' = atom
f. goes(diana, south) = structure
g. 45 = number
h. 5(X, Y) = syntactically incorrect
i. +(north, west) = structure
j. three(Black(Cats)) = syntactically incorrect

exercise: representing geometric objects
```prolog
rectangle(A, D, C).
square(A, D, C).
circle(A, R)

R1 = rectangle(point(1, 1), point(1, 3), point(2, 3)).
S1 = square(point(4, 1), point(4, 2), point(5, 2)).
C1 = circle(point(6, 3), point(6, 4)).
```

## 2.2 Matching

two terms are matched if:
(1) they are identical
		OR
(2) the variables in both terms can be instantiated to objects in such a way that after the substitution of variables by these objects the terms become identical

example:
`date(D, M, 2001)` and `date(D1, may, Y1)` match

one instantiation that makes both terms identical is:
-  D is instantiated to D1
-  M is instantiated to may
-  Y1 is instantiated to 2001

```prolog
D = D1
M = may
Y1 = 2001
```

example:
`date(D, M, 2001)` and `date(D1, M1, 1444)` do not match
`date(X, Y, Z)` and `point(X, Y, Z)` do not match

**matching** = process that takes as input two terms and checks whether they match

terms do not match = process fails
terms match = process succeeds and instantiates the variables in both terms to such values that the terms become identical

matching two dates in prolog:
```prolog
?- date(D, M, 2001) = date(D1, may, Y1).

D = D1,
M = may,
Y1 = 2001.
```

matching in prolog always results in the most general instantiation
 -  it commits the variables to the least possible extent

during the execution of consecutive goals, variables typically become instantiated to increasingly more specific values
```prolog
?- date(D, M, 2001) = date(D1, may, Y1),	
   date(D, M, 2001) = date(15, M, Y).
	
D = D1, D1 = 15,
M = may,
Y1 = Y, Y = 2001.
```

**general rules to decide whether two terms S and T match:**
(1) if S and T are constants then S and T match only if they are the same object
(2) if S is a variable and T is anything, then they match, and S is instantiated to T. If T is a variable then T is instantiated to S.
(3) If S and T are structures then they match only if
-  S and T have the same principle functor
-  all their corresponding components match
the resulting instantiation is determined by the matching of the components

if we imagine a tree - the matching process starts at the root (the principal functors)

example: geometry (vertical and horizontal lines)
```prolog
vertical(seg(point(X, Y), point(X, Y1))).
horizontal(seg(point(X, Y), point(X1, Y))).
```

questions and answers:
```prolog
% true because the goal in the question matched one of the facts in the program
?- vertical(seg(point(1, 1), point(1, 2))).
true.

% no match possible
?- vertical(seg(point(1, 1), point(2, Y))).
false.

% Y forced to become 1 by matching the fact about horizontal segments
?- horizontal(seg(point(1, 1), point(2, Y))).
Y = 1.
```

are there vertical points that start at the point(2, 3)?
answer: yes, any segment that ends at any point `(2, _)` which means anywhere on the vertical line `x = 2`
```prolog
?- vertical(seg(point(2, 3), P)).
P = point(2, _).
```

is there a segment that is both vertical and horizontal?
answer: yes, any segment that is degenerated to a point has the property of being vertical and horizontal at the same time
```prolog
?- vertical(S), horizontal(S).
S = seg(point(_A, _B), point(_A, _B)).
```

exercise: using the representation for line segments as described in this section, write a term that represents any vertical line segment at `x = 5`
```prolog
seg(point(5, Y1), point(5, Y2)).
```

exercise: rectangle is regular if two of its sides are horizontal and vertical
```prolog
rectangle(P1, P2, P3, P4)
regular(rectangle(point(X1, Y1), point(X2, Y1), point(X2, Y3), point(X1, Y3))).
```

## 2.3 Declarative meaning of Prolog programs

example:
```prolog
P :- Q, R.
```

-  P, Q, R are terms

alternative declarative reading of this clause:
```
P is true if Q and R are true.
From Q and R follows P.
```

alternative procedural readings of this clause are:
```
To solve problem P, first solve the subproblem Q and then the subproblem R.
To satisfy P, first satisfy Q and then R.
```

**instance of a clause C** = clause C with each of its variables substituted by some term
**variant of a clause C** = such an instance of the clause C where each variable is substituted by another variable

example:
```prolog
hasachild(X) :- parent(X, Y).
```

variants
```prolog
hasachild(A) :- parent(A, B).
hasachild(X1) :- parent(X1, X2).
```

instances
```prolog
hasachild(peter) :- parent(peter, Z).
hasachild(barry) :- parent(barry, small(caroline)).
```

**declarative meaning**
A goal G is true (that is, satisfiable, or logically follows from the program) if and only if:
(1) there is a clause C in the program such that
(2) there is a clause instance I of C such that 
-  the head of I is identical to G
-  all the goals in the body of I are true

**disjunction**
any one of the goals in it has to be true
```prolog
P :- Q; R.

% same as
P :- Q.
P :- R.
```
this is read as: P is true if Q is true or R is true

exercise:
two people are relatives if
(a) one is a predecessor of the other
(b) they have a common predecessor
(c) they have a common successor

```prolog
relatives(X, Y) :- predecessor(X, Y); predecessor(Y, X); predecessor(Z, X), predecessor(Z, Y); predecessor(X, Z), predecessor(Y, Z).
```

exercise: rewriting the program without semicolon notation
```prolog
translate(Number, Word) :-
	Number = 1, Word = one;
	Number = 2, Word = two;
	Number = 3, Word = three.
```

```prolog
translate(Number, Word) :- Number = 1, Word = one.
translate(Number, Word) :- Number = 2, Word = two.
translate(Number, Word) :- Number = 3, Word = three.
```

## 2.4 Procedural meaning

procedural meaning = procedure for executing a list of goals with respect to a given program
execute goals = try to satisfy them

example: procedure execute
input: a program and a goal list
output: a success/failure indicator and an instantiation of variables

## 2.5 Example: monkey and banana

1.  monkey is at door
2.  monkey is on floor
3.  box is at window
4.  monkey does not have banana

represent this as a structured object:
1.  horizontal position of monkey
2.  vertical position of monkey
3.  position of box
4.  monkey has or has not banana

```prolog
state(_, _, _, has)
```

allowed moves that change the world from one state to another
1.  grasp banana
2.  climb box
3.  push box
4.  walk around

not all moves are possible in every possible state of the world
-  move grasp banana is only possible if the monkey is standing on the box directly under the banana (in the middle of the room) and does not have the banana yet

we can formalise it like this
```prolog
move(State1, Move, State2)
```

final code solution in github