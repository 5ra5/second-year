***100% will be in the exam***
Template Method is a behavioural design pattern that defines the skeleton of an algorithm in the superclass but lets subclasses override specific steps of the algorithm without changing its structure

Allows subclasses to override specific steps without changing the overall algorithm structure.

## problem

-  data mining application
-  users give all types of documents (.doc, .csv, .pdf, etc.)
-  you try to extract meaningful data from it and try to work with it
-  the way we extract data is the same, the only difference is how we process it
-  we need to do something to split it in steps to know what exactly we need to do
## solution

The Template Method pattern suggests that you break down an algorithm into a series of **steps**, turn these steps into methods, and put a series of calls to these methods inside a single template method.

## steps

**abstract steps** must be implemented by every subclass

**optional steps** already have some default implementation, but still can be
overridden if needed

**Hooks** - a hook is an optional step with an empty body. A template method would work even if a hook isn’t overridden. Usually, hooks are placed before and after crucial steps of algorithms, providing subclasses with additional extension points for an algorithm.

## structure

The Abstract Class declares methods that act as steps of an algorithm, as well as the actual template method which calls these methods in a specific order. The steps may either be declared abstract or have some default implementation.

Concrete Classes can override all of the steps, but not the template method itself.

## why?

-  Encapsulates common behaviour in a superclass.
-  Reduces code duplication by enforcing a general workflow.
-  Promotes the Open/Closed Principle – Base class remains unchanged while subclasses add functionality.
-  Helps in framework and library development by allowing controlled customisation.
## when to use the template method pattern?

When **multiple classes share a common workflow**, but some steps vary.

When you want to **prevent code duplication** by enforcing a standard structure.

When you design **frameworks** and allow users to implement specific steps.

When an **algorithm should be easily extensible** with minor modifications.

## how to implement

1. Analyse the target algorithm to see whether you can **break it into steps**. Consider which steps are common to all subclasses and which ones will always be unique.

2. Create the **abstract base class** and declare the template method and a set of **abstract methods** representing the algorithm’s steps. Outline the algorithm’s structure in the template method by executing corresponding steps. Consider making the **template method final** to prevent subclasses from overriding it.

3. It’s okay if all the steps end up being abstract. However, some steps might benefit from having a **default implementation**. Subclasses don’t have to implement those methods.

4. Think of adding **hooks between the crucial steps** of the algorithm.

5. For each variation of the algorithm, create a new concrete subclass. It must **implement all of the abstract steps**, but may also override some of the optional ones.

## template method vs strategy pattern

| Feature           | Template Method        | Strategy Pattern            |
| ----------------- | ---------------------- | --------------------------- |
| Code Reusability  | High                   | Depends                     |
| Algorithm Control | Defined in superclass  | Defined in separate classes |
| Flexibility       | Less flexible          | More flexible               |
| Use Case          | Standardising workflow | Interchangeable behaviours  |
