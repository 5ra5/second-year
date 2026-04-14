**Question 1**
The following component is intended to allow users to add items to a todo list and count how many todos have been added in total. It contains several bugs — some will prevent it from working entirely, others are more subtle. Identify all the issues and rewrite the component correctly.

```jsx
import { useState } from 'react';

function TodoList() {
  const [todos, setTodos] = useState([]);
  const [input, setInput] = useState('');  
  const [count, setCount] = useState(0);
  
  const addTodo = () => {
    todos.push(input);  
    setInput('');  
  };

  useEffect(() => {  
    const interval = setInterval(() => {  
      setCount(count + 1);  
    }, 1000);  
    return () => clearInterval(interval);  
  }, []);

  return (  
    <div>  
      <input value={input} onChange={e => setInput(e.target.value)} />  
      <button onClick={addTodo}>Add</button>  
      <ul>  
        {todos.map((todo, index) => (  
          <li>{todo}</li>  
        ))}  
      </ul>  
      <p>Todos added after {count} seconds</p>  
    </div>  
  );  
}

export default TodoList;
```

- useEffect is never imported
- to add a todo list you must change the state by calling setTodos
- `<li>{todo}</li>` is incorrect, lists in react should have a key prop, e.g. `<li key={index}>{todo}</li>`

**Question 2**
The following component fetches a list of users and displays them. It contains several bugs — some will prevent it from being used in a wider application, others will cause serious runtime problems. Identify all the issues and rewrite the component correctly.

```jsx
import { useState, useEffect } from 'react';

function UserDashboard() {
  const [users, setUsers] = useState([]);

  fetch('[https://api.example.com/users'](https://api.example.com/users')) 
    .then(res => res.json())
    .then(data => setUsers(data));

  return (  
    <ul>  
      {users.map(user => (  
        <li key={user.id}>user.name</li>
      ))}
    </ul>  
  );  
}
```

- Missing export default at the bottom
- There is no loading or error state during the fetch call
- The fetch call should be wrapped inside useEffect to avoid an infinite loop of component reloads
- There are missing '{' and '}' around `user.name` in `<li key={user.id}>user.name</li>`

**Question 3**
What is the primary purpose of React's Virtual DOM?

a. To keep a lightweight in-memory representation of the DOM and batch updates efficiently
b. To synchronise state across multiple browser tabs
c. To directly manipulate the browser's DOM for faster rendering
d. To replace the need for a real DOM entirely

**Question 4**
What is wrong with the following JSX?

```jsx
function Greeting() {
	const name = "Alice";
	return <h1>Hello, name</h1>;
}
```

a. `name` should be in double quotes: `"name"`
b. The function needs to be a class component to use variables
c. Nothing
d. `name` should be wrapped in curly braces: `{name}`

**Question 5**
What happens when `useEffect` is given an empty dependency array `[]`?

a. The effect never runs
b. The effect runs before the component mounts
c. The effect runs on every render
d. The effect runs once after the initial render

**Question 6**
Why does React require a `key` prop when rendering lists?

a. To link each list item to its corresponding state value
b. To apply CSS styling to each element
c. To help React identify which items have changed, been added, or removed
d. To ensure elements render in alphabetical order

**Question 7**
Which of the following is a valid custom hook?

a. A regular function that calls `fetch` and returns a promise
b. A function named `getData` that calls `useState` internally
c. A class method that calls `useEffect`
d. A function named `useData` that calls `useState` internally

**Question 8**
What makes an input element controlled in React?

a. Its value is bound to component state and updated via an `onChange` handler
b. It is wrapped in a `<form>` element
c. It has a `defaultValue` attribute
d. It uses a `ref` to access the DOM node directly

**Question 9**
What does this component render after the button is clicked once?

```jsx
const [count, setCount] = useState(0);

const handleClick = () => {
	setCount(count + 1);
	setCount(count + 1);
};

return <button onClick={handleClick}>{count}</button>;
```

a. 1
b. React throws an error
c. 0
d. 2

**Question 10**
Which of the following statements is true?

a. State can be passed from a child to a parent directly
b. State is managed internally by a component and triggers a re-render when updated
c. Props are mutable within the component that receives them
d. Props and state both persist between full page reloads