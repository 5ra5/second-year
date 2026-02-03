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
