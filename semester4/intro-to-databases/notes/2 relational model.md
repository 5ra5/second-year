
## overview

-  based on the mathematical concept of **relation**, which is represented by a **table**
-  relation is actually a product of 2 sets generally

**relation** = table with columns and rows - a set of tuples
-  mathematically, elements of a set have no order so tuples in a relation have to particular order (*so don't worry if your answers don't match the others*)

**attribute** = named column of a relation
-  if there is more than one value in a column, it violates the relational model definition, each value in a tuple is atomic - it is not divisible into components

the order of attributes doesn't matter, we try to keep them organised for better readability
*in labs you will have multiple tables that are related to one another, so you will need to do a combination of them to get a proper answer*

-  every attribute or relation has a domain
-  a domain is not just a set of numbers, it can be multiple values of characters, integers, strings, bools, floats etc..
-  every row is defined as a tuple - a tuple is a row of a relation
-  in a relation, all the tuples should be unique

**intension** = the structure of the relation
**extension** = the number of rows 

**a relation's degree** = number of attributes the relation contains
-  the degree of a relation is a property of the intension of the relation because it's the part of the structure of the relation

**cardinality** = number of tuples the relation contains

*intension, extension, relation's degree and cardinality are all related, so make sure that you understand them because they are important*


these are ordered pairs
```
D1 = (2, 4)
D2 = (1, 3, 5)

D1 x D2 = {(2, 1), (2, 3), (4, 3), (4, 5)}
```

any subset of Cartesian product is a relation

## null values
*important*

-  we use them in the case we don't have the appropriate data to include in the relational model

there are various scenarios in which we use them:
-  value unknown
-  value exists but is not available
-  attribute does not apply to this tuple
## constraints

**constraints on databases can be divided into 3 main categories**
- **inherent constraints** -  if there is more than one value in a column, it violates the relational model definition (e.g. relation cannot have a duplicate)
-  **DDL(data definition language)** - we call these **schema-based constraints or explicit constraints** - **domain constraints** specify that within each tuple, the value of each attribute A must be an atomic value from the domain dom(A), they deal with the data types that can be allowed in the tuples because the size of data types is important to consider
-  **application-based constraints**

### types of constraints

-  **key constraints** - **a superkey** is something that can identify a tuple of a relation, if the column has the same value in it, it's key cannot be a superkey because it cannot identify tuples uniquely. a superkey can identify multiple tuples, given that their information is unique

```
f(a, b, c) -> [x1, x2, x3, x4]
f(x) -> y
```

-  if we remove c and the outputs are still unique, then we know that c was redundant (unnecessary) in the superkey
-  otherwise the key cannot be a superkey
-  hence every superkey is a key, but every key is not a superkey

-  **foreign key** = a key that is related to the primary key in a different relation

**entity integrity constraint** = no primary key value can be NULL
-  this is because the primary key value is used to identify individual tuples in a relation, and we can't do that with a NULL value

### constraint violations

-  insert, delete and update change the state of relations in the database, these operations might violate constraints
-  we must make sure to be careful when preforming these

**insertion** = provides a list of attribute values for a new tuple t that is to be inserted into a relation R, we have to make sure that every column matches the domain, otherwise we can violate all integrity constraints

**delete** = can violate only referential integrity, to fix use `restrict` or `cascade`
`restrict` rejects the deletion
`cascade` deletes tuples that reference the tuple that is being deleted
*it's better to use restrict*
`set null` or `set default` sets all tuples that reference the tuple that is being deleted to NULL or default value we already defined (but we can change primary key that way which can violate entity integrity)

**update** = updating an attribute that is neither part of a primary of foreign key causes no problems

