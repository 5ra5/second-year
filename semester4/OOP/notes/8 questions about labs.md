## ternary/conditional operator

an alternative if-else statement
```java
a = productName != null ? productName : "Unkown";
```

```java
condition ? expression_if_true : expression_if_false;
```

## for

enhanced for-loop (for-each loop)
-  used to iterate over collections like `ArrayList`, `HashSet`, or arrays
-  eliminates the need for a traditional for loop with an index
```java
for (Player player : players) {
	...
}
```

example:
```java
String[] cars = {"Volvo", "BMW", "Ford", "Mazda"};
for (String abc : cars) {
	System.out.println(abc);
}
```

lab example:
```java
for (var player : players) {
	System.out.println(player.name)
}
```

question: why do we define a list of players instead of ArrayList of players?
-  you can do both, but list is a better design choice
```java
List<Player> players = new ArrayList<>();

list - interface
	add()
	remove()
	get()
	size()

ArrayList<Player> players = new ArrayList<>();
ArrayList - class

// we can easily modify List to be any of the lists listed	
List<Player> players = new ArrayList<>();
List<Player> players = new LinkedList<>();
stores something that behaves like List
ArrayList
LinkedList
Vector
CopyOnWriteArrayList
```

example:
```java
class Vehicle{
}

class Car implements Vehicle{
}

class Bike implements Vehicle{
}

Vehicle v = new Car();
// you can use the same variable for other things
v = new Bike();
v = new Car();
```

example in python
```python
class A:
	def plot_data():
		pass
	
class B:
	def update():
		pass

# you can put any type of data in the list
t = [A, B, A, B, 3, "hello", NULL]

# a problem with this - you have to specify which type of objects are you working with
for el in t:
	if typeof(el)=='class A':
		el.plot_data()
```

```java
// a holds any type of object
List<Object> a;
```