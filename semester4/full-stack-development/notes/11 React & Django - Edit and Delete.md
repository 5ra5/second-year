
show individual author page
-  when it turns on - get the ID from the URL and then make a call to the backend ("get me that specific author")
```jsx
import {useState, useEffect} from "react";
import {use Params, Link} form "react-router-dom";
import api from "../api/api";

function AuthorIndividual() {
	const {id} = useParams();
	const [author, setAuthor] = useState(null);
	const [loading, setLoading] = useState(true);
	const[error, setError] = useState(null);
	
	useEffect(() =>{
		async function fetchAuthor(){
			const response = await api(`/api/authors/${id}`);
			if(! response.ok){
				setError('Author not found');
				setLoading(false);
				return;
			}
			const data = await response.json();
			setAuhor(data);
			setLoading(false);
		}
		fetchAuthor();
	}, [id])
	
	if(loading) return <p>Loading</p>
	if(error) return <p>{error}</p>

	return (
		<div>
			<Link to="/authors">Back to Auhor List</Link>
			<h1>{author.name}</h1>
			<p>Birthday {author.birth_date}</p>
	)
}

export default AuthorIndividual;
```

remember to include navigation links, don't hard type URLs to get around the app (3rd year project)

## form to create a new author - AuthorCreate

implement event handler which updates as the user interacts with the app
have a dictionary for all data to avoid repetition
```jsx
const [formData, setFormData] = useState({
		name:'',
		birth_year:'',
		genre:'',
	})
```

don't update everything separately, do a general event handler
```jsx
import {useState} from "react";
import (userNavigate) from "react-router-dom";
import api from "../api/api";

function AuthorCreate(){
	const [formData, setFormData] = useState({
		name:'',
		birth_year:'',
		genre:'',
	})
	const [error, setError] = useState(null);
	const navigate = useNavigate();
	
	// general event handler
	function handleChange(e){
		setFormData({...formData, [e.target.name]:e.target.value});
	}
	
	/*
		what general event handler does
		{birth_year: '',
		genre:''
		name: whatever i type in}
	*/
	
	// bounce the user to the next page that confirms the data they have put in
	async function handleSubmit(e){
		e.preventDefault();
		setError(null);
		const response = await api('/api/authors', {
			method:'POST',
			body: JSON.stringify(formData)
		});
		if(!response.ok){
			const data = await response.json();
			setError(data);
			return;
		}
		const newAuthor = response.json();
		navigate(`/authors/${newAuthor.id}`)
	}

	return (
		<form onSubmit={handleSubmit}>
		<h1>Add Author</h1>
		{error && (
			<ul>
			{// for every field in messages, you get a list of all possible errors
			// general form error handling
				{
					Object.entries(error).map(([field, messages])=>(
						<li key={field}><strong>{field}:</strong> {messages.join(', ')} </li>
					))
				}
		)}
		
		</form>
		<div>
			<label htmlFor="name">Name</label>
			<input name="name" value={formatData.name} onChange={handleChange} />
		</div>
		<div>
		{/*
			06/07/10
			problem with this - what is month, day, year???
			you can't allow users to type in whatever they want
		*/}
			<label htmlFor="birth_year">Birthday</label>
			<input name="birth_year" type="date" value={formData.birth_year} onChange={handleChange} />		
		</div>
		<div>
			<label htmlFor="genre">Genre</label>
			<input name="genre" value={formatData.genre} onChange={handleChange} />
		</div>
}

export default AuthorCreate;
```