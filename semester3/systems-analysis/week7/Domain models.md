- Conceptual model of all the topics related to a specific problem, describing the various entities, their attributes, roles and relationships, plus the constraints that govern the problem domain
- Requirement is about getting the problem, not solution
- "All models are wrong, but some are useful" - we say that all models are wrong because they are not complete, they are a simplified version of a system and don't contain details that make the system
- We still make a model because it is useful to have: it contains a conceptual framework in problem space, and it helps us think about what needs to be developed in the system

Object-Oriented Modelling
- Object - represents a particular instance of a class
- It can be physical or abstract
- It combines multiple data structures in a single entity
- Every object is self-contained and extends to intangibles
- Class - a template for creating objects
- Instance - an individual object of a certain class, for example an instance of a bank is information about a specific bank account

Analysing an example of an object-oriented system - finding key concepts:
1. highlight nouns & noun phrases - potential entity
2. highlight verbs & verb phrases - potential relation
3. Combine these to find concepts - two entities are objects, and relations connect them

UML Class Diagram
- Classes can be arranged into a hierarchy
- Each subclass inherits all properties of its superclass and may add its own (new) properties
- Class hierarchy is easy to extend - we just need another branch on the same level as other object - concept of inheritance in class
- Inheritance is transitive - a subclass inherits all properties of all its ancestors

Instance (Object) Diagram
- Contains actual values of objects unlike the class diagram, which contains only the names of these
- We have a class name and the instance name at the top, and the details at the bottom

An association is a logical connection between two or more classes - it describes links between their object instances. It can have roles as well

Multiplicity is an association that represent the possibility of links

# Object oriented approach

- Abstraction
- Encapsulation (information hiding)
- Sharing & re-use
- Focus on class structure, not on procedure

Abstraction
- Focus on essential aspects of the problem, ignore the rest
- Essential aspects depend on the problem and the perspective of the problem-solver

Encapsulation
- Separate internal and external aspects of the system

Sharing & re-use
- Use inheritance to save time and keep some of the same structure of the code in the system


Domain objects are not software objects, domain model is a problem-space, not solution-space.
