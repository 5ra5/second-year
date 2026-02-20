***included in the CA3***
***exam: find a primary key from a functional dependency***

relation = mapping between 2 sets
function = one to one mapping
main difference: one to one relation, one to many relation, etc,  but function has to be one to one

relational database design aim = group attributes into relations to minimise data redundancy
-  trying to reduce storage issues
-  helps to minimise the cost
-  updating to the data stored in the database with minimal operations

the only kind of essential redundancy: copies of primary keys acting as foreign keys in related relations to enable modeling of relationships between data

**example 1:**
we don't know which one is better since we don't know the use cases
```sql
Staff(staffNo, sName, position, salary, branchNo)
Branch(branchNo, bAddress)
```

**example 2: combined table**
you don't need to join tables when you already combine them from the start
```sql
StaffBranch(staffNo, sName, position, salary, branchNo, bAddress)
```

when we have redundant data it causes **update anomalies**
1.  insertion
2.  deletion
3.  modification

## insertion anomalies

-  entering redundant data
-  if we insert a new branch but include a different address, this will cause anomalies
-  we need to be consistent

-  if we create a new branch with a new branch number and address
-  once the branch is opened, we have no staff so all values are NULL, which is another anomaly
-  the first example avoids this problem because Branch is separate from Staff

## deletion anomalies

-  if you delete the only member that is a part of the branch, you loose the entire branch (this is a problem when there is a combination like in example 2)
-  if these are separated like in example 1, we are not affected by this

## modification anomalies

-  we update the branch address in the example 2
-  if we have 3 people working in the same branch, and we change one, that means that other people's branches will not update automatically
-  if we do the same thing in example 1, branches will update automatically

## decomposition

-  example 1 is better than example 2

2 properties:
1.  lossless-join - any instance of the original relation can be identified from corresponding instances in the smaller relation (no data is lost)
2.  dependency preservation - a constraint on the original relation can be maintained by enforcing constraints on each of the smaller relations (if a relation is violated, we don't need to join two tables to maintain constraint violations because each has their own constraints)

## functional dependencies

**if A and B are attributes of relation R, B is functionally dependent of A (A --> B), if each value of A is associated with exactly one value of B**
-  deals with columns, not with rows
-  not dependent on extension or cardinality 
-  property of the meaning or semantics of the attributes in a relation

example: a value of one column will always give a value of another column
-  `StaffNo`
-  `BranchNo` - multiple employees have the same `BranchNo` - it is functionally dependent of `StaffNo`
-  you can search in `BranchNo` to find `StaffNo`

**A, B  and C example**:
no functional dependencies if columns of A and B have different values
(A can have values a, a, a, but B will have b, c, d in the same rows)

functional dependencies happen if A has values a, a, a but column C has the values c, c, c (C is functionally dependent on A because it has the same value c each time the value of A is A)
-  A --> C
-  A functionally determines C
-  A is **determinant** = attribute, or group of attributes, on the left-hand side of a functional dependency
-  so C depends on a determinant A

staff example:
-  a member of staff holds one position, but several members of staff may have the same position
-  `staffNo` and `position` is one to one (1:1): for each staff number, there is only one position
-  `position` and `staffNo` is one to many (1:*): there are several staff numbers associated with a given position
-  `staffNo` = determinant of this functional dependency
-  `staffNo --> position`
-  `position x/--> staffNo`

## FD types

-  identify functional dependencies between attributes that have a one-to-one relationship between attribute(s) on the left-hand side (determinant), and attribute(s) on the right-hand side of a dependency.
-  (when identifying FDs between attributes) important to distinguish between the values held by and attribute at a given point in time and the set of all possible values that an attribute may hold at different times
-  functional dependency is a property of a relational schema (intension) and not property of a particular instance of the schema (extension)
-  deals with columns, not rows
-  if something is deleted it does not affect functional dependency

## integrity constraints

-  functional dependency should be valid on all types of FD to avoid integrity constraints
-  integrity constraints = limitation on the values that a relation can legitimately assume

-  you need to understand what every column means when inspecting your data
-  then you can identify the set of all possible values for attributes in a relation

## functional dependencies represent 1-1 relationships

`staffNo` and `sName` relationship: 1 to 1
`sName` and `staffNo` relationship: 1 to N (may be several staff numbers associated with a given name)

## full functional dependency

`staffNo, sName --> branchNo`
-  if i give you `staffNo` and `sName`, can you find `branchNo`
-  NO
-  not a full functional dependency because `branchNo` is also functionally dependent on a subset of `(staffNo, sName): staffNo`
-  this is a **partial dependency**

**full functional dependency**: `staffNo --> branchNo`

## FD for normalisation

1.  1 to 1 relationship between the attributes on the left-hand side and those one the right-hand side of a functional dependency
2.  they hold for all time
3.  determinant has the minimal number of attributes

**transitive dependency** = A, B, C attributes of a relation such that if `A --> B` and `B --> C`, C is transitively dependent on A via B (provided that `A x/--> B or C)

staff example:
`branchNo --> bAddress` exists of `staffNo` via `branchNo`

## identifying FDs

-  if one FD holds, the other way will not necessarily hold
-  `A--> C` not the same as `C --> A`
-  you can identify FDs using sample data only if it's a true representation of all possible data values that the database may hold
-  examine the sample relation and identify FDs when values in one column are consistent with the presence of particular values in other columns
-  start from the left-most column and go through the table from left to right and take note of any consistent columns
-  do A with every other column, B with every other column, C with every other column, etc., until you get to the end

**primary key identification using FDs**
-  main purpose of identifying FDs: specify the set of integrity constraints that must hold on a relation
-  first identify candidate keys, one is selected as a primary key for the relation
-  staff example: `StaffNo` would be a primary key
-  A, B, C example: A and B are primary keys because you can figure out all of the other keys from them

essential characteristic for a candidate key: the attributes of a determinant either individually or working together must functionally determine all other attributes in one relation

-  A can't determine all other relation
-  nor can B
-  together, they can