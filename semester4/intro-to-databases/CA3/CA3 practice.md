# 2025

Q1. Functional Dependencies
1.  Assuming that a functional dependency is of the form L→ R where L represents one or more (determinant) attributes and R represents a different set of attributes, list 5 functional dependencies for the STUDENTS relation Provide a **different value** for L in each dependency.
2.  Assume you have a relation R with attributes (a,b,c,d,e). Briefly describe an algorithm to locate all functional dependencies in R.

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
Table A: Students relation


| CourseID | Department              | Head           |
| -------- | ----------------------- | -------------- |
| DC101    | Department of Computing | Prof. Murphy   |
| DC102    | Department of Biology   | Prof. Swan     |
| DC103    | Department of Physics   | Prof. McDonald |

# 2024

| flight_num | passenger_id | date       | destination | duration | loyalty_num |
| ---------- | ------------ | ---------- | ----------- | -------- | ----------- |
| FR123      | P101         | 01/02/2023 | Bristol     | 1        | 2101        |
| EI246      | P102         | 01/02/2023 | Alicante    | 2        | 2102        |
| EI248      | P103         | 01/02/2023 | Amsterdam   | 1.5      | 2103        |
| FR223      | P104         | 01/02/2023 | Dusseldorf  | 2        | 2104        |
| FR153      | P105         | 01/02/2023 | Palma       | 2        | 2105        |
| US401      | P106         | 01/02/2023 | Atlanta     | 7        | 2106        |
| US402      | P107         | 01/02/2023 | Boston      | 6        | 2107        |
| EI514      | P108         | 01/02/2023 | Toulouse    | 2        | 2108        |
| EI646      | P109         | 01/02/2023 | Madrid      | 2        | 2109        |
| FR129      | P110         | 01/02/2023 | Rome        | 2        | 2110        |
| EI101      | P111         | 02/02/2023 | New York    | 7        | 2111        |
| EI514      | P101         | 02/02/2023 | Toulouse    | 2        | 2101        |
| FR333      | P105         | 02/02/2023 | Madrid      | 2        | 2105        |
| EI249      | P112         | 02/02/2023 | Rome        | 2        | 2112        |
| EI101      | P120         | 02/02/2023 | New York    | 7        | 2120        |
| US401      | P121         | 02/02/2023 | Atlanta     | 7        | 2121        |
| EI102      | P122         | 02/02/2023 | Boston      | 6        | 2122        |
| IB400      | P102         | 02/02/2023 | Alicante    | 2        | 2102        |
| FR102      | P123         | 02/02/2023 | Amsterdam   | 1.5      | 2123        |
| FR223      | P108         | 02/02/2023 | Dusseldorf  | 2        | 2108        |
No passenger will depart Dublin airport twice on the same day!

# 2023 resit

| ITEM# | PRODUCT_CODE | DESCRIPTION            | QTY | BACKORDERED | FILLED | PRICE/UNIT | AMOUNT  |
| ----- | ------------ | ---------------------- | --- | ----------- | ------ | ---------- | ------- |
| 1     | FR233        | HALF SIZE REFRIGERATOR | 2   | 0           | 2      | 750.99     | 1501.98 |
| 2     | TB101        | PATIO TABLE            | 5   | 2           | 3      | 150.00     | 450.00  |
| 3     | CH089        | PATIO CHAIRS           | 20  | 0           | 20     | 35.00      | 700.00  |

# 2023

| FlightNo | Date       | Destination | Pilots                       | Plane | Capacity | Load | Gate |
| -------- | ---------- | ----------- | ---------------------------- | ----- | -------- | ---- | ---- |
| FR666    | 24/10/2022 | Birmingham  | A. Murphy, B.Smith           | B737  | 180      | 165  | 103  |
| EI3228   | 24/10/2022 | Glasgow     | T. Trent, L. Byrne           | A320  | 190      | 190  | 336  |
| FR437    | 24/10/2022 | Reus Salou  | P. Henri, D. Gayet           | B737  | 180      | 122  | 107  |
| FR7156   | 24/10/2022 | Madrid      | G. Alonzo, G. Herrera        | B737  | 180      | 178  | 104  |
| EI638    | 24/10/2022 | Brussels    | D. Dunne, E. Evans           | A320  | 190      | 188  | 422  |
| LG4884   | 24/10/2022 | Luxembourg  | A. Claret, B. Tuna           | B737  | 190      | 89   | 224  |
| EI564    | 24/10/2022 | Barcelona   | G. Thompson, A. Lane         | A321  | 210      | 210  | 418  |
| EI528    | 24/10/2022 | Paris CDG   | N. Cave, J. Lydon            | A320  | 190      | 160  | 414  |
| FR288    | 24/10/2022 | London STN  | E. Leclerc, E. Collins       | B737  | 180      | 180  | 103  |
| BA4473   | 24/10/2022 | London LCY  | R. Sunak, A. Mess            | B737  | 180      | 175  | 204  |
| TP1327   | 24/10/2022 | Lisbon      | D. Jota, P. Nunez            | A320  | 190      | 180  | 304  |
| EK164    | 24/10/2022 | Dubai       | A. Latif, B. Asad, C. Murphy | A330  | 250      | 242  | 410  |

| Col1 | Col2 | Col3  | Col4 | Col5    |
| ---- | ---- | ----- | ---- | ------- |
| 127  | abc  | Green | A1   | Yes     |
| 128  | abd  | Green | A2   | Yes     |
| 129  | abe  | Green | A3   | Yes     |
| 132  | abe  | Red   | A7   | No      |
| 133  | abf  | Green | B1   | Yes     |
| 134  | abf  | Green | B3   | Yes     |
| 140  | abg  | Red   | B4   | No      |
| 141  | abh  | Red   | B5   | Partial |
| 148  | abj  | Red   | B6   | Partial |
| 149  | abk  | Green | B9   | Yes     |

# 2018

| staffNo | branchNo | BranchAddress                      | name           | position  | hoursPerWeek |
| ------- | -------- | ---------------------------------- | -------------- | --------- | ------------ |
| S4555   | B002     | 5a Drumcondra Road East, Dublin 9. | Katie Taylor   | Assistant | 16           |
| S4555   | B002     | 5a Drumcondra Road East, Dublin 9. | Katie Taylor   | Assistant | 9            |
| S4612   | B004     | 10 Collins Ave. West, Dublin 9.    | James McCarthy | Assistant | 14           |
| S4612   | B004     | 10 Collins Ave. West, Dublin 9.    | James McCarthy | Assistant | 10           |
The table represents the hours worked per week for temporary staff at every branch for one company.

```
branchNo -> BranchAddress
staffNo -> name
staffNo -> position
```

