Q1. Which of the following is a system call in a Unix-like operating system?
a. `malloc()`
b. `printf()`
c. `strlen()`
d. `fork()`
e. `scanf()`

Q2. Which part of a process in memory contains temporary data such as function parameters and local variables for a function?
a. stack
b. text section
c. critical section
d. None of these options
e. data section

Q3. Which of the following best describes a process?
a. A collection of resources managed by the operating system
b. A program currently executing
c. A thread within a program
d. A compiled program stored on disk
e. A file opened by the operating system

Q4. What is the main role of the CPU scheduler?
a. To allocate memory to processes
b. To manage transitions between user mode and kernel mode
c. To control when a running process performs I/O operations
d. To handle system calls
e. To select which process runs next on the CPU

Q5. What is a race condition?
a. When a process runs faster than expected
b. When multiple processes execute in parallel on different CPU cores
c. When two or more processes access shared data concurrently and at least one modifies it
d. When a process is preempted while executing a critical section
e. When two CPUs run the same program

Q6. What happens if `exec() `is successful?
a. None of these options
b. It pauses the process
c. It creates a new process
d. It duplicates the process
e. It returns -1

Q7. Which of the following is used to enforce mutual exclusion?
a. Cache
b. File descriptor
c. Compiler
d. Mutex lock
e. Scheduler time-slicing mechanism

Q8. A process calls `fork()`. Which statement is correct?
a. The child receives 0 as the return value
b. Both parent and child return -1 on success
c. The child process has the same PID as the parent
d. Only the child continues execution after `fork()`
e. The parent receives 0 as the return value

Q9. What is the key problem with a spinlock?
a. It allows multiple threads to enter the critical section simultaneously
b. It does not work with threads
c. It wastes CPU time while waiting
d. It requires multiple CPUs
e. It cannot enforce mutual exclusion

Q10. What is the output of the following program?
```c
int main(){
	int x = 1;
	if (fork() == 0){
		x = 2;
	}
	printf("%d\n", x);
	return 0;
}
```

a. Prints "1" twice
b. Prints "2" twice
c. Prints "1" and "2" (order not guaranteed)
d. Prints "1" once
e. Prints "1" twice

Q11. Which statement about threads is correct?
a. Threads cannot run concurrently
b. Each thread has its own separate address space
c. Threads require separate processes to execute
d. Threads within a process share the same address space
e. Threads cannot share data

Q12. What is a critical section?
a. A function that cannot be interrupted
b. A section of code that performs I/O
c. A part of a program that executes first
d. A part of code that accesses shared data
e. A section of memory reserved for the OS

Q13. Which of the following best describes a deadlock?
a. Processes are waiting indefinitely for resources held by each other
b. A process uses too much CPU
c. A process crashes due to an error
d. Two processes run at the same time
e. A program enters an infinite loop

Q14. Which statement about scheduling is correct?
a. Preemptive scheduling runs processes to completion
b. Non-preemptive scheduling interrupts processes
c. Scheduling determines memory allocation
d. Preemptive scheduling allows the OS to interrupt a running process
e. None of these options