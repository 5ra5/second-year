# What is JavaScript?

HTML - Structure & Content
CSS - Styling & Layout
JavaScript - Behaviour & Interaction

**JavaScript** manages the *interaction*:
-  what happens when you click a button
-  how a form validates input before submitting
-  how new data appears on the page without a reload
-  how the page *behaves*
-  the layer that makes a static page feel like an application

runs on browsers, servers (via `Node.js`), mobile devices and desktop applications

## What JavaScript Does in the Browser

three main functions:
-  **Handling user events and input** - e.g. button presses, form filling, key presses
-  **Updating the HTML and CSS on the page** - e.g. showing an error message or a confirmation dialog without reloading the page
-  **Requesting and sending data to remote servers** - e.g. talking to your Django REST API to fetch or submit data

# Running JavaScript

## Running JavaScript in the Browser

web page - JavaScript written inside the `<script>` tags
three ways to include it:

**1. Inline - directly in the HTML file**
write the script before closing `</body>` tag, after all your page content:
```html
<html>
	<head></head>
	<body>
		<!-- Web page content goes here -->
		<script>
			console.log("Hello JavaScript");
		</script>
	</body>
</html>
```

**2. Local file - using the `src` attribute**
if you have a separate `.js` file (e.g. `sayhello.js`), you can link to it:
-  `<script>` goes in the head now, not in the body
```js
// file: sayhello.js
console.log("Hello JavaScript");
```

```html
<html>
	<head>
		<title>Loading JS from a file</title>
		<script src="sayhello.js"></script>
	</head>
	<body>
		<!-- Web page content goes here -->
	</body>
</html>
```

**3. remote file - loading a library from a CDN**
external libraries (like jQuery) are often loaded from a CDN (Content Delivery Network)
the library provides a URL you copy into your HTML:
```html
<html>
	<head>
		<title>Loading jQuery from CDN</title>
		<script src="https://code.jquery.com/jquery-3.6.0.slim.min.js"></script>
	</head>
	<body>
		<!-- Web page content goes here -->
	</body>
</html>
```

in practice, all three are used together
```html
<html>
	<head>
		<title>Example using all three</title>
		<!-- Load external libraries first -->
		<script src="https://code.jquery.com/jquery-3.6.0.slim.min.js"></script>
		<!-- Then load our own JS files -->
		<script src="sayhello.js"></script>
	</head>
	<body>
		<!-- Web page content goes here -->
		<script>
			/* Page-specific JavaScript goes here */
		</script>
	</body>
</html>
```

**Script loading order**
Scripts load from top to bottom. Include JS in this order:
-  external libraries in head
-  local JS file in head
-  page-specific JS in the end of body

# JavaScript Fundamentals

## `console.log()`

```js
console.log("Hello");
console.log(42);
console.log("Name:", name);
```

node - prints to the terminal
browser - prints to the developer console

## data types

| Type      | JavaScript Example               | Python Equivalent                       |
| --------- | -------------------------------- | --------------------------------------- |
| String    | `"hello"` or `'hello'`           | `"hello"` or `'hello'`                  |
| Number    | `42` or `3.14`                   | `int`/`float`                           |
| Boolean   | `true` or `false`                | `True` or `False`                       |
| Array     | `[1, 2, 3]`                      | `[1, 2, 3]` (list)                      |
| Object    | `{"name" : "Alice", "age" : 21}` | `{"name" : "Alice", "age" : 21}` (dict) |
| null      | `null`                           | `None`                                  |
| undefined | `undefined`                      | *no equivalent*                         |
note:
-  **booleans are lowercase** - `true` and `false`, not `True` and `False`
-  **JavaScript has one number type**, not separate integers and floats. Both `42` and `3.14` are just "numbers".
-  `null` and `underfined` - `null` means "deliberately empty", `undefined` means "hasn't been assigned a value yet" (mostly encountered when you access a variable that hasn't been set)
-  **Arrays** are like python lists - they can hold mixed types, e.g. `["hello", 1, 3,14, true]`
-  **Objects** are like python dictionaries - key-value pairs

## Declaring Variables

-  `let` - declares a variable that can be reassigned:
```js
let score = 0;
score = 10; // this is fine
```

-  `const` - declares a variable that cannot be reassigned:
```js
const pi = 3.14159;
pi = 3; // Error! Cannot reassign a const
```

**Which one should I use?**
use `const` by default, only use `let` when you know the value needs to change

`var` - original way to declare variables in JavaScript 

## Operators

**Division difference**
python: `10 / 3` = `3.333...` and `10 // 3` = `3` (integer division)
JavaScript: only has `/`, which always gives a decimal result, there is no `//` operator

**Comparison Operators**

| Operator | Description           | **Example (where `x = 5`)** | **Result** |
| -------- | --------------------- | --------------------------- | ---------- |
| `==`     | Equal to (loose)      | `x == "5"`                  | `true`     |
| `===`    | Equal to (strict)     | `x === "5"`                 | `false`    |
| `!=`     | Not equal (loose)     | `x != "5"`                  | `false`    |
| `!==`    | Not equal (strict)    | `x !== "5"`                 | `true`     |
| `>`      | Greater than          | `x > 3`                     | `true`     |
| `<`      | Less than             | `x < 3`                     | `false`    |
| `>=`     | Greater than or equal | `x >= 5`                    | `true`     |
| `<=`     | Less than or equal    | `x <= 4`                    | `false`    |
`==` operator tries to convert values to the same type before comparing
`5 == "5"` is `true` because JavaScript converts the string `"5"` first
`===` operator does **no conversion** - both the value and the type must match

**always use `===`**

**Logical operators**

```js
if (x > 0 && x < 10){ }    // and
if (x === 5 || y === 5){ } // or
if (!(x === y)) { }        // not
```

## Type Coercion

| Expression   | Result  | Why?                                                            |
| ------------ | ------- | --------------------------------------------------------------- |
| `2 < 12`     | `true`  | Both numbers - straightforward                                  |
| `2 < "12"`   | `true`  | String `"12"` is converted to number `12`                       |
| `2 < "John"` | `false` | `"John"` can't be converted to a number, gives `NaN`            |
| `"2" < "12"` | `false` | Both strings - compared alphabetically, `"2"` comes after `"1"` |
| `"2" > "12"` | `true`  | Same reason - string comparison, not numeric                    |
type coercion - JavaScript automatically converts types to try to make an operation work

the safest approach: 
-  use `===` for comparisons
-  be explicit about types when doing arithmetic
-  if you want to convert a string to a number, use `Number("42")` or `parseInt("42")`

# Control Flow

## `if` / `else if` / `else`

```js
let temperature = 22;

if (temperature > 30) {
	console.log("It's hot");
} else if (temperature > 15) {
	console.log("It's mild");
} else {
	console.log("It's cold");
}
```

## `switch`

```js
let day = new Date().getDay(); // returns 0-6 (Sunday-Saturday)

switch (day) {
    case 0:
        console.log("Sunday");
        break;
    case 1:
        console.log("Monday");
        break;
    case 2:
        console.log("Tuesday");
        break;
    case 3:
        console.log("Wednesday");
        break;
    case 4:
        console.log("Thursday");
        break;
    case 5:
        console.log("Friday");
        break;
    case 6:
        console.log("Saturday");
        break;
}
```

-  `case` tests the variable against a value
-  `break` exits the switch block after a match is found

**don't forget `break`**
if you leave out `break`, JavaScript will "fall through" and execute the next case's code as well, even if it doesn't match

# Loops

## The Classic `for` loop

```js
for (let i = 0; i < 5; i++) {
	console.log(i);
}
```

```
0
1
2
3
4
```

example: looping through an array by index:
```js
let names = ['John', 'Paul', 'George', 'Ringo'];

for (let i = 0; i < names.length; i++) {
	console.log(names[i]);
}
```

```
John
Paul
George
Ringo
```

## `for...of` - Looping Over Values

use if you don't need the index
```js
let names = ['John', 'Paul', 'George', 'Ringo'];

for (let name of names) {
	console.log(name);
}
```

```
John
Paul
George
Ringo
```

## `forEach` - A Method on Arrays

calls a function for each element:
```js
let names = ['John', 'Paul', 'George', 'Ringo'];

names.forEach(function(name) {
	console.log(name);
})
```

written more concisely using an **arrow function**
```js
names.forEach(name => console.log(name));
```

-  use **`for...of`** when you just need each item
-  use the **classic** **`for`** when you need the index
-  use **`forEach`** when working with array methods and chaining operations

## `for...in` - Looping Over Object Keys

```js
let person = {"Name" : "Michael", "Age" : 42, "Title" : "Dr"};

for (let key in person) {
	console.log(key, person[key]);
}
```

```
Name Michael
Age 42
Title Dr
```

**`for...in` vs `for...of`**
-  use `for..of` for **arrays** (loops over values)
-  use `for..in` for **objects** (loops over keys)
-  using `for...in` on an array will give you the *index numbers* as strings, not the values

# Functions

## Function Declarations

use `function` keyword

```js
function greet(name) {
	console.log("Hello, " + name);
}

greet("Alice"); // Hello, Alice
```

## Returning Values

use `return` keyword
if a function doesn't have a `return` statement, it returns `undefined`
```js
function add(x, y) {
	return x + y;
}

let result = add(2, 3);
console.log(result); // 5
```

## Arrow Functions

**arrow functions** = shorter syntax for writing functions
```js
// Regular function
function add(x, y) {
	return x + y;
}

// Arrow function
const add = (x, y) => {
	return x + y;
};

// Arrow function - short form (single expression)
const add = (x, y) => x + y;
```

syntax:
1.  drop the `function` keyword
2.  put the parameters before a `=>` arrow
3.  if the function body is a single expression, drop the curly braces and the `return` - result returned automatically

```js
let numbers = [1, 2, 3, 4, 5];

// Double each number
let doubled = numbers.map(n => n * 2);
console.log(doubled) // [2, 4, 6, 8, 10]

// Keep only even numbers
let evens = numbers.filter(n => n % 2 === 0);
console.log(evens); // [2, 4]
```

**When to use which?**
-  use **regular functions** for named, reusable functions that you'll call multiple times
-  use **arrow functions** for short, inline callbacks - anywhere you'd use a `lamda` in Python

## Functions as Values

**functions are values**
you can:
-  store them in variables
-  pass them as arguments to other functions
-  return them from functions - like you would with a number or a string

**storing functions in variables**
when you write an arrow function, you're already doing this:
```js
const greet = (name) => console.log("Hello, " + name);
```

`greet` - variable that holds a function
you call it like any other function - `greet("Alice")`
you can also:
-  reassign it if you use `let`
-  pass it somewhere else
-  put it in an array

also works with regular functions:
```js
const sayHello = function(name) {
    console.log("Hello, " + name);
};

sayHello("Alice");  // Hello, Alice
```

**function expression** = creating a function and assigning it to a variable, rather than declaring it with a name

**passing functions as arguments (callbacks)**

```js
let names = ['John', 'Paul', 'George', 'Ringo'];
names.forEach(name => console.log(name));
```

-  the arrow function `name => console.log(name)` is being **passed** to `forEach` as an argument
- `forEach` *calls* that function once for each item in the array

**callback** = a function that is passed to another function

callbacks don't have to be anonymous arrow functions - you can pass any function by name
```js
function shout(name) {
	console.log(name.toUpperCase() + "!");
}

let names = ['John', 'Paul', 'George', 'Ringo'];
names.forEach(shout);
```

```
JOHN!
PAUL!
GEORGE!
RINGO!
```

note: `forEach(shout)`, not `forEach(shout())`
-  `shout` - the function itself (a value we're passing)
-  `shout()` - *calls* the function immediately and passes its **return value**

when you want to pass a function as a callback, you pass its *name* without parentheses

example: "when the button is clicked, call the `handleClick` function"
```js
button.addEventListener("click", handleClick);
```

-  passing `handleClick` as a callback
-  the browser will call it back when the click event happens
-  you don't call it yourself

in react: "call this when the user clicks"
```html
<button onClick={handleDelete}>Delete</button>
```

**a pattern you will see everywhere**
callbacks appear constantly in JavaScript:
-  handling user events
-  responding to network requests
-  running code after a timer
-  processing array data

# Debugging in the Browser

in browser:
the output of `console.log()` is **hidden from the user** and only visible through the browser's built-in developer tools (developer console)

## Errors in the Console

console also shows errors
if your JavaScript has a bug, the error message will appear there, along with the file name and line number where the problem occurred
-  you can click the line number to jump straight to the problematic code

**JavaScript is case-sensitive**

in python: `True` and `true` would be `NameError`
in JavaScript: `sayHello` and `sayhello` treated as completely different names

## The Console as a Playground

you can type JavaScript directly into the console and it will execute immediately
useful for:
-  testing small snippets of code
-  inspecting variables on the current page
-  experimenting with JavaScript features

# Summary


| Concept                     | Python                 | JavaScript                    |
| --------------------------- | ---------------------- | ----------------------------- |
| Print output                | `print()`              | `console.log()`               |
| Booleans                    | `True` / `False`       | `true` / `false`              |
| Null value                  | `None`                 | `null` / `undefined`          |
| Variable (mutable)          | `x = 5`                | `let x = 5;`                  |
| Variable (constant)         | -                      | `const x = 5;`                |
| Equality                    | `==`                   | `===` (always use strict)     |
| Logical and / or / not      | `and` / `or` / `not`   | `&&` / `\|\|` / `!`           |
| if / else if / else         | `if` / `elif` / `else` | `if` / `else if` / `else`     |
| For loop (range)            | `for i in range(n)`    | `for (let i = 0; i < n; i++)` |
| For loop (items)            | `for x in list:`       | `for (let x of array)`        |
| For loop (dict/object keys) | `for k in dict:`       | `for (let k in obj)`          |
| Define a function           | `def fn()`             | `function fn {}`              |
| Anonymous functon           | `lambda x: x + 1`      | `(x) => x + 1`                |
## Key takeaways

-  JavaScript is the **only** language that runs natively in the browser
-  use `let` and `const` to declare variables - prefer `const` by default
-  **always** use `===` and `!==` for comparisons to avoid type coercion bugs
-  functions are **values** - you can store them in variables and pass them as callbacks
-  the **developer console** is your primary debugging tool in the browser
-  JavaScript is **case-sensitive** - `myFunction` and `myfunction` are different names