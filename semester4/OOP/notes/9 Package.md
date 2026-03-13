# Java Program Structure

Components:
-  **Package**: Defines a namespace to organise code.
-  **Class**: The blueprint for objects.
-  **Methods**: Perform actions in a class.
-  **Main Method**: The entry point of a Java application.

package com.example; --> Groups related classes.
`public class Main` --> Defines a class.
`public static void main(String[] args)` --> The main method, execution starts here.
```java
package com.example; // Package declaration (optional)

public class Main { // Class declaration
	public static void main(String[] args) { // Entry point
		System.out.println("Hello, Java!");
	}
}
```

# What is a Package in Java?

-  A package is a way to group related Java classes together.
-  It provides organisation, reusability, and access control.
-  Packages help prevent name conflicts between classes.

**Encapsulation** – Controls access to classes.
Code Organisation – Helps manage large code bases.
Avoids **Naming Conflicts** – Prevents different libraries from having the same class names.
**Modular** Development – Makes maintenance and collaboration easier.
!!! Each **class in the same folder should have the same package** declaration. !!!

## Package Structure
When you define a package, Java organises files in directories
com.example.utils corresponds to the folder com/example/utils/
Java uses dot notation (.) to represent folder hierarchy

```java
package com.example; // Package declaration (optional)

public class Main { // Class declaration
	public static void main(String[] args) { // Entry point
		System.out.println("Hello, Java!");
	}
}
```

## How to Use a Package?

`javac -d . com/example/utils/MathUtils.java com/example/Main.java`
`java com.example.Main`

```java
import com.example.utils.MathUtils; // Importing a class

public class Main {
	public static void main(String[] args) {
		int sum = MathUtils.add(5, 3);
		System.out.println("Sum: " + sum);
	}
}
```

## Java Built-in Packages

`java.lang` (automatically imported)
-  String, Math, System

`java.util` (utility classes)
-  List, ArrayList, HashMap

`java.io` (file handling)
-  File, BufferedReader

`java.net` (networking)
-  URL, Socket

`java.sql` (database connectivity)
-  Connection, Statement

## Using Build Tools

**Maven** (Dependency Management)
-  Creates a project structure automatically.
-  Handles external dependencies.
-  Uses XML

**Gradle** (Alternative to Maven)
-  Uses Groovy or Kotlin scripts instead of XML.