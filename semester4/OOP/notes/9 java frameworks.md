## why use frameworks?

Speeds up development
Encourages best practices
Reduces code duplication
Provides built-in functionalities

# Hibernate

an **ORM** (Object-Relational Mapping) framework for managing databases in Java
Converts Java objects into database records
Supports HQL (Hibernate Query Language)
Works with multiple databases
(MySQL, PostgreSQL, etc.)

-  takes all your memory (objects) and puts it in a database

# Spring Framework

the most widely used enterprise-level framework for building Java applications.

**Spring Boot**: Simplifies application development
**Spring MVC**: Supports web applications
**Spring Data**: Simplifies database access
**Spring Security**: Manages authentication and authorisation

MVC - model controller view
-  a user writes instagram.com, you send a request to the web server
-  the controller contacts model
-  model talks to the database
-  model returns data to the controller
-  controller decides how to send the web page back

# JavaServer Faces (JSF)

a Java web framework for building user interfaces
Uses XML-based templates for UI
Supports event handling and component-based architecture

# Framework vs library

***not coming up on the exam***

| Definition         | A collection of pre-written code that developers can call to perform specific tasks. | A complete structure for building applications, enforcing a specific way to write code     |
| ------------------ | ------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------ |
| Control Flow       | You call the library methods when needed.                                            | The framework controls when and how your code is executed (Inversion of<br>Control - IoC). |
| Flexibility        | You can use only what you need, mix with other libraries.                            | You must follow the framework’s structure and conventions                                  |
| Example            | Apache Commons (String manipulation, file handling)                                  | Spring Framework (Enforces MVC structure for web apps)                                     |
| Who is in control? | Developer decides when and how to use it.                                            | Framework dictates how the code should be structured and executed.                         |
