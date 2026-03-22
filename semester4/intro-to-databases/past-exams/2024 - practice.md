
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
Q3. (a) Describe the method for determining all Functional Dependencies (FDs) with 2 attributes (flight_num,a) on the left hand side and 1 attribute (b) on the right side. In your description, write down all combinations of FDs in the order in which you find them. Note: a and b represent any 2 attributes ≠ flight_num.

Answer:
```
(flight_num, passenger_id) -> date
(flight_num, passenger_id) -> destination
(flight_num, passenger_id) -> duration
(flight_num, passenger_id) -> loyalty_num

(flight_num, date) -> destination
(flight_num, date) -> duration

(flight_num, destination) -> duration

(flight_num, loyalty_num) -> passenger_id
```

(b) Label each FD found in part (a) as Full or Partial.

PK = (flight_num, passenger_id) because they can determine all other attributes
```
FULL (flight_num, passenger_id) -> date
FULL (flight_num, passenger_id) -> destination
FULL (flight_num, passenger_id) -> duration
FULL (flight_num, passenger_id) -> loyalty_num

PARTIAL (flight_num, date) -> destination
PARTIAL (flight_num, date) -> duration

PARTIAL (flight_num, destination) -> duration

PARTIAL (flight_num, loyalty_num) -> passenger_id
```

(c) Identify all functional dependencies with left hand sides:
(i) loyalty_num →X (where X is a single attribute)
```
loyalty_num -> passenger_id
```

(ii) passenger_id →X (where X is a single attribute)
```
passenger_id -> loyalty_num
```

(iii) Are all of the rules in parts (i) and (ii) commutative (the reverse FD holds)? Explain your answer. 
Yes, they are commutative because `loyalty_num` can only find `passenger_id` on its own and vice versa. It is a 1 - to - 1 mapping because each passenger_id has a unique loyalty_number which stays consistent.

(d) (i) In terms of decomposition, what is meant be the lossless join property. Using the table of flights, provide an example.
Lossless join property ensures that any instance of the original relation can be identified from corresponding instances in smaller relations. For example, if we decompose the table into FLIGHT and PASSENGER where
(flight_num -> date, destination, duration) and (passenger_id -> loyalty_num), we would need to create a relationship relation which would connect these two relations so that we can still identify a passenger on a flight - in other words, so we don't loose any information about the flight and all of its passengers

(ii) What is meant by the dependency preservation property? Using the same table, provide an example.
A dependency preservation property ensures that the same dependencies are kept after the table has been decomposed into smaller tables.
For example: if duration of the flight is dependent on the flight number, then that has to remain true when we decompose the original table into flight and passenger table.

Q4. (a) State the condition by which a table is in first normal form (1NF). Is the passenger_flight table in 1NF? Explain your answer.

A table is in the first normal form is all of the values in all of the columns are atomic, meaning there is only a single value and there are no repeating groups or arrays. The passenger_flight table is in 1NF because there is no columns that contain multiple values, and there is no multi-valued or nested attributes.

(b) State the condition by which a table is in second normal form (2NF). Explain why the passenger_flight table is not in 2NF by providing 2 functional dependencies that prove that 2NF does not hold.

A table is in second normal form (2NF) if there is no partial dependencies in the relation, meaning that all attributes can be identified only by all attributes in the primary key. If one of the attributes of the primary key can identify an attribute, but the other one cannot, that means that there is a partial dependency, and the 2NF is not satisfied.
passenger_table is not in 2NF because:
```
PK is (flight_num, passenger_id)
(flight_num) -> destination
(passenger_id) -> loyalty_num

passenger_num cannot determine destination and duration alone, but flight_num can
flight_num cannot determine loyalty_num, but passenger_id can
```

(c) Convert the passenger_flight table to 2NF and show the structure of the tables.
structure of the tables:
FLIGHT(flight_num -> date, destination, duration)
PASSENGER(passenger_id -> loyalty_num)

to maintain lossless join property:
FLIGHT_PASSENGER(flight_num, passenger_id)

(d) State the condition by which a table is in third normal form (3NF). Check that tables from part (c) are in 3NF. Write an explanation for each table.

A table is in third normal form if it is already in second normal form and has no transitive dependencies, meaning that no non-key attribute is dependent on the primary key through another attribute (A -> B, B -> C, given that A x/-> C).
FLIGHT table is in 3NF because the primary key flight_num can determine the date, destination and duration of the flight directly
PASSENGER table is in 3NF because the primary key passenger_id can directly idenitify loyalty_num
FLIGHT_PASSENGER table is in 3NF because there is no non-key attributes.