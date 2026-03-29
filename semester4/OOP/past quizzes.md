# Quiz 1

Q1. Which of the following are **features of Java**? (one or more)
a. Object-oriented
b. Automatic memory management (garbage collection)
c. Platform independent
d. Strong typing of variables
e. The `main` method is the entry point of Java applications

Q2. Consider the following code:
```java
class Engine {
	void start() {}
}

class Car {
	private Engine engn;
	
	public Car(Engine engine) {
		engn = engine;
	}
}
```
What type of relationship is demonstrated between Car and Engine? (one)
a. Aggregation (weak has-a)
b. Association
c. Composition (strong has-a)
d. Encapsulation
e. Inheritance

Q3. Which statement(s) about constructors in Java is/are TRUE? (one or more)
a.  A constructor is called when an object is created
b. A constructor must have a return type
c. A constructor **can** have the same name as any method
d. A constructor can exist without a class
e. There is no such thing as a constructor in Java

Q4. Consider the code:
```java
class Student {  
    private int age;
  
    public Student(int a) {

        age = -1;

        if (age > 18 )  
              age = a;  
    }  
}

public class Main {  
    public static void main(String[] args) {  
        Student s = new Student(17);  
        System.out.println(s.age);  
    }  
}
```
Why does this code **NOT compile**? (one or more)
a. `age` is private and accessed directly
b. The constructor assigns the wrong value
c. The class `Student` must be private
d. The constructor parameter hides the field

Q5. Which of the following are **core principles of Object-Oriented Programming**? (one or more)
a. Abstraction
b. Encapsulation
c. Polymorphism
d. Compilation
e. Inheritance

# Quiz 2

Q1. What will happen if two overloaded methods in the same class have the same number and types of parameters but different return types? (one)
a. Compiler will choose based on return type
b. Compiler will choose the most specific return type
c. **Runtime** error due to ambiguity
d. None of the above

Q2. What will be the output of the following Java program? (one)
```java
class TypePromotionTest {
	void show(int a) {
		System.out.println("int");
	}
	
	void show(double a) {
		System.out.println("double");
	}
	
	public static void main(String[] args) {
		TypePromotionTest obj = new TypePromotionTest();
		obj.show(10L); // What happens here?
	}
}
```

a. int
b. double
c. Compilation Error
d. None of the above

Q3. 
```java
class Test {
	int a;
	int b;
	
	public Test() {
		// blank - offer some choices
		System.out.println("Default Constructor");
	}
	
	public Test(int x) {
		// blank - offer some choices
		this.a = x;
		System.out.println("One-parameter Constructor");
	}
	
	public Test(int x, int y) {
		this.a = x;
		this.b = y;
		System.out.println("Two-parameter Constructor");
	}
	
	public static void main(String[] args) {
		Test obj = new Test();
	}
}
```

Expected Output when `new Test();` runs correctly:
**Two-parameter Constructor**
**One-parameter Constructor**
**Default Constructor**

Q4. What will be the output of the following code? (one)
```java
class Parent {
	void show() { System.out.println("Parent"); }
}

class Child extends Parent {
	private void show() { System.out.println("Child"); }
}

public class Test {
	public static void main(String[] args) {
		Parent obj = new Child();
		obj.show();
	}
}
```

a. Child
b. Runtime error
c. Compilation error
d. Parent

Q5. Consider the following statements about class interactions in Java. Which one is **correct**? (one)
a. Two classes can interact **only through inheritance**.
b. If a class **has an instance of another class as a field**, it is an example of **composition**.
c. A class **cannot** have a reference to an instance of another class.
d. A class can only interact with another class if they are **static**.

# Quiz 3

Q1. Which of these statements about Java Lists are true? (one or more)
a. `LinkedList` maintains insertion order.
b. `List<?> list = new ArrayList<String>()` is valid.
c. `List` is an interface.
d. `ArrayList` allows duplicates.

Q2. Which of the following statements about the Observer Pattern are true? (one or more)
a. The Observer Pattern promotes **loose coupling** because the subject does not need to know the concrete implementations of its observers.
b. Real-world examples of the Observer Pattern include **event-driven programming**, such as GUI event listeners and the **Publish-Subscribe** model in messaging systems.
c. The Observer Pattern is a **behavioural pattern** that allows an object to notify multiple dependent objects when its state changes.
d. Unlike the Mediator Pattern, where objects communicate **indirectly** through a central mediator, the Observer Pattern allows **direct** communication between the subject and its observers.

Q3. Which data structures support random access in Java? (one or more)
a. String
b. HashMap
c. Array
d. ArrayList

Q4. What can a node in a chain of responsibility do? (one or more)
a. Do nothing
b. Throw an exception
c. Handle the request
d. Pass the request along

Q5. A developer wants to inject a DatabaseConnection dependency into a Repository class. Which type of Dependency Injection is used in this case? (one)
```java
class Repository {
	private DatabaseConnection db;
	public Repository(DatabaseConnection db) {
		this.db = db;
	}
}
```

a. Constructor Injection
b. Local injection
c. There is no name for such thing
d. Setter injection

Q6. Which of the following will compile in Java? (one or more)
a. `List<?> integers = new ArrayList<Double>();`
b. `List<Boolean> bool = new LinkedList<Short>();`
c. `List<Object> strings = new ArrayList<Double>();`
d. `List<? extends Number> nums = new ArrayList<Integer>();`

Q7. Which of these patterns reduces coupling between components? (one or more)
a. Chain of Responsibility
b. Decorator
c. Mediator
d. Factory Method