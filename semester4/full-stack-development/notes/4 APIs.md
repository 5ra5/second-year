-  application programmer interface
-  a library or a contract that you give to other programmers
-  to send data in APIs we want to use JSON (JavaScript Object Notation), not HTML or XML
```json
{
	"books": [
		{
		"author": "Frank Herbert",
		"title": "Dune"
		}
	]
}
```

-  this is easy to read for JavaScript and it is also easily translatable into python, where this would turn into a books dictionary
-  this is how to send data, but we don't do anything with it

we use **Flask** for this instead of Django. Flask doesn't have as many set up settings as Django, we need to make our database manually for example

installing flask: using uv instead of pip
```shell
uv add flask
uv add requests
```

setting up a simple flask server
```python
# server.py
from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route("/", methods=["GET"])
def main():
	return "Hello from csc1040-flask!"
	
if __name__ == "__main__":
	app.run(debug=True, host='0.0.0.0', port=8080)
```

to run the server
```shell
uv run python server.py
```

`jsonify` = setting a very important HTTP header called the Application Content Type, by sending it that, the browser knows it's JSON


see the output of the website in terminal by running this
```shell
curl http://127.0.0.1:8080/asjson
```

```python
# client.py
import requests
import json

if __name__ == "__main__":
	response = requests.get('http://127.0.0.1:8080/asjson')
	json_data = json.load(response.json())
```

```
uv run client.py
uv run python server.py
```


add two numbers
```python
# server.py
from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route("/", methods=["GET"])
def main():
	return "Hello from csc1040-flask!"
	
@app.route("/asjson", methods=["GET"])
def asjson():
	data = {
		"message" = "This is a JSON response",
		"status" : "success"
	}
	return jsonify(data)
	
def add_numbers("/add", methods=["POST"]):
	data = request.get_json()
	num1 = data['a']
	num2 = data['b']
	return jsonify({"result": num1 + num2})
	
if __name__ == "__main__":
	app.run(debug=True, host='0.0.0.0', port=8080)
```

```python
# client.py
import requests
import json

def add_numbers(a, b):
	url = 'http://127.0.0.1:8080/add'
	payload = {'a' : a, 'b' : b}
	response = requests.post(url, json=payload)
	return jsonify({"result" : response})
	
if __name__ == "__main__":
	response = requests.get('http://127.0.0.1:8080/asjson')
	print(reponse.json())
	print(add_numbers(5, 7))
```

-  you should document your APIs, use open API specs `openpai.yami`
-  you describe what your API is = describe all your functions and responses
-  use swagger interface = it allows you to interact with all functions, you can see what they do and even try them out
```shell
localhost:8080/docs
```

# Website notes

**In Django**:

-  the view fetches the data and decides how to display it
-  the template receives Python objects and converts them to HTML

fundamental idea behind APIs: your server becomes a *data service* that any application can talk to
-  backend provides data, frontend presents it

web API's use HTTP request protocol because HTTP is universal (any programming language can make HTTP requests)

JSON = JavaScript Object Notation
-  Human-readable
-  Language-agnostic
-  Lightweight
-  Maps to native data structures

## request-response cycle

1.  the client constructs an HTTP request and sends it to a URL (method, URL, headers, body)
2.  the server receives the request, processes it, and constructs a response
3.  the server sends the HTTP response back to the client (status, headers, body)
4.  the client receives and processes the response

-  same as when your browser loads a webpage
-  difference is what's in the response: a webpage returns HTML that the browser renders visually; an API returns JSON that the client processes programmatically

### anatomy of an HTTP request

**method** - what action do you want to perform?

| Method | Purpose               | Example                    |
| ------ | --------------------- | -------------------------- |
| GET    | Retrieve data         | Get a list of books        |
| POST   | Create new data       | Add a new book             |
| PUT    | Replace existing data | Update a book completely   |
| PATCH  | Partially update data | Change just a book's price |
| DELETE | Remove data           | Delete a book              |
**URL** - where is the resource you want to interact with? URL identifies what you're operating on:

```
https://api.bookshop.com/books/        # All books
https://api.bookshop.com/books/42/     # Book with ID 42
https://api.bookshop.com/authors/7/    # Author with ID 7
```

**headers** - metadata about the request. the most important one of APIs in `Content-Type`, which tells the server what format your data is in:

this tells the server "I'm sending you JSON data"
```
Content-Type: application/json
```

**body** - the actual data you're sending (for POST, PUT, PATCH requests)
```json
{
	"title": "The Hobbit",
	"author_id" : 1,
	"year" : 1937
}
```

* GET and DELETE requests typically don't have a body - you're just asking for or removing something, not sending data

### anatomy of an HTTP response

**Status Code** - A number indicating what happened. You've seen these before - 404 means "not found", 500 means "server error". APIs rely heavily on status codes to communicate success or failure:

|Code|Meaning|When It's Used|
|---|---|---|
|200|OK|Request succeeded, here's the data|
|201|Created|New resource was created successfully|
|400|Bad Request|Your request was malformed or invalid|
|401|Unauthorized|You need to authenticate first|
|403|Forbidden|You're authenticated but not allowed to do this|
|404|Not Found|The resource doesn't exist|
|500|Internal Server Error|Something went wrong on the server|

**Headers** - Metadata about the response. The server also sends `Content-Type` to tell you what format the response is in:
```
Content-Type: application/json
```

**body** - the actual data being returned
successful
```json
{
    "id": 42,
    "title": "The Hobbit",
    "author": "J.R.R. Tolkien",
    "year": 1937
}
```

errors
```json
{
    "error": "Validation failed",
    "details": {
        "year": "Must be a positive integer"
    }
}
```


view returns data, not pages
the client decides how to present that data
```python
# API view returning JSON
from django.http import JsonResponse

def book_list_api(request):
	books = Book.objects.all()
	data = [{'id' : b.id, 'title' : b.title} for b in books]
	return JsonResponse(data, safe=False)
```

**Server**: The application that holds the data and enforces the rules. It waits for requests, processes them, and sends responses. In our case, this is our Django (or Flask) application running on a computer somewhere. The server is the _authority_ - it decides what data exists, who can access it, and what operations are allowed.

**Client**: Any application that makes requests to the server. This could be a web browser, a mobile app, a Python script, another server, or even a command-line tool like `curl`. The client is the _consumer_ - it asks for data and decides how to display or use it.

-  **the server doesn't know or care what the client is**
-  **One server, many clients**: This is the primary benefit. Build your API once, and any number of different applications can use it.
-  independent development
-  independent deployment
-  scalability
-  technology freedom

### the API contract

contract: what requests the server accepts and what response it returns
documented as API documentation, which specifies:
-  what endpoints exist(`/books/`, `/authors/`, etc)
-  what methods each endpoint accepts (GET, POST, etc.)
-  what data to send in requests (JSON format, required fields)
-  what data comes back in responses (JSON format, field names)
-  what status codes indicate success or failure

**why uv instead of pip**
-  speed
-  reliability - better dependency resolution
-  reproducibility - `uv.lock`, `uv sync`
-  project management - handles virtual environment automatically
-   modern tooling

```python
# server.py
from flask import Flask, request, jsonify

app = Flask(__name__)

# In-memory storage for our list of numbers
# In a real application, this would be a database
numbers = []


@app.route('/add', methods=['POST'])
def add_two_numbers():
    """Add two numbers together and return the result."""
    data = request.get_json()

    if data is None:
        return jsonify({'error': 'Request body must be JSON'}), 400

    if 'a' not in data:
        return jsonify({'error': 'Missing required field: a'}), 400
    if 'b' not in data:
        return jsonify({'error': 'Missing required field: b'}), 400

    if not isinstance(data['a'], (int, float)):
        return jsonify({'error': 'Field "a" must be a number'}), 400
    if not isinstance(data['b'], (int, float)):
        return jsonify({'error': 'Field "b" must be a number'}), 400

    result = data['a'] + data['b']
    return jsonify({'result': result})


@app.route('/numbers', methods=['GET'])
def get_numbers():
    """Return the current list of numbers."""
    return jsonify({
        'numbers': numbers,
        'count': len(numbers)
    })


@app.route('/numbers', methods=['POST'])
def add_number_to_list():
    """Add a new number to the list."""
    data = request.get_json()

    if data is None:
        return jsonify({'error': 'Request body must be JSON'}), 400

    if 'number' not in data:
        return jsonify({'error': 'Missing required field: number'}), 400

    if not isinstance(data['number'], (int, float)):
        return jsonify({'error': 'Field "number" must be a number'}), 400

    numbers.append(data['number'])

    return jsonify({
        'message': 'Number added successfully',
        'numbers': numbers
    }), 201  # 201 Created - indicates a new resource was created


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=8080)
```

`from flask import Flask, request, jsonify` - 
-  `Flask` = the application class
-  `request` = gives us access to the incoming HTTP request
-  `jsonify` = converts Python dictionaries to JSON responses

`app = Flask(__name__)` - Creates our Flask application. The `__name__` argument tells Flask where to find resources

`numbers = []` - our in-memory storage. in a real application, this would be a database. note that this list resets every time you restart the server.

`@app.route('/add', methods=['POST'])` - this decorator registers our function as a handler for POST requests to `/add`

`request.get_json()` - parses the request body as JSON and returns a Python dictionary. if the body isn't valid JSON, this returns `None`

**Validation**
1.  check the request body was valid JSON
```python
if data is None:
        return jsonify({'error': 'Request body must be JSON'}), 400
```

2.  check required fields are present
```python
if 'a' not in data:
        return jsonify({'error': 'Missing required field: a'}), 400
    if 'b' not in data:
        return jsonify({'error': 'Missing required field: b'}), 400
```

3. check fields are correct type (numbers)
```python
if not isinstance(data['a'], (int, float)):
        return jsonify({'error': 'Field "a" must be a number'}), 400
    if not isinstance(data['b'], (int, float)):
        return jsonify({'error': 'Field "b" must be a number'}), 400
```

-  if any check fails, we return a 400 Bad Request with an error message

`@app.route('/numbers, methods=['GET'])` - the GET endpoint doesn't need a request body. it simply returns the current state of our `numbers` list. there's no validation needed - GET requests are just asking for data

`@app.route('/numbers', methods=['POST'])` - same URL as the GET endpoint, but different method. flask routes to the correct function based on the HTTP method. this adds a number to our list and returns **201 Created**

`jsonify({'result' : result})` - converts our python dictionary to a JSON response. flask automatically sets the `Content-Type: application/json` header

`app.run(debug=True)` - starts the development server. the `debug=True` flag enables auto-reloading when you change the code

```python
# client.py
import requests

BASE_URL = 'http://localhost:8080'


def add_numbers(a, b):
    """Call the addition API and return the result."""
    response = requests.post(f'{BASE_URL}/add', json={'a': a, 'b': b})

    if response.status_code == 200:
        return response.json()['result']
    else:
        raise Exception(f"API error: {response.json().get('error', 'Unknown error')}")


def get_numbers():
    """Get the current list of numbers from the API."""
    response = requests.get(f'{BASE_URL}/numbers')
    return response.json()


def add_number_to_list(number):
    """Add a number to the list via the API."""
    response = requests.post(f'{BASE_URL}/numbers', json={'number': number})

    if response.status_code == 201:
        return response.json()
    else:
        raise Exception(f"API error: {response.json().get('error', 'Unknown error')}")


if __name__ == '__main__':
    # Test the /add endpoint
    print("Testing /add endpoint:")
    print(f"  5 + 3 = {add_numbers(5, 3)}")
    print(f"  10 + 20 = {add_numbers(10, 20)}")

    # Test the /numbers endpoints
    print("\nTesting /numbers endpoints:")

    # Check the initial list (should be empty)
    result = get_numbers()
    print(f"  Initial list: {result['numbers']} (count: {result['count']})")

    # Add some numbers
    add_number_to_list(42)
    add_number_to_list(3.14)
    add_number_to_list(100)

    # Check the list again
    result = get_numbers()
    print(f"  After adding numbers: {result['numbers']} (count: {result['count']})")
```

`import requests` - the `requests` library is python's standard way to make HTTP requests (installed with `uv add requests`)

`BASE_URL` - we define the server URL once and reuse it

`requests.post(...)` - makes a POST request to the specified URL
the `json=` parameter automatically:
1.  converts the python dictionary to JSON
2.  sets the `Content-Type: application/json` header
3.  puts the JSON in the request body

`requests.get(...)` - makes a GET request. no `json=` parameter because GET requests don't have a body

`response.status_code` - the HTTP status code (200, 201, 400, etc.)
`response.json()` - parses the response body as JSON and returns a python dictionary

```bash
curl -X POST http://localhost:8080/add \
  -H "Content-Type: application/json" \
  -d '{"a": 5, "b": 3}'
```

`-X POST` - use the POST method
`-H "Content-Type: application/json"` - set the content-type header
`-d '{"a" : 5, "b" : 3}` - the request body (our JSON data)

**important:**
1.  **GET requests retrieve data** without modifying anything - you can call them repeatedly with the same result
2.  **POST requests create or modify data** - each call changes the server's state
3.  **The API doesn't care what client is calling it** - curl, Python, JavaScript, a mobile app - they all get the same responses

### swagger UI

```python
# server.py
import os
from flask import Flask, request, jsonify, send_from_directory
from flask_swagger_ui import get_swaggerui_blueprint

app = Flask(__name__)

# Get the directory where this script is located
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

# In-memory storage for our list of numbers
numbers = []

# Swagger UI configuration
SWAGGER_URL = '/docs'  # URL for Swagger UI
API_URL = '/openapi.yaml'  # URL for the OpenAPI spec

swagger_ui_blueprint = get_swaggerui_blueprint(
    SWAGGER_URL,
    API_URL,
    config={'app_name': "Numbers API"}
)

app.register_blueprint(swagger_ui_blueprint, url_prefix=SWAGGER_URL)


@app.route('/openapi.yaml')
def serve_openapi_spec():
    """Serve the OpenAPI specification file."""
    return send_from_directory(BASE_DIR, 'openapi.yaml', mimetype='text/yaml')


@app.route('/add', methods=['POST'])
def add_two_numbers():
    """Add two numbers together and return the result."""
    data = request.get_json()

    if data is None:
        return jsonify({'error': 'Request body must be JSON'}), 400

    if 'a' not in data:
        return jsonify({'error': 'Missing required field: a'}), 400
    if 'b' not in data:
        return jsonify({'error': 'Missing required field: b'}), 400

    if not isinstance(data['a'], (int, float)):
        return jsonify({'error': 'Field "a" must be a number'}), 400
    if not isinstance(data['b'], (int, float)):
        return jsonify({'error': 'Field "b" must be a number'}), 400

    result = data['a'] + data['b']
    return jsonify({'result': result})


@app.route('/numbers', methods=['GET'])
def get_numbers():
    """Return the current list of numbers."""
    return jsonify({
        'numbers': numbers,
        'count': len(numbers)
    })


@app.route('/numbers', methods=['POST'])
def add_number_to_list():
    """Add a new number to the list."""
    data = request.get_json()

    if data is None:
        return jsonify({'error': 'Request body must be JSON'}), 400

    if 'number' not in data:
        return jsonify({'error': 'Missing required field: number'}), 400

    if not isinstance(data['number'], (int, float)):
        return jsonify({'error': 'Field "number" must be a number'}), 400

    numbers.append(data['number'])

    return jsonify({
        'message': 'Number added successfully',
        'numbers': numbers
    }), 201


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=8080)
```

`from flask_swagger_ui import get_swaggerui_blueprint` - import the Swagger UI blueprint generator

`SWAGGER_URL = '/docs'` - the URL where Swagger UI will be available

`API_URL = '/openapi.yaml` - the URL where the OpenAPI spec is served (Swagger UI will fetch this)

`get_swaggerui_blueprint(...)` - creates a flask blueprint that serves the swagger UI static files

`app.register_blueprint(...)` - mounts the Swagger UI blueprint at `/docs`

`BASE_DIR` - we calculate the absolute path to the directory containing our script. this ensures we can find `openapi.yaml` regardless of which directory we run the server from

`send_from_directory(BASE_DIR, 'openapi.yaml', ...)` - serves a file from a specific directory. this is more reliable than `send_file()` with a relative path, which can fail depending on your current working directory

recap of what we have:
`.python-version`
`pyproject.toml` = dependencies managed by uv
`uv.lock` = locked versions for reproducibility
`openapi.yaml` = API contract/specification
`server.py` = Flask API server
`client.py` = python client
