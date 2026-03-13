**Question 1**
Which of the following correctly describes the difference between let and var?

a. `let` is block-scoped, `var` is function-scoped
b. There is no difference; they are interchangeable
c. Both `let` and `var` are block-scoped
d.`var` is block-scoped, `let` is function-scoped

**Question 2**
What does the following expression evaluate to?
`typeof null`

a. boolean
b. null
c. object
d. undefined

**Question 3**
For the following html code, what query selector can be used to target the button inside the form with the class "submit"
```html
<form id="checkout">
<button type="submit" class="submit">Submit</button>
</form>
```

a. `document.querySelector("#checkout .submit")`
b. `document.querySelector("form > .submit")`
c. `document.querySelector("#checkout button.submit")`
d. `document.getElementById("checkout").button`

**Question 4**
Review the code below. Identify any errors and explain what the correct version should be.
```js
const btn = document.getElementById(".myButton");

btn.addEventListener("click", function() {
  btn.innerText = "Clicked!"; 
})
```

-  `getElementById` does not use CSS selector syntax — the `.` prefix is incorrect.
-  It should be `getElementById("myButton")`.
-  If a class selector is intended, `querySelector(".myButton")` should be used instead.

**Question 5**
Comment on the quality of the following code. What improvements would you suggest?
```js
var x = document.querySelectorAll("div");
for (var i = 0; i < x.length; i++) {
  var x = x[i].innerText;
  console.log(x);
}
```

-  `var x` is re-declared inside the loop, overwriting the `NodeList` on the first iteration — this will cause a crash
-  `var` should be replaced with `let` or `const` to avoid function-scoped leakage
-  A cleaner approach uses `forEach`: `x.forEach(el => console.log(el.innerText))`

**Question 6**
What is the correct way to prevent a form from submitting when a button is clicked?

a. `return null`
b. `event.stopPropagation()`
c. `event.cancel()`
d. `event.preventDefault()`

**Question 7**
The following fetch request is not working as expected. Identify the problem(s):
```js
function getData() {
	const result = fetch("https://api.example.com/data");
	console.log(result.json());
}
```

-  `fetch()` returns a Promise — `await` (or `.then()`) is needed before it resolves
-  `.json()` also returns a Promise and must be awaited.

The corrected version:
```js
async function getData() {
	const response = await fetch("https://api.example.com/data");
	const result = await response.json();
	console.log(result);
}
```

**Question 8**
Review this fetch code. What is missing and why does it matter?
```js
async function loadUser(id) {
	const res = await fetch ('/api/users/${id}');
	const data = await res.json();
	document.getElementById("username").innerText = data.name;
}
```

There is no error handling. If the network request fails, or the server returns a non-2xx status, the code will either throw an unhandled exception or silently display `undefined`. A proper implementation should:
- Wrap in `try/catch`
- Check `res.ok` before parsing JSON

**Question 9**
What is the output of the following code
```js
a = null
x = a||5
console.log(x);
```

a. false
b. undefined
c. null
d. 5

**Question 10**
Which of the following is a valid way to declare and immediately call an anonymous function?

a. `anonymous function() { console.log("hi"); }()`
b. `function() { console.log("hi"); }()`
c. `() => { console.log("hi"); }()`
d. `(function() { console.log("hi"); })()`