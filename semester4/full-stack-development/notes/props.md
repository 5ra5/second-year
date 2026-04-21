passing props
```jsx
<PageTitle text="Welcome to the Dice Roller" />
<PageTitle text="About This App" />
```

```jsx
function PageTitle({ text }) {
	return <h1>{text}</h1>;
}
```

string values use quotes, everything else uses `{}`
```jsx
<ScoreDisplay score={42} isWinner={true} rolls={[3, 6, 1]} />
```

default prop values
```jsx
function PageTitle({ text = "My React App" }) {
  return <h1>{text}</h1>;
}

// Both of these work:
<PageTitle />                        // renders: My React App
<PageTitle text="Dice Roller" />     // renders: Dice Roller
```

