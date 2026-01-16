-  50% exam - MCQ + programming in Java
-  50% CA - 15% quizzes, 15% project, 20% labs

## Primitive data types

-  The simplest building blocks of data in programming
-  Integer, float, string
-  Fixed size in memory

## Advanced data structures

-  Arrays
-  Arrays typically store data of the same type
-  Dictionary - associative array
-  Made to represent relationships between data, key-value pairs were introduced

**What is a structure?**
-  Blueprint for organizing related data together
-  Defines attributes but does not include behaviours
-  Enforces consistency

## What is OOP

-  Computer programming paradigm that organises software design around data, or objects, rather than functions and logic

**Key concepts**

-  object = a real-world entity in a program, encapsulating data and behaviour
-  class = a blueprint or template for creating objects
-  fields (attributes) = data stored in an object
-  methods (function) = the ways in which the object interacts with the data

## Most important properties

-  **Encapsulation** = concept of hiding the internal details of an object and exposing only the necessary part (security, simplicity, code maintainability, protection from errors, scalability)
-  Getters and setters = getting (retrieve information using methods), setting (update information using methods)

- **Abstraction** = process of showing only essential details while hiding the internal implementation - users interact with the system based on what they need to know, now how it works internally
-  Interface = the way sections of code or objects communicate with each other (modularity, reausability)

-  **Inheritance** = allows a class (child class) to acquire properties and behaviours (methods) from another class (parent class)
-  Parent Class (Superclass)
-  Child Class
-  Types: Single, Hierarchical, MultiLevel, Hybrid, Multiple
-  Advantages: reusability, extensibility, maintainability
-  Access modifiers = determine how attributes of a class can be accessed or inherited
-  Public = accessible from any class in the hierarchy or external code, for example, one of the child classes can access information of any class **(used for general information sharing)**
-  Protected = accessible within the parent and child classes, for example, a child class can only access the information of it's sibling class and the parent **(used for controlled sharing within the hierarchy)**
-  Private = accessible only within the defining class **(used to encapsulate sensitive data)**


-  **Polymorphism** = allows methods to take many forms, so a single function name or method can behave differently based on the context (flexibility and reusability)
-  Two types: dynamic and static
-  Dynamic: child classes override parent classes - they have the same name but their functions have different implementation. this happens during runtime
-  Static: defines multiple methods with the same name but different parameters. this happens during compiling. it overloads methods in the same class
-  We use polymorphism to avoid repetition in the code

-  Don't overuse inheritance, use composition instead
-  inheritance - "is-a" relationship (dog has legs)
-  composition - "has-a" relationship (dog is an animal)

-  Make sure to focus on encapsulation for the exam, don't leave class attributes public
-  use private or protected attributes with getters and setters
-  don't leave spaces for easy errors

-  don't make large, monolithic classes that control the entire code, instead break them down to classes that focus on a specific action
-  this is because mistakes are easier to solve if you know which class to look to, you don't need to change the entire monolithic class