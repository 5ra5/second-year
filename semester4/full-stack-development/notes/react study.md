focus on:
week 9 - react intro
-  components (functional components) - what a component is, how it returns JSX
-  JSX - embedding JS with {}, returning JSX properly, expressions vs text
-  props - props are read-only, passed from parent -> child
-  state (useState) - how to declare state, updating state, re-rendering

week 9 - react lifecycle
-  useEffect - when it runs, dependency array ([] -> once after mount, [x] -> when x changes), no array -> every render
-  side effects - fetching data, timers(setInterval), DOM updates
-  cleanup function - return() => clearInterval(interval);
-  stale state in useEffect - count + 1 inside interval -> wrong unless handled properly

week 10 - react + DRF (data fetching)
-  fetching data - must be inside useEffect, use .then() or async/await, update state with response
-  avoid infinite loops - if fetch is outside useEffect (component re-renders, fetch runs again, infinite loop)

week 11 - react + DRF (continued)
-  rendering lists from data - users.map(user => ...)
-  keys in lists - must exist, must be unique

 lab 6
-  forms/inputs - controlled components: value={state} onChange={...}
-  handling events - onClick, onChange
-  updating arrays in state - correct (setTodos([...todos, input]);, wrong(todos.push(input));