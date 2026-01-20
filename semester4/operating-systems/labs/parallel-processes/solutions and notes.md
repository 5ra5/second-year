## making a process

```python
# basic1.py
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
# basic2.py
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
# manyGreetings.py
from multiprocessing import *

def sayHi2(n):
	print("Hi", n, "from process", current_process().pid)

def manyGreetings():
	print("Hi from process", current_process().pid, "(main process)")
	name = "Jimmy"
	
	p1 = Process(target=sayHi2, args=(name,))
	p2 = Process(target=sayHi2, args=(name,))
	p3 = Process(target=sayHi2, args=(name,))

	p1.start()
	p2.start()
	p3.start()

manyGreetings()
```

```python
# manyGreetings2.py
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

## execution order and resource contention

```python
# manyGreetings3.py
from multiprocessing import *

def sayHi3(personName):
	print("Hi", personName, "from process", current_process().name, "- pid", current_process().pid)

def manyGreetings3():
	print("Hi from process", current_process().pid, "(parent process)")
	personName = "Jimmy"

	for i in range(10):
		Process(target=sayHi3, args=(personName,), name=str(i)).start()

manyGreetings3()
```

3 outputs are possible, but the parent process is always printed first: 
1.  all processes are printed in order
2.  processes are printed in a random order
```
Hi from process 14483 (parent process)
Hi Jimmy from process 0 - pid 14488
Hi Jimmy from process 1 - pid 14489
Hi Jimmy from process 2 - pid 14490
Hi Jimmy from process 3 - pid 14491
Hi Jimmy from process 4 - pid 14492
Hi Jimmy from process 5 - pid 14493
Hi Jimmy from process 6 - pid 14494
Hi Jimmy from process 7 - pid 14495
Hi Jimmy from process 8 - pid 14496
Hi Jimmy from process 9 - pid 14497
```

3. processes are all mixed up
```
Hi from process 14528 (parent process)
Hi JimmyHi Jimmy from process 1 - pid 14534
 from process 0 - pid 14533
Hi Jimmy from process 2 - pid 14535
Hi Jimmy from process 3 - pid 14536
Hi Jimmy from process 4 - pid 14537
Hi Jimmy from process 6 - pid 14539
Hi Jimmy from process 5 - pid 14538
Hi Jimmy from process Hi Jimmy7  from process- pid  8 14540- pid
 14541
Hi Jimmy from process 9 - pid 14543
```

