# Part 0: Understanding Method Overriding

method overriding = allows a subclass to provide a specific implementation of a method that is already defined in its superclass
-  enables polymorphism
-  allows objects of different subclasses to be treated as instances of the parent class while still executing subclass-specific behaviour

## rules for overriding

**1. same method signature**
-  the method in the subclass must have the same name, return type and parameters as in the parent class

**2. using @Override annotation**
-  not mandatory, but it helps prevent mistakes by ensuring the method is correctly overridden

**3. access modifier restrictions**
-  the overriding method cannot have more restrictive access modifier than the method in the superclass
-  example: if the superclass method is `protected`, the subclass cannot override it with `private`

**4. static and final methods cannot be overridden**
-  methods declared as `static` or `final` in the parent class cannot be overridden in a subclass

**5. calling superclass methods**
-  the `super` keyword can be used to call the overridden method from the superclass

## example of method overriding
```java
// superclass
class Animal {
	void makeSound() {
		System.out.println("Some generic animal sound");
	}
}

// subclass overriding the method
class Dog extends Animal {
	@Override
	void makeSound() {
		System.out.println("Dog barks!");
	}
}

// main class to test overriding
class Main {
	public static void main(String[] args) {
		Animal myAnimal = new Animal();
		myAnimal.makeSound(); // Output: Some generic animal sound
		
		Animal myDog = new Dog();
		myDog.makeSound();
	}
}
```

-  `Animal` defines a method `makeSound()`
-  `Dog` extends `Animal` and overrides `makeSound()` to provide its own behaviour
-  when calling `makeSound()` on an Animal object, the superclass method is used
-  when calling `makeSound()` on a Dog object (even when referenced as Animal), the overridden method in Dog executes

## using super in overriding

if a subclass wants to reuse the parent class method while adding extra behaviour, it can call `super.methodName()`

```java
class Employee {
	void work() {
		System.out.println("Employee is working");
	}
}

class Manager extends Employee {
	@Override
	void work() {
		super.work(); // Call parent class method
		System.out.println(" and managing the team");
	}
}

// Test
class Main {
	public static void main(String[] args) {
		Manager manager = new Manager();
		manager.work();
	}
}
```

-  `super.work()` calls the parent method before executing the subclass-specific logic

# Part 1: Abstract Classes

## Theory: what are abstract classes?

abstract class = class that cannot be instantiated directly
-  server as a blueprint for other classes

they can have:
-  abstract methods (methods without a body, forcing subclasses to implement them)
-  concrete methods (regular methods with an implementation)
-  fields (variables that can store data)

abstract class defined using the `abstract` keyword
```java
abstract class Animal {
	String name;
	
	Animal(String name) {
		this.name = name;
	}
	
	abstract void makeSound(); // Abstract method (no implementation)
	
	void sleep() { // Concrete method
		System.out.println(name + " is sleeping.");
	}
}
```

subclasses must implement all abstract methods from the abstract class
```java
class Dog extends Animal {
	Dog(String name) {
		super(name);
	}
	
	@Override
	void makeSound() {
		System.out.println(name + " barks!");
	}
}
```

# Part 2: Interfaces

## Theory: what are interfaces?

interface = a contract that classes must follow
-  only contains abstract methods (before Java 8)
-  can have default and static methods from Java 8 onward

they allow multiple inheritance and ensure consistency across different classes
```java
interface Vehicle {
	void start();
	void stop();
}
```

classes implement interfaces using the `implements keyword`
```java
class Car implements Vehicle {
	@Override
	public void start() {
		System.out.println("Car is starting...");
	}
	
	@Override
	public void stop() {
		System.out.println("Car is stopping...");
	}
}
```