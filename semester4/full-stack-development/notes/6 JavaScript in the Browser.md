# The Document Object Model (DOM)

browser doesn't display the raw text of a HTML file, it **parses** it into a DOM
Document Object Model = structured, in-memory representation of a HTML file
-  a tree of **nodes**, where every HTML element becomes an object that JavaScript can read, modify, create, or delete
-  every node in the tree has a **parent** (except the root), zero or more **children**, and zero or more **siblings**
-  parent-child structure mirrors the nesting of your HTML tags directly
-  the root of the tree is always `document`

`document` = global object that JavaScript has access to automatically, without you needing to declare it
-  every selector and DOM operation starts from `document`

**The DOM is not your HTML file**
-  if JS modifies the DOM - e.g. adds a new `<li>` to that list - the change exists only in memory
-  the original `.html` file on disk is unchanged
-  if you reload the page, the DOM is rebuilt from the file and your changes disappear
-  **DOM is live, HTML file is static**

# Selecting Elements

to do anything with the DOM, you first need to get a **reference** you want to work with

## The Classic Methods

| Method                                 | What it selects                                   | Returns                          |
| -------------------------------------- | ------------------------------------------------- | -------------------------------- |
| `document.getElementById(id)`          | The single element with a matching `id` attribute | One element, or `null`           |
| `document.getElementByClassName(name)` | All elements with a matching `class` attribute    | An `HTMLCollection` (array-like) |
| `document.getElementsByTagName(tag)`   | All elements of a given tag type                  | An `HTMLCollection` (array-like) |
**`getElementsBy...` vs `getElementById`**
subtle difference:
-  `getELementById` is singular - IDs are unique, so it returns one element
-  `getElementsByClassName` and `gerElementsByTagName(tag)` - they can match many elements, so they return a collection

example: using all three on the same page:
```html
<html>
	<head>
		<title>Element selection example</title>
	</head>
	<body>
		<p>Paragraph 1</p>
		<p>Paragraph 2</p>
		<p class="myclass">Paragraph with class</p>
		<p class="myclass">Paragraph 2 with class</p>
		<p id="myparagraphid">Paragraph with identifier</p>
		<script>
			let allPTags = document.getElementsByTagName("p");
			console.log(allPTags);
			
			let allPClassTags = document.getElementsByClassName("myclass");
			console.log(allPClassTags);
			
			let specificTag = document.getElementById("myparagraphid");
			console.log(specificTag);
		</script>
	</body>
</html>
```

the console output breaks down as follows:
```
HTMLCollection(5) [p, p, p.myclass, p#myparagraphid] <- all <p> tags
HTMLCollection(2) [p.myclass, p.myclass]             <- class matches
<p id="myparagraphid">Paragraph with identifier</p>  <- single element by ID
```

## The Modern Approach: `querySelector`

classic methods: require you to decide upfront whether you're searching by tag, class or ID
modern alternative: `querySelector` and `querySelectorAll`: uses the same **CSS selector syntax** you already know, which makes it far more flexible

| Method                                | What it selects                               | Returns                   |
| ------------------------------------- | --------------------------------------------- | ------------------------- |
| `document.querySelector(selector)`    | The **first** element matching a CSS selector | One element, or `null`    |
| `document.querySelectorAll(selector)` | All elements matching a CSS selector          | A `NodeList` (array-like) |
you can use CSS selector you'd use in a stylesheet
-  tag names
-  classes with `.`
-  IDs with `#`
-  attribute selectors
-  combinators
-  ...

```js
// by ID - equivalent to getElementByID
document.querySelector("#myparagraphid");

// first element with class="myclass"
document.querySelector(".myclass");

// all elements with class="myclass"
document.querySelectorAll(".myclass");

// first <p> on the page
document.querySelect("p");

// all <li> elements inside a <ul>
document.querySelectorAll("ul li");

// an input with type="email"
document.querySelector("input[type='email']")'
```

## Reading & Modifying Elements

-  `innerHTML` for content
-  `value` for form inputs
-  `style` for CSS

## `innerHTML` - Reading and Changing Content

`innerHTML` = gives you the HTML content inside an element as a string
-  you can both read from it and write to it

to change the text inside `<p id="myparagraphid"> Paragraph with identifier</p>` to `"Hello from JavaScript"`:
```html
<html>
	<head>
		<title>innerHTML example</title>
	</head>
	<body>
		<p>Paragraph 1</p>
		<p>Paragraph 2</p>
		<p class="myclass">Paragraph with class</p>
        <p class="myclass">Paragraph 2 with class</p>
        <p id="myparagraphid">Paragraph with identifier</p>
        <script>
	        let specificPTag = document.querySelector("#myparagraphid");
	        specificPTag.innerHTML = "Hello from JavaScript";
	    </script>
	</body>
</html>
```

the DOM now looks like this - the original text is gone, replaced by what JavaScript wrote:
```html
<html>
  <head></head>
  <body>
    <p>Paragraph 1</p>
    <p>Paragraph 2</p>
    <p class="myclass">Paragraph with class</p>
    <p class="myclass">Paragraph 2 with class</p>
    <p id="myparagraphid">Hello from JavaScript</p>
    <script></script>
  </body>
</html>
```

**don't use `innerHTML` with untrusted data**
`innerHTML` interprets its value as HTML
-  setting it to user-supplied content can introduce **Cross-Site Scripting (XSS)** vulnerabilities
-  example: a malicious user could inject a `<script>` tag - if you're displaying content that a user has typed in, use `textContent` instead - it treats the value as plain text and never parses it as HTML

## `style` - changing CSS

CSS property names that contain hyphens (e.g. `background-color`) are written in camelCase in JavaScript (`backgroundColor`)

```js
<script>
	let specificTag = document.querySelector("#myparagraphid");
	specificPTag.innerHTML = "Hello from JavaScript";
	specificPTag.style.color = "red";
</script>
```

examples of common style changes:
```js
element.style.color = "red";

// note: camelCase, not background-color
element.style.backgroundColor = "lightblue";

element.style.fontSize = "24px";

// hides the element
element.style.display = "none";

// shows it again
element.style.display = "block";

element.style.border = "2px solid black";
```

**prefer CSS classes over inline styles**
-  `style` directly works for quick changes
-  cleaner approach: define a CSS class and use `element.classList.add("my-class")` to apply it

## `value` - reading from inputs

`innerHTML` does not work for
-  `<input>`
-  `<textarea>`
-  `<select>`

you read them using the **`value`** property
```js
let usernameInput = document.querySelector("#username");
let typedText = usernameInput.value; // reads whatever the user typed
```


| Element type                           | Use this property              |
| -------------------------------------- | ------------------------------ |
| `<p>`, `<h1>`, `<div>`, `<span>`, etc. | `.innerHTML` or `.textContent` |
| `<input>`, `<textarea>`, `<select>`    | `.value`                       |

# Handling Events

**event-driven programming** = code is not running in a straight line, it registers functions that the browser will call when *something happens*
-  those functions = **event handlers**
-  **callback** = passing a function to be called later

## Common Events

| Event              | Fired when...                                                  |
| ------------------ | -------------------------------------------------------------- |
| `click`            | The user clicks an element                                     |
| `submit`           | A form is submitted                                            |
| `keyup`            | The user releases a key                                        |
| `keydown`          | The user presses a key down                                    |
| `change`           | The value of an `<input>`, `<select>`, or `<textarea>` changes |
| `mouseover`        | The cursor moves over an element                               |
| `DOMContentLoaded` | The page has fully loaded and the DOM is ready                 |

## `addEventListener`

used to call your function when an event fires
takes two arguments:
1.  the **name of the event** as a string (e.g. `'click'`)
2.  the **function to call** when that event fires - the callback
```js
element.addEventListener('event-name', handlerFunction);
```

example: a page with a button that shows an alert when clicked
```html
<html>
	<head>
		<title>Event handling example</title>
	</head>
	<body>
		<button id="mybutton">Click me</button>
		<script>
			function showAlert() {
				alert("The button was pressed");
			}
			
			let myButton = document.querySelector("#mybutton");
			myButton.addEventListener('click', showAlert);
		</script>
	</body>
</html>
```

first we **select** the button, then we **register** the handler

**pass the function, don't call it**
the second argument to `addEventListener` must be a function itself
```js
// correct - passes the function
myButton.addEventListener('click', showAlert);

// wrong - calls it immediately and passes undefined
myButton.addEventListener('click', showAlert());
```

writing `showAlert` with parentheses calls the function *right now* and passes its return value (which is `undefined`) to `addEventListener`
 -  this click will never do anything

## the `event` object

when the browser calls your handler, it passes it one argument automatically - an **event object** containing information about what just happened
-  you can capture it by adding a parameter to your function:
```js
function showAlert(event) {
	console.log(event.type);   // "click"
	console.log(event.target); // the element that was clicked
}

myButton.addEventListener('click', showAlert);
```

`event` is commonly named `e` 

# Form Validation

validating data before it gets send anywhere on the client side, before a request even leaves the browser
-  catching empty fields
-  badly formatted email addresses
-  mismatched passwords

## why `event.preventDefault()`?

when a user submits an HTML form, the browser's **default behaviour** is to package up the form data and send it as an HTTP request, then navigate to a new page

we want to intercept that submission, inspect the data ourselves, and decide what to do next

we call **`event.preventDefault()`** as the very first line of our handler
```js
function handleSubmit(event) {
	event.preventDefault(); // stop the browser navigating away
	// now we're in control
}

document.querySelector("#myform").addEventListener('submit', handleSubmit)
```

**always call `preventDefault()` first**
if you forget it, the browser will submit the form and reload the page - wiping out any JavaScript state and making your handler appear to do nothing

## a complete example

login form that validates the username and password fields before doing anything else
pattern:
-  create the form
-  create a handler
-  register the handler on the `submit` event of the form (not the button - the form)

```html
<html>
    <head>
        <title>Form validation example</title>
    </head>
    <body>
        <form id="myform">
            <label for="name-input">Your username</label>
            <input type="text" id="name-input" placeholder="Your username here">

            <label for="password-input">Your password</label>
            <input type="password" id="password-input" placeholder="Your password here">

            <button type="submit">Submit</button>
        </form>

        <script>
            function formValidator(event) {
                event.preventDefault(); // always prevent default first

                let username = document.querySelector("#name-input").value;
                let password = document.querySelector("#password-input").value;

                if (username === "") {
                    alert("Username cannot be blank");
                } else if (password === "") {
                    alert("Password cannot be blank");
                } else {
                    alert("Form is valid — ready to submit to the API");
                }
            }

            let myForm = document.querySelector("#myform");
            myForm.addEventListener('submit', formValidator);
        </script>
    </body>
</html>
```

note:
-  the event listener is on the `<form>`, not the `<button>`
-  the `submit` event is fired by the form element itself - attaching it to the button would miss cases where the user submits by pressing ++enter++.
-  we use `.value` (not `.innerHTML`) to read the input contents
-  we check with `=== ""` (strict equality) to detect a blank field

## showing errors in the page

`alert()` is convenient for demos, but poor practice in real applications
-  blocks the entire browser
-  looks jarring
-  can't be styled

write error messages directly into the DOM using a dedicated element
```html
<form id="myform">
    <label for="name-input">Your username</label>
    <input type="text" id="name-input" placeholder="Your username here">
    <p id="username-error" style="color: red;"></p>

    <label for="password-input">Your password</label>
    <input type="password" id="password-input" placeholder="Your password here">
    <p id="password-error" style="color: red;"></p>

    <button type="submit">Submit</button>
</form>

<script>
    function formValidator(event) {
        event.preventDefault();

        let username = document.querySelector("#name-input").value;
        let password = document.querySelector("#password-input").value;

        // clear any previous error messages before re-validating
        document.querySelector("#username-error").textContent = "";
        document.querySelector("#password-error").textContent = "";

        if (username === "") {
            document.querySelector("#username-error").textContent = "Username cannot be blank";
        } else if (password === "") {
            document.querySelector("#password-error").textContent = "Password cannot be blank";
        } else {
            console.log("Form is valid — ready to submit to the API");
        }
    }

    document.querySelector("#myform").addEventListener('submit', formValidator);
</script>
```

## Creating & Removing Elements

## creating elements

```js
// creates a new <li> element
let newItem = document.createElement("li");

// set its content
newItem.textContent = "New Item";
```

## adding elements to the page

**`appendChild`** adds the new element as the **last child** of parent element
```js
let list = document.querySelector("#mylist");
list.appendChild(newItem); // inserts <li> at the end of the list
```

example: loop over an array of names and build an HTML list from them
```html
<html>
    <head>
        <title>Creating elements example</title>
    </head>
    <body>
        <ul id="mylist"></ul>
        <script>
            let list = document.querySelector("#mylist");
            let names = ["John", "Paul", "George", "Ringo"];

            for (let i = 0; i < names.length; i++) {
                let nameElement = document.createElement("li"); // create a new <li>
                nameElement.innerHTML = names[i];               // set its text
                list.appendChild(nameElement);                  // add it to the <ul>
            }
        </script>
    </body>
</html>
```

**other insertion methods**
-  `appendChild` always adds at the end
-  **`insertBefore`** and **`insertAdjacentElement`** give you finer-grained positioning

## removing elements

```js
let item = document.querySelector("#item-to-delete");
item.remove()
```

common pattern - pair this with a click handler
example: add a delete button to each item in a list
```js
let names = ["John", "Paul", "George", "Ringo"];
let list = document.querySelector("#mylist");

names.forEach(name => {
	let li = document.createElement("li");
	li.textContent = name;
	
	let deleteBtn = document.createElement("button");
	deleteBtn.textContent = "Remove";
	// remove the parent <li> on click
	deleteBtn.addEventListener("click", () => li.remove());
	
	li.appendChild(deleteBtn);
	list.appendChild(li);
})
```

arrow function `() => li.remove()` passed to `addEventListener`
-  it is defined inside the loop, it **closes over** `li` and always refers to that specific list item, not whichever `li` happens to be last

# Lab 5 notes

## `Async` / `Await`

```js
// .then() style
fetch(url)
	.then(response => response.json())
	.then(data => console.log(data))
	.catch(error => console.error(error))
	
// async/wait style
async function loadData() {
	try {
		const response = await fetch(url);
		const data = await response.json();
		console.log(data);
	} catch (error) {
		console.error(error);
	}
}

loadData();
```

-  `await` keyword pauses execution inside the function until the promise resolves
-  `try`/`catch` block handles any errors - equivalent to `.catch()` - but it also catches runtime errors inside the block, making it more robust

**you cannot use `await` at the top level inside a `<script> tag`**
`await` only works inside a function declared with `async`
-  always wrap your fetch logic in an `async` function and call it:
```js
async function loadQuestions() {
	// await goes here
}
loadQuestions();
```

### Fetching from Multiple Endpoints

`Promise.all` takes an array of promises and resolves when all of them complete:
```js
const [userRes, postRes] = await Promise.all([
	fetch(userUrl),
	fetch(postUrl)
]);
const user = await userRes.json();
const posts = await postRes.json();
```

this is faster than two sequential `await fetch(...)` calls because both requests run at the same time

**error handling with Promise.all**
if *any* promise in the array rejects, the whole `Promise.all` rejects
-  a single `try` / `catch` around it is enough to handle failure from either request

### Loading on Demand

new content is fetched only when the user asks for it
fetch a random post from an API

**generating a random integer**
```js
const id = Math.floor(Math.random() * 100) + 1; 
```

**disabling a button temporarily**
```js
button.disabled = true;
button.innerHTML = "Loading...";
// ... after fetch completes ...
button.disabled = false;
button.innerHTML = "Load Post";
```

put the cleanup in a `finally` block so it always runs, even if the fetch fails
```js
try {
	// fetch logic
} catch (error) {
	// show error
} finally {
	button.disabled = false;
	button.innerHTML = "Load Post";
}
```

## `localStorage`

**`localStorage`** lets you save data in the browser that persists across page reloads and even after the tab is closed
-  it stores everything as strings, so objects and arrays must be converted using `JSON.stringify()` and `JSON.parse()`
```js
// Saving data
localStorage.setItem("username", "Alice");
localStorage.setITem("scores", JSON.stringify([10, 20, 30]));

// Reading data
// "Alice"
const name = localStorage.getItem("username");

// [10, 20, 30]
const scores = JSON.parse(localStorage.getItem("scores"));

// Removing data
localStorage.removeItem("username");
```

if `getItem` is called for a key that does not exist, it returns `null` - always check for this before calling `JSON.parse`

**running code on page load**
put any startup logic directly in the `<script>` tag, outside of any event listener - it runs automatically when the page loads:
```js
const saved = localStorage.getItem("username");
if (saved) {
	document.querySelector("#name-input").value = saved;
	document.querySelector("#greeting").innerHTML = `Welcome back, ${saved}!`;
}
```

### Persistent List 

survives a page reload

**keeping localStorage in sync**
maintain a JavaScript array as your source of truth
when an item is added, push to the array then save it
when the page loads, restore the array first then render it

```js
let items = JSON.parse(localStorage.getItem("list")) || [];

function render() {
	const ul = document.querySelector("ul");
	ul.innerHTML = "";
	for (const text of items) {
		const li = document.createElement("li");
		li.innerHTML = text;
		ul.appendChild(li);
	}
}
render(); // restore on load
```

after any change, call `localStorage.setItem("list", JSON.stringify(items))` and `render()`.

### theme switcher

**toggling a CSS class**
```js
document.body.classList.add("dark");
document.body.classList.remove("light");
```
or use `classList.toggle("dark")` if you only have one class to switch

**applying the saved theme on load**
read `localStorage` at the top of your script and apply the class before the page renders any interaction
```js
const theme = localStorage.getItem("theme") || "light";
document.body.classList.add(theme);
```

# ES6 Classes

classes give you a way to bundle related data and behaviour together
a **class** defines the structure, you create individual **instances** form it using `new`

```js
class Animal {
	constructor(name, sound) {
		this.name = name;
		this.sound = sound;
	}
	
	speak() {
		console.log(`${this.name} says ${this.sound}`);
	}
}

const dog = new Animal("Dog", "woof");
dog.speak(); // Dog says woof
```

-  **`constructor`** runs automatically when you call `new` - use it to set up the instance's properties with **`this`**
-  methods are defined directly in the class body, without the `function` keyword
-  each instance gets its own copy of the data but shares the same methods

**defining a class method**
methods go inside the class body, at the same level as `constructor`:
```js
class BankAccount {
	constructor(owner, initialBalance) {
		this.owner = owner;
		this.balance = initialBalance;
	}
	
	deposit(amount) {
		this balance += amount;
	}
}
```
