N philosophers at a round table with bowl of rice in the middle
states = thinking or eating
they do not interact with their neighbours
eating:
-  try to pick up 2 chopsticks (one at a time) to eat from bowl (need both to eat, then release both when done)

shared data (5 philosophers):
-  bowl of rice (data set)
-  semaphore chopstick 5 initialised to 1

```c
// philosopher
while (true) {
	wait (chopstick[i]);
	wait (chopStick[(i+1) % 5);
	// eat for a while
	signal(chopstick[i]);
	signal(chopstick[i+1] % 5);
	// think for a while
}
```