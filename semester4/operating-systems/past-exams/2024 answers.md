**Q1**
(a) Consider the process life-cycle figure shown below, where processes change between various states during their lifetime. (6 marks)
Describe why each of the following state transitions of a process might occur: 
i) transition from a running state to a ready state (A) 
ii) transition from a ready state to a running state (B) 
iii) transition from a waiting state to a ready state (C)

i) The process ran out of time while running because of preemption, the CPU dispatcher puts it back in the ready queue to allow for another process to run.
ii) The CPU dispatcher allows the process to run
iii) The process waited for an I/O event to happen or to acquire a resource, once that happens the process is put back into ready state. It is not put back into running state because a different process runs in the meantime to not waste CPU time.

(b) Consider the following C program that will be compiled and executed on Linux.
```c
01: #include <stdio.h> 
02: #include <unistd.h> 
03: #include <sys/types.h> 
04: #include <sys/wait.h> 
05: int main() 
06: { 
07: pid_t pid; 
08: pid = fork(); 
09: if (pid < 0) { 
10: return 1; 
11: } 
12: else if (pid == 0) { 
13: execlp("/bin/ls","ls",NULL); 
14: printf("Here123 \n"); 
15: } 
16: else { 
17: wait(NULL); 
18: } 
19: return 0; }
```

i) Explain what the fork() and execlp() calls do. 
ii) Will the print statement on line 14 be executed? Explain why or why not. 
iii) What is the purpose of the call to wait() on line 17? (11 marks)

i) Fork() call creates a child process, which is a copy of a parent process, but it runs independently and has its own memory. The parent process returns the child's PID and the child process returns a PID of 0. Execlp() replaces the current process image with a new program, and p means that it can search through a given path to find the program executable, in this example, it will execute ls.

ii) The print statement on line 14 will not be printed because when execlp() replaces the current process image with ls and ls is executed, anything else in this program will not get executed.

ii) wait() on line 17 blocks the parent process until the child process is finished. It is used to not make the child process an orphan process.

(c) What information would we expect to find about a process in a Process Control Block about? (4 marks)

We can find information like process state, program counter, CPU registers, CPU scheduling information, memory-management information, accounting information, I/O status information, etc.

(d) The size command on Linux gives us information about the size of memory for initialised data, uninitialised data, and code size. Why doesn't the size command on Linux give us information about the heap size of a program? (4 marks)

The size command on Linux doesn't give us information about the heap size because heap keeps blocks of dynamically allocated memory, which is always allocated during runtime, different and changing through execution of a process as it is claiming and releasing memory.

**Q2**

(a) What is Amdahl's law? What does Amdahl's law tell us about a program? (5 marks)

Amdahl’s law describes the maximum speedup possible when only part of a program can be parallelised.
It shows that program speedup is limited by the **serial portion** of the program. Even if more processors are added, the serial part must still run sequentially, so there is an upper limit on the speedup that can be achieved..

(b) Shared memory and message passing are two ways that processes on a system can communicate. Explain what both of these are. (6 marks)

Shared memory is a method of communication in which two processes read and write from variables situated on a block of memory both processes can access. It requires a level of synchronisation to achieve clear communication. It can be achieved through a bounded buffer and reader/writer processes.
Message passing is a method of communication in which one process is the sender, and one is a receiver. This can be done directly, or through a port/mailbox. Message passing can also be blocking or non-blocking, which either makes processes wait for the message to be sent or received, or they can continue running.

(c) Consider the following C program that will be compiled and executed on Linux. The writer of the code expected an output of 200,000 to be printed, however, the value 177,249 was printed. With reference to specific line numbers, explain the problem and describe what changes you would make to the code to resolve it. (9 marks)
```c
01: #include <stdio.h> 
02: #include <threads.h> 
03: #include <stdatomic.h> 
04: int cnt; 
05: int f(void* thr_data) 
06: { 
07: for(int n = 0; n < 10000; ++n) 
08: ++cnt; 
09: return 0; 
10: } 
11: int main(void) 
12: { 
13: thrd_t thr[20]; 
14: for(int n = 0; n < 20; ++n) 
15: thrd_create(&thr[n], f, NULL); 
16: for(int n = 0; n < 20; ++n) 
17: thrd_join(thr[n], NULL); 
18: printf("The counter is %u\n", cnt); 
19: } 
```

The main problem is that the cnt variable initialised in line 4 is not atomic, even though the atomic library was imported in line 3. Line 14 and 15 create 20 threads, and each of those threads can access and modify the count in the loop in lines 7 and 8, but because the count is not atomic, it allows multiple threads to modify it at the same time. This causes threads reading and writing to a stale value, which doesn't increment the count properly. So when we print the count in line 18, we will get a different value at each execution. The way to fix this is to initialise cnt as atomic_int cnt in line 4. This way the final value will always be the expected value.

(d) Is the following statement true or false? Explain why or why not? 
Using a round robin scheduler in an operating system will mean that some processes are never scheduled to execute. (5 marks)

This statement is false because round robin gives each process the same amount of time (time quantum) to run in a circle, so that no process is left out and process starvation is completely avoided.

**Q3**

(a) Explain what is meant by the term deadlock prevention. In your answer, describe each of the 4 necessary conditions for deadlock to occur. (11 marks)

Deadlock prevention means designing the system so that at least one of the four necessary conditions for deadlock cannot occur.
The four necessary conditions are:
1. **Mutual exclusion**: at least one resource is non-shareable, so only one process can use it at a time. This can be prevented only for resources that can be made shareable.
2. **Hold and wait**: a process holds one resource while waiting for another. This can be prevented by requiring a process to request all needed resources before execution, or to release held resources before requesting more.
3. **No preemption**: resources cannot be forcibly taken from a process; they must be released voluntarily. This can be prevented by preempting resources from a process if it cannot obtain the additional resources it requests.
4. **Circular wait**: a cycle exists where each process waits for a resource held by the next process. This can be prevented by imposing a strict ordering on resource types and requiring processes to request resources in that order.

(b) Consider the following Python code for the dining philosophers problem. Will this code result in deadlock? Explain why or why not. In your answer, make reference to specific line numbers. (8 marks)
```python
01: import threading, random, time 
02: def philosopher_func(name, left, right): 
03: while True: 
04: fork1, fork2 = left, right 
05: print(name, "thinking") 
06: time.sleep(random.uniform(1,10)) 
07: while True:
08: fork1.acquire(True) 
09: locked = fork2.acquire(False) 
10: if locked: 
11: break 
12: fork1.release() 
13: fork1, fork2 = fork2, fork1 
14: print(name, "dining") 
15: time.sleep(random.uniform(1,10)) 
16: fork2.release() 
17: fork1.release()
18: forks = [threading.Lock() for n in range(5)] 
19: names = ('Aristotle','Kant','Spinoza','Marx', 'Russel') 
20: for i in range(5): 
21: t = threading.Thread(target=philosopher_func, \ 
22: args=(names[i], forks[i%5], forks[(i+1)%5])) 
23: t.start() 
```

No, this code should not result in deadlock.
At line 08, a philosopher acquires the first fork using a blocking acquire. At line 09, it tries to acquire the second fork using acquire(False), which is non-blocking. If the second fork is successfully acquired, line 10 is true and the philosopher breaks out of the loop to dine.
However, if the second fork is not available, the philosopher does not wait while holding the first fork. Instead, line 12 releases fork1 and line 13 swaps the fork order before trying again.
This prevents the hold and wait condition, because a philosopher does not continue holding one fork while waiting indefinitely for the other. Therefore, deadlock is avoided.

(c) Consider the resource-allocation graph below for a system where a single instance is available for each resource (i.e. R1, R2, and R3). T1/T2/T3 are tasks/processes. Is this system in a safe, unsafe or deadlocked state? Explain your answer. 
Note: a broken-arrow line indicates a claim edge. (6 marks)

This system is in an unsafe state. If T3 requests R2, the system will fall into a deadlock state because circular wait would start - every process is holding a resource while waiting for another one (also hold and wait condition), and  only one process is available to each resource (mutual exclusion condition).

**Q4**

(a) What does the term internal fragmentation mean in the context of memory management? Use an example as part of your answer. (7 marks)

Internal fragmentation happens when there is an extra unused memory left in a page that holds a process which is smaller than the page. This usually happens when multiple pages are used for one process, so the size of the process does not perfectly match the page size after it has been split up between pages. For example, if the page size if 4KB and a process needs 10KB, it must be allocated 3 pages, which means that we would have 2KB wasted.