**Q1**
(a) In the Linux process life-cycle, explain why a process may transition from a ready state to a running state and from a running state to a ready state. (5 marks)

Answer: 
A process transitions from the ready state to the running state when it is selected by the CPU scheduler and dispatched onto the CPU for execution. 
A process transitions from the running state to the ready state when it is preempted by the operating system, for example when its time slice expires or a higher-priority process becomes available, causing the scheduler to move it back to the ready queue.

(b) A C program on Linux contains the following two lines of code: 
```c
execlp("/bin/ls","ls",NULL); 
printf("123");
```
When this program is run, will "123" be printed to the screen? Explain your reasoning, considering what happens when execlp is called. (5 marks)

Answer:
123 will not be printed, assuming `execlp()` succeeds. The call to `execlp("bin/ls", "ls", NULL)` replaces the current process image with the `ls` program. Therefore, the original program does not continue executing after `execlp()`, so the `printf("123")` line is not reached.

(c) Explain the memory layout of a C program using example C code. For each of the following memory sections: text, initialised data, uninitialised data, heap, and stack, provide one line of C code that places a variable or function in that section. (9 marks)

Answer: Sample code:
```c
int x; // uninitialised data
int y = 15; // initialised data

int main(int argc, char *argv) { // text section (program code)
	int *values; // stack (local variable)
	int i; // stack (local variable)
	
	values = (int *)malloc(sizeof(int)*5); // heap (dynamic allocation)
}
```

-  Text section: contains program code (e.g. `main()` function)
-  Initialised data: global variables with values (`int y = 15;`)
-  Uninitialised data (BSS): global variables without values (`int x;`)
-  Heap: dynamically allocated memory (`malloc(...)`)
-  Stack: local variables, parameters(values, i)

(d) Explain what is meant by the terms parent and child when talking about processes in Linux. In your answer, describe any relevant system calls. (6 marks)

Answer:
A parent process is a process that creates another process, while a child process is the newly created process.
In Linux, a child process is created using the fork() system call. This creates a copy of the parent process, including its address space, but the child runs as an independent process with its own memory. 
The child process may then use `exec()` system call to replace its process image with a new program.
The parent process can use `wait()` to block until the child terminates, and processes can be terminated using `exit()` or by sending signals (e.g. using `kill()`).

**Q2**
(a) Using Amdahl's law, calculate the speedup of a program with a 50% serial proportion for 10 processors. Assuming there is an unlimited number of processors available, what's the maximum speedup that could be achieved? (7 marks)

Using Amdahl's Law: speedup <= 1.81
maximum speedup with unlimited processors <= 2

(b) Explain what busy waiting (spinlock) is and why it is undesirable. Then, using an example, describe a synchronization primitive a programmer could use to avoid it. (7 marks)

Answer:
Busy waiting (spinlock) is when a process continuously checks a condition (e.g. a lock) in a loop without releasing the CPU. This is undesirable because it wastes CPU cycles, as the process is actively running but doing no useful work.
To avoid busy waiting, a programmer can use a semaphore with blocking operations. Instead of looping, a process that cannot proceed is blocked (put to sleep) and placed in a waiting queue:

```c
wait(S) {
    if (S.value > 0)
        S.value--;
    else {
        // add process to S.queue
        block();
    }
}

signal(S) {
    if (S.queue != empty) {
        // remove process from queue
        wakeup(P);
    } else {
        S.value++;
    }
}
```

(c) Message passing and shared memory are two ways that processes on a system can communicate. Explain what both of these are. (6 marks)

Answer:
Message passing is a way for processes to communicate without resorting to shared variables through two operations: send(message) and receive(message). This can be done directly or indirectly. In direct communication we pass the reference of the process we wish to communicate with along with the message: send(P, message), receive(Q, message) for processes P and Q, and with indirect communication messages are directed and received via some intermediary entity (mailbox, ports). Message passing can also be blocking (sender and receiver are blocked until message is received/available) and non-blocking (sender and receiver can continue no matter what).
Shared memory is an area of memory shared among the processes that wish to communicate by reading and writing to the same memory area. The communication is under the control of the user processes, not the operating system. 

(d) A thread scheduled using shortest-remaining-time-first (SRTF) will always run to completion without being pre-empted. Is this statement true or false? Justify your answer. (5 marks)

False.
In shortest-remaining-time-first (SRTF), a thread can be **preempted** if another thread arrives with a shorter remaining execution time. Therefore, a thread will not necessarily run to completion once it starts executing, as it may be interrupted by a newly arrived thread with a smaller remaining burst time.