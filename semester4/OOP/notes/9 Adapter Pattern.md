The Adapter Pattern is a **structural design pattern** that allows two
incompatible interfaces to work together.

Commonly used when integrating third-party libraries or legacy code into
modern applications.

Also Known As: **Wrapper Pattern**

## Problem

A stock market app downloads **XML-based** stock data from multiple sources.

A third-party analytics library is introduced to enhance the app, but it only supports **JSON** data.

Directly modifying the library to accept XML is risky (may break existing code) or
impossible (source code unavailable)

## Solution

Allows seamless integration of new features without modifying existing systems.

-  Decouples the app from the third-party library, making it flexible for future changes.
-  Follows the Open/Closed Principle – adapts behaviour without modifying existing classes.

### How it works

The adapter wraps the XML-based system.

It converts XML to JSON behind the scenes.

The analytics library receives JSON as expected.

The original system remains unchanged and unaware of the adapter.

### Structure

The Client is a class that contains the existing business logic of the program

The Client Interface describes a protocol that other classes must follow to be able to collaborate with the client code

The Service is some useful class (usually 3rd-party or legacy). The client can’t use this class directly because it has an incompatible interface

The Adapter is a class that’s able to work with both the client and the service: it implements the client interface, while wrapping the service object. The adapter receives calls from the client via the client interface and translates them into calls to the wrapped service object in a format it can understand.

The client code doesn’t get coupled to the concrete adapter class as long as it works with the adapter via the client interface. Thanks to this, you can introduce
new types of adapters into the program without breaking the existing client code.
This can be useful when the interface of the service class gets changed or
replaced: you can just create a new adapter class without changing the client code.

## When to Use the Adapter Pattern?

You need to integrate an existing class that has an incompatible interface with
your system.

You’re working with legacy code or third-party libraries that cannot be modified.

You want to reuse multiple subclasses that lack common functionality without
modifying the superclass.

## How to Implement

Identify Incompatible Classes
-  **Service Class** (unchangeable) - A third-party, legacy, or dependency- heavy class 
-  **Client Class** -  Needs to use the service class but has an incompatible interface.

Define a Common interface
-  Create a client-friendly interface that defines how the client expects to communicate with the service.

Create the Adapter Class
-  Make it implement the client interface (methods initially empty).
-  Store a reference to the service class in a field, initialised via the constructor.

Implement the Adapter Methods
-  Delegate most of the work to the service object
-  Convert interface/data format as needed

## Pros and Cons

**Single Responsibility Principle**. You can separate the interface or data conversion code from the primary business logic of the program

**Open/Closed Principle**. You can introduce new types of adapters into the
program without breaking the existing client code, as long as they work with the
adapters through the client interface.

**The overall complexity of the code increases** because you need to introduce a
set of new interfaces and classes. Sometimes it’s **simpler just to change the**
**service class** so that it matches the rest of your code