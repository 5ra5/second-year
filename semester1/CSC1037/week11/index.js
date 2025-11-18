// index.js

function greet(name, callback) {
    console.log("Hello, " + name);
    callback();
}

function sayGoodbye() {
    console.log("Goodbye!");
}

// Call the greet function and pass sayGoodbye as a callback
greet("Alice", sayGoodbye);