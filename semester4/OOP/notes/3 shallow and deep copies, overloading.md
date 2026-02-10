
### compiling with multiple classes in one file

 **file structure with multiple classes**:
-  only one class can be `public` and must match the filename
-  other classes are package-private and accessible only within the same package
**compilation process**:
-  compiling the file generates separate `.class` files for each class

```java
public class MainClass {
	public static void main(String[] args) {
		HelperClass.sayHello();
	}
}

class HelperClass {
	public static void sayHello() {
		System.out.println("Hello from HelperClass!");
	}
}
```

```java
Fridge fridge = new Fridge(50);
```

`Fridge` = **class name, your data type**
`fridge` = **variable name** (**reference** holds the memory address of the Fridge object)
`new` = **keyword** (used to create a new object in the memory)
`Fridge(50)` = call to the **constructor** of the Fridge class (initialises the Fridge object with a balance of 50 (or other parameters))

```java
Fridge b = new Fridge(50);
Fridge abc = new Fridge(50);
Fridge fRiDgE = new Fridge(50);
```

### reference types in java

**what is a reference type?**
-  a variable that stores the **memory address** of an object, not the object itself
-  examples: strings, arrays, custom objects

**passing references to methods**:
-  java passes **a copy of the reference** (not the actual object)
-  changes made to the object **inside the method** affect the original object

### passing primitive types to methods

```java
public class PrimitiveExample{
	public static void modifyValue(int num) {
		num = 100; // This only changes the local copy inside the method
	}
	
	public static void main(String[] args) {
		int number = 1;
		modifyValue(number);
		System.out.println(number); // Output: 1 (unchanged)
	}
}
```

-  when `modifyValue(number)` is called, a **copy** of the value stored in number is passed to the method
-  the parameter `num` holds the copy of the value
-  changing `num` inside the method does **not** affect the original number in the main method
-  **primitive types are passed by value**, meaning changes inside the method are limited to the local copy

## passing references to methods

```java
public class ReferenceExample {
	public static void modifyArray(int[] arr) {
		arr[0] = 100; // Changes the original array
	}
	
	public static void main(String[] args) {
		int[] numbers = {1, 2, 3};
		modifyArray(numbers);
		System.out.println(numbers[0]); // Output: 100
	}
}
```

-  `numbers` variable pointing to an array in memory
-  a method modifying the same array through its reference

## arrays and arrayLists

**arrays**:
-  fixed size, reference-type behaviour
-  modifications within methods affect the original array

```java
int[] numbers = {1, 2, 3};
modifyArray(numbers);
```

```java
public static void modifyArray(int[] arr)
{
	arr[0] = 42;
}
```

**arrayLists**:
-  a resizable version of arrays, also reference types
-  adding, removing or modifying elements affects the original list

```java
ArrayList<String> names = new ArrayList<>();
modifyList(names);
```

```java
public static void modifyList(ArrayList<String> list)
{
	list.add("Hello");
}
```

## shallow copy

-  a copy of the **reference**, not the actual object
-  both the original and the copied reference point to the **same object** in memory
-  modifications to the object via one reference affect the other reference because they share the same memory

```java
Car car1 = new Car("Toyota");
Car car2 = car1; // Both refer to the same object
```

```java
class Person {
	String name;
	
	Person(String name) {
		this.name = name;
	}
}

public class Main {
	public static void main(String[] args) {
		Person original = new Person("Alice");
		Person shallowPerson = original; // Shallow copy
		
		shallowPerson.name = "Bob"; // Modifies the shared object
		System.out.println(original.name); // Output: Bob
	}
}
```

both `original.name` and `shallowPerson.name` reflect the same value
both `original.name` and `shallowPerson.name` reflect the same change

## deep copy

-  a new object is created, and all fields are **manually copied** or copied using a constructor
-  the original and the copied objects are **completely independent** (no shared memory)
-  changes to one object do not affect the other

```java
class Car {
	String brand;
	double price;
	
	// Constructor
	public Car(String brand, double price){
		this.brand = brand;
		this.price = price;
	}
	
	// Method to create a deep copy of the object
	public Car copyCar() {
		return a; // return the new independent object
	}
}

public static void main(String[] args) {
	// original car
	Car original = new Car("Toyota", 30000.0);
	
	// create a deep copy using the copyCar method
	Car copied = original.copyCar();
}
```

```java
class Car {
	String brand;
	double price;
	
	// constructor
	public Car(String brand, double price) {
		this.brand = brand;
		this.price = price;
	}
	
	public Car(Car other) {
		this.brand = other.brand;
	}
	
	// method to create a deep copy of the object
	public Car copyCar() {
		Car a = new Car(this.brand, this.price); // use constructor to copy fields
		return a; // return the new independent object
	}
}
```