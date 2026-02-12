***exponential averaging not coming up on the exam***

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