**lecture**

**look at WEB APIs for more info**

running JS in the frontend
in `<head>` or `<body>`:
required code is going in the `<head>`, customised code goes in the `<body>`, just before the closing tag `</body>`
-  this is because it might depend on the stuff that's written in the body which needs to load with it
```html
<head>
	<title>Tests JS</title>
	<script src="./names.js"></script>
	<script src="http://somelonglink.js"></script>
	<script>
		// my javascript goes here
	</script>
</head>
<body>
	<p>Welcome to my page</p>
	<script>
		// my other javascript goes here
	</script>
</body>
```

everything starts with document

```html
<body>
	<p>Paragraph 1</p>
	<p>Paragraph 2</p>
	<p class="test">Test p1</p>
	<p class="test">Test p2</p>
	<p id="myspecialparagraph">Paragraph made with id</p>
	<script>
		let allPTags = document.getElementsByTagName("p");
		console.log(allPTags)
	</script>
</body>
```

this gets you an object `HTMLCollection` in the console

get elements by their class name:
```js
let testPTags = document.getElementsByClassName("p");
```

get individual element:
```js
let singlePTag = document.getElementById("p");
console.log(singlePTag);
```

you can query on anything with `querySelector` to get objects in a more simple way
-  it is used by convention - it is more powerful than get elements by ID
```js
document.querySelector

let allPTags = document.querySelector("p")
let testPTags = document.querySelectorAll(".test")
let singlePTag = document.querySelector("#myspecialparagraph");
```

return inner HTML (what is written inside a p tag) in the console
```js
let singlePTagText = singlePTag.innerHTML;
console.log(singlePTagText);
```

change the output
```js
singlePTag.innerHTML = "Changed by JS"
singlePTag.style.color = 'red';

// adding a CSS class hello
singlePTag.classList.add("hello");
```

# forms
-  it is good practice to verify data with JS before it is even sent to Django for another check
-  browser can perform automated checks for you (e.g. "Please fill in this field")
```html
<form>
	<label for="username">Username</label>
	<input type="text" name="username" placeholder="Your username"/>
	<label for="age">Age</label>
	<input type="number" name="age" min="0" placeholder="Your age" />
	<button type="submit">Submit</button>
</form>
```

 we use event handlers because we always have to wait for an even before triggering anything
 -  2 parameters (event, function)
 -  HTML events (you can look up W3Schools)
 -  we write the function ourselves - `handleSubmit(e)`
 -  in this case we use the HTML event - submit
 -  don't type in `handleSumbit()` because it immediately runs that function - form will be submitting automatically
 -  we don't want it to run immediately, we want to pass it  to the event handler to be ran later
 -  `()=>` - when it's submitted, run the function
 - `e.preventDefualt()` = "don't automatically redirect the user and submit the form"
```js
let myButton = document.querySelector("button");
function handleSubmit(e){
	console.log("Form submitted")
}
myForm.addEventListener('submit', (e)=>) {
	e.preventDefault();
	console.log("Form submitted");
	// load the tag where the user entered their name
	let nameInput = document.querySelector("input[name='username']");
	
	// load the tag where the user entered their age
	let ageInput = document.querySelector("input[type='number']");
	
	// check the values for name and age
	// display error message (if needed)
	// use span for error printing
	console.log('nameInput.innerHTML', nameInput.innerHTML);
	console.log('nameInput.value', nameInput.value);
	if(nameInput.value ==== "Michael"){
		document.querySelector("#error-user").innerHTML="No Michaels allowed";
	}
	// continue with submit (send data to the server)
})
```

ignore the `favicon.ico` 404 (Not Found) error that shows up in the console
`favicon` = a small logo that shows up in the tab
-  doesn't matter until further production

use value
first name will be empty
second name will show the value
```js
	console.log('nameInput.innerHTML', nameInput.innerHTML);
	console.log('nameInput.value', nameInput.value);
```

be sure to display an appropriate error message to avoid having to deal with a lot of support tickets from customer that don't know why they got the error message (they have to be non-general)
```js
// too general
document.querySelector("#error-user").innerHTML="Error occured";

// perfect
document.querySelector("#error-user").innerHTML="No Michaels allowed";
```

a case of error printing with no span
```JS
myForm.addEventListener('submit', (e)=>) {
	e.preventDefault();
	console.log("Form submitted");
	// load the tag where the user entered their name
	let nameInput = document.querySelector("input[name='username']");
	
	// load the tag where the user entered their age
	let ageInput = document.querySelector("input[type='number']");
	
	// check the values for name and age
	// display error message (if needed)
	console.log('nameInput.innerHTML', nameInput.innerHTML);
	console.log('nameInput.value', nameInput.value);
	if(nameInput.value ==== "Michael"){
		let errorMessageBox = document.createElement("span");
		errorMessageBox.textContent = "No Michaels allowed";
		document.querySelector("form").appendChild(errorMessageBox);
	}
	// continue with submit (send data to the server)
})
```

even quicker way:
```js
document.querySelector("form").innerHTML = 
	document.querySelector("form").innerHTML + '<span style="color: red">No Michals</span>';
```

## asynchronous tasks
`taskB` is not finished before `taskC` starts
```
taskA()
asyn taskB()
taskC()
```
#  lists

1.  hard coded version (usually not used)
```html
<head>
	<title>Tests JS</title>
	<script src="./names.js"></script>
	<script src="http://somelonglink.js"></script>
	<script>
		// my javascript goes here
	</script>
</head>
<body>
	<p>Welcome to my page</p>
	<script>
		let names = ['John', 'Paul', 'George', 'Ringo'];
		const ul = document.querySelector("ul");
		names.forEach((n)=>{
			let nn = document.createElement("li");
			nn.textContent = n;
			ul.appendChild(nn)
		})
	</script>
</body>
```

2.  coming from an external API - not hard coding
-  use fetch statement
-  promise style - use this
```html
	<script>
		let names = ['John', 'Paul', 'George', 'Ringo'];
		const ul = document.querySelector("ul");
		names.forEach((n)=>{
			let nn = document.createElement("li");
			nn.textContent = n;
			ul.appendChild(nn)
		})
		
		// get data at this address - you get a promise back
		fetch("http://localhost:8000/api/books"){
			.then(resp=>resp.json)
			.then(json=>{
				// what do i want to do with the JSON
			})
			.catch(error=>{
			
			})
		}
	</script>
```

old blocking style - doesn't exist anymore - very dangerous
-  you would make the user wait for a lot of time before they can do anything
-  some browsers like Firefox crash the website after a few seconds
```js
const response = await fetch("http://localhost...");
const data = await response.json();
console.log(data);
```

chaining Pokemon data with a link
```js
// get data at this address - you get a promise back
fetch("http://pokemonAPIlink"){
	.then(resp=>resp.json)
	.then(json=>{
		json['results'].forEach(p)=>{
			console.log(p);
			let name = p['name']
			let url = p['url']
			document.querySelector("ul").innerHTNL = 
				document.querySelector("ul").innerHTNL + `<li><a href="${url}">${name}</a></li>`
		})
	})
	.catch(error=>{
			
	})
}
```

**website**