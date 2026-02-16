***not coming up in the exam setting*** 
- model context protocol
-  allows you to write functions and introduce them to LLM so it can run them for you
-  they can do anything you program

example of tracking assignments for college using an LLM (storing assignments as a list and give itself access to them as needed)
-  you write a small server yourself, similar to FLASK but with a difference in the end (you need to comment your code for LLM to read them so it knows what to do)
-  JSON file stores your assignments, it will have a few methods in it: a list method, an add method etc.
-  using fast MCP (library), we create MCP server

```python
# read and write function
. . .

# mcp tools writen in pydoc syntax (a way to comment in python)
@mcp.tool()
def add_assignment:
	"""Add a new assignment.
	
	Args:
		module: Module code e.g CSC1040
		title: title of the module e.g. Full Stack
		...
	"""
		
		
# Run
if __name__ = "__main__":
	mcp.run()
```

-  you don't run this for a local version
-  you need to run it in Claude desktop
-  settings - developer - edit config - open `.json` file
-  now you can ask Claude to return all of your assignments and their status, add new assignment etc.
-  it can modify your data - e.g you can tell it "i have an assignment in 2 weeks from now" and it will assign a correct due date in the `.json` file

disadvantage: limited context - you can't make the server do everything because you run out of memory
-  the model understands everything, but can't do anything
-  you need to be aware of how long your comments are and how many functions do you want the LLM to do