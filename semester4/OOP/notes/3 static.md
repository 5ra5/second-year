# static members

In Java, static members belong to the class rather than instances. This means:
-  Shared across all objects of the class
-  Loaded into memory once at class loading time
-  Can be accessed without creating an object

**types of static members:**

-  Static Variables – Shared across all instances
-  Static Methods – Can be called without an instance
-  Static Blocks – Executes once when the class loads
-  Static Inner Classes – A nested class that doesn’t need an outer class instance (don't use it)

## static variables - shared across objects

```java
class Counter {
	static int count = 0; // Static variable
	
	Counter() {
		count++; // Incrementing static variable
	}
	
	void displayCount() {
		System.out.println("Count: " + count);
	}
}
```

A static variable is common for all objects. 
Stored in the class memory, not in individual objects. 
All objects share the same static variable count.

## static methods - calling without an object

```java
class MathUtil {
	static int square(int num) {
		return num * num;
	}
	
	public static void main(String[] args) {
		System.out.println("Square of 5: " + MathUtil.square(5));
		// No object needed
	}
}
```

Static methods belong to the class, not instances. 
Cannot use this inside static methods.
Can only access other static members directly. 
Static methods can be called using the class name `(MathUtil.square(5))`. 
No need to create an instance.
-  useful when you want to create independent functions

## Static Blocks – Code That Runs Once

A static block executes once when the class is loaded, before the `main()` method. 
Used for one-time initialisation (e.g., database connections, constants). Static blocks execute first, even before `main()`

```java
class Example {
	static {
		System.out.println("Static block executed.");
	}
	public static void main(String[] args) {
		System.out.println("Main method executed.");
	}
}

-> output:
static block executed.
main method executed.
```



