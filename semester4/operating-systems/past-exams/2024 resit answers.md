
**Q1**
(a) Explain the differences between a process and a thread. Provide an example of a situation where using a process is appropriate and another example where using a thread is appropriate. (6 marks)

A process is an independent program in execution with its own address space and resources. Processes are more isolated from each other, so communication between them usually requires IPC such as pipes, message passing, or shared memory.
A thread is smaller unit of execution within a process. Threads in the same process share the same address space and data, but each thread has its own stack, registers, and program counter.
A process is appropriate when isolation is important, for example running separate applications or handling tasks that should not affect each other if one crashes. A thread is appropriate when tasks need to share data efficiently, for example multiple worker threads in a web server handing requests using shared memory/cache.

(b) 
a) Explain the purpose of the fork() system call and describe what happens in both the parent and child processes after a fork() call. 
b) Explain the purpose of the exec() system call and describe how it changes the behaviour of the process that calls it. 
c) Provide a scenario where using both fork() and exec() are used together. Explain the sequence of calls and the expected outcomes. (11 marks)

a) The purpose of the fork() system call is creating a new child process. The child process is a copy of the parent process, but it runs independently from the parent since it has it's own memory space and resources. After a fork call, the parent gets the PID of a child, and a child gets the PID of 0.
b) The purpose of the exec() system call is to load a new program inside a child process after the fork() system call, replacing the current process image with that new program and executing it.
c) fork() and exec() can be used together in implementation of background execution while building a shell. Fork() creates a new process, exec() loads a program and executes it, and the fork does not call wait() if the process is specified to run in the background, otherwise it does.

(c) What is a dynamically linked library? What is a benefit of using a dynamically linked library? (4 marks)

A dynamically linked library is a library whose code is not copied into the executable at compile time. Instead, it is loaded and linked at runtime when the program needs it.
A benefit is that the executable file is smaller, and multiple programs can share the same library code in memory. It also allows the library to be updated without recompiling every program that uses it.

(d) Briefly explain what the pstree command does on Linux. In your answer explain the relationship it shows between processes. (4 marks)

pstree returns a list of all running processes in a form of a tree, where branches are connecting parent processes to their child processes.

**Q2**
(a) Using Amdahl's law, calculate the speedup of a program with a 50% serial proportion for 10 processors. (5 marks)

1.81

(b) The kill command on Linux can be used to send a signal to a process. Explain what a signal is and explain why it can be beneficial for a process to receive signals. (6 marks)

A signal is passed to a process to notify it that a particular event has occurred. It can be beneficial for a process to receive signals so it can change its operation based on the state of the system or user input, for example if we want the process to terminate gracefully, we can send a SIGTERM signal, and the program will handle the signal either in default behaviour, or a manual one we have set up.

(c) Consider the following C program that will be compiled and executed on Linux. The writer of the code expected an output of 100,000 to be printed for both the 1st and 2nd counter i.e. on lines 22 and 23. While the value 100,000 was printed for the 2nd counter, the value 66,149 was printed for the 1st counter. With reference to specific line numbers, briefly explain why there is a difference in the printed values. (6 marks)
```c
01: #include <stdio.h> 
02: #include <threads.h> 
03: #include <stdatomic.h> 
04: atomic_int acnt; 
05: int cnt; 
06: int f(void* thr_data) 
07: { 
08: for(int n = 0; n < 10000; ++n) 
09: { 
10: ++cnt; 
11: ++acnt; 
12: } 
13: return 0; 
14: } 
15: int main(void) 
16: { 
17: thrd_t thr[10]; 
18: for(int n = 0; n < 10; ++n) 
19: thrd_create(&thr[n], f, NULL); 
20: for(int n = 0; n < 10; ++n) 
21: thrd_join(thr[n], NULL); 
22: printf("The 1st counter is %d \n", cnt); 
23: printf("The 2nd counter is %d \n", acnt); 
24: }
```

The main difference that makes the two values turn out differently is that the cnt in line 5 is not an atomic count. This means that its value is never consistent while threads are modifying it concurrently in line 10. Threads can see and modify a stale value of the count, which makes the count different at every run when it's printed in line 22. The atomic count is an atomic variable, which means that it uses a mechanism like compare_and_swap, which makes sure that the value stays consistent with the previous increment. Only one thread is able to modify it at a time in line 11, and if a thread accesses a stale value, it fails and tries again later. That is why we will get the value of 100,000 in the print statement in line 23 at every execution of the program.

(d) Priority scheduling with round robin is used the schedule the processes in the table below for execution on a single-core CPU with a time quantum of 2. Using a Gantt Chart, illustrate the execution order of the processes. (8 marks)

| Process | Priority | Burst time |
| ------- | -------- | ---------- |
| P1      | 3        | 4          |
| P2      | 2        | 5          |
| P3      | 2        | 8          |
| P4      | 1        | 7          |
| P5      | 3        | 3          |
```
P4: runs 7 seconds, 0 left
P2: runs 2 seconds, 3 left
P3: runs 2 seconds, 6 left
P2: runs 2 seconds, 1 left
P3: runs 2 seconds, 4 left
P2: runs 1 second, 0 left
P3: runs 2 seconds, 2 left
P3: runs 2 seconds, 0 left
P1: runs 2 seconds, 2 left
P5: runs 2 seconds, 1 left
P1: runs 2 seconds, 0 left
P5: runs 1 second, 0 left
```

**Q3**
(a) Explain the difference between deadlock prevention and deadlock avoidance. In your answer describe the necessary conditions for deadlock to occur. (12 marks)

Deadlock prevention deals with programming in a way that makes sure that at least one of four conditions are disabled from the start, while deadlock avoidance still allows the possibility of conditions happening, but uses an algorithm that dynamically examines the resource-allocation state to ensure that deadlock does not happen.
Deadlock prevention includes disabling one of four in these ways:
1. Mutual exclusion - using shareable resources so they can be accessed by multiple processes at the same time
2.  Hold and Wait - must have a guarantee that a process will not wait for a resource while already holding one or allocating resources before execution begins
3.  No preemption - if a process is holding a resource and is waiting for another one, force it to release the resource and go to the waiting queue. It can try execution later when it regains all resources it needs
4.  Circular wait - impose a total ordering of all resource types, and require that each process requests resources in an increasing order of enumeration

Deadlock avoidance algorithm require a prior knowledge of which process needs which resource before execution. We can use algorithms like the Banker's algorithm, which calculates a safe and unsafe state, unsafe state being the one in which there is a possibility of a deadlock, and ensures that the system never enters the unsafe state. When a process requests an available resource, system must decide if immediate allocation leaves the system in a safe state. Safe state occurs when there are enough resources available to satisfy all processes if they request them, and if they are not immediately available, then processes need to wait until they are.

(b) Explain what busy waiting / spinlock is. Why is it not advantageous to use busy waiting / spinlock? What alternatives could be used instead of busy waiting / spinlock? (7 marks)

Spinlock is a way for the process to wait for a requested resource, and it is usually implemented with a while loop. The process constantly checks the state of a lock to determine whether the resource is available, but does no other useful job, which is precisely why it is not advantageous to use it because it wastes CPU cycles and time.
Alternatives to busy waiting / spinlocks are semaphores with a wait queue. If a process is waiting for a resource to be released, it is placed in a wait queue by wait(), so it does not perform a useless job, but instead it quietly waits for the resource. Once the resource is free, signal() removes the process from the queue.

(c) Consider the resource-allocation graph below for a system where a single instance is available for each resource (i.e. R1, R2, and R3). T1/T2/T3 are tasks/processes. Is this system in a safe, unsafe or deadlocked state? Explain your answer. 
Note: a broken-arrow line indicates a claim edge. (6 marks)

This system is currently in a safe state, even though T2 holding R1 and waiting for R3 is causing hold and wait condition. If T1 requests R2, it will have to wait for T3 to finish using it, but since T3 already holds R3 and R2 and is not waiting for another resource, there is no circular wait, which means that there is no risk of deadlock occurring in the current moment.

**Q4**
(a) The chmod command is used to set file permissions. Explain what file permissions are set for filename with the following command: 
chmod 761 filename (5 marks)

-  owner has full permissions: read, write, execute
-  group has read and write permissions
-  others can only execute

(b) Explain the difference between hard and soft links in the context of a filesystem. (4 marks)

Hard links make two files point to the same inode, so if the original file is deleted, the content is not lost, while soft links just make one file point to another file, so if the original file is deleted, the content is lost and cannot be accessed through the file that was linked to it.

(c) Paging is a memory management scheme. Explain how paging works using an example of a 32-bit virtual address. In your answer, explain how swapping can be used as part of paging memory management. (11 marks)

A 32-bit virtual address is translated into a physical address with a help of a page table. Assuming a page size of 4KB, the virtual address is split into a page number p (20 bits) and page offset d (12 bits because 4KB = 2^12). Page table maps the page number to a frame number, and the frame number combined with the offset gives us the actual physical address. 
If a total memory space of a process exceeds physical memory, that process can be swapped temporarily out of memory to a backing store (fast disk large enough to hold all copies of all memory images for all users), and then brought back into memory for continued execution. System maintains a ready queue for ready-to-run processes which have memory images on disk.

(d) Explain what is meant by the term DMA (Direct Memory Access). (5 marks)

Direct Memory Access is a mechanism that allows the DMA controller or and I/O device to transfer data directly to and from main memory without the help of the CPU. The CPU sets up the transfer, and the controller then does the rest of the work, so the CPU does not have to move data byte by byte, which saves a lot of time and cycles during large data transfers.