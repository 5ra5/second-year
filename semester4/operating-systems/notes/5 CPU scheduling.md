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

▪ CPU utilisation – keep the CPU as busy as possible
▪ Throughput – number of processes that complete their execution per time unit
▪ Turnaround time – total time from process submission to process completion (includes waiting, execution, and I/O)
▪ Waiting time – amount of time a process spends in the ready queue
▪ Response time – amount of time it takes from when a request was submitted until the first response is produced.
▪ Max CPU utilisation
▪ Max throughput
▪ Min turnaround time
▪ Min waiting time
▪ Min response time

improving one metric often worsens another


## **first-come, first-served (FCFS) scheduling**

processes need to wait for the previous one to finish so that they can start
Suppose that the processes arrive in the order:  P1 , P2 , P3
Waiting time for P1 = 0; P2 = 24; P3 = 27
Average waiting time: (0 + 24 + 27)/3 = 17

Suppose that the processes arrive in the order: P2 , P3 , P1
Waiting time for P1 = 6; P2 = 0; P3 = 3
Better than previous case i.e. lower average waiting time
Convoy effect - short processes delayed by a long CPU-bound
process

