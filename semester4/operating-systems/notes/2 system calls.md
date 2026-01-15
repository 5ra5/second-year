## Operating system services

-  user interface
-  program execution
-  I/O operations
-  file-system manipulation
-  communications
-  error detection

## System calls

-  System calls enable software to use/interact/do things with the operating system kernel to make it do something
-  We use them so we don't have to interact with the computer hardware ourselves
-  Application Programming Interface (API) - we will use POSIX API

## Tracing system calls

```c
// simple.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	char *name = malloc(220);
	
	printf("What's your name?\n");
	fgets(name, 20, stdin);
	
	printf("Hello %s\n", name);
}
```

```bash
strace ./simple
```

```bash
ltrace ./simple
```

 Manual page of system calls - list of all of them
```bash
man syscalls
```
## System call implementation

-  Each system call has its own number
-  We don't need to know these
-  They are kept in the system-call interface which maintains an indexed table

## Types of system calls

-  Process control
-  File management
-  Device management
-  Information maintenance
-  Communications
-  Protection

## Kernel

 In computer science, this is the lowest level we go to
```bash
nano syscall_64.S
```

 Disassembling simple.c into assembly level instructions
```
objdump -d simple
```

## System services / programs

Types of system programs:

• File manipulation
• Status information sometimes stored in a file
• Programming language support
• Program loading and execution
• Communications
• Background services
• Application programs

## Linux System Structure

- Monolithic + modular design

Monolithic = The monolithic operating system is a very simple operating system where the kernel directly controls device management, memory management, file management, and process management. All of the system's resources are accessible to the kernel. Every part of the operating system is contained within the kernel in monolithic systems.

## Building and booting linux

 You can compile your own kernel version by configuring the one you already have
```bash
make menuconfig
```

