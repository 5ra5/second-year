## processes

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

-  ready and wait queues are oversimplified in the slides

-  **context switch** occurs when the CPU switches from one process to another (this can happen when there is an interrupt or a new system call and it is used to handle these interrupts - context switch must be able to stop some processes and run some other processes)

`pstree -p` - you can see the parent-child relationships of all processes that are currently running, this is useful because parent processes create children processes, and we can trace which process created which
