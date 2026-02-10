***exam question: differentiate between threads and processes***
-  lightweight processes
-  different because they can share memory and have the same visibility of variables
-  processes cannot see each other unless we manually program it
-  threads can see the same memory space of the process

**they are similar in that they allow concurrent/parallel execution of code**

examples of a scenario in which we want concurrent processing:
if we have a word document and we want to print it, we don't want to wait to edit the document until the printer is finished printing
in this case we want to have a thread that handles printing, another one that handles user interaction in word etc.

web browser - has multiple tabs, we don't want to wait for one tab to finish process until we use another one

**it is important for responsiveness and is cheaper than process creation**

## single vs multithreaded process

multithreaded application can have multiple threads that are doing different activities but they are able to see the same variables inside a process

multithreaded processes have to have their own stack (resource set up), while a single process uses one default stack

### single
**when we fork() a new process, it has it's own memory - parent process does not see change to val from child and vice versa**
in this example we have a global variable of 5, the child changes the value of the variable to 100, and the parent runs after, but doesn't recognise the change of the value

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int var = 5;

int main(int argc, char**argv)
{
	pid_t fork_ret;
	
	fork_ret = fork();
	
	if (fork_ret == 0) // in the child
	{
		var = 100;
		printf("In the child with pid %d, and the value of var is %d\n", getpid(), var)
	}
	else // in the parent
	{
		sleep(4) // sleep in the parent so child has had a chance to run for a while
		printf("In the parent with pid %d, and the value of var is %d\n", getpid(), var);
	}
	
	return 0;
}
```

output:
```
In the child with pid 3264225, and the value of var is 100
In the parent with pid 3264224, and the value of var is 5
```

when we use fork for a process and don't include exec, it's only making a copy of that process

### multithreaded
**example to show that in a process with two threads, they can see the same variable**
*  there are caveats to allowing direct shared access like this

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 0; // shared memory (same address space)

void* writer(void *arg)
{
	sleep(1);
	shared = 42;
	printf("Writer: set shared = %d\n", shared);
	return NULL;
}

void* reader(void* arg)
{
	printf("Reader: initial shared = %d\n", shared);
	
	while (shared == 0) {
		// busy wait until the value of shared is changed
	}
	
	printf("Reader: saw shared change to %d\n", shared);
	return NULL;
}

int main()
{
	pthread_t, t1, t2;
	
	pthread_create(&t1, NULL, reader, NULL);
	pthread_create(&t2, NULL, writer, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}
```

how to compile:
```bash
gcc thread_example.c -pthread -o thread_example
```

output:
```
Reader: initial shared = 0
Reader: saw shared change to 42
Writer: set shared = 42
```

## multicore programming

**multicore or multiprocessor** systems put pressure on programmers, challenges include:
-  dividing activities
-  balancing
-  data splitting
-  data dependency
-  testing and debugging (heisenbugs)

**parallelism** = system can perform more than one task simultaneously
-  threads can run at the same time
**concurrency** = supports more than one task making progress
-  single processor/core, scheduler providing concurrency
-  each thread gets a little bit of time to execute and do a bit of their function, but they can't execute at the same time

### python threads

this is an edge case, other programming language can do this without any problems
GIL = Global Interpreter Lock in python (doesn't allow threads to run in parallel with each other)

this **does not** create multiple processes
```python
from threading import Thread

def my_fun(c):
	while True:
		pass
		
for i in range(3):
	Thread(target=my_fun, args=(1000,)).start()
```

this does - each process uses close to 100% of a CPU, but they are separate processes not threads
```python
from multiprocessing import Process

def my_fun(c):
	while True:
		pass
		
for i in range(3):
	Process(target=my_fun, args=(1000,)).start()
```

**data parallelism** = distributes subsets of the same data across multiple cores, **same operation on each**
**task parallelism** = distributing threads across cores, each thread performing **unique operation**
## amdahl's law

identifies performance gains from adding additional cores to an application that has both serial and parallel components

parallel part of the program = breaking up the data, adding a million numbers from a file, can be broken down
serial part of the program = loading, running, loading numbers into memory, can't be broken down any further

S = serial portion
N processing cores

**serial portion of an application impacts performance gained by adding additional cores**

speedup has to be less or equal to 1 over serial portion S plus parallel portion (1-S) - number of processing cores N
-  if application if 75% parallel/25% serial, moving from 1 to 2 cores results in speedup of 1.6 times
-  as N approaches infinity, speedup approaches 1/S (maximum speed)

amdahl's law doesn't apply over all examples of multithreading - it is not always appropriate (e.g. games)



