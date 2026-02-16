***exponential averaging not coming up on the exam***
***shortest-time-remaining-first example might come up on the exam (more complex than slides)***
***completely fair scheduler not coming up on the exam (calculations, explanation of the concept)***

the scheduler operates when processes move between READY and RUNNING

a **context switch** occurs when the CPU switches from one process to another
scheduling decides *who* (which processes run and which don't), context switching decides *how*

-  obtain maximum CPU utilisation with multiprogramming
-  CPU-I/O burst cycle - process execution consists of a cycle of CPU execution consists of a cycle of CPU execution and I/O wait
-  CPU burst followed by I/O burst
-  observed CPU usage over time is of main concern

CPU burst times = large number of short bursts, small number of longer bursts

-  The CPU scheduler selects one process from the ready set and allocates a CPU core to it. Queue may be ordered in various ways

CPU scheduling decisions are involved in the following state
transitions:
1. Switches from running to waiting state
2. A running process is preempted (running -> ready)
3. Switches from ready to running state
4. Terminates
▪ For situations 1 and 4, the running process must leave the CPU, so another ready process (if any) must be selected.
▪ For situations 2 and 3, however, there is a choice.

## preemptive and nonpreemptive scheduling

nonpreeemptive = once the CPU has been allocated to a process, the process keeps the CPU until it releases it either by **terminating** or by switching to the **waiting** state
-  otherwise is **preemptive** (used by virtually all operating systems)

## dispatcher

▪ Dispatch latency – the time it takes for the system to stop one process and start executing the process selected by the scheduler.

Dispatch involves giving control of the CPU to the process selected by the CPU
scheduler; this involves:
• Switching context
• Switching to user mode
• Jumping to the proper location in the user program to restart that program

# basic schedulers
## scheduling criteria

▪ **CPU utilisation** – keep the CPU as busy as possible
▪ **Throughput** – number of processes that complete their execution per time unit
▪ **Turnaround time** – total time from process submission to process completion (includes waiting, execution, and I/O) - doesn't always apply because some processes do not have runtime
▪ **Waiting time** – amount of time a process spends in the ready queue
▪ **Response time** – amount of time it takes from when a request was submitted until the first response is produced.

▪ Max CPU utilisation
▪ Max throughput
▪ Min turnaround time
▪ Min waiting time
▪ Min response time

improving one metric often worsens another


## **first-come, first-served (FCFS) scheduling**

processes need to wait for the previous one to finish so that they can start - the simplest, most naive scheduling

Suppose that the processes arrive in the order:  P1 , P2 , P3
Waiting time for P1 = 0; P2 = 24; P3 = 27
Average waiting time: (0 + 24 + 27)/3 = 17

order matters and it affects the runtime:
Suppose that the processes arrive in the order: P2 , P3 , P1
Waiting time for P1 = 6; P2 = 0; P3 = 3
Better than previous case i.e. lower average waiting time
Convoy effect - short processes delayed by a long CPU-bound
process

## shortest-job-first (SJF) scheduling

-  if we know what will be the burst time of a process, we prioritise the shortest ones
-  SJF is optimal – (in the sense that) it gives minimum average waiting time for a given set of processes with known burst times

processes and their burst time:
P1 = 6
P2 = 8
P3 = 7
P4 = 3

-  Average waiting time = (3 + 16 + 9 + 0) / 4 = 7
-  Waiting times: P₁ = 3, P₂ = 16, P₃ = 9, P₄ = 0

we end up with the minimum waiting time

## Determining Length of Next CPU Burst

Can only estimate the length – should be similar to the previous one 
-  Then pick process with shortest predicted next CPU burst
-  estimate the average of two last bursts
-  older value should have less contribution, don't get an average of all burst times

## Shortest-remaining-time-first

main things to take away:
* ***concept of preemption***
-  ***accountancy exercise - keeping track of the remaining time to be able to calculate average waiting time***
-  ***can appear in the exam***

**SRTF**: Shortest-remaining-time-first algorithm: the preemptive version of shortest job first
Now we add the concepts of **varying arrival times** and **preemption** to the analysis

prioritising processes by the shortest burst time
-  while processes arrive in time, we keep track of other processes remaining time to determine which process to prioritise
-  waiting time = time spent in the ready queue
-  the shortest process interrupts the longer one to run

## Round Robin (RR)

-  Each process gets a small unit of CPU time (time quantum q), usually 10-100 milliseconds. After this time has elapsed, the process is preempted and added to the end of the ready queue.
-  If there are **n** processes in the ready queue and the time quantum is **q**, then each process gets **1/n** of the CPU time in chunks of at most q time units at once. No process waits more than **(n-1) * q** time units.
-  **Timer** interrupts every quantum to schedule next process

Performance
-  q large -> FIFO 
-  q small -> q must be large with respect to context switch, otherwise overhead is too high

Linux uses something a little more complex than this for scheduling, but the concept of interruption, time quantum and RR applies
-  In linux there’s a `scheduler_tick()` that gets called periodically 

**example of Round Robin with Time quantum = 4**

| Process | Burst TIme |
| ------- | ---------- |
| P1      | 24         |
| P2      | 3          |
| P3      | 3          |

the Gantt chart:
-  P1 runs for 4 milliseconds (0 to 4)
-  P2 runs for 3 milliseconds (4 to 7)
-  P3 runs for 3 milliseconds (7 to 10)
-  P1 continues to run in 4 millisecond interval until it is done (10 to 30)

typically, higher average turnaround than shorter-job-first, but better **response**
q should be large compared to context switch time
-  q usually 10 milliseconds to 100 milliseconds
-  context switch < 10 microseconds

**turnaround time varies with the time quantum**
**rule of thumb**: 80% CPU bursts should be shorter than q

## Priority Scheduling

nice command in linux = how nice a process should be to other processes (what is the priority of that process)
if nice of a process = 20; if something is less nice, it will run before that process
you can renice a process - set a new nice value

a priority number (integer) is associated with each process
the CPU is allocated to the process with the highest priority
-  preemptive
-  nonpreemptive

shortest-job-first is *akin* priority scheduling where priority is the inverse of predicted next CPU burst time

problem = **starvation** - low priority processes may never execute
one solution = **aging** - as time progresses increase the priority of the process

**example of priority scheduling**:

| ***Process*** | ***Burst Time*** | ***Priority*** |
| ------------- | ---------------- | -------------- |
| P1            | 10               | 3              |
| P2            | 1                | 1              |
| P3            | 2                | 4              |
| P4            | 1                | 5              |
| P5            | 5                | 2              |
Priority Scheduling Gantt Chart:
-  P2 runs for 1 millisecond (0 to 1)
-  P5 runs for 5 milliseconds (1 to 6)
-  P1 runs for 10 milliseconds (6 to 16)
-  P3 runs for 2 milliseconds (16 to 18)
-  P4 runs for 1 millisecond (18 to 19)

average waiting time = 8.2

**combining strategies: example of priority scheduling with Round Robin**

-  would be done in older versions of operating systems - we can simplify this today with completely fair scheduler

| Process | Burst Time | Priority |
| ------- | ---------- | -------- |
| P1      | 4          | 3        |
| P2      | 5          | 2        |
| P3      | 8          | 2        |
| P4      | 7          | 1        |
| P5      | 3          | 3        |
-  run the process with the highest priority
-  process with the same priority run round-robin

Gantt Chart with time quantum = 2
-  P4 runs for 7 milliseconds (0 to 7)
-  P2 runs for 2 milliseconds (7 to 9)
-  P3 runs for 2 milliseconds (9 to 11)
-  P2 runs for 2 milliseconds (11 to 13)
-  P3 runs for 2 milliseconds (13 to 15)
-  P2 runs for 1 millisecond (15 to 16)
-  P3 runs for 4 milliseconds (16 to 20)
-  P1 runs for 2 milliseconds (20 to 22)
-  P5 runs for 2 milliseconds (22 to 24)
-  P1 runs for 2 milliseconds (24 to 26)
-  P5 runs for 1 millisecond (26 to 27)

## Multilevel Queue

-  with priority scheduling, have separate queues for each priority
-  schedule the process in the highest-priority queue!

priority = 0 (T0, T1, T2, T3, T4)
priority = 1 (T5, T6, T7)
priority = 2 (T8, T9, T10, T11)
priority = n (TX, TY, TZ)

prioritisation is based upon process type
from highest to lowest priority:
-  real-time processes
-  system processes
-  interactive processes
-  batch processes

## Multilevel Feedback Queue

a process can **move between the various queues**
**multilevel-feedback-queue scheduler** defined by these parameters/features:
-  number of queues
-  **different** scheduling algorithms for each queue
-  method used to determine when to **upgrade** a process
-  method used to determine when to **demote** a process
-  method used to determine which queue a process will enter when that process needs service

Aging can be implemented using multilevel feedback queue

**example of Multilevel Feedback Queue**
three queues
-  Q0 - RR with time quantum 8 milliseconds
-  Q1 - RR with time quantum 16 milliseconds
-  Q2 - first-come-first-served, etc.

**scheduling**
A new process enters Q0, which is served in RR
-  when it gains CPU, the process receives 8 milliseconds
-  if it does not finish in 8 milliseconds, the process is moved to queue Q1
At Q1 job is again served in RR and receives 16 additional milliseconds
-  if it still does not complete, it is preempted and moved to queue Q2

Problem: processes in the low priority queues can starve, solution may be to boost priority after X time has passed

Strategies like this:
-  reduce feedback time
-  more flexible than plain MQs (starvation)
But downside is the complexity

### in Linux - Completely Fair Scheduler

***not coming up in the exam***
Linux CFS scheduler provides an efficient algorithm for selecting which task to run next. Each runnable task is placed in a red-black tree - a balanced binary search tree whose key is based on the value of `vruntime`
-  Task with the smallest value of `vruntime` is placed in the left-most child position

virtual runtime = virtual calculation
selecting whatever process has the minimum virtual runtime

step 1:
`time slice = min(10 milliseconds, priority number divided by sigma P times target)`
higher value - higher priority - gets a bigger time slice
if you sum up all of the priorities - sigma P
target = 100 milliseconds (what we divide among all processes)

step 2:
`vruntime += exec/P`

after each iteration, we sort the list again by the `vruntime`
this strategy is better than multilevel queues etc.

## Multiple-Processor Scheduling

CPU scheduling more complex when multiple CPUs are available
Multiprocess may be any one of the following architectures:
-  Multicore CPUs
-  Multithreaded cores
-  NUMA systems
-  Heterogeneous multiprocessing

caching = allow cache unit to make it seem like memory is working faster
not something we program ourselves, proprietary secrets of companies
if a process is put on the same core as previously, cache is less likely to fail and have to load data from main memory because it still contains the data it used the last time

### processor affinity

When a thread/process has been running on one processor, the cache
contents of that processor stores the memory accesses by that thread.

-  We refer to this as a thread having **affinity** for a processor (i.e., “processor affinity”)
-  Load balancing may affect processor affinity as a thread may be moved from one processor to another to balance loads, yet that thread loses the contents of what it had in the cache of the processor it was moved off of.
-  **Soft affinity** – the operating system attempts to keep a thread running on the same processor, but no guarantees.
-  **Hard affinity** – allows a process to specify a set of processors it may run on.