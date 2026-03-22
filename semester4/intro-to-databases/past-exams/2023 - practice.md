Q3 - Normalisation

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
The table above represents a sample of departures from Dublin airport. The primary key for this table is (FlightNo, Date) as each flight (FlightNo) departs only once per day. All plane types (Plane) have the same maximum seating (capacity) and all planes require 2 pilots except for the A330 which requires 3 pilots. Load represents the actual seat occupancy on the flight.

(a) (i) convert DEPARTURES to 1NF
-  The Pilots attribute contains multiple values (e.g. "A. Murphy, B. Smith")
-  This violates 1NF, which requires atomic (indivisible) values

What we do to convert DEPARTURES to 1NF:
-  Remove the repeating group (Pilots)
-  Create a separate relation to store pilots

(ii) New schema (1NF)
```
DEPARTUES(FlightNo, Date, Destination, Plance, Capacity, Load, Gate)
PKl (FlightNo, Date)

FLIGHT_PILOT(FlightNo, Date, Pilot)
PK: (FlightNo, Date, Pilot)
FK: (FlightNo, Date) -> DEPARTURES
```

(b) (i) How to test for 2NF
Method:
1.  Identify the primary key
2.  Check on each non-key attribute
3.  See if it depends on the whole key or only part of the key (partial dependency)
(ii) Which table is not in 2NF?
DEPARTURES
PK = (FlightNo, Date)

Check dependencies:
-  (FlightNo, Date) -> Destination, Plane, Load, Gate
-  BUT Plane -> Capacity
-  Capacity depends on the Plane, not directly on the full key

FLIGHT_PILOT
PK = (FlightNo, Date, Pilot)
-  No non-key attributes - Already in 2NF

(c) Convert to 2NF
we remove the dependency: plane -> capacity
```
DEPARTURES(FlightNo, Date, Destination, Plane, Load, Gate)
PK: (FlightNo, Date)

PLANE(Plane, Capacity)
PK: Plane

FLIGHT_PILOT(FlightNo, Date, Pilot)
PK: (FlightNo, Date, Pilot)
```

(d) (i) How to test for 3NF
A relation is in 3NF if:
1.  It is in 2NF
2.  No transitive dependencies

test: check if any non-key attribute depends on another non-key attribute

(ii) Does any table fail?
After 2NF decomposition:
