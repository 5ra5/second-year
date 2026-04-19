**rewrite question**
this component is supposed to display a button that increases a counter when clicked
```jsx
import { useState } from 'react';

function Counter() {
	const [count, setCount] = useState(0);
	
	function handleClick() {
		setCount(count + 1);
	};
	
	return <button onClick={handleClick}>{count}</button>;
}
```

**rewrite question**
this component should let the user type into an input
```jsx
import { useState } from 'react';

function NameInput() {
	const [name, setName] = useState('');
	
	function onChangeHandler(e) {
		setName(e.target.value);
	}
	
	return (
		<input
			type="text"
			value={name}
			onChange={onChangeHandler}
		/>
	);
}
```

**rewrite question**
this component should fetch users once when the component mounts and then display them
```jsx
import { useState, useEffect } from 'react';

function Users() {
	const[users, setUsers] = useState([]);
	
	useEffect(() => {
		fetch('https://api.example.com/users')
		.then(res => res.json())
		.then(data => setUsers(data));
	}, [])
	
	return (
		<ul>
			{users.map((user => (
				<li key={user.id}>{user.name}</li>
			))}
		</ul>
	);
}

export default Users;
```

this component should add a new todo to the list when the button is clicked
```jsx
import { useState } from 'react';

function TodoApp() {
  const [todos, setTodos] = useState([]);
  const [text, setText] = useState('');

  const addTodo = () => {
	if (text.trim() === '') return;
	  
	setTodos([...todos, text]);
	setText('');
  };
  
  return (
    <div>
    <input 
	    value={text} 
	    onChange={(e) => setText(e.target.value)} 
	/>
      <button onClick={addTodo}>Add</button>
      <ul>
        {todos.map((todo, index) => (
          <li> key={index}>{todo}</li>
        ))}
      </ul>
    </div>
  );
}

export default TodoApp;
```

What is wrong with this code:
```jsx
function Welcome() {
  const name = "Sam";
  return <h1>Hello, name</h1>;
}
```

-  `name` is being rendered as plain text instead of a JavaScript variable
-  it should be {name}

correct code:
```jsx
function Welcome() {
  const name = "Sam";
  return <h1>Hello, {name}</h1>;
}
```

what is wrong with this code?
```jsx
import { useState } from 'react';

function App() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    console.log("Mounted");
  }, []);

  return <p>{count}</p>;
}
```

- `useEffect` is used but not imported

**identify issues and rewrite question**
this component is supposed to:
-  let the user type a name
-  add the name to a list when clicking a button
-  display all names
```jsx
import { useState } from 'react';

function NameList() {
  const [names, setNames] = useState([]);
  const [input, setInput] = useState('');

  function addName() {
    names.push(input);
    setInput('');
  }

  return (
    <div>
      <input
        value=input
        onChange={(e) => input = e.target.value}
      />
      <button onClick={addName}>Add</button>

      <ul>
        {names.map((name) => {
          <li>{name}</li>
        })}
      </ul>
    </div>
  );
}
```

-  pushing names without useState is wrong, React will not know to re-render the component so the new name will not be added to the list, so instead of push, we use setNames() and setInput()
-  when mapping there should be a key to identify each name uniquely
- there should be export default NameList; in the end of the component

```jsx
import { useState } from 'react';

function NameList() {
	const[names, setNames] = useState([]);
	const [input, setInput] = useState('');
	
	function addName() {
		setNames([...names, input]);
	    setInput('');
	}
	
	return (
		<div>
			<input
				value={input}
				onChange={(e) => setInput(e.target.value)}
			/>
			<button onClick={addName}>Add</button>
			
			<ul>
				{names.map((name, index) => {
					<li key={index}>{name}</li>
				})}
			</ul>
			</div>
	);
}

export default NameList;
```

**rewrite question**

this component is supposed to:
-  fetch a list of posts
-  store them in state
-  display each post title in a list

```jsx
import { useState, useEffect } from 'react';

function PostList() {
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    fetch('https://api.example.com/posts')
      .then(res => res.json())
      .then(data => posts = data);
  }, []);

  return (
    <ul>
      {posts.map((post, index) => {
        <li key={index}>post.title</li>
      })}
    </ul>
  );
}
```

corrected:
```jsx
import { useState, useEffect } from 'react';

function PostList() {
	const [posts, setPosts] = useState([]);
	
	useEffect(() => {
		fetch('https://api.example.com/posts')
			.then(res => res.json())
			.then(data => setPosts(data));
			.catch((error) => {
				console.error(error.message});
			});
	}, [])
	
	return (
		<ul>
			{posts.map((post, index) => {
				<li key={index}>{post.title}</li>
			})}
		</ul>
	);
}

export default PostList;
```

**rewrite question**
this component should:
-  let the user type a task
-  add it to a list when clicking a button
-  display all tasks

```jsx
import { useState } from 'react';

function TaskApp() {
  const [tasks, setTasks] = useState([]);
  const [task, setTask] = useState("");

  const addTask = () => {
    if (task !== "") {
      setTasks([...tasks, task]);
      setTask("");
    }
  };

  return (
    <div>
      <input
        value={task}
        onChange={(e) => setTask(e.target.value)}
      />

      <button onClick={addTask}>Add Task</button>

      <ul>
        {tasks.map((task, index) => {
          return <li key={index}>{task}</li>
        })}
      </ul>
    </div>
  );
}

export default TaskApp;
```

**rewrite question**
this component should:
-  fetch a list of products when the component mounts
-  store them in state
-  display each product name in a list
```jsx
import { useState, useEffect } from 'react';

function ProductList() {
  const [products, setProducts] = useState([]);

  useEffect(() => {
    fetch('https://api.example.com/products')
      .then(res => res.json())
      .then(data => {
        setProducts(data);
      });
  }, []);

  return (
    <div>
      <ul>
        {products.map((product, index) => (
          <li key={index}>{product.name}</li>
        ))}
      </ul>
    </div>
  );
}

export default ProductList;
```

**rewrite question**
this component should fetch Pokemon data once when the component mounts and display the names
```jsx
import { useState, useEffect } from 'react';

function Pokedex() {
  const [pokemon, setPokemon] = useState([]);

useEffect(() => {
	fetch('https://pokeapi.co/api/v2/pokemon')
    .then(res => res.json())
    .then(data => setPokemon(data.results));
}, [])

  return (
    <ul>
      {pokemon.map((p) => (
        <li key={p.name}>{p.name}</li>
      ))}
    </ul>
  );
}

export default Pokedex;
```

**rewrite question**
The following component is intended to add items to a list and display them. It contains multiple issues. Identify all problems and rewrite it correctly.
```jsx
import { useState } from 'react';

function ItemList() {
  const [items, setItems] = useState([]);
  const [text, setText] = useState('');

  const addItem = () => {
    items.push(text);
    setText('');
  };

  return (
    <div>
      <input value={text} onChange={(e) => setText(e.target.value)} />
      <button onClick={addItem}>Add</button>

      <ul>
        {items.map(item => (
          <li>{item}</li>
        ))}
      </ul>
    </div>
  );
}

export default ItemList;
```

-  items.push is wrong, we should use `setItems` to add an item into the list
-  items should be mapped using keys so that React can track them during adding, updating and deletion

```jsx
import { useState } from 'react';

function ItemList() {
  const [items, setItems] = useState([]);
  const [text, setText] = useState('');

  const addItem = () => {
    setItems([...items, text]);
    setText('');
  };

  return (
    <div>
      <input value={text} onChange={(e) => setText(e.target.value)} />
      <button onClick={addItem}>Add</button>

      <ul>
        {items.map((item, id) => (
          <li key={id}>{item}</li>
        ))}
      </ul>
    </div>
  );
}

export default ItemList;
```

**rewrite question**
This component fetches data from an API. Identify all issues and rewrite it correctly.
```jsx
import { useState } from 'react';

function Posts() {
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    fetch('https://api.example.com/posts')
      .then(res => res.json())
      .then(data => setPosts(data));
  });

  return (
    <div>
      {posts.map(post => (
        <p key={post.id}>post.title</p>
      ))}
    </div>
  );
}
```

-  useEffect is not imported
-  no dependency array in useEffect, it should contain an empty array since we are loading once on mount
-  no export default Posts at the end
-  posts.map should include the key at the top along with post, before it is declared as a key in p
-  post.title should be in curly brackets

```jsx
import { useState, useEffect } from 'react';

function Posts() {
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    fetch('https://api.example.com/posts')
      .then(res => res.json())
      .then(data => setPosts(data));
  }, []);

  return (
    <div>
      {posts.map((post, id) => (
        <p key={post.id}>{post.title}</p>
      ))}
    </div>
  );
}

export default Posts;
```

**rewrite question**
This component is meant to toggle a boolean state. Identify all issues and rewrite it correctly.
```jsx
import { useState } from 'react';

function Toggle() {
  const [isOn, setIsOn] = useState(false);

  const handleClick = () => {
    setIsOn(!isOn);
    setIsOn(!isOn);
  };

  return (
    <button onClick={handleClick}>
      {isOn ? "ON" : "OFF"}
    </button>
  );
}
```

-  two lines of the same code are redundant - they will have the same effect
- missing export default Toggle

```jsx
import { useState } from 'react';

function Toggle() {
  const [isOn, setIsOn] = useState(false);

  const handleClick = () => {
	  setIsOn(prev => !prev);
  };

  return (
    <button onClick={handleClick}>
      {isOn ? "ON" : "OFF"}
    </button>
  );
}

export default Toggle;
```

**rewrite question**
This component should display a filtered list of items based on user input. Identify all issues and fix it.
```jsx
import { useState } from 'react';

function SearchList() {
  const [query, setQuery] = useState('');
  const items = ['apple', 'banana', 'orange'];

  const filtered = items.filter(item => {
    item.includes(query);
  });

  return (
    <div>
      <input onChange={(e) => setQuery(e.target.value)} />

      <ul>
        {filtered.map(item => (
          <li>{item}</li>
        ))}
      </ul>
    </div>
  );
}
```

-  there is no export default at the end
-  no key to map items, React will not be able to track items
-  `{}` is used without return in const filtered - it returns undefined for every item, so nothing passes the filterc

```jsx
import { useState } from 'react';

function SearchList() {
  const [query, setQuery] = useState('');
  const [items, setItems = useState(['apple', 'banana', 'orange']);

  const filtered = items.filter(item => item.includes(query));

  return (
    <div>
      <input onChange={(e) => setQuery(e.target.value)} />

      <ul>
        {filtered.map((item, index) => (
          <li key={index}>{item}</li>
        ))}
      </ul>
    </div>
  );
}

export default SearchList;
```

**rewrite question**
This component is intended to increment a counter every second. Identify all issues and rewrite it correctly.
```jsx
import { useState, useEffect } from 'react';

function Timer() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    setInterval(() => {
      setCount(count + 1);
    }, 1000);
  }, []);

  return <p>{count}</p>;
}
```

-  setInterval should be used inside of a const variable, so we can use it for a cleanup function
-  there is no cleanup function to clear the interval after timer unmounts or before re-running the effect
-  count should be updated based on the previous count
-  no export default

```jsx
import { useState, useEffect } from 'react';

function Timer() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    const interval = setInterval(() => {
      setCount(count => count + 1);
    }, 1000);
    
    return () => clearInterval(interval)
  }, []);

  return <p>{count}</p>;
}

export default Timer;
```

**rewrite question**
This component is meant to pass data from a parent to a child. Identify all issues and fix it.
```jsx
function Parent() {
  const message = "Hello";

  return <Child message={message}/>;
}

function Child(props) {
  return <p>{props.message}</p>;
}
```

-  the parent calls the child, but never passes the message

**rewrite question**
This component is intended to fetch data from a Django REST API and display it. 

```jsx
import { useState, useEffect } from 'react';

function Products() {
  const [products, setProducts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    fetch('http://localhost:8000/api/products')
      .then(res => {
        if (!res.ok) throw new Error("Failed to fetch");
        return res.json();
      })
      .then(data => {
        setProducts(data);
        setLoading(false);
      })
      .catch(err => {
        setError(err.message);
        setLoading(false);
      });
  }, []);

  if (loading) return <p>Loading...</p>;
  if (error) return <p>Error: {error}</p>;

  return (
    <ul>
      {products.map(product => (
        <li key={product.id}>{product.name}</li>
      ))}
    </ul>
  );
}

export default Products;
```

**rewrite question**
This component is meant to fetch and display users. Identify all issues and rewrite it correctly.
```jsx
import { useState, useEffect } from 'react';

function Users() {
  const [users, setUsers] = useState([]);

  useEffect(() => {
    fetch('http://localhost:8000/api/users')
      .then(res => res.json())
      .then(data => setUsers(data));
  }, []);
  
  if (loading) return <p>Loading...</p>;
  if (error) return <p>Error: {error} </p>;

  return (
    <ul>
      {users.map((user, index) => (
        <li key={index}>{user.name}</li>
      ))}
    </ul>
  );
}

export default Users;
```

-  missing export default
-  missing key for user
-  missing loading and error states
-  missing dependency array for useEffect

**rewrite question**
This component is intended to update input state and display it. Identify all issues and fix it.
```jsx
import { useState } from 'react';

function InputDisplay() {
  const [text, setText] = useState("");

  return (
    <div>
      <input onChange={(e) => setText(e.target.value)} />
      <p>{text}</p>
    </div>
  );
}

export default InputDisplay;
```

-  setText not used in input
-  no export default

**rewrite question**
This component is intended to fetch data using `async/await`. Identify all issues and rewrite it correctly.
```jsx
import { useState, useEffect } from 'react';

function Posts() {
  const [posts, setPosts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    async function fetchData() {
      const res = await fetch('http://localhost:8000/api/posts');
      
      if (!res.ok) {
	      setError("Fething data failed");
	      setLoading(false);
	      return;
      }
      
      const data = await res.json();
      setPosts(data);
      setLoading(false)
    }

    fetchData();
  }, []);

  return (
    <ul>
      {posts.map(post => (
        <li key={post.id}>{post.title}</li>
      ))}
    </ul>
  );
}

export default Posts;
```

-  fetchData should be called in the end by using `()`
-  post should use a key
-  no export default at the bottom
-  no res.ok check after the fetch with early return
-  no loading and error states
-  no await for json data

**rewrite question**
This component tries to handle loading state. Identify all issues and fix it.
```jsx
import { useState, useEffect } from 'react';

function Data() {
  const [data, setData] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    async function fetchData() {
      const res = await fetch('/api/data');
      const json = await res.json();
      setData(json);
      setLoading(false);
    }
    
    fetchData();
  }, []);

  if (loading) return <p>Loading...</p>;

  return (
    <div>
      {data.map(item => <p key={item.id}>{item.name}</p>)}
    </div>
  );
}

export default Data;
```

-  setLoading should be set to false after we set json data
-  no error checks and error state - if there is an error, loading must be stopped as well
-  no key usage for item in return
-  no export default
-  api is not imported at the top

