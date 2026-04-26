**Q1**
(a) Describe the Linux process life-cycle, indicating the state transitions that can occur for a process e.g. new state to a ready state. In your answer, explain the role that the operating system scheduler has in these state transitions. (8 marks)

Answer:
Process life-cycle in linux starts with the creation of a process. When the process is created and ready to be executed, it is placed in a ready queue where it waits for its turn to run. Going from ready state to running state is not determined by a process, but by the system scheduler (order depends on the scheduling algorithm put in place). Once the scheduler determines that the process should run, the CPU dispatcher allows the process to run. The process can go three ways from the running state. It can go back to ready state if it is interrupted by the scheduler to give another process time to run, it can go to a waiting state if it is waiting for a resource or an I/O action, or it can be terminated if it finished its task. The process goes back to ready state from the waiting state because while that process is in the waiting state, another process goes into the running state.

(b) Briefly explain what the C function execlp() does on Linux. (4 marks)

Answer:
execlp() replaces the process image with a new program, commonly in the child process after fork(). The p means it searches the directories in the PATH variable to find the executable.

(c) Explain the memory layout of the C program below. In your answer, state what will be stored in each of the following memory sections when the program shown below is executed: heap, text, initialised data, uninitialised data and stack. (8 marks)
```c
00: #include <stdio.h> 
01: #include <stdlib.h> 
02: 
03: int a=2; 
04: int b; 
05: 
06: int main(int argc, char **argv) 
07: { 
08: int *vals;
09: int i;
10: 
11: vals = (int *)malloc(sizeof(int)*10);
12: 
13: for (i = 0; i < 10; i++) 
14: vals[i] = i; 
15: 
16: return 0; 
17: }
```

Answer:
-  Heap contains dynamically allocated memory block, memory block in line 11 will be stored in heap.
-  Text contains executable program code - functions and instructions of the program, so line 6 would be contained in text section.
-  Initialised data contains global or static variables that are assigned value initially: contains line 3.
-  Uninitialised data contains global or static variables that are not assigned a value initially: contains line 4
-  Stack contains all local variables: contains lines 8 and 9

(d) Explain why an executable program compiled on one system may not be executable on another system. (5 marks)

Answer:
Executable program compiled on one system may not be executable on another system because each system provides its own unique system calls, so instructions in the executable may be incompatible. If the program is written in a standard language like C, it needs to be compiled separately on each operating system to run on each, while interpreted languages allow for multi-system applications.

**Q2**
(a) Using Amdahl's law, calculate the speedup of a program with a 25% serial proportion for 5 processors. Assuming there is an unlimited number of processors available, what's the maximum speedup that could be achieved? (7 marks)

Answer:
speedup <= 2.5
speedup with unlimited processors <= 0.2

(b) The following C code demonstrates the operation of the compare-and-swap instruction that executes atomically. Provide a code example that shows how the compare-and-swap instruction could be used to implement an atomic integer variable i.e. show you would implement `void increment(atomic_int *v)` (8 marks)
```c
int compare_and_swap( int *value, int expected, int new_value) 
{
	int t = *value; 
	
	if (*value == expected) 
		*value = new_value; 
		
	return t; 
}
```

Answer:
```c
void increment(atomic_int *v)
{
	int temp;
	do {
		temp = *v;
	} while (temp != (compare_and_swap(v, temp, temp+1));
}
```

(c) In the table below, the shortest-remaining-time-first scheduling is used to schedule processes for execution on a single-core CPU. Show the execution order of the processes (e.g. using a Gantt Chart) and calculate the average waiting time of the processes. (10 marks)

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| P1      | 0            | 8          |
| P2      | 1            | 4          |
| P3      | 2            | 9          |
| P4      | 3            | 5          |

Answer:
The schedule:
```
P1: 0–1
P2: 1–5
P4: 5–10
P1: 10–17
P3: 17–26
```

Waiting times:
```
P1 = 17 - 0 - 8 = 9
P2 = 5 - 1 - 4 = 0
P3 = 26 - 2 - 9 = 15
P4 = 10 - 3 - 5 = 2
```

Average waiting time:
```
(9 + 0 + 15 + 2) / 4 = 6.5
```

**Q3**
(a) Using an example of an integer variable counter, where 2 threads execute counter++ concurrently, explain what a race condition. In your answer, describe how a programmer would prevent a race condition. (7 marks)

Answer:
A race condition occurs when multiple threads access shared data concurrently and the final result depends on the order/timing of execution.
For example, `counter++` is not atomic. It may be implemented as:
```c
register1 = counter;
register1 = register1 + 1;
counter = register1;
```
If two threads both execute this when `counter = 0`, both may read 0, both increment their register to 1, and both write back 1. The final value is 1 instead of 2.
This can be prevented by protecting the critical section with a synchronisation primitive such as a mutex or semaphore:
```c
lock(mutex);
counter++;
unlock(mutex);
```
This ensures only one thread updates counter at a time.

(b) Explain the wait() and signal() operations of the semaphore synchronisation primitive. In your answer, explain how busy waiting can be avoided in the implementation of the wait() operation. (7 marks)

Answer:
wait(S) is used before entering a critical section or using a resource. If the semaphore value is greater than 0, wait() decrements it and the process continues. If the value is 0, the process cannot continue and is placed in a waiting queue.
signal(S) is called when a process leaves the critical section or releases a resource. If processes are waiting, one process is woken up and moved to the ready queue. If no processes are waiting, the semaphore value is incremented.
Busy waiting can be avoided by implementing wait() and using block() instead of spinning in a loop. When the semaphore is unavailable, the process is blocked and placed in the semaphore's waiting queue, so it does not waste CPU cycles repeatedly checking the semaphore.

(c) The following program will end up in a deadlocked state. Explain why, by discussing each of 4 necessary conditions for deadlock, and explain how each applies to the program below with reference to specific line numbers. (11 marks)
```c
00: import threading 
01: 
02: lock1 = threading.Lock() 
03: lock2 = threading.Lock() 
04: 
05: def thr1(): 
06: while True: 
07: lock1.acquire() 
08: lock2.acquire() 
09: print("CS: Thr1") 
10: lock1.release() 
11: lock2.release()
```

```c
12: def thr2(): 
13: while True: 
14: lock2.acquire() 
15: lock1.acquire() 
16: print("CS: Thread2") 
17: lock2.release() 
18: lock1.release() 
19: 
20: def main(): 
21: threading.Thread(target=thr1).start() 
22: threading.Thread(target=thr2).start() 
23: print("running ...") 
24: 
25: main()
```

Thread 1 acquires lock1(line 07), then lock2(line 08) and Thread 2 acquires lock2(line 14), then lock1(line 15). This will cause circular wait condition because both threads need to acquire both locks to continue execution, but acquiring them in this order will cause Thread 1 to wait for the lock2 indefinitely, while Thread 2 waits for lock1 indefinitely. This also causes hold and wait condition, because both threads are waiting for another resource while already holding one. Another condition that causes deadlock here is that there is no preemption because there is no mechanism put in place which terminates threads if the state of deadlock happens, so the indefinite wait is unstoppable. The last condition that causes deadlock in this scenario is mutual exclusion, and it happens because each lock can be held by only one thread at a time.

**Q4**
(a) The following sequence of commands are run on Linux:
```shell
echo "123" > myfile1.txt 
ln myfile1.txt myfile3.txt 
ln myfile1.txt myfile2.txt 
echo "XYZ" > myfile2.txt 
echo "ABC" > myfile3.txt
```

What (if anything) is contained in myfile1.txt? (4 marks)

Answer:
myfile1.txt contains ABC

(b) Explain the difference between hard and soft links in the context of a filesystem. In your answer, explain why hard links are not allowed for directories. (6 marks)

Answer:
Hard links point to the same inode on the disk (same file-system object like file or directory), while soft links just point to a file. With soft links, if the original file is deleted, we cannot access the content through the file that was pointing to it, unlike with hard links.
Hard links are not allowed for directories because they create cycles in the directory graph. These cycles can cause infinite loops in file system traversal.

(c)
Paging is a memory management scheme.
i) Explain how a page table works by using an example of a 32-bit virtual address. 
ii) Describe the implications of using a small versus a large frame/page size (12 marks)

Answer:
i) A page table holds mappings from page numbers to frame numbers and is used in mapping a virtual address to a physical address. Assuming the page size of 4KB, a 32-bit virtual address is split into a page number p = 20 (used as an index to a page table) and an offset d = 12 (because 4KB = 2^12). Offset is combined with the frame number associated with the page number. Frame number f and offset d make a physical address. This process can be optimised using a TLB (Translation Lookaside Buffer) which keeps recent mappings, so if it contains a recently mapped page number, the address does not have to go to the page table, which saves time and resources.

ii) A large frame/page size might require us to to add more page tables to further break them down. This is required to avoid internal fragmentation (unused space in a memory unit when it is holding something of a smaller size than the actual unit). Large frame/page sizes handle large logical addresses well because they do not have to be broken down. A small frame/page size avoids the problem of internal fragmentation, but bigger virtual addresses (e.g. 64-bits) have to be broken down into many pages, which grows the number of memory access we would need to get to one physical memory location.

(d) Explain what the following Linux command does: 
`chmod 711 myfile` (3 marks)

-  owner gets full permission: read, write, execute
-  group can only execute
-  others can only execute