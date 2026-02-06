-  binary search finds data, binary tree keeps it

**KD-tree (K-Dimensional Tree)**
-  used in two or multi-dimensional spaces

# inheritance

**very** important
-  Inheritance allows one class to acquire properties and methods of another class
-  Enables code reuse and extensibility

```java
class Parent {
	int x = 10;
}

class Child extends Parent {
	// Child inherits Parent
	int y = 20;
}
```

## types of inheritance

-  **Single Inheritance** – One class inherits another
-  **Multilevel Inheritance** – A class inherits from a class that is already inherited
-  **Hierarchical Inheritance** – Multiple classes inherit from a single parent.
-  Java does not support **multiple inheritance** with classes (attribute conflicts, ambiguity, if 2 classes have the same variable, java doesn't know which one to inherit)

## single inheritance

● Single Inheritance is a mechanism where a single child class inherits from a single parent class
● The child class gains access to the fields and methods of the parent class, allowing code reuse and extension
● It promotes modularity and reduces redundancy in code.

child can't inherit private methods

Code Reusability – Avoids writing duplicate code.
Improves Maintainability – Changes in the parent class automatically reflect in the child class.
Extensibility – Allows adding new functionality in derived classes without modifying the parent.


```
Banking Systems:
	`BankAccount` → `SavingsAccount`
E-commerce Platforms:
	`User` → `VIP` `User`
Automobile Industry:
	`Car` → `Electric` `Car`
```

