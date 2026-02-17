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

### exercises

1.1
```prolog
12 ?- parent(jim, X).
false.

13 ?- parent(X, jim).
X = pat.

14 ?- parent(pam, X), parent(X, pat).
X = bob.

15 ?- parent(pam, X), parent(X, Y), parent(Y, jim).
X = bob,
Y = pat.
```

1.2
(a) who is pat's parent?
```prolog
?- parent(X, pat).
```

(b) does liz have a child?
```prolog
?- parent(liz, X).
```

(c) who is pat's grandparent?
```prolog
?- parent(X, pat), parent(Y, X).
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
