# basics

-  1999
-  frontend
**difference between Java and JavaScript**
-  look similar because JavaScript was based on Java
-  Java static and OOP, JS dynamic and not OOP

`node` = JS interpreter
-  good to test out things and debug

list comprehension
```js
let names = ['John', 'Paul', 'Georgr', 'Ringo'].forEach(x)=>console.log(x));
```

output:
```
John
Paul
George
Ringo
```

**data types**
```js
strings "A"
ints 34
floats 42.0
boolean true, false
lists [1,2,3], [1,'a',5.0]
dictionaries {"name":"Michael"} // you need to use double quotes in JS
null // None - something that doesn't have a value (an empty box)
undefined // something that doesn't exist (no box)
```

**variables**
```js
let, const

let a = 'A';
const b = 5;
```

`let` = mutable, can change the value
`const` = value cannot change at runtime

```js
const API_SERVER_LOCATION = "http://127.0.0.1:8000"
```
-  we use const for things that are not meant to be changed
-  use upper case letters to name const variables
-  const variables optimise your program a lot because they don't make compiler do a lot of work like when you change c from something short to something very long
```js
let c = 'Hello';
c = "ajdshkjasdhgkjajdfghakj"
const d = 'Hello';
```


**operators**
```js
5+6
5-6
5*6
5**2
5/2
10%3
a++; // python a += 1
b--; // python a -= 1
```

`%` = comes up a lot in job interviews (fizz/buzz example)

**2 types of equality in JS**
JS does conversion on the run type inversion
does the value match?
```js
// this would be false in python
> 5 == '5'
true

> 5 != '5'
false

> 5 !== '5'
true
```

does the value and the data type match?
```js
> 5 === '5'
false
```

**example of syntax**
```js
let temperature = 32;
/// &&, ||,
if (temperature > 50){
	console.log("too hot")
}
else if (temperature == 32){
	console.log("just right")
}
else{
	console.log("everything else")
}
```

**switch statement**
-  important to use `break` with each case
```js
let day = 5;
switch(day){
	case 1:
		console.log("Monday");
		break;
	case 2:
		console.log("Tuesday");
		break;
	default:
		cosole.log("day");
		break;
}
```

**loops**
```js
for (let i=0; i<500; i++){
	console.log(i);
}

while(){
	...
}

do{
	...
}while()
```

**traversing through an array**
```js
let names = ['A', 'B', 'C', 'D'];
for(let i=0; i < names.length; i++){
	console.log(names[i]);
}

// optimised version
for(let name of names){
	console.log(name)
}
```

very common: passing functions as an argument to another function
```js
function print(x){
	console.log(x);
}

name.forEach(print);

// optimised version - anonymous function
names.forEach(function(x){
	console.log(x);
});

// even more optimised
(x)=>console.log(x)
names.forEach((x)=>console.log(x))
```

two identical things - 1 is just a shortcut
```js
let square = (x)=>x**2; // 1

function square(x){ // 2
	return x**2;
}
```

an example of a value of a variable being a function
```js
{
	"name":"Michael",
	"sayName": ()=>console.log("Michael");
}

nm.sayName();
nm['sayName']();
nm['sayName'] = ()=>{}
```

using 2 values in a function
```js
(x,y)=>x+y;
```

**mapping & filtering**
applying a function to each name in the array - mapping
```js
let names = ['John', 'Mark', 'Luke'];
names.map((x) => 'hello $(x)')
```