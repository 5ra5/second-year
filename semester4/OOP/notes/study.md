# week 5

-  abstraction
-  interfaces
-  mediator

| Access Modifier | Where It's Accessible                              | Notes                         |
| --------------- | -------------------------------------------------- | ----------------------------- |
| `public`        | Anywhere, from any class or package                | Most permissive               |
| `protected`     | Some package + subclasses (even in other packages) | Slightly restricted           |
| *(default)*     | Some package only (no keyword needed)              | Also called "package-private" |
| `private`       | Only within the same class                         | Most restrictive              |
```java
class Example {
	public int a;    // Accessible from anywhere
	protected int b; // Accessible from same package and subclasses
	int c;           // default: accessible in the same package
	private int d;   // Accessible only within Example class
}
```

"The overridden method cannot be more restrictive in access modifier"
-  If the **parent class** method is `public`, the **child class** method **cannot be `protected` or `private`**, because that would **reduce visibility**.
-  If the parent method is `protected`, the child method cannot be `private`, but it could be `protected` or `public`.

## upcasting
more powerful (full access to subclass), but less flexible for polymorphism
```java
Animal a = new Dog();
a.eat();  // Works, uses Dog's overridden method if present
a.bark(); // ERROR! 'bark' is only in Dog
```

more flexible, still executes overridden behaviour, but limited to superclass methods
```java
Dog a = new Dog();
a.eat();  // Inherited from Animal
a.bark(); // Defined in Dog
```

```java
class Animal {
    void eat() { System.out.println("Animal eats"); }
}

class Dog extends Animal {
    void eat() { System.out.println("Dog eats"); } // overrides Animal.eat()
    void bark() { System.out.println("Woof!"); }
}

public class Test {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        myDog.eat();  // Calls Dog's overridden version → "Dog eats"
        myDog.bark(); // Dog-specific method → "Woof!"
    }
}
```

## abstract vs. concrete methods
```java
abstract class Animal {
	abstract void makeSound(); // Abstract method
	
	void eat() { // Concrete method
		System.out.println("Eating food...");
	}
}

class Dog extends Animal {
	void makeSound() {
		System.out.println("Bark!");
	}
}
```

## interfaces vs abstract classes

- **Interfaces can be multiply inherited** — you can implement multiple interfaces but can only extend **one** abstract class.
- **Interfaces cannot have constructors or instance fields** — they don’t define state, only behavior/contract.
- **Abstract classes are better for shared state or partial implementation**, while interfaces are best for **purely behavioural contracts**.