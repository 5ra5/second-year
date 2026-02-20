# `GameLobby.Java`

player = interface (sudo abstract - define behaviour)
-  place where we declare, but not implement communication methods with mediator
-  `GameLobby` can communicate with everything that inherits Player interface

`abstractPlayer` = abstract class (implement everything that will be the same for all player types)

`abstractPlayer` is inherited by `AlPlayer`, `HumanPlayer`, Spectator (all the differences and specifics of each type)

we can store any type of player, if we add a new player type, we don't need to modify anything
-  you don't need 3 different arrays for each type of player, but have all of them together
 -  "this list will hold objects that follow the Player contract"
 -  each object is an instance of a different type of player
 -  you are only allowed to use methods defined in Player
```java
List<Player> players = new ArrayList<>();
```

# outer and inner classes

**outer class** = a regular class that is not nested inside another class
example: classes A, B and Test which has a main function know of each other and can communicate between each other, but they don't live inside one another

characteristics
-  contains variables and methods
-  cannot be static (it's a top level class so it cannot be shared with anybody)
-  can be public or private
-  can be instantiated directly

**inner class** = class inside another outer class

characteristics
-  has access to outer class variables and methods, even if all attributes and functions of the outer class are private
-  **requires an instance of the outer class to be created and used**
-  used for logically grouping related code
-  useful when a class is only relevant to another class and should not be used outside
-  bad practice because it is confusing - try to avoid as much as possible

**static inner class**: no longer belongs to an instance of the outer class
 -  behaves like an independent class inside the outer class
 -  it does NOT need an instance of the outer class to be created
 -  it CANNOT access non-static members (instance variables/methods) of the outer class
 -  it can be instantiated just like a normal class, using `Outer.StaticInner`
 -  also bad practice to use

# list vs arraylist

## list

-  `list<e>` = interface that defines a sequence of something
-  does not store data - it provides a contract that different implementations must follow (`ArrayList, LinkedList`)

## arraylist

-  `ArrayList<E>` = concrete implementation of `list<e>` interface
-  uses dynamic array to store elements

opposite of a linked list:
-  fast random access
-  slow insertion and deletion

# loose coupling

a design principle that minimises connections between components in a system: we rely on an abstractions (interfaces or abstract classes) of something rather than specific implementations
-  more flexible, more scalable and more maintainable

so if you want to change a class or an interface, we only need to change the abstractions