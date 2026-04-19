-  frontend - used for 3rd year and 4th year project
-  in demand, may be considered old but there is no better replacement yet
-  software library, not a framework

structured and based on components
you need to start with a diagram of what the system is going to look, otherwise you will not have a good application
problem: coupling HTML and CSS with the logic of how to display things

build tools advance every year
build tools = what brings all of your react files together

build tool we use = vite

running vite initially
```shell
nmp create vite@latest . -- --template react
```

running vite again
```shell
npm run dev
```

**building components:**
helloworld.jsx
```jsx
function HelloWorld(){
	return <h1>Hello World</h1>;
}

export default HelloWorld;
```

app.jsx
```jsx
import HelloWorld

return (
	<HelloWorld />
	<p>Element 1</p>
	<p>Element 2</p>
)
```

arguments in react = props
`{name || "world"}` = if there is no name, print world
`age=10` = default prop

```jsx
function HelloWorld({name, age=10}){
	return <h1>Hello {name || "world"}</h1>;
}

export default HelloWorld;
```

```jsx
import HelloWorld

return (
	<HelloWorld name={'Mike'}/>
	<HelloWorld age={15}/>
	<p>Element 1</p>
	<p>Element 2</p>
)
```

randombutton.jsx
```jsx
function RandomButton(onClick){
	return <button> onClick={onCLick}Click here</button>
}

export default RandomButton;
```

app.jsx
```jsx
import RandomButton

function App() {
	function handleClick(){
		console.log("Clicked here");
	}
	
	return {
		<RandomButton onClick={handleClick} />
		<RandomButton onClick={()}
	}
}
```

each component stores a state - a variable
-  it can see if the value ever changes, and it it does it automatically updates itself
-  components are functions, that have all of the functionality split between them in smaller functionalities
-  we typically split each component into their own file

inputName.jsx - page automatically says whatever you're typing in the input box
-  input
-  header
```jsx
function InputName(){
	const [text, setText] = useState(null);

	function handleChange(e){
		const val = e.target.value; // current value of the input box
		setText(val);
	}
	
	return(
		<div>
			<h2>Hello {text || 'World'}</h2>
			<input onChange={} type="text" />
		</div>
	)
}

export default InputName;
```

```jsx
import InputName

function App{
	return (
		<InputName />
	)
}
```

**dice roll app example:**

app.jsx
```jsx
function App() {
	const [result, setResult] = useState(null);
	const[history, setHistory] = useState([]);
	
	
	function handleRoll(){
		const roll = Math.ceil(Math.random()*6);
		setResult(roll);
		setHistory([roll, ...history]);
		// history = [1,2,3], roll=4
		// setHistory([4,1,2,3])
	}
	
	return(
		<RandomButton onClick={handleRoll} />
		<DiceResult result={result} />
		<DiceHistory history={history} />
	)
}
```

diceResult.jsx - component
```jsx
function DiceResult({result}){
	return (
		<p>Result: {result ?? }
	)
}
```

diceHistory
```jsx
function DiceHistory({history}){
	return <>
		<h2>Roll History</h2>
		<ul>
			{history.map((roll, index)=>
				<li key={index}>{history.length-index}: {roll}</li>
			)}
		</ul>
	</>
}

export default DiceHistory;
```

## JSX Rules

1.  You must return a single root element
```jsx
// This will error - two root elements
return (
	<h1>Hello</h1>
	<p>World</p>
)

// Wrap in div
return (
	<div>
		<h1>Hello</h1>
		<p>World</p>
	</div>
)

// Or use a Fragment - renders no extra DOM element
return (
	<>
	<h1>Hello</h1>
	<p>World</p>
	</>
)
```

2.  Use `className` instead of `class`
```jsx
// HTML attribute - wrong in JSX
<div class="card">

// JSX attribute
<div className="card">
```

3.  Embed JavaScript expressions with `{}`
```jsx
const name = 'Alice';
const score = 42;

return (
	<p>{name} scored {score * 2} points</p>
)

// renders: <p>Alice scored 84 points</p>
```

4. All tags must be closed
```jsx
// Valid HTML, invalid JSX
<br>
<input type="text">

// valid JSX
<br />
<input type="text" />
```

## JSX vs Vanilla JS DOM Creation

```js
function createWelcomeCard(name) {
	const div = document.createElement('div');
	div.className = 'card';
	
	const h2 = document.createElement('h2');
	h2.textContent = `Welcome, ${name}`;

	const p = document.createElement('p');
	p.textContent = 'Glad to have you here.';

	div.appendChild(h2);
	div.appendChild(p);
	return div;
}
```

same thing in JSX:
```jsx
function WelcomeCard({ name }) {
	return(
		<div className="card">
			<h2>Welcome, {name}</h2>
			<p>Glad to have you here.</p>
		</div>
	)
}
```

## Components

-  JavaScript function that returns JSX

the simplest possible one:
```jsx
function Greeting() {
	return <h1>Hello, World</h1>;
}
```

to use it, write it like and HTML tag:
```jsx
function App() {
	return (
		<div>
			<Greeting />
		</div>
	);
}
```
## Props

passed in JSX the same way you write HTML attributes:
```jsx
<PageTitle text="Welcome to the Dice Roller" />
<PageTitle text="About This App" />
```

destructure props directly in the function signature
```jsx
function PageTitle({ text }) {
	return <h1>{text}</h1>;
}
```

you can pass any JS value as a prop
-  string values use quotes
-  everything else uses {}
```jsx
<ScoreDisplay score{42} isWinner={true} rolls={[3, 6, 1]} />
```

## passing functions as props

```jsx
function RollButton({ onRoll }) {
	return <button onClick={onRoll}>Roll</button>;
}

function App() {
	function handleRoll() {
		console.log('rolled!');
	}
	
	return <RollButton onRoll={handleRoll} />;
}
```
## handling events

in vanilla JS - event listeners attached imperatively
```js
const button = document.getElementById('roll-btn');
button.addEventListener('click', handleRoll);
```

example in JSX
```jsx
function RollButton() {
	function handleClick() {
		console.log('Button clicked!');
	}
	
	return <button onClick={handleClock}>Roll the dice</button>;
}
```

example with inline handler
```jsx
<button onClick={() => console.log('clicked')}>Roll</button>
```

## the event object
```jsx
function SearchBox() {
	function handleChange(event) {
		console.log(event.target.value); // current value of the input
	}
	
	return <input type="text" onChange={handleChange} />;
}
```

## preventing default behaviour

```jsx
function LoginForm() {
	function handleSubmit(event) {
		event.preventDefault();
		console.log("Form submitted - handling it ourselves");
	}
	
	return (
		<form onSubmit={handleSubmit}>
			<button type="submit">Log in</button>
		</form>
	);
}
```

## state & the render cycle

```jsx
function Counter() {
	let count = 0;
	
	function handleClick() {
		count = count + 1;
		console.log(count); // increments correctly in the console...
	}
	
	return (
		<div>
			<p>{count}</p> {/* ... but this never changes */}
			<button onClick={handleClick}>Increment</button>
		<div>
	);
}
```

-  react renders a component by calling the function
-  it runs `Counter()`
-  it captures the JSX it returns and builds the DOM from it

-  changing a local variable does not tell react anything happened
-  react never re-runs the function, so the UI stays frozen at its initial render
-  the variable and the UI are out of sync
-  to make react re-render a component when data changes, the data needs to be state

use - `useState`
```jsx
import { useState } from 'react';

function Counter() {
	const [count, setCount] = useState(0);
	
	function handleClick() {
		setCount(count + 1);
	}
	
	return (
		<div>
			<p>{count}</p>
			<button onClick={handleClick}>Increment</button>
		<div>
	);
}
```

`useState(0)` returns an array of exactly two things, which you destructure:
-  `count` - the current value (starts at 0)
-  `setCount` - the function you call to update it

when you call `setCount(count + 1)`, two things happen in sequence:
1.  react stores the new value
2.  react re-runs the `Counter` function - re-rendering the component with the updated count

**never mutate state directly**
```jsx
// wrong - react does not know this happened
count = count + 1;

// correct - triggers a re-render
setCount(count + 1);
```

## multiple state values

calling either setter triggers a re-render
-  multiple state updates made in the same event handler batched into a single re-render
-  `setResult` and `setTotalRolls` cause only one pass through the render cycle
```jsx
function DiceRoller() {
	const [result, setResult] = useState(null);
	const [totalRolls, setTotalRolls] = useState(0);
	
	function handleRoll() {
		setResult(Math.ceil(Math.random() * 6));
		setTotalRolls(totalRolls + 1);
	}
	
	return (
		<div>
			<p>Result: {result ?? '--'}</p>
			<p>Total rolls: {totalRolls}</p>
			<nutton onClick={handleRoll}>Roll</button>
		</div>
	);
}
```

## `useEffect`

a hook that lets you run side effects
side effects = anything that is not "return JSX"
-  setting the document title
-  starting a timer
-  listening to a WebSocket
-  reading from `localStorage`

basic shape:
```jsx
import { useEffect } from 'react';

useEffect(() => {
	// side effect code runs here
});
```

running on mount - `[]`
"run once when the component first appears" = something only needs to happen once
```jsx
function DiceRoller() {
	useEffect(() => {
		document.title = 'Dice Roller';
	}, []);
	
	return <div>...</div>
}
```

running when state changes - `[value]`
list the values the effect depends on, react re-runs the effect whenever any of them change
```jsx
function DiceRolller() {
	const [totalRolls, setTotalRolls] = useState(0);
	
	useEffect(() => {
		document.title = `Dice Roller - ${totalRolls} rolls`;
	}, [totalRolls]);
	
	// ...
}
```

## cleanup function

without cleanup - interval keeps running and trying to update state on a component that no longer exists
-  common source of memory leaks and React warnings
```jsx
function CountdownTimer() {
	const[seconds, setSeconds] = useState(60);
	
	useEffect(() => {
		const interval = setInterval(() =>
			setSeconds(s => s - 1);
		}, 1000);
	
		// cleanup - runs when component unmounts
		return () => clearInterval(interval);
	}, []); // start once on mount
	
	return <p>Time remaining: {seconds}s</p>;
}
```