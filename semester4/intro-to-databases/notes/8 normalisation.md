## normalisation of relations
normalisation = take a relation schema through a series of tests to certify whether it satisfies a certain normal form
-  top-down fashion = evaluating each relation against the criteria for normal forms and decomposing relations as necessary
-  relational design by analysis
-  3 normal forms based on a single analytical tool: the functional dependencies among the attributes of a relation

normalisation of data = considered a process of analysing the given relation schemas based on their FDs and primary keys to achieve the desirable properties of
-  minimising redundancy
-  minimising the insertion, deletion, and update anomalies

considered as a filtering or purification process to ensure the design has successively better quality
unsatisfactory relation schemas that do not meet certain conditions (the normal form tests) = decomposed into smaller relation schemas

## definition

the normal form of a relation refers to the highest normal form condition that it meets - indicates the degree to which it has been normalised
-  normal forms do not guarantee a good database design
-  generally not sufficient to check separately that each relation schema in the database is in 3NF
-  normalisation through decomposition must also be lossless - must also confirm the existence of additional properties that the relational schemas, taken together, should process (when we put them together)

## properties

(critical)**nonaddictive join or lossless join property** = guarantee that the spurious tuple generation problem does not occur with respect to the relation schemas created after decomposition

(desirable, but not essential) **dependency preservation property** = ensures that each functional dependency is represented in some individual relation resulting after decomposition 

## keys and attributes

-  The difference between a key and a superkey is that a key has to be minimal

**prime attribute** = attribute of relation schema if it is a member of some candidate key
**nonprime attribute** = not a prime attribute: it is not a member of any candidate key

## first normal form 1NF

***coming up in the exam***
**unnormalised form (UNF)** = a table that contains one or more repeating groups
**first normal form (1NF)** = a relation in which the intersection of each row and column contains one and only one value

**transforming to 1NF**:
-  identify the key attribute for the unnormalised table
-  identify the repeating group in the unnormalised table
-  examine the multiple values at the intersection of certain rows and columns
-  transform to 1NF: ensure a single value exists at each row/column intersection (achieved by removing the repeating group)

## second normal form 2NF

**no partial dependencies**

**second normal form (2NF)**: a relation that is in 1NF and every non-primary key attribute is fully functionally dependent on the primary key
-  based on the concept of full functional dependency
-  applies to relations with composite keys: a primary key composed of two or more attributes

-  a relation with a single-attribute primary key must (at least) be 2NF!!
-  a relation that is not in 2NF may suffer from the update anomalies
- if only one tuple is updated with the new rent, this results in an inconsistency in the database

-  use FDs to identify candidate keys
-  select the primary key for the relation, and place the PK at the left-hand side of the relation

FD1 shows the primary key
FD2 highlights a partial dependency
FD3 highlights a partial dependency
FD4 highlights a transitive dependency
FDs 5 and 6 show candidate keys

**issue with 1NF** = subject to update anomalies, to remove them, we must transform the relation into 2NF
-  this relation contains redundancy and may suffer from similar update anomalies

**transforming to 2NF**:
create new relations so non-PK attributes are removed along with a copy of that part of the PK on which they are fully functionally dependent
-  remove the repeating group together with a copy of the original key attribute into a separate relation
-  identify the primary keys with the help of the functional dependencies

## partial dependencies

normalisation of 1NF relations to 2NF involves the removal of partial dependencies
-  if a partial dependency exists, we remove the partially dependent attribute(s) from the relation by placing them in a new relation along with a copy of their determinant
-  we got rid of 1 problem but more partial dependencies remain

## third normal form 3NF

**no transitive dependencies**

Although 2NF relations have less redundancy, they may still suffer from update anomalies. If one tuple were updated but not the second, the database would be in an inconsistent state. 
-  This update anomaly is caused by a transitive dependency.
-  Remove these dependencies to progress to Third Normal Form.

**third normal form (3NF)** = a relation that is in first and second normal form and in which no non-primary key attribute is transitively dependent on the primary key
-  The normalisation of 2NF relations to 3NF involves the removal of transitive dependencies.
-  f a transitive dependency exists, remove the transitively dependent attribute(s) by placing the attribute(s) in a new relation along with a copy of the determinant


## practice questions for CA3

***in what normal form is the given relation and how can you reduce it to third normal form - see 2025 exam***

***find the primary key and decompose it into first, second and third normal form - see notes in the copy***

given:
```
R(A,B,C,D,E)
```

***need to explain why you would remove certain partial dependencies***