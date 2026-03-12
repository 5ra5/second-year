components = functions split between different files - each function does a small aspect of functionality
we need to fetch data because front-end itself is dumb

example: using Pokemon API to fetch data

-  this will make infinite fetches
-  Pokemon loads, then we fetch our data and we get our Pokemon
-  it automatically reloads
-  this causes an infinite loop
```jsx
function PokemonCard() {
	const [pokemon, setPokemon] = useState(null);
	
	fetch("http://localhost/api/v2/pokemon/15").then(
		resp=>resp.json()
	).then(json=>setPokemon(json))
	
	if (poemon == null){
		return{
			<p>Loading</p>
		}
	} else {
		return (
			<div>
			<h2>{pokemon.name}</h2>
			<img src="{pokemon.sprites.front_default}" />
			</div>
		)
	}
}

export default PokemonCard;
```

how to fix it: useEffect
```jsx
import {useState, useEffect} from "react";

function PokemonCard() {
	const [pokemon, setPokemon] = useState(null);
	const [error, setError] = useState(null);
	const [loading, setLoading] = useState(null);
	
	useEffect(()=>{
		async function fetchPokemon(){
			setLoading(true);
			setError(null);
			const response = await fetch("http://localhost/api/v2/pokemon/${name}");
			if (! response.ok){
				setError('Request failed for ${name} ${response.status}');
				setLoading(false);
				return;
			}
		}	
	}, [name]) // run only once when the component finishes loading
	
	if(loading) return <p>Loading</p>
	if(error) return <p>{error}</p>
		
	const types = pokemon.types.map(t=>t.type.name).join(', ');
	
	return (
		<div>
		<h2>{pokemon.name}</h2>
		<img src="{pokemon.sprites.front_default}" />
		<p>Types {types}</p>
		<p>Height: {pokemon.height}cm</p>
		<p>Weight: {pokemon.weight}m</p>
		</div>
	)

}

export default PokemonCard;
```

```jsx
function App() {
	return(
		<PokemonCard name="charizard"/>
		<PokemonCard name="pikachu"/>
	)
}
```

```jsx
// searchbox.jsx

function SearchBox({value, onSearch}){
	return (
		<input value={value} onChange={e => onSearch(e.target.value)} placeholders = "Search for a pokemon" />
	)
}

export default SeachBox;
```

combine everything together
```jsx
// pokedex
import {useState, useEffect} from "react";
import SearchBox from "./SearchBox";
import PokemonCard from "./PokemonCard";

function Pokedex(){
	const [query, setQuery] = useState('');
	const [results, setResults] = useState([]);
	const [loading, setLoading] = useState(false);
	const [error, setError] = useState(null);
	
	useEffect(() =>
	
		if (!query){
			setResults([])
			return;
		}
		async function search(){
			setLoading(true);
			setError(null);
			const response = await fetch("http://localhost/api/v2/pokemon/${query}")
			if(!response.ok){
				setError('Search failed');
				setLoading(false);
				return;
			}
			
			const data = await response.json()
			setResults(data.results)
			setLoading(false)
		}
		search();
	}, [query])
	
	return(
		<div>
			<SearchBox value={query} onSearch={setQuery} />
			{loading && <p>Searching ...</p>}
			{errpr && <p>Error: {error}</p>}
			<div>
				{results.map(result.map)}
			</div>
		</div>
	)
}

export default Pokedex;
```

```jsx
function App() {
	return(
		<Pokedex />
	)
}

export default App
```