data set shared among a number of concurrent processes
-  readers - only read the data set, do not perform any updates (multiple readers at the same time is okay)
-  writers - can both read and write (only one writer at a time, and no readers when writing)

several variations of how readers and writers are considered - all involve some form of priorities
-  first, second and third

shared data:
-  data set
-  semaphore `rw_mutex` initialised to 1
-  semaphore mutex initialised to 1 (used to protect read_count)
-  integer read_count initialised to 0 (how many are reading - and needs to be protected)

```c
// writer
while (true) {
	wait(rw_mutex);
	...
	// writing is performed
	... signal(rw_mutex);
}

// reader
while (true) {
	wait(mutex);
	read_count++;
	if (read_count == 1) // first reader
		wait(rw_mutex);
	signal(mutex);
	...
	// reading is perfomed
	...
	wait(mutex);
	read_count--;
	if (read_count == 0) // last reader
		signal(rw_mutex);
	signal(mutex);
}
```

## problem variations

1.  no reader should be kept waiting, unless a writer has already obtained permissions (readers-preference)
2.  if a writer is ready to write, it writes as soon as possible i.e, takes priority over waiting readers (writers-preference)
3.  a reader nor writer shall starve (both the first and second may result in starvation)