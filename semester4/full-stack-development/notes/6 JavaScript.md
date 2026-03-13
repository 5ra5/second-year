
**lecture**
# basics

-  1999
-  frontend
**difference between Java and JavaScript**
-  look similar because JavaScript was based on Java
-  Java static and OOP, JS dynamic and not OOP

`node` = JS interpreter
-  good to test out things and debug

list comprehension
```js
let names = ['John', 'Paul', 'Georgr', 'Ringo'].forEach(x)=>console.log(x));
```

output:
```
John
Paul
George
Ringo
```

**data types**
```js
strings "A"
ints 34
floats 42.0
boolean true, false
lists [1,2,3], [1,'a',5.0]
dictionaries {"name":"Michael"} // you need to use double quotes in JS
null // None - something that doesn't have a value (an empty box)
undefined // something that doesn't exist (no box)
```

**variables**
```js
let, const

let a = 'A';
const b = 5;
```

`let` = mutable, can change the value
`const` = value cannot change at runtime

```js
const API_SERVER_LOCATION = "http://127.0.0.1:8000"
```
-  we use const for things that are not meant to be changed
-  use upper case letters to name const variables
-  const variables optimise your program a lot because they don't make compiler do a lot of work like when you change c from something short to something very long
```js
let c = 'Hello';
c = "ajdshkjasdhgkjajdfghakj"
const d = 'Hello';
```


**operators**
```js
5+6
5-6
5*6
5**2
5/2
10%3
a++; // python a += 1
b--; // python a -= 1
```

`%` = comes up a lot in job interviews (fizz/buzz example)

**2 types of equality in JS**
JS does conversion on the run type inversion
does the value match?
```js
// this would be false in python
> 5 == '5'
true

> 5 != '5'
false

> 5 !== '5'
true
```

does the value and the data type match?
```js
> 5 === '5'
false
```

**example of syntax**
```js
let temperature = 32;
/// &&, ||,
if (temperature > 50){
	console.log("too hot")
}
else if (temperature == 32){
	console.log("just right")
}
else{
	console.log("everything else")
}
```

**switch statement**
-  important to use `break` with each case
```js
let day = 5;
switch(day){
	case 1:
		console.log("Monday");
		break;
	case 2:
		console.log("Tuesday");
		break;
	default:
		cosole.log("day");
		break;
}
```

**loops**
```js
for (let i=0; i<500; i++){
	console.log(i);
}

while(){
	...
}

do{
	...
}while()
```

**traversing through an array**
```js
let names = ['A', 'B', 'C', 'D'];
for(let i=0; i < names.length; i++){
	console.log(names[i]);
}

// optimised version
for(let name of names){
	console.log(name)
}
```

very common: passing functions as an argument to another function
```js
function print(x){
	console.log(x);
}

name.forEach(print);

// optimised version - anonymous function
names.forEach(function(x){
	console.log(x);
});

// even more optimised
(x)=>console.log(x)
names.forEach((x)=>console.log(x))
```

two identical things - 1 is just a shortcut
```js
let square = (x)=>x**2; // 1

function square(x){ // 2
	return x**2;
}
```

an example of a value of a variable being a function
```js
{
	"name":"Michael",
	"sayName": ()=>console.log("Michael");
}

nm.sayName();
nm['sayName']();
nm['sayName'] = ()=>{}
```

using 2 values in a function
```js
(x,y)=>x+y;
```

**mapping & filtering**
applying a function to each name in the array - mapping
```js
let names = ['John', 'Mark', 'Luke'];
names.map((x) => 'hello $(x)')
```

**website**

**JavaScript** manages the _interaction_ — what happens when you click a button, how a form validates input before submitting, how new data appears on the page without a reload. It's how the page _behaves_.

### JavaScript in the Browser

JavaScript in the browser has three main functions:
- **Handling user events and input** — e.g. button presses, form filling, key presses
- **Updating the HTML and CSS on the page** — e.g. showing an error message or a confirmation dialog without reloading the page
- **Requesting and sending data to remote servers** — e.g. talking to your Django REST API to fetch or submit data

written inside `<script>` tags. Three ways to include it:

**1. Inline - directly in the HTML file**
write the script before the closing `</body>` tag, after all your page content:
```html
<html>
	<head></head>
	<body>
		<!--Web page content goes here -->
		<script>
			console.log("Hello JavaScript");
		</script>
	</body>
</html>
```

**2. Local file - using the `src` attribute**
if you have a separate `.js` file (e.g. `sayhello.js`), you can link to it:
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

**3. Remote file - loading a library from a CDN**
External libraries (like jQuery) are often loaded from a CDN (Content Delivery Network). The library provides a URL you copy into your HTML:
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

in practice, you'll often use all three together:
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

**script loading order** = Scripts load in order from top to bottom. External libraries should be loaded first (in the `<head>`), so that your own code can use them. Page-specific inline scripts go at the bottom of the `<body>`, after all the HTML content has loaded.

## JavaScript Fundamentals

### `console.log()`

```js
console.log("Hello");
console.log(42);
console.log("Name:", name);
```

-  in Node it prints to the terminal
-  in the browser it prints to the developer console

### data types
|Type|JavaScript Example|Python Equivalent|
|---|---|---|
|String|`"hello"` or `'hello'`|`"hello"` or `'hello'`|
|Number|`42` or `3.14`|`int` / `float`|
|Boolean|`true` or `false`|`True` or `False`|
|Array|`[1, 2, 3]`|`[1, 2, 3]` (list)|
|Object|`{"name": "Alice", "age": 21}`|`{"name": "Alice", "age": 21}` (dict)|
|null|`null`|`None`|
|undefined|`undefined`|_(no equivalent)_|
note:
-  **Booleans are lowercase** — `true` and `false`, not `True` and `False`.
-  **JavaScript has one number type**, not separate integers and floats. Both `42` and `3.14` are just "numbers".
-  **`null` and `undefined`** — JavaScript has _two_ ways to represent "nothing". `null` means "deliberately empty" (like Python's `None`). `undefined` means "hasn't been assigned a value yet". You'll mostly encounter `undefined` when you access a variable that hasn't been set.
-  **Arrays** are like Python lists — they can hold mixed types, e.g. `["hello", 1, 3.14, true]`.
-  **Objects** are like Python dictionaries — key-value pairs. This is where the term **JSON** (JavaScript Object Notation) comes from.

### declaring variables

two keywords for declaring variables

-  `let` = declares a variable that can be reassigned:
```js
let score = 0;
score = 10; // this is fine
```

-  `const` = declares a variable that cannot be reassigned:
```js
const pi = 3.14159;
pi = 3; // Error! Cannot reassign a const
```

**which one to use?** = Use `const` by default. Only use `let` when you know the value needs to change. This is a good habit — it makes your code easier to reason about because you can see at a glance which values might change and which won't.
-  You may also see `var` in older code and tutorials. It's the original way to declare variables in JavaScript, but `let` and `const` (introduced in 2015) are preferred because they behave more predictably. For this module, stick with `let` and `const`.