
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