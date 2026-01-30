# 1. Constructor overloading

constructor overloading = allows a class to have multiple constructors with different parameter lists. It gives flexibility in how objects are initialised.

example: overloaded constructors in a rectangle class
```java
public class Rectangle {
	private int width;
	private int height;
	
	// Default constructor
	public Rectangle() {
		this.width = 1;
		this.height = 1; // Default dimensions
	}
	
	// Constructor with one parameter
	public Rectangle(int size) {
		this.width = size;
		this.height = size; // Square dimensions
	}
	
	// Constructor with two paremeters
	public Rectangle(int width, int height) {
		this.width = width;
		this.height = height;
	}
	
	@Override
	public String toString() {
		return "Rectangle{" +
				"width=" + width +
				", height=" + height +
				'}';
	}
}
```

**default constructor**: initialises a rectangle with default dimensions of 1x1
**single-parameter constructor**: creates a square where both dimensions are equal
**two-parameter constructor**: initialises a rectangle with custom dimensions

expected output:
```java
public class Main {
	public static void main(String[] args) {
		Rectangle defaultRectangle = new Rectangle();
		Rectangle square = new Rectangle(5);
		Rectangle customRectangle = new Rectangle(4, 8);
		
		System.out.println(defaultRectangle); // Rectangle{width=1, height=1}
		System.out.println(square); // Rectangle{width=5, height=5}
		System.out.println(customRectangle); // Rectangle{width=4, height=8}
	}
}
```

## @Override

`@Override` = annotation that indicates that a method is being overridden from a superclass or an implemented interface
-  not mandatory, but helps the compiler catch errors if the method signature does not match the one in the superclass or interface

**purpose**: ensures that the method overrides a method from a superclass or implements an interface method
**compiler check**: if the annotated method does not match a method in the superclass or interface, the compiler throws an error
**improves readability**: signals to other developers that the method modifies or extends behaviour from the superclass

## toString

-  method defined in the `Object` class and is inherited by all Java classes
-  it returns a string representation of the object by default like this:
```
ClassName@HashCode
```

example:
```java
class Person {}

public class Main {
	public static void main(String[] args) {
		Person person = new Person();
		System.out.println(person.toString()); // Outputs something like: Person@1a2b3c
	}
}
```

### Why override toString?

-  the default toString implementation does not provide meaningful information about the object
-  overriding it allows you to return a custom string representation, which can be helpful for debugging or logging

## overriding toString in a Custom Class

```java
public class Person {
	private String name;
	private int age;
	
	// Constructor
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	// Overriding the toString method
	@Override
	public String toString() {
		return "Person{name='" + name + "', age=" + age + "}";
	}
}

public class Main {
	public static void main(String[] args) {
		Person person = new Person("Alice", 30);
		
		
		// Using the overriden toString method
		System.out.println(person); // Automatically calls person.toString()
	}
}
```

1.  **original toString**: if toString is not overridden, `Person` would inherit the default method from the `Object` class, which outputs `Person@HashCode`
2.  **custom toString**:
	-  the method is overridden using the `@Override` annotation
	-  a meaningful string is returned, displaying the `name` and `age` attributes
3.  **using toString**:
	-  when `System.out.println(person)` is called, the toString method is automatically invoked
	-  the custom string representation is printed: `Person{name='Alice', age=30}`

if the `@Override` annotation is omitted, the code will still work, but:
-  **potential errors**: if the method signature is incorrect (e.g. `tostring()` instead of `toString()`, the compiler won't throw an error, and the default toString method from `Object` will be used)
-  **readability**: the absence of `@Override` can confuse other developers, making it unclear whether the method is intended to override or is a new method

**benefits of @Override**
-  **error prevention**: ensures correct overriding of superclass methods
-  **improves debugging**: overridden methods like toString provide meaningful representations of objects, making logs and debugging easier
-  **code clarity**: clearly indicates the purpose of the method to other developers

# 2. shallow copy

-  creates a new object but shares references for any non-primitive fields
-  changes made to shared references affect both the original and the copy

```java
import java.util.ArrayList;
import java.util.List;

public class Person {
    private String name;
    private List<String> hobbies;

    public Person(String name, List<String> hobbies) {
        this.name = name;
        this.hobbies = hobbies; // Shared reference
    }

    @Override
    public String toString() {
        return "Person{name='" + name + "', hobbies=" + hobbies + '}';
    }
}

public class Main {
    public static void main(String[] args) {
        List<String> hobbies = new ArrayList<>();
        hobbies.add("Reading");
        hobbies.add("Swimming");

        Person original = new Person("Alice", hobbies);
        Person shallowCopy = new Person("Alice", hobbies); // Shallow copy

        // Modify the shared list
        hobbies.add("Gaming");

        System.out.println(original); // Person{name='Alice', hobbies=[Reading, Swimming, Gaming]}
        System.out.println(shallowCopy); // Person{name='Alice', hobbies=[Reading, Swimming, Gaming]}
    }
}
```

-  both `original` and `shallowCopy` share the same `hobbies` list
-  modifying the `hobbies` list reflects both objects since they share the same reference

# 3. deep copy

-  creates a new object and duplicates all fields, including non-primitive ones
-  this ensures that the new object is independent of the original

```java
import java.util.ArrayList;
import java.util.List;

public class Person {
    private String name;
    private List<String> hobbies;

    public Person(String name, List<String> hobbies) {
        this.name = name;
        this.hobbies = new ArrayList<>(hobbies); // Deep copy of the list
    }

    @Override
    public String toString() {
        return "Person{name='" + name + "', hobbies=" + hobbies + '}';
    }
}

public class Main {
    public static void main(String[] args) {
        List<String> hobbies = new ArrayList<>();
        hobbies.add("Reading");
        hobbies.add("Swimming");

        Person original = new Person("Alice", hobbies);
        Person deepCopy = new Person("Alice", hobbies); // Deep copy

        // Modify the original list
        hobbies.add("Gaming");

        System.out.println(original); // Person{name='Alice', hobbies=[Reading, Swimming, Gaming]}
        System.out.println(deepCopy); // Person{name='Alice', hobbies=[Reading, Swimming]}
    }
}
```

-  the `hobbies` list is copied using `new ArrayList<>(hobbies)`
-  modifications to the original list do not affect the deep copy since it uses its own independent list