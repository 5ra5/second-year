# an overview

SQL = practical language
relational algebra = formal language - provides the foundation for the SQL query language
-  the basic set of relation model *operations* is the **relational algebra**

operations can be divided into 2 groups
-  one group includes set operations from mathematical set theory: these are applicable because each relation is defined to be a set of tuples in the formal relational model

1.  Set Theory Operations - **UNION, INTERSECTION, Set Difference, Cartesian Product** (Cross Join)
2.  Operations Specific for Relational Databases - **SELECT, PROJECT, JOIN** etc.

# unary operations

**unary operations** = Selection (goes over rows), Projection (goes over columns)

## selection
selection (restriction) operation
$$
σpredicate R
$$

-  SELECT operator is unary: applied to a single relation
-  As the selection operation is applied to each tuple individually, selection conditions cannot involve more than one tuple.
-  the SELECT operation is commutative and thus, a sequence of SELECTs can be applied in any order.
-  we can always combine a cascade (or sequence) of SELECT operations into a single SELECT operation with a conjunctive (AND) condition
-  these are nested queries - they can be unnested and rewritten using AND
operators.
```
σ<cond1> ( σ<cond2> ( \ … . . ( σ<condn> (R) ) \ …… ) ) =
σ<cond1> AND <cond2> AND \ …… AND <condn> (R)…. Or
we can also write as
σ<cond1> ^ <cond2> ^ \ …… ^ <condn> (R)…
```

## project

-  The PROJECT operation selects certain columns and discards the remaining columns.
-  PROJECT operation can be visualised as a vertical partition of the relation into two relations: one with the chosen columns, and the other with discarded columns.

Produce a list of salaries for staff, showing only the staffNo, fName, lName, and salary details.
```
^π staffNo, fName, lName, Salary ^(STAFF)

general form:
^π <attribute list>^(R)
```

-   degree of PROJECT is equal to the number of attributes in `<attribute list>`
-  PROJECT is not commutative, the order of operations matters

## sequences of operations

-  To apply multiple algebra operations, either write a single relational algebra expression using nesting, or apply one operation at a time and create intermediate result relations

# set operations

-  Cartesian product
-  Union
-  Intersection
-  Set difference (minus)

these are not unary operations, these are binary operations because each operation is applied to 2 sets of tuples


-  When these operations are adapted to relational databases, the two relations on which any of these three operations are applied must have the same type of tuples.
-  This condition has been called union compatibility or type compatibility.

## union

`R ∪ S` = The union of two relations R and S defines a relation that contains all the tuples of R, or S, or both R and S.
-  Union is only possible where the schemas of the two relations match: the same number of attributes with matching attributes having the same domain. (union compatible)
-  duplicate tuples are eliminated

## set difference

`R - S` = The Set Difference (or MINUS) operation defines a relation consisting of the tuples that are in relation R, but not in S.
-  R and S must be union-compatible

## intersection

`R ∩ S` = The Intersection operation defines a relation consisting of the set of all tuples that are in both R and S.
 -  all duplicates are eliminated as well
 -  in SQL, there are three operations: UNION, INTERSECT, and EXCEPT, that correspond to the set operations described here
-   INTERSECTION can be expressed in terms of union and set difference as follows:
```
R ∩ S = ((R ∪ S ) - (R - S )) - (S - R)
```

## PRODUCT

-  The CARTESIAN PRODUCT operation (or CROSS PRODUCT or CROSS JOIN), is denoted by ×
-  This operation produces a new element by combining every member (tuple) from one relation (set) with every member (tuple) from the other relation (set).
-  The resulting relation Q has one tuple for each combination of tuples: one from R and one from S
-  the CARTESIAN PRODUCT operation applied by itself is generally meaningless
-  It is mostly useful when followed by a selection that matches values of attributes coming from the component relations.
-  Select all books, loaned to a particular student
-  Select all staff, who work in a particular branch