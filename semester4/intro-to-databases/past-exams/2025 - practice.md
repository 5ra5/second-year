Q1. Functional Dependencies
1.  Assuming that a functional dependency is of the form L→ R where L represents one or more (determinant) attributes and R represents a different set of attributes, list 5 functional dependencies for the STUDENTS relation Provide a **different value** for L in each dependency.
2.  What is meant by the dependency preservation property? In your answer, explain the circumstances in which it may occur and how it should be resolved.
3.  Assume you have a relation R with attributes (a,b,c,d,e). Briefly describe an algorithm to locate all functional dependencies in R.

Q2. Normalisation
1.  In what normal form would you consider the STUDENTS table to be? Why?
2.  In what normal form would you consider the PROFESSORS table to be? Why?
3.  Taking the relation STUDENTS, explain the steps you would take to bring this relation to third normal form. At each step, highlight the specific functional dependency that informed your decision for decomposition.
4. Take the PROFESSORS table and write an un-normalised version of this table to your answer book. Explain what you did and why it became an un-normalised table.


| SID      | Name           | Address   | CourseID | CourseName            | TutorID | TutorName     |
| -------- | -------------- | --------- | -------- | --------------------- | ------- | ------------- |
| 20181011 | Michael Murphy | Dundalk   | DC101    | Computer Applications | 750001  | Jack Sharp    |
| 20181015 | Ann Burke      | Dunboyne  | DC101    | Computer Applications | 750003  | Pauline Burke |
| 20181022 | Tom Flynn      | Finglas   | DC101    | Computer Applications | 750004  | Nora Martin   |
| 20181111 | Mary Burke     | Glasnevin | DC101    | Computer Applications | 750004  | Nora Martin   |
| 20181211 | Brian Byrne    | Glasnevin | DC102    | Enterprise Computing  | 750004  | Nora Martin   |
| 20181256 | Ellen Molloy   | Glasnevin | DC102    | Enterprise Computing  | 750007  | Eilis Flynn   |
| 20181260 | Deirdre flynn  | Finglas   | DC101    | Computer Applications | 750007  | Eilis Flynn   |
| 20181275 | Alan Marr      | Finglas   | DC102    | Enterprise Computing  | 750001  | Jack Sharp    |
Table A: STUDENTS relation

| CourseID | Department              | Head           |
| -------- | ----------------------- | -------------- |
| DC101    | Department of Computing | Prof. Murphy   |
| DC102    | Department of Biology   | Prof. Swan     |
| DC103    | Department of Physics   | Prof. McDonald |
Table B: PROFESSORS relation

Answers:
Q1.
1.  
   ```
fd1 (primary key)     : SID, CourseID -> Name, Address, TutorID, TutorName, CourseName
fd2 (partial dep)     : SID -> Name, Address
fd3 (partial dep)     : CourseID -> CourseName
fd4 (partial dep)     : TutorID -> TutorName
fd5 (combination)     : CourseID, TutorID -> TutorName
   ```

2.  Dependency preservation property ensures that a constraint on the original relation can be maintained by enforcing constraints on each of the smaller relations. This occurs in circumstances in which we have to decompose a relation into smaller relations, and we need to make sure that those smaller relations maintain the same constraints as the original table. For example, if we decompose the STUDENTS relation into a smaller relation like TutorInfo(TutorID, TutorName), TutorID being the primary key is the determinant of TutorName, which means that the dependency was preserved and we do not need to join this relation with other smaller relations to determine whether TutorName is dependent on TutorID.
3.  **Algorithm to find all functional dependencies in a relation `R(a,b,c,d,e)`**:
	 **Check single attributes (|L| = 1):**  
    For each attribute `X` in `R`, test whether `X → Y` for every other attribute `Y` in `R`.
    - If the value of `X` uniquely determines `Y` in all tuples, record `X → Y`.
	**Check combinations of attributes (|L| = 2, 3, …):**  
    Consider all combinations of two or more attributes as determinants.
    - For each combination `L` and each attribute `Y` not in `L`, check if `L → Y` holds.
    - Record all valid dependencies.
	**Repeat until all possible combinations** have been checked.
	**Eliminate redundant dependencies:**
    - If a dependency `L → Y` can be inferred from other dependencies using transitivity, it can be omitted from the minimal set.
	**Output all identified functional dependencies.**

Q2.
(a) 
1. I would consider the STUDENTS table to be in 1NF because all values in each attributes are atomic, meaning that there is only one value in each column of the relation. However the table does not satisfy 2NF because it contains partial dependencies (example: if the primary key is SID, CourseID, TutorID, a partial dependency would be SID -> name, address)
2.  I would consider the PROFESSORS table to be in 2NF because all of the values are atomic, and there is no partial dependencies since the primary key courseID determines both the department and the head. This table cannot be in 3NF because Head transitively depends on courseID through the Department.

(b) Since there is partial dependencies when the primary key is (SID, CourseID), i would decompose the STUDENT relation into two smaller relations: STUDENT and COURSE
this would take the table into 2NF
i made this decision based on dependencies like SID -> Name, Address
this is a partial dependency since CourseID does not determine the Name and Address but it is part of a PK
student would look like this: sid is the primary key
```
SID -> Name, Address, CourseID
```

course would look like this: courseID is the primary key
```
CourseID -> CourseName, TutorID, TutorName
```

This way there is one primary key for each relation which determines all of the attributes in their respective tables

after this step there is still a dependency where TutorName is transitively dependent of CourseID through TutorID, so i would decompose the COURSE relation further into COURSE and TUTOR
course would look like this: courseID is primary key
```
CourseID -> CourseName, TutorID
```

tutor would look like this: tutorID is the primary key
```
TutorID -> Tutor
```

it is important to include foreign keys in each relation we decompose so all of the relations are still connected

(c)

| CourseID | Department                  | Head                         | HeadID        |
| -------- | --------------------------- | ---------------------------- | ------------- |
| DC101    | Department of Computing<br> | Prof. Murphy<br>Prof. Cullen | HC383<br>HC67 |
| DC102    | Department of Biology       | Prof. Swan                   | HC56          |
| DC103    | Department of Physics       | Prof. McDonald               | HC281         |
This is an unnormalised table because it contains **repeating groups and non-atomic values**. For example, the attributes _Head_ and _HeadID_ contain multiple values in a single cell (e.g. “Prof. Murphy, Prof. Cullen”), which violates the requirement that each field should contain only one value. This results in a table that is not in First Normal Form (1NF).