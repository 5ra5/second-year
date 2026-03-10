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