# race condition
non-atomic variable: processes are interleaving
-  two threads can execute a piece of code at the same time
-  they modify the same variable at the same time
-  threads can interfere with processes executing correctly so we get a different output every time
-  multiple instructions running at the same time

**race condition** is used to stop this from happening - once one thread runs a process, other threads are not allowed to access it
-  we protect the **atomic** variable using a set of instructions
-  atomic instructions (e.g. mutual exclusion)
-  different processes are going to have different fundamental set of instructions, but the idea stays the same

if P0 and P1 are creating child processes using `fork()`
race condition on kernel variable `next_available_pid` which represent the next available process identifier (pid)

## critical section problem

**problem:**
-  n processes
-  every process has a critical section (updating a variable, a table, writing a file etc.)
-  multiple threads shouldn't be in the same critical section, we need to find a way to solve this

here the critical section is modifying the count variable
we need to avoid multiple threads accessing it because we will not get the 10000 output otherwise
```c
int cnt = 0; // non atomic variable
for (int n = 0; n < 10000; ++n)
{ // critical section begins - entry section
	++cnt;
	a1 = cnt * cnt2
} // critical section ends - exit section
```

we need:
**mutual exclusion** = if process P is executing in its critical section, then no other processes can be executing in their critical sections
**progress** = if there is no process that has a critical section, and there is processes that want to enter it, we include logic to include it
**bounded waiting** =  threads should have the same amount of time to access critical sections (no unfairness)

## interrupt-based solution

-  straw man solution: you shouldn't use this except for embedded hardware
-  entry section: disable interrupts
-  exit section: enable interrupts
-  disabling the scheduler, turning it off and on

## Peterson's algorithm

-  works on much older hardware
-  **warning to not try to implement your own solutions because they are not good solutions in the modern time for modern hardware**


-  2 processes with entry and exit sections for the critical section
-  variables are shared between processes so they know who's turn it is to enter the critical section
-  this can be an array and a regular int variable

`flag[0] = true` = one process in the critical section
`turn = 1;` =  one process in the critical section
`turn = 0` = process is outside of the critical section

these instructions are **atomic** - when something runs, it runs to completion and nothing else will be able to interrupt it
-  we are passing turn variable so both threads can access the critical section

process 1:
```c
while(true) {
	flag[0] = true;
	turn = 1;
	while (flag[1] && turn == 1){
		// critical setion here
		flag[0] = false
	} // remained section here
}
```

process 2:
```c
while(true) {
	flag[0] = true;
	turn = 0;
	while (flag[0] && turn == 0){
		// critical section here
		flag[1] = false
	} // remained section here
}
```

## modern architecture example

two threads share the variables
```c
boolean flag = false;
int x = 0;
```

thread 1 performs
```c
while (!flag);
print x
```

thread 2 performs
```c
x = 100;
flag = true
```

expected output: 100
actual output: 0

why? = compiler can reorder instructions here, it's not always the case that instructions are performed in the sequence we wrote them in
eg. thread 1 hurries up to print x before thread 2 gets to perform its function
-  **the solution no longer works**

# memory barrier

memory visibility issues = cache can hold a stale variable and perform with it
we need to be able to show up to date variables to each thread

we use **memory barrier** to ensure that Peterson's solution works correctly
-  memory models = memory guarantees a computer architecture makes to application programs