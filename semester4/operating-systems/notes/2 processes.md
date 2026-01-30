**process** = program in execution
(program itself is passive entity stored on disk - it becomes a process when an executable file is loaded into memory)

**multiple parts of a process**:
-  text section
-  program counter
-  stack
-  data section
-  heap (connected to using calloc, malloc, realloc)

```c
// simple.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	prinf("Hello");
}
```

these will have different sizes - static will be bigger because all libraries are already included in the executable program

dynamically compiling doesn't load libraries within the program

```bash
// regular (dynamic) compiling
gcc simple.c -o simple
```

```bash
gcc simple.c -o simple --static
```

`objdump -T` - display information about simple.c

-  source code is compiled into object file (partially linked artefacts) - **relocatable object file**
-  apps compiled on one system usually not executable on other operating systems because each operating system provides its own unique system calls
-  some apps can be multi-operating system (eg. apps written in interpreted languages and interpreters themselves)

## process state

As a process executes, it changes state
• New: The process is being created
• Running: Instructions are being executed
• Waiting: The process is waiting for some event to occur
• Ready: The process is waiting to be assigned to a processor
• Terminated: The process has finished execution

`top` - check which processes are running

*ready and wait queues are oversimplified in the slides*

-  **context switch** occurs when the CPU switches from one process to another (this can happen when there is an interrupt or a new system call and it is used to handle these interrupts - context switch must be able to stop some processes and run some other processes)

*linker, loader, memory layout = next lab*

## process creation

commands to inspect processes
*make sure to mess around with commands on Loop*

`top` = something like task manager (contains pids of processes, commands that start them and users)

`pstree -p` - you can see the parent-child relationships of all processes that are currently running, this is useful because parent processes create children processes, and we can trace which process created which
`pstree -p | less`

when a process is created: address space
-  child is a duplicate of parent
-  child has a program loaded into it

`fork()` = makes a copy of a parent process for a child
`exec()` = using to replace the process' memory space with a new program, we need to use it after fork()
-  a copy is only realised when we make a change to the program in the child process, if we run exec() right away it wont do anything

*c program in slide 36 - do in the lab*
-  `bash -> ./fork-example`
-  this code will split itself
-  we make the fork system call above, one of the processes remains a parent (it's the one that got the value of pid being greater than 0)
-  the child process gets the pid of 0 - it is not necessary the pid of the child process
-  creates a child process that runs a ls command
-  the parent gets the child pid and the child pid gets 0
-  parent will wait for the child process to terminate, and then it will print child complete
-  this is how process are created in linux

check the result, if you include ; you can run 2 commands in one line
```bash
gcc fork_example.c -o fork_example.c ; ./fork_example
```

now we can modify the original code
```c
// in the child process
printf("I am the child %d\n, my PID is %d\n", pid, getpid())

// in the parent process
printf("I am the parent with child pid is %d, and my parent PID is %d\n", pid, getpid())
```

now check the result again

-  a statement will never print if you put it under the exec() because we have replaced what sits inside of that process, we changed the process image
-  if we tell the parent not to wait for the child process to terminate, the child will keep running, but the parent will be able to complete an exit
-  the child still continues running even after parent exits
-  the child becomes an orphaned process, it searches for a reaper. if there is no reapers, it goes all the way up to the first process
-  the default reaper is pid = 1
-  you can also have sub-reapers that you can use when you use docker

`Z+` = zombie process (**a process that has completed execution (via the exit system call) but still has an entry in the process table**)

### processes and trees of processes

```shell
`echo $$` = get a pid of a current bash instance
`3878
`pstree -p | grep 3878 -C 10` = when it finds the line with the particular number, it will print 10 lines before and after it

output:
```bash
 pstree -p | grep 3878 -C 10
           |               |                   |-{gnome-shell}(2620)
           |               |                   |-{gnome-shell}(2621)
           |               |                   |-{gnome-shell}(3226)
           |               |                   `-{gnome-shell}(3312)
           |               |-gnome-shell-cal(2717)-+-{gnome-shell-cal}(2718)
           |               |                       |-{gnome-shell-cal}(2719)
           |               |                       |-{gnome-shell-cal}(2721)
           |               |                       |-{gnome-shell-cal}(2722)
           |               |                       |-{gnome-shell-cal}(2723)
           |               |                       `-{gnome-shell-cal}(2851)
           |               |-gnome-terminal-(3867)-+-bash(3878)-+-grep(4101)
           |               |                       |            `-pstree(4100)
           |               |                       |-{gnome-terminal-}(3868)
           |               |                       |-{gnome-terminal-}(3869)
           |               |                       |-{gnome-terminal-}(3870)
           |               |                       |-{gnome-terminal-}(3871)
           |               |                       |-{gnome-terminal-}(3873)
           |               |                       `-{gnome-terminal-}(3877)
           |               |-goa-daemon(2739)-+-{goa-daemon}(2768)
           |               |                  |-{goa-daemon}(2769)
           |               |                  |-{goa-daemon}(2780)
```
`
`ps -A | wc -l` = all processes and word count

*slide 29 code*
importing multiprocessing library
do_a_loop() - it will use CPU cycles, does nothing productive
main() - starting 9 child processes

`python multi.py`
if you run `pstree -p | grep 3878 -C 10` again you will be able to see those new processes that are now running as children

`killall python` = do this when you're done inspecting

`systemd` = first daemon to start during boot (after kernel)
`pstree -p 1` = how to inspect it

## process termination

deallocation = most resources are freed, but the kernel keeps some information like PID and exit status until after the parent calls `wait()`. between `exit()` and `wait()` the process is called a zombie process

if a parent terminates before the child process, the child process continues, some OS configs do not allow child to exist if its parent has terminated. if a process terminates, then all its children must also be terminated. it uses **cascading termination** where children, grandchildren etc. are terminated.

***QUESTION IN THE EXAM***
***what's the difference between a zombie and an orphan process?***

`killall python` = kill all python processes
 **killing a process group**
 ```shell
 pstree -p | grep python
 kill -TERM -PID
 ```

## interprocess communication

-  some processes within a system may be **independent** or **cooperating** with other processes
-  **cooperating** process can affect or be affected by other processes including sharing data
-  they need **interprocess communication (IPC)**
-  2 primary models: shared memory, message passing
 **remember**: by default processes are isolated and do not share memory

## producer-consumer problem

-  we can use this problem to think about how cooperating processes interact with each other
-  we have the producer process that produces information that is consumed by a consumer process (and they share a buffer)

two variations:
-  unbounded buffer: places no practical limit on the size of the buffer
-  bounded buffer: assumes that there is a fixed buffer size

we can use IPC-shared memory to solve the bounded buffer problem
-  we only have 2 variables to synchronise processes: in and out
-  we can use a counter variable if we want to fill all the buffers, as the int counter keeps track of the number of full buffers

a problem with shared memory is the **race condition**

to turn off optimisation when compiling
```shell
gcc raceexample.c -o raceexample -O0
```

