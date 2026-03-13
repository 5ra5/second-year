An **exception** is an event that disrupts the normal flow of a program.
It occurs when something **unexpected** things happen.
```java
class Test {
	public static void main(String[] args)
	{
		int n = 10;
		int m = 0;
		int ans = n / m;
		System.out.println("Answer: " + ans);
	}
}
```

```
Exception in thread "main" java.lang.ArithmeticException: / by zero
	at test.main(test.java:6)
```

## Causes

-  Invalid user input
-  Device failure
-  Loss of network connection
-  Physical limitations (out-of-disk memory)
-  Code errors
-  Out of bound
-  Null reference
-  Type mismatch
-  Opening an unavailable file
-  Database errors
-  Arithmetic errors

## exception vs **error**

**Errors** are usually caused by serious problems that are outside the control of the program
-  out of memory
-  system crash

it’s usually not appropriate for a program to catch errors. Instead, the best course of action is usually to **log the error** **and exit** the program

**Exceptions** are used to handle errors that **can be recovered** from within the program
-  null reference
-  input/output errors
-  illegal argument is passed to a method

Exceptions **can be caught** and handled within a program, it’s common to include code to catch and handle exceptions in Java programs

By handling exceptions, you can provide more informative error messages to users and **prevent the program from crashing**.

## checked exceptions

Compile-time exceptions because these exceptions are checked at compile-time
by the compiler.

Must be handled using **try-catch** or declared using **throws**
-  IOException (File not found)
-  SQLException (Database errors)
-  InterruptedException (Thread interruptions)

```java
try {
	FileReader fr = new FileReader("file.txt");
} catch (IOException e) {
	System.out.println("File not found.");
}
```

## unchecked exceptions

The compiler will not check these exceptions at compile time.

Do not require explicit handling.
-  NullPointerException
-  ArrayIndexOutOfBoundsException
-  IllegalArgumentException

```java
int[] arr = new int[3];
System.out.println(arr[5]);
```

## try-catch block

A try-catch block in Java is a mechanism to handle exception. The try block
contains code that might thrown an exception and the catch block is used to
handles the exceptions if it occurs.

```java
try {
	int result = 10 / 0;
} catch (ArithmeticException e) {
	System.out.println("Cannot divide by zero!");
}
```

## finally block

The finally Block is used to execute important code regardless of whether an
exception occurs or not.

Used for releasing resources (closing files, DB connections)

```java
try {
	FileReader fr = new FileReader("file.txt");
} catch (IOException e) {
	System.out.println("File not found.");
} finally {
	System.out.println("Closing resources...");
}
```

## handling multiple exception

```java
try {
	// Code that may throw an exception
} catch (ArithmeticException e) {
	// Code to handle the exception
} catch(ArrayIndexOutOfBoundsException e){
	//Code to handle the anothert exception
}catch(NumberFormatException e){
	//Code to handle the anothert exception
}
```

## the throws keyword

Used in method signatures to declare exceptions
```java
void readFile() throws IOException {
	FileReader fr = new FileReader("file.txt");
}
```

used to manually throw exceptions
```java
throw new IllegalArgumentException("Invalid input");
```

```java
void checkAge(int age) throws InvalidAgeException {
	if (age < 18) {
		throw new InvalidAgeException("Age must be 18 or older");
	}
}
```

## how does JVM handle an exception?

1. The run-time system searches the call stack for an Exception handler
2. It starts searching from the method where the exception occurred and proceeds backward through the call stack.
3. If a handler is found, the exception is passed to it.
4. If no handler is found, the default exception handler terminates the program and prints the stack trace

```java
class Test {
	static int divideByZero(int a, int b) {
		int i = a / b;
		return i;
	}
	
	static int computeDivision(int a, int b) {
		int res = 0;
		// exception doesn't match
		try {
			res = divideByZero(a, b);
		}
		catch(NumberFromatException ex) {
			System.out.println("NumberFormatException is occurred");
		}
		return res;
	}
	
	public static void main(String args[]) {
		int a = 1;
		int b = 0;
		// appropriate exception handler
		try {
			int i = computeDivision(a, b);
		}
		catch (ArithmeticException ex) {
			System.out.println(ex.getMessage());
		}
	}
}
```

## common mistakes in exception handling

Catching **Exception** instead of specific exceptions

Swallowing exceptions (empty catch block)

Using exceptions for normal flow control

## best practices for writing robust exception handling

Always catch the most specific exception first.

Use meaningful exception messages.

Avoid suppressing exceptions (catch (Exception e) { })