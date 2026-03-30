## no busy waiting

```c
struct semaphore {
	int value;
	queue L; // list of processes
}

wait(S) {
	if (s.value > 0)
		s.value = s.value - 1;
	else
		add this process to s.L;
		block;
}

signal(S) {
	if (S.L != EMPTY) {
		remove a process from S.L;
		wakeup(P);
	}
	else
		s.value = s.value + 1;
}
```