***part of the project: making a solution using only UMLs***

UML - unified modelling language
-  standard for modeling object-oriented systems

helps in planning, visualising, and documenting software architecture
-  commonly used in system design, software documentation, and team collaboration

## types of UML diagrams

**we focus on Class Diagram**
-  **structural diagrams**: Class Diagram, Object Diagram, Component Diagram, Deployment Diagram

-  **behavioural diagrams**: Use Case Diagram, Sequence Diagram, Activity Diagram, State Diagram

## class diagrams

used in designing and modeling software to describe classes and their relationships
-  high level of abstraction
-  no source code
-  shows the names and attributes of the classes, connections between the classes, and sometimes also the methods of the classes

-  constructors are listed first
-  you have to write the return type of a method

## connections between classes

If we add a variable author, type of which is Person, in the source code the variable is declared like all other class variables

object references are better represented through relationships rather than listing them as attributes inside the class box
-  * instead of a name of a variable tells us that a book can have between 0 and unlimited number of authors

if we have specific number of authors, do this = `3.5`
-  this means "from three to five"

if there is no arrowhead in a connection, both classes know about each other

## describing inheritance

-  described by an arrow with a triangle head
-  the triangle points to the class being inherited from

abstract classes: use `<<abstract>>` above the name of the class
interface: use `<<interface>>` above the name of the class
-  shown as a dashed arrow with a triangle arrowhead