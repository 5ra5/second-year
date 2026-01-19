## Making a Process

```python
from multiprocessing import *

def sayHi():
    print("Hi from process", current_process().pid)

def procEx():
    print("Hi from process", current_process().pid, "(parent process)")

    otherProc = Process(target=sayHi, args=())

    otherProc.start()

procEx()
```

output:
```
Hi from process 20416 (parent process)
Hi from process 20417
```

 -  first we call `procEx` = the first line in that function prints a simple message about what process is running
 -  function `current_process()` = returns a Process object representing the currently running process, defined by the multiprocessing module.
 -  **pid** = process identifier
 -  `current_process().pid` = returns the pid of the currently running process (what we print)
 -  in the second line we call the Process constructor, which creates a new Process object, but does not start a new process.
 -  `otherProc.start()` = starts the process by changing the state of the Process object it was called on (otherProc) so that it is made available for execution

**make a child process do some task**:
**1.** create a Process object using the constructor `Process()`
**2.** start the Process using the `start` function

-  in this case, the child process executes the `sayHi()` function because it was specified in the constructor call

## creating multiple child processes

```python
from multiprocessing import *

def sayHi():
	print("Hi from process", current_process().pid)

def procEx():
	print("Hi from process", current_process().pid, "(parent process)")
	proc1 = Process(target=sayHi, args=())
	proc2 = Process(target=sayHi, args=())
	proc3 = Process(target=sayHi, args=())

  

proc1.start()
proc2.start()
proc3.start()

procEx()
```

output:
```
Hi from process 21817 (parent process)
Hi from process 21822
Hi from process 21823
Hi from process 21824
```
- each process uses the same `sayHi` function defined before, but each process executes that function independent of the others, so each child process has its own pid

```python
from multiprocessing import *

def sayHi2(n):
	print("Hi", n, "from process", current_process().pid)

def greetings():
	name = str(input("Type in your name: "))
	process = int(input("How many greetings you want: "))
	for proc in range(process):
		proc = Process(target=sayHi2, args=(name,))
		proc.start()

greetings()
```

anonymous Process objects are created like this. they are called anonymous because they are not stored in any variable name, they are executed right away
```python
proc = Process(target=sayHi2, args=(name,)).start()
```