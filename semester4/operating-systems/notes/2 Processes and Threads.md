# Processes
## Process Concept

An operating system executes a variety of programs that run as processes.

**Process** – a program *in execution*; process execution progresses in **sequential** fashion i.e. **No parallel execution of instructions of a single process.**

Multiple parts (**a process in memory**)
-  The program code, also called **text section**
-  Current activity including **program counter**, processor registers
-  **Stack** containing temporary data
	-  Function parameters, return addresses, local variables
-  **Data section** containing global variables
-  **Heap** containing memory dynamically allocated during run time

Program is **passive** entity stored on disk (**executable file**); process is **active**
-  Program becomes a process when an executable file is loaded into memory

Execution of program started via GUI mouse clicks, command line entry of its name, etc. **e.g. `./run_my_c_program`**

One program can be several processes
-  Consider multiple users executing the same program

## Linkers and Loaders

Source code is compiled into object files (partially linked artefacts) – **relocatable object file**
**Linker** combines these into single binary **executable** file
-  Also brings in libraries
Program resides on secondary storage as binary executable
Must be brought into memory by **loader** to be executed
-  **Relocation** updates address references so code and data work correctly at their assigned **virtual addresses**
**But**  modern general purpose systems don’t always link libraries into executables
-  Rather, **dynamically linked libraries** (in Windows, **DLLs**) are loaded as needed, shared by all that use the same version of that same library (loaded once)
Object, executable files have standard formats, so operating system knows how to load and start them 

## Why Applications are Operating System Specific

Apps compiled on one system usually not executable on other operating systems
**Each operating system provides its own unique system calls**
-  Own file formats, etc.
Apps can be multi-operating system
-  Written in interpreted language like Python, Ruby, and interpreter available on multiple operating systems
-  App written in language that includes a VM containing the running app (like Java)
-  Use standard language (like C), compile separately on each operating system to run on each
**Application Binary Interface** (**ABI**) is low-level equivalent of API, defines how different components of binary code can interface for a given operating system on a given architecture, CPU, etc.

## Process State

As a process executes, it changes **state**:
-  **New**: The process is being created
-  **Running**: Instructions are being executed
-  **Waiting**: The process is waiting for some event to occur
-  **Ready**: The process is waiting to be assigned to a processor
-  **Terminated**: The process has finished execution

```c
static const char * const task_state_array[] = {

	/* states in TASK_REPORT: */
	"R (running)",		/* 0x00 */
	"S (sleeping)",		/* 0x01 */
	"D (disk sleep)",	/* 0x02 */
	"T (stopped)",		/* 0x04 */
	"t (tracing stop)",	/* 0x08 */
	"X (dead)",		/* 0x10 */
	"Z (zombie)",		/* 0x20 */
	"P (parked)",		/* 0x40 */

	/* states beyond TASK_REPORT: */
	"I (idle)",		/* 0x80 */
};
```
From: https://github.com/torvalds/linux/blob/3950e975431bc914f7e81b8f2a2dbdf2064acb0f/fs/proc/array.c#L129-L143

## Process Control Block (PCB)
Information associated with each process (also called **task control block**)
-  Process state – running, waiting, etc.
-  Program counter – location of instruction to next execute
-  CPU registers – contents of all process-centric registers
-  CPU scheduling information- priorities, scheduling queue pointers
-  Memory-management information – memory allocated to the process
-  Accounting information – CPU used, clock time elapsed since start, time limits
-  I/O status information – I/O devices allocated to process, list of open files
-  ...

## Process Representation in Linux

(in part) Represented by the C structure `task_struct`
```c
pid t_pid;                 /* process identifier */
long state;                /* state of the process */
...unsigned int time_slice /* scheduling information */
struct task_struct *parent;/* this process’s parent */
struct list_head children; /* this process’s children */
struct files_struct *files;/* list of open files */
struct mm_struct *mm;      /* address space of this process */
```

## Process Scheduling

**Process scheduler** selects among available processes for next execution on CPU core

Goal -- Maximise CPU use, quickly switch processes onto CPU core

Needs to maintain **scheduling queues** of processes
-  **Ready queue** – set of all processes residing in main memory, ready and waiting to execute
-  **Wait queues** – set of processes waiting for an event e.g., I/O
-  Processes migrate among the various queues

## Context Switch

**Context switch**:
-  When CPU switches to another process, the system must **save the state** of the old process and load the **saved state** for the new process

And the **Context** of a process represented in the PCB

Context-switch time is **pure overhead**; **the system does no useful work while switching**
-  The more complex the OS and the PCB ➔ the longer the context switch

## Process Creation

**When we create a new process, some choices might need to be made...**

**Resource sharing options**
-  Should... Parent and children share all resources?
-  Children share subset of parent’s resources?
-  Parent and child share no resources?

**Execution options**
-  Parent and children execute concurrently?
-  Parent waits until children terminate?

**We’ll come back to this a bit later...**

**Parent** process(es) create **children** processes, which, in turn create other processes, forming a **tree** of processes

**Run "`pstree -p`" on linux to see process tree**

Process identified and managed via a **process identifier** (**pid**)

### A little detour... Processes and trees of processes

-  The bash shell is a program, so it has a PID (process identified)
-  We can find the PID of the current bash instance we are using by typing “**`echo $$`**” at the prompt
```bash
petra@petra-Aspire-A515-56G:~$ echo $$
6602
```

-  Other processes?
```bash
petra@petra-Aspire-A515-56G:~$ ps
    PID TTY          TIME CMD
   6602 pts/0    00:00:00 bash
   6817 pts/0    00:00:00 ps
```

- All processes?
```bash
petra@petra-Aspire-A515-56G:~$ ps -A
    PID TTY          TIME CMD
      1 ?        00:00:02 systemd
      2 ?        00:00:00 kthreadd
      3 ?        00:00:00 pool_workqueue_release
      4 ?        00:00:00 kworker/R-rcu_g
      5 ?        00:00:00 kworker/R-rcu_p
      6 ?        00:00:00 kworker/R-slub_
      7 ?        00:00:00 kworker/R-netns
      9 ?        00:00:00 kworker/0:0H-events_highpri
     10 ?        00:00:00 kworker/0:1-events
     12 ?        00:00:00 kworker/R-mm_pe

```

```bash
petra@petra-Aspire-A515-56G:~$ ps -A | wc -l
306
```

For example, if I used multiprocessing in python to start 10 processes:
```bash
petra@petra-Aspire-A515-56G:~$ echo $$
6602
petra@petra-Aspire-A515-56G:~$ python3 multi.py
```

```python
from multiprocessing import *
import random

def do_a_loop():
	while 1:
		if random.randint(1,100000000) == 1:
			break
			
def main():
	for i in range(1,10);
		p = Process(target=do_a_loop, args=()).start()
		
main()
```

I could also look at output from "`pstree -p 6602`"
-  will see all of the processes running `python3(pid)`, with pid being their unique identifier

## A Tree of Processes in Linux

**`Systemd`** is the first daemon to start during boot (after kernel)

```bash
petra@petra-Aspire-A515-56G:~$ pstree -p 1
systemd(1)─┬─ModemManager(1497)─┬─{ModemManager}(1502)
           │                    ├─{ModemManager}(1503)
           │                    └─{ModemManager}(1506)
           ├─NetworkManager(1386)─┬─{NetworkManager}(1455)
           │                      ├─{NetworkManager}(1456)
           │                      └─{NetworkManager}(1459)
           ├─accounts-daemon(1323)─┬─{accounts-daemon}(1423)
           │                       ├─{accounts-daemon}(1424)
           │                       └─{accounts-daemon}(1427)
           ├─avahi-daemon(1325)───avahi-daemon(1369)
           ├─bluetoothd(1326)
           ├─colord(2707)─┬─{colord}(2718)
           │              ├─{colord}(2719)
           │              └─{colord}(2721)
           ├─containerd(1607)─┬─{containerd}(1623)
           │                  ├─{containerd}(1625)
           │                  ├─{containerd}(1626)
           │                  ├─{containerd}(1627)
           │                  ├─{containerd}(1628)

```

## Process Creation

When a process is created...
-  Child is duplicate of parent (different address space)
-  Child has a program loaded into it

UNIX examples
-  **`fork()`** system call wrapper (uses **`clone()`**) to create new process
-  **`exec()`** system call wrapper used after a **`fork()`** to replace the process’ memory space with a new program
-  Parent process calls **`wait()`** waiting for the child to terminate

`fork() `does a ‘copy’ of heap, stack, etc ... but the copy is not realised (because it’s not used).
A mechanism called copy on write & paging (covered later) handles this. 

## C Program Forking Separate Process

```c
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	
	/* fork a child process */
	pid = fork();
	
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) { /* child process */
		execlp("/bin/ls", "ls", NULL);
	}
	else { /* parent process */
		/* parent will wait for the child to complete*/
		wait(NULL);
		printf("Child Complete");
	}
	
	return 0;
}
```

**The parent gets the child PID, and the child PID gets 0**

## Process Termination

Process executes last statement and then terminates by calling **`exit()`** (which eventually invokes the kernel).
-  Exit status is recorded by the kernel and retrieved later by the parent via **`wait()`**
-  Process’ resources are *deallocated* by operating system

Parent may terminate the execution of children processes by sending a signal via **`kill()`**. Termination depends on signal type and handling. Some reasons for doing so:
-  Child has exceeded allocated resources
-  Task assigned to child is no longer required
-  The parent is exiting, and the child should not continue if its parent terminates
-  ...

*most resources are freed, however, the kernel keeps some information like PID and exit status until after the parent calls **wait()**. Between **exit()** and **wait()**, the process is a **Zombie***

On Linux/Unix (by default), if a parent terminates before its child process, the child process *continues*.

The parent process may wait for termination of a child process by using the **`wait()`** system call. The call returns status information and the pid of the terminated process
**`pid = wait(&status);`**

If parent terminated without invoking wait(), process is an **orphan**
-  The process ends up *reparented* to PID 1 (or another reaper)

Sometimes a process has finished running and called exit() but it still has a (partial) PCB .. It’s a **zombie** (because the parent has not called wait())
-  The zombie is cleaned up when its parent (or reaper) calls wait()

*Some operating systems configs do not allow child to exists if its parent has terminated. If a process terminates, then all its children must also be terminated. It uses **cascading termination where** children, grandchildren, etc., are terminated.*

### If I kill a process which process is the new parent?

PID=1 is the default reaper, unless there’s a nearer reaper. There can be other processes along the tree that can act as (sub)reapers e.g. docker, or container-type tools

### We can also kill a process group

**Using `kill -TERM -PID` (notice the minus/negation)**

## Interprocess Communication

Processes within a system may be ***independent*** or ***cooperating***
**Cooperating** processes can affect or be affected by other processes (and can even share data)
Reasons for cooperative processes:
-  Information sharing
-  Computation speedup
-  Modularity
-  ...

Cooperating processes need **interprocess communication** (**IPC**)
Two (primary) models of IPC
-  **Shared memory (we’ll look at this in C)**
-  **Message passing (we’ll talk about this)**

**Remember:** By default, processes are isolated and do not share memory.

## Producer-Consumer Problem

(way to think about) Paradigm for cooperating processes:
-  producer process **produces** information that is **consumed** by a consumer process (**and there’s a *buffer* they share**)

Two variations:
**unbounded-buffer** places no practical limit on the size of the buffer:
-  Producer never waits
-  Consumer waits if there is no buffer to consume
**bounded-buffer** assumes that there is a fixed buffer size
-  Producer must wait if all buffers are full
-  Consumer waits if there is no buffer to consume

**We'll use the bounded-buffer producer-consumer problem (as a context) to explain these different methods for *IPC***

## IPC - Shared Memory

***Solution 1 to the bounded-buffer problem using* *Shared Memory* for *IPC***
-  An area of memory shared among the processes that wish to communicate
-  The communication is ***under the control of the user processes*** not the operating system.
-  Major issues is to provide mechanism that will allow the user processes to ***synchronise their actions*** when they access shared memory
-  **Synchronisation** is discussed in greater detail later.

**Mutex, lock, semaphore, ...**

## Bounded-Buffer - Shared-Memory Solution

-  **Shared data**
```c
#define BUFFER_SIZE 10
typedef struct {
	...
} item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
```

## Consumer Process - Shared Memory

```c
item next_command;

while (true) {
	while (out == in)
		; /* do nothing */
	next_consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE;
	
	/* consume the item in next consumed */
}
```

## Producer Process - Shared Memory

```c
item next_produced;

while (true) {
	/* produce an item in next produced */
	while (((in + 1) % BUFFER_SIZE) == out)
		; /* do nothing */
	buffer[in] = next_produced;
	in = (in + 1) % BUFFER_SIZE;
}
```

**Solution is correct, but can only use *`BUFFER_SIZE-1`* elements**

## What about Filling all the Buffers?

-  Suppose that we wanted to provide a solution to the consumer-producer problem that ***fills all the buffers*** ..

-  We can do so by having an integer **`counter`** that keeps track of the number of full buffers.
-  Initially, **`counter`** is set to 0.
-  The integer **`counter`** is incremented by the producer after it produces a new buffer.
-  The integer **`counter`** is and is decremented by the consumer after it consumes a buffer.

## Consumer

```c
while (true) {
	while (counter == 0)
		; /* do nothing */
	next_consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE;
	counter--;
	/* consume the item in next consumed */
}
```

## Producer

```c
while (true) {
	/* produce an item in next produced */
	
	while (counter == BUFFER_SIZE)
		; /* do nothing */
	buffer[in] = next_produced;
	in = (in + 1) % BUFFER_SIZE;
	counter++;
}
```

## Issues with shared memory?

-  **`counter++`** could be implemented as
```c
register1 = counter
register1 = register1 + 1
counter = register1
```

-  **`counter--`** could be implemented as
```c
register2 = counter
register2 = register2 - 1
counter = register2
```

-  Consider this execution interleaving with "count = 5" initially:
```
S0: producer execute register1 = counter        {register1 = 5}
S1: producer execute register1 = register1 + 1  {register1 = 6}
S2: consumer execute register2 = counter        {register2 = 5}
S3: consumer execute register2 = register2 - 1  {register2 = 4}
S4: producer execute counter = register1        {counter = 6}
S5: consumer execute counter = register2        {counter = 4}
```

This is called a **race condition** - we look at situations like these and solutions later in the course...

## Examples of IPC Systems - POSIX

Let’s look at setting up shared memory on Linux
-  In Linux, this is a file, but we map it into memory!

POSIX Shared Memory
-  Process first creates shared memory segment 
   `shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);`
-  Set the size of the object
   `ftruncate(shm_fd, 4096);`
-  Use `mmap()` to memory-map a file pointer to the shared memory object
-  Reading and writing to shared memory is done by using the pointer returned by `mmap()`.

## Shared memory example

```c
./producer

 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

int main()
{
	const int SIZE = 4096;
	const char *name = "OS";
	const char *message0= "Studying ";
	const char *message1= "Operating Systems ";
	const char *message2= "Is Fun!";

	int shm_fd;
	void *ptr;

	/* create the shared memory segment */
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	/* configure the size of the shared memory segment */
	ftruncate(shm_fd,SIZE);

	/* now map the shared memory segment in the address space of the process */
	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("Map failed\n");
		return -1;
	}

	/**
	 * Now write to the shared memory region.
 	 *
	 * Note we must increment the value of ptr after each write.
	 */
	sprintf(ptr,"%s",message0);
	ptr += strlen(message0);
	sprintf(ptr,"%s",message1);
	ptr += strlen(message1);
	sprintf(ptr,"%s",message2);
	ptr += strlen(message2);

	return 0;
}
```

```c
./consumer

* @author Gagne, Galvin, Silberschatz
 * Operating System Concepts - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
	const char *name = "OS";
	const int SIZE = 4096;

	int shm_fd;
	void *ptr;
	int i;

	/* open the shared memory segment */
	shm_fd = shm_open(name, O_RDONLY, 0666);
	if (shm_fd == -1) {
		printf("shared memory failed\n");
		exit(-1);
	}

	/* now map the shared memory segment in the address space of the process */
	ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("Map failed\n");
		exit(-1);
	}

	/* now read from the shared memory region */
	printf("%s",(char *)ptr);

	/* remove the shared memory segment */
	if (shm_unlink(name) == -1) {
		printf("Error removing %s\n",name);
		exit(-1);
	}

	return 0;
}
```

```bash
petra@petra-Aspire-A515-56G:~/Documents/second_year/semester4/operating-systems/shm$ gcc consumer.c -o consumer -lrt
petra@petra-Aspire-A515-56G:~/Documents/second_year/semester4/operating-systems/shm$ gcc producer.c -o producer -lrt
petra@petra-Aspire-A515-56G:~/Documents/second_year/semester4/operating-systems/shm$ ./producer
petra@petra-Aspire-A515-56G:~/Documents/second_year/semester4/operating-systems/shm$ ./consumer
Studying Operating Systems Is Fun!
```

Note:
1.  You need to use `-lrt` with `gcc` (so it knows to use rt library)
2.  That the shared memory persisted, even after producer exited!
3.  Consumer could have have been run as a different user ...

# IPC - Message Passing

**Solution 2 to the bounded-buffer problem using IPC & Message Passing**
Processes can communicate with each other without resorting to shared variables
IPC (Message Passing) facility provides two operations:
-  **send**(message) 
-  **receive**(message)
The *message* size is either fixed or variable

If processes ***P*** and ***Q*** wish to communicate, they need to:
-  Establish a **communication link** between them
-  Exchange messages via **send** / **receive**

(some) Implementation considerations:
-  Can a link be associated with more than **two processes**?
-  How many links can there be **between every pair** of communicating processes?
-  What is the capacity of a link? (buffer size? queue length?)
-  Will the size of a message that the link can accommodate fixed or variable?
-  Will a link be **unidirectional** or **bi-directional**?

# Direct / Indirect Communication

**Direct** - The sender names the receiver ***explicitly***:
-  **`send(P, message)`** -  send a message to process P
-  **`receive(Q, message)`** - receive a message from process Q

**Indirect** - Messages are directed and received from **mailboxes** (also referred to as ports,.... ) - basically some intermediary entity:
-  Each **mailbox** has a unique id
-  Processes can communicate only if they share a mailbox

## Synchronisation

Message passing may be either blocking or non-blocking

**Blocking** is considered **synchronous**
**Blocking send()** -- the sender is blocked until the message is received
**Blocking receive()** -- the receiver is blocked until a message is available

**Non-blocking** is considered asynchronous
**Non-blocking send** -- the sender sends the message and continue
**Non-blocking receive** -- the receiver receives:
-  A valid message, or
-  Null message

Different combinations possible
-  If both send and receive block, we have a **rendezvous**

## Producer-Consumer: Message Passing

-  Producer
```c
message next_produced;
while (true) {
	/* produce an item in next_produced */
	
	send(next_produced);
}
```

-  Consumer
```c
message next_consumed;
while (true) {
	receive(next_consumed)
	
	/* consume the item in next_command */
}
```

## (considerations) Buffering

Queue of messages attached to the link.
Implemented in one of three ways
1.  Zero capacity – no messages are queued on a link. Sender must ***wait*** for receiver (rendezvous)
2.  Bounded capacity – finite length of *n* messages. Sender must ***wait*** if link full
3.  Unbounded capacity - infinite length. Sender never waits (but practically, what about memory RAM issues?)

## Pipes

Acts as a **conduit** allowing processes to communicate

Configuration:
-  (typically) Communication is **unidirectional**
-  FIFO
-  ...

**Ordinary pipes** - Ordinary pipes are unnamed and accessible only to processes that inherit the pipe’s file descriptors (typically parent and child).

**Named pipes** - can be accessed without a parent-child relationship.

## Ordinary Pipes

-  Ordinary Pipes allow communication in standard producer-consumer style
-  Producer writes to one end (the **write-end** of the pipe)
-  Consumer reads from the other end (the **read-end** of the pipe)
-  Require parent-child relationship between communicating processes
-  Windows calls these **anonymous pipes**

### Pipe example (ordinary)

```c
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END	0
#define WRITE_END	1

int main(void)
{
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg[BUFFER_SIZE];
	pid_t pid;
	int fd[2];

	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	/* now fork a child process */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}

	if (pid > 0) {  /* parent process */
		/* close the unused end of the pipe */
		close(fd[READ_END]);

		/* write to the pipe */
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1); 

		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}
	else { /* child process */
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);

		/* read from the pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("child read %s\n",read_msg);

		/* close the write end of the pipe */
		close(fd[READ_END]);
	}

	return 0;
}
```

## Named Pipes

-  Named Pipes are more flexible in how processes find each other
-  Communication can be bidirectional
-  No parent-child relationship is necessary between the communicating processes **`mkfifo` example**
-  Several processes can use the named pipe for communication
-  Provided on both UNIX and Windows systems
-  Appears as a file, processes attach to it for IPC

## Communications in Client-Server Systems (Sockets)

-  A **socket** is defined as an endpoint for communication
-  Concatenation of IP address and **port** – a number included at start of message packet to differentiate network services on a host
-  The socket **161.25.19.8:1625** refers to port **1625** on host **161.25.19.8**
-  Communication consists between a pair of sockets
-  All ports below 1024 are ***well known***, used for standard services
-  Special IP address 127.0.0.1 (**loopback**) to refer to system on which process is running

# Signals & Signal Handling for processes

## Signal Handling

**Signals** are used in UNIX systems to notify a process that a particular event has occurred.
A **signal handler** is used to process signals
1.  Signal is generated by particular event
2.  Signal is delivered to a process
3.  Signal is handled by one of two signal handlers:
	1.  default
	2.  user-defined

Every signal has **default handler** defined by the kernel
-  **User-defined signal** handler can override default
-  For single-threaded, signal delivered to process
-  Some signals cannot be caught or ignored (e.g. `SIGKILL`, `SIGSTOP`)

When a signal is sent to a process, it interrupts its normal execution, and either:
-  Uses the default signal handler
-  Or uses a process defined signal handler

Use `kill -l`, to see a list of available signals

Examples:
-  SIGINT = when you press ctrl + c
-  SIGQUIT = when you press ctrl + \
-  SIGTERM = tell the process to terminate (gracefully)
-  SIGFPE = illegal arithmetic error e.g. (divide by zero)
-  ...

We send these to a process using kill.. E.g.
-  kill 123456
-  kill –SIGTERM 123456 (same as above, default is SIGTERM)

Or in C:
```c
kill(pid, SIGTERM); // or any of the list of available signals
```

## Signal handling (setup)

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sighandler(int signum)
{
	printf("Received a signal %d\n", signum);
}

int main()
{
	signal(SIGINT, sighandler);
	while(1);
	return;
}
```

```bash
petra@petra-Aspire-A515-56G:~/Documents/second_year/semester4/operating-systems/shm$ gcc sig.c -o sig
petra@petra-Aspire-A515-56G:~/Documents/second_year/semester4/operating-systems/shm$ ./sig
Received a signal 2
```

I found the PID using `ps a`
```bash
petra@petra-Aspire-A515-56G:~/Documents/second_year/semester4/operating-systems/shm$ kill -SIGINT 10484
```

# Threads

## Benefits

**Threads and processes are similar in that they allow concurrent/parallel execution of code (depending on OS & programming language)**

-  **Responsiveness** – may allow continued execution if part of process is blocked, especially important for user interfaces **(like processes**)
-  **Resource Sharing** – threads share resources of process, easier than shared memory or message passing (**unlike between child/parent/child processes**)
-  **Economy** - cheaper than process creation, thread switching lower overhead than context switching
-  **Scalability** – effective way to take advantage of multicore architectures

**So, what's the difference between a process and a thread?**

## Multiprocess Architecture - Chrome Browser

Many web browsers in the past as single process (**maybe some still do?**)
-  If one web site causes trouble, entire browser can hang or crash

Google Chrome Browser is multiprocess with 3 different types of processes:
-  **Browser** process manages user interface, disk and network I/O
-  **Renderer** process renders web pages, deals with HTML, JavaScript. A new renderer created for each website opened
	-  Runs in **sandbox** restricting disk and network I/O, minimising effect of security exploits
-  **Plug-in** process for each type of plug-in

## Multicore Programming

**Example to show when we fork() a new process, it has it’s own memory i.e. parent process does not see change to val from child, and vice versa!**
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
		printf("In the child with pid %d, and the value of var is %d\n", getpid(), var);
	}
	else // in the parent
	{
		sleep(4); // sleep in the parent so child has had a chance to run for a while
		printf("In the parent with pid %d, and the value of var is %d\n", getpid(), var);
		wait(NULL);
		
	}
	
	return 0;
}
```

```bash
In the child with pid 3264225, and the value of var is 100
In the parent with pid 3264225, and the value of var is 5
```

**Example to show that in a process with two threads, they can see the same variable*
**there are caveats to allowing direct shared access like this which we discuss later e.g. race conditions**
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 0; // shared memory (same address space)

void* writer(void* arg)
{
	sleep(1); // give reader time to start
	shared = 42;
	printf("Writer: set shared = %d\n", shared);
	return NULL;
}

void* reader(void* arg)
{
	printf("Reader: initial shared = %d\n", shared);
	
	while (shared == 0) {
		// busy wait
	}
	
	printf("Reader: saw shared change to %d\n", shared);
	return NUll;
}

int main()
{
	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, reader, NULL);
	pthread_create(&t2, NULL, writer, NULL);
	
	pthread_join(t1, NULL);
	pthread_join)t2, NULL);
	
	return 0;
}
```

```bash
petra@petra-Aspire-A515-56G:~/shm$ ./thread_example
Reader: initial shared = 0
Writer: set shared = 42
Reader: saw shared change to 42
```

Multicore or multiprocessor systems put pressure on programmers, challenges include:
-  **Dividing activities**
-  **Balancing**
-  **Data splitting**
-  **Data dependency**
-  **Testing and debugging (e.g. heisenbugs)**

***Parallelism*** implies a system can perform more than one task simultaneously
***Concurrency*** supports more than one task making progress
-  Single processor / core, scheduler providing concurrency

## Are Python threads real threads?

