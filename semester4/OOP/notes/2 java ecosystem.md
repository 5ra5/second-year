-  introduced at 1995 by Sun Microsystems
-  created by James Gosling
-  originally designed for interactive television systems
-  java programs are compiled into bytecode instead of machine code. it's essentially another layer of protection
-  this ensures that Java programs run on any device with a compatible JVM, which makes Java a very popular choice of a programming language because it eliminates platform-specific dependencies

**difference between C++ and Java**
C++
-  source code (.cpp) -> compiler -> assembly code -> assembler -> binary code (machine code)

Java
-  source code (.java) -> compiler(javac) -> bytecode (.class) -> JVM -> binary code (machine code) (one extra step)

**ecosystem**
-  JDK = development tools
-  JVM = runs java programs
-  JRE = bridges development and execution

## java basics

- **strong typing**  = variables must be declared with a specific type (int, string, etc.)

the main class
```java
public class Main {
	public static void main(String[] args){
		System.out.println("Hello, world");
	}
}
```

`public` - accessible to the JVM because it looks for the main method to begin execution
`static` - belongs to the class, not an instance
`void` - no return value
`String[] args` - used for command-line arguments

`system.out.println` = used to print messages to the console
```java
System.out.println("Hello, Java!"); // Prints with a newline
System.out.print("No newline"); // Prints without a newline
System.out.printf("Formatted number: %.2f", 3.14159) // Formatted output
```

**java input**
`scanner` class for input
```java
import java.util.Scanner;

public class InputExample{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter your name: ");
		String name = scanner.nextLine();
		System.out.println("Hello, " + name + "!");
	}
}
```

`nextLine()` = reads a line of text
`nextInt()`, `nextDouble()` = reads numbers

java data types - *might appear on the exam!*
2 main types: primitive and reference
-  a primitive type can be initialised very easily - it creates a new memory location and stores the object and the name of the object in this location
-  a reference type stores a reference that points to the memory location where the object or data is stored

**stack:** temporary storage for method execution, local variables and references
**heap:** long-term storage for objects and shared data, managed by the garbage collector
