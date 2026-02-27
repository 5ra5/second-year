## 1.1 Defining relations by facts

programming language for symbolic, non-numeric computation
well suited for solving problems that involve objects and relations between objects

fact: **tom is a parent of bob**
```prolog
parent(tom, bob).
```

`parent` = name of the relation
`tom`, `bob` = arguments of a relation

```prolog
parent(pam, bob).
parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(pat, jim).
```
-  this program consists of *six clauses*
-  each clause terminates with a full stop
-  each clause declares one fact about the `parent` relation
-  such an instance also called a *relationship*

**relation** = a set of all its instances
**atoms** = concrete objects or constants (e.g. `tom` and `ann`)
**is bob a parent of pat?**
```prolog
?- parent(bob, pat).

true.
```

**is liz a parent of pat?**
```prolog
?- parent(liz, pat).

false.
```
-  because program does not mention anything about liz being a parent of pat

**is tom a parent of ben?**
```prolog
?- parent(tom, ben)

false.
```
-  because the program hasn't heard of the name ben

**variables** = the arguments of relations that are general objects such as X and Y
**who is Liz's parent?**
```prolog
?- parent(X, liz).

X = tom.
```

**who are bob's children?**
```prolog
?- parent(bob, X).

X = ann;
X = pat.
```
-  prolog provides only one answer, and you get the second one by typing the semicolon

who is a parent of whom?
find X and Y such that X is a parent of Y
```prolog
?- parent(X, Y).

X = pam,
Y = bob ;
X = tom,
Y = bob ;
X = tom,
Y = liz ;
X = bob,
Y = ann ;
X = bob,
Y = pat ;
X = pat,
Y = jim.
```
-  prolog finds all the parent-child pairs one after another
-  solutions displayed one at a time

questions can consist of one or more *goals*
positive answer = goal is satisfiable and it succeeded
negative answer = goal was unsatisfiable and it failed
if several answers satisfy the question then prolog finds as many of them as desired by the user

**who is the grandparent of jim?**
-  **who is a parent of jim? = Y**
-  **who is a parent of Y? = X**
```prolog
?- parent(Y, jim), parent(X, Y).

Y = pat,
X = bob.
```

this can be read as:
find such X and Y that satisfy the following two requirements
```prolog
parent(Y, jim) and parent(X, Y)
```

if we change the order of the two requirements the logical reasoning remains the same:
```prolog
parent(X, Y) and parent(Y, jim)
```

**who are tom's grandchildren?**
```prolog
?- parent(tom, X), parent(X, Y).

X = bob,
Y = ann ;
X = bob,
Y = pat ;
false.
```

**do ann and pat have a common parent?**
-  **who is a parent, X, of ann?**
-  **is (this same) X a parent of pat?**
```prolog
?- parent(X, ann), parent(X, pat).

X = bob
```

## 1.2 Defining relations by rules

unary relations - one place
used to declare simple yes/no properties of objects
```prolog
female(pam);
male(bob);
male(tom);
female(liz);
female(ann);
female(pat);
male(jim);
```

binary relation = relation between pairs of objects (e.g. parent)

```
sex(pam, feminine).
sex(tom, masculine).
sex(bob, masculine).
```

**declaring an offspring as an inverse of parent**

liz is an offspring of tom - declaring by facts
```prolog
offspring(liz, tom)
```

we can declare this based on this logical statement:
```
For all X and Y
	Y is an offspring of X if
		X is a parent of Y.
		
				OR
				
For all X and Y,
	if X is a parent of Y then
	Y is an offspring of X.
```

```prolog
offspring(Y, X) :- parent(X, Y)
```
-  an example of a rule

**rules** = specify things that are true if some condition is satisfied
they have:
-  body = a condition part (the right-hand side of the rule)
-  head = a conclusion part (the left-hand side of the rule)

rules are general because they are applicable to any X and Y

mother rule:
```prolog
mother(X, Y) :- parent(X, Y), female(X).
```
-  a comma between two conditions indicated the conjunction of the conditions, meaning that both conditions have to be true

grandparent rule:
```prolog
grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
```

sister rule:
For any X and Y,
	X is a sister of Y if
	(1) both X and Y have the same parent, and
	(2) X is a female.

```prolog
sister(X, Y) :-
	parent(Z, X),
	parent(Z, Y),
	female(X).
```
-  some Z must be a parent of X and this same Z must be a parent of Y

problem: if we ask "who is the sister of pat", we will get pat herself as the answer along with her sister
solution: add a rule that states that X and Y must be different
```prolog
different(X, Y).
```

-  Facts are clauses that have a head and the empty body. Questions only have the body. Rules have the head and the (non-empty) body.

## 1.3 Recursive rules

predecessor rule:

-  direct predecessor
```
for all X and Z,
	X is a predecessor of Z if
	X is a parent of Z.
	
predecessor(X, Z) :-
	parent(X, Z).
```

-  indirect predecessor
```
predecessor(X, Z) :-
	predecessor(X, Y),
	parent(Y, Z).
```

combined
```
For all X and Z,
	X is a predecessor of Z if
	there is a Y such that
	(1) X is a parent of Y and
	(2) Y is a predecessor of Z.

% rule pr1
predecessor(X, Z) :-
	parent(X, Z).
	
% rule pr2
predecessor(X, Z) :-
	parent(X, Y),
	predecessor(Y, Z).
```

-  the predecessor relation is defined by two clauses
-  we say that these two clauses are about the predecessor relation
**procedure** = set of clauses about the same relation

how to comment in prolog:
```
/*This is a comment*/
% This is also a comment
```

## 1.4 How Prolog answers questions

a question to prolog is always a sequence of one or more goals
to answer a question, prolog tries to satisfy all the goals
satisfy a goal = demonstrate that the goal is true, assuming that the relations in the program are true
-  demonstrate that the goal locally follows from the facts and rules in the program

if the question contains variables, prolog has to find what are the particular objects (in place of variables) for which the goals are satisfied
-  if it does not find them, the answer will be false

example:
All men are fallible.
Socrates is a man.

it is logical to say that Socrates is fallible.
can be rewritten as for all X, if X is a man then X is fallible

```prolog
fallible(X) :- man(X). % All men are fallible
man(socrates)          % Socrates is a man
?- fallible(socrates). % Socrates is fallible?
yes
```

more complicated example: proof sequence
```prolog
?- predecessor(tom, pat).
```

`parent(bob, pat)` is a fact
-  using this fact and rule `pr1` we can conclude that `predecessor(bob, pat)`

**derived fact** = cannot be found explicitly in our program, but it can be derived from facts and rules in the program

inference step such as this can be written in a more compact form
```
parent(bob, pat) => predecessor(bob, pat)
```
-  read as: from `parent(bob, pat)` it follows that `predecessor(bob, pat)` by rule `pr1`

`parent(tom, bob)` is a fact
-  using this fact and the derived fact `predecessor(bob, pat)` we conclude `predecessor(tom, pat)` by rule `pr2`

```
parent(bob, pat) => predecessor(bob, pat)
parent(tom, bob) and predecessor(bob, pat) => predecessor(tom, pat)
```

**how does prolog conclude all of this?**

-  uses inverse order of the above example
-  starts with the goals and, using rules, substitutes the current goals with new goals, until new goals happen to be simple facts

```prolog
?- predecessor(tom, pat).
```

to satisfy this goal prolog will try to find a clause in the program from which the above goal could immediately follow (`pr1` and `pr2`)
-  heads of these rules match the goal
-  prolog first tries that clause which appears first in the program

this goal fails because there is no clause in the program whose head matches the goal `parent(tom, pat)`
```
predecessor(X, Z) :- parent(X, Z).

X = tom, Z = pat
predecessor(tom, pat)
parent(tom, pat)
```

prolog tries rule 2
```
predecessor(X, Z) :-
	parent(X, Y),
	predecessor(Y, Z).
	
X = tom, Z = pat
parent(tom, Y)
predecessor(Y, pat)
```

after prolog finds variables to use for X and Z, and is faced with two goals, it tries to satisfy them in the order in which they are written
the first goal is satisfied
```
X = tom, Z = pat, Y = bob
parent(tom, bob)
```

remaining goal - to satisfy it, prolog uses `pr1` again
immediately satisfied because we have it as a fact in the program
```
predecessor(bob, pat)

parent(bob, pat)
```


## 1.5 Declarative and procedural meaning of programs

declarative = concerned only with the relations defined by the program
-  determines what will be the output of the program

procedural = concerned with how the relations are actually evaluated by the prolog system
-  determines how this output is obtained

## Summary

-  Prolog programming consists of defining relations and querying about relations
-  A program consists of clauses. These are of three types: facts, rules and questions
-  A relation can be specified by facts, simply starting the n-tuples of objects that satisfy the relation, or by stating rules about the relation.
-  A procedure is a set of clauses about the same relation.
-  Querying about relations, by means of questions, resembles querying a database.
-  In Prolog, to establish whether an object satisfies a query is often a complicated process that involves logical inference, exploring among alternatives and possibly backtracking. All this is done automatically by the Prolog system and is, in principle, hidden from the user.
-  Two types of meaning of Prolog programs are distinguished: declarative and procedural. The declarative view is advantageous from the programming point of view. Nevertheless, the procedural details often have to be considered by the programmer as well.