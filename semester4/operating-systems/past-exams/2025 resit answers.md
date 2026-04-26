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

**Q3**
(a) A programmer is attempting to implement a solution to the bounded-buffer/producer- consumer problem for a buffer of size n. They have encountered difficulty when using the implementation below. Three semaphores mutex, full and, empty have been initialised to 1, 0, and n, respectively. The following implementation has logical issues. Outline the changes you would make for it to operate correctly. Refer to specific line numbers in your answer, and explain the correct use of each semaphore. (8 marks)

Consumer process: 
01: while (true) { 
02: wait(empty); 
03: signal(mutex); 
04: ... 
05: /* remove item from buffer*/ 
06: ... 
07: signal(full); 
08: signal(empty); 
09: }

Producer Process: 
10: while (true) { 
11: /* produce an item */ 
12: signal(empty); 
13: wait(mutex); 
14: ... 
15: /* add produced item to buffer */ 
16: ... 
17: wait(empty); 
18: }

Answer:
Wait should always be at the top, and signal at the bottom because both processes are waiting for an event to happen (either the buffer is empty or full or mutex is 0 or 1) to add or remove from the buffer, after which they signal the other process.
The line 02 should be wait(full), and line 03 should be wait(mutex), line 07 should be signal(mutex)
The line 12 should be wait(empty), line 17 should be signal(mutex), and we should have another line after it with signal(full)
These changes have to be made because the producer is supposed to wait for at least one slot of the buffer to be empty and the lock to be free to add to the buffer, and the consumer needs to wait for the buffer to be full to remove an item from the buffer. After each process does its job, they signal the other one to do its job.

(b) The program below has two threads that may execute concurrently (i.e. thread-A and thread-B), and two locks shared between these threads (i.e. lock1 and lock2). Using the program below, explain the concept of deadlock. In your answer, describe the four necessary conditions for deadlock and show how they apply with reference to specific line numbers. (11 marks)
code from thread A
```c
A-1: lock1.lock() 
A-2: lock2.lock() 
A-3: a=a+b 
A-4: lock1.unlock() 
A-5: lock2.unlock()
```

code from thread B
```c
B-1: lock2.lock() 
B-2: lock1.lock() 
B-3: b=b+a 
B-4. lock2.unlock() 
B-5: lock1.unlock() 
```

Answer:
Deadlock can occur if Thread A obtains `lock1` at A-1 and Thread B obtains `lock2` at B-1. Thread A then waits for `lock2` at A-2, while Thread B waits for `lock1` at `B-2`, so neither can continue.
The four conditions are: mutual exclusion, because each lock can only be held by one thread; hold and wait, because each thread holds one lock while waiting for the other; no preemption, because locks cannot be forcibly removed and must be released using `unlock()`; and circular wait, because A waits for B's lock while B waits for A's lock. The problem is caused by acquiring locks in different orders. Both threads should acquire locks in the same order to avoid deadlock.

(c) Describe two different changes that could be made to the program for Q3(b) so that deadlock would not occur. In your answer, indicate what condition(s) of deadlock each change invalidates. (6 marks)

Answer:
Instead of two locks, threads can use one lock. This would cancel hold and wait, because if Thread A holds the lock, Thread B has to wait for its turn to hold it without holding up another resource, which would also solve circular wait.
Alternatively, the order of acquiring locks could be changed to be same: both look to acquire lock1 first, which would cancel circular wait because Thread-A would not be holding lock1 and wait for lock2 and vice versa with Thread-B.

**Q4**
(a) The following sequence of commands are run on Linux:
```shell
echo "123" > myfile1.txt 
ln myfile1.txt myfile3.txt 
ln myfile1.txt myfile2.txt 
echo "XYZ" > myfile2.txt 
rm myfile2.txt 
echo "ABC" > myfile2.txt
```
After the above commands are executed, what content is stored in myfile1.txt? (4 marks)

Answer:
The content stored in myfile1.txt is XYZ.

(b) Explain what is meant by the term DMA (Direct Memory Access). In your answer, explain why DMA would be used instead of programmed I/O. (6 marks)

Answer:
DMA is a feature of computer systems that allows certain hardware subsystems to access main system memory independently of the CPU. It is used instead of programmed I/O for large data movement because it reduces CPU overhead by avoiding the need for the CPU to transfer each byte/word individually. It can bypass CPU and transfer data directly between I/O device and memory to optimise the performance of the system - CPU can now work on other actions.

(c) Paging is a memory management scheme. 
i) Explain how a page table works, using an example of a 32-bit virtual address. 
ii) Describe the role of the Translation Lookaside Buffer (TLB) in paging. (12 marks)

Answer:
i) Paging divides virtual memory into fixed-size pages and physical memory into fixed-size frames. A page table stores the mapping from each virtual page number to a physical frame number.
For example, with a 32-bin virtual address and 4KB pages, the offset is 12 bits because:
```
4KB = 2^12 bytes
```
So the 32-bit virtual address can be split into:
```
20-bit page number | 12-bit page offset
```
The CPU generates a virtual address. The page number is used as an index into the page table. The page table entry gives the physical frame number. The offset stays the same and is combined with the frame number to form the physical address.
Example:
```
virtual address = page number p + offset d
page table[p] = frame number f
physical address = frame number f + offset d
```
If a two-level page table is used, the 20-bit page number may be split further, for example:
```
10-bit outer page table index | 10-bit inner page table index | 12-bit offset
```
This reduces the need to store one large contiguous page table.

ii) The Translation Lookaside Buffer, or TLB, is a small fast hardware cache that stores recent virtual-page-to-physical-frame translations.
Without a TLB, each memory access may require two memory accesses: one to read the page table entry, and one to access the actual data or instruction in memory.
With a TLB, the CPU first checks whether the page number is in the TLB. If there is a **TLB hit**, the frame number is found quickly and the physical address can be generated without reading the page table from memory. If there is a **TLB miss**, the page table must be accessed, and the resulting translation may be inserted into the TLB.
The TLB improves performance because many programs repeatedly access the same pages. Some TLB entries may also include an address-space identifier so that translations belonging to different processes can be distinguished safely

(d) Explain what the following Linux command does: 
`chmod 755 myfile` (3 marks)

This command gives the following permissions:
-  owner can read, write and execute
-  group can read and execute
-  others can read and execute