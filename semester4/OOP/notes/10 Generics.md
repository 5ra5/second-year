## What is Generic?

A feature in Java that allows classes, interfaces, and methods to operate on any data type without sacrificing type safety.

Generics enable **parameterised types**, meaning you can write a class or method where the **type is a placeholder** (like T, E, K, V), and it will be specified later when the code is used.

```java
class Box<T> {
	private T value;
	
	public void set(T value) {
		this.value = value;
	}
	
	public T get() {
		return value;
	}
}

// List<String> list = newArrayList<>();
Box<String> stringBox = new Box<>();
stringBox.set("Hello");
String s = stringBox.get(); // No casting needed
```
Generics = **Write once, use with any type** (String, Integer, custom classes, etc.)

## Syntax of Generics

T is a **type parameter** - can be replaced with any actual type (e.g., String, Integer).
```java
class Box<T>{
	private T value;
	
	public void set(T value) {this.value = value; }
	public T get() {return value; }
}

Box<String> stringBox = new Box<>();
stringBox.set("Janet");
```

## Common Type Parameters

| Symbol | Meaning     | Where It's Used                        |
| ------ | ----------- | -------------------------------------- |
| T      | **Type**    | Generic classes and methods (`Box<T>`) |
| E      | **Element** | Used in **collections** (`List<E>`)    |
| K      | **Key**     | Used in **maps** (`Map<K, V>`)         |
| V      | **Value**   | Used in **maps** (`Map<K, V>`)         |

### Can I Use Any Letter in Generics?

Technically, **Yes**.

You can use ***any valid identifier*** (not just a single letter) as your type parameter in generics.
```java
class Box<Banana> {
	private Banana item;
	public void set(Banana item) {this.item = item; }
	public Banana get() { return item; }
}
```

This is valid Java -- but...

### But Please Don't

By convention, we use:
-  **T** for Type
-  **E** for Element
-  **K, V** for Key and Value
-  **N** for Number

These are well understood and expected by other developers.

## Generic Methods

A generic method defines its own type parameter (like `<T>`) that can be used within its parameter list and return type.

`<T>` appears before the return type -> this is required.
```java
public <T> void printArray(T[] array) {
	for (T element : array) {
		System.out.println(element);
	}
}

String[] words = {"Hello", "World"};
Integer[] numbers = {1, 2, 3};

printArray(words); // prints each word
printArray(numbers); // prints each number
```

## Bounded Types

Sometimes you want your generic type to be limited to a specific type or its subclasses, e.g., only numbers.
```java
public <T extends Number> void printDouble(T value) {
	System.out.println(value.doubleValue());
}
```

This method accepts:
-  Integer
-  Double
-  Float
-  But not String or Booleans

## Wildcards: ?

The **?** wildcard means "some unknown type."
```java
public void printAnything(List<?> list) {
	for (Object item : list) {
		System.out.println(item);
	}
}
```

## Generic Method vs. Wildcard Parameter

Use **`<T>`** when:
-  You want the method to know and work with a specific type
-  You want to return or pass around that type

Use **`<?>`** when:
-  You just want to read a list (or collection)
-  You don't care what's inside, just need to loop over it

## Wildcards - super and extend

**"? extends T"** -> "Some unknown subtype of T (maybe T, maybe a child)"
**"? super T"** -> "Some unknown supertype of T (maybe T, maybe a parent)"

**extends** = Java is protecting you from putting something too general into a more specific type

**super** = Java is protecting you from assuming a specific return type from a more general container