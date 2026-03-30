# solution 1 - shared memory for IPC

-  area of memory shared among the processes that wish to communicate
-  producer must wait if all buffers are full
-  consumer waits if there is no buffer to consume

buffer = fixed-size circular queue (ring buffer) in shared memory, basically a temporary storage area between the two processes
-  the producer writes items into it
-  the consumer reads items from it
-  `in = (in + 1) % BUFFER_SIZE;` this line makes it circular, when you reach the end, you wrap back to the beginning
-  when a consumer consumes an item, it is not physically removed from the buffer

```c
// shared data
#define BUFFER_SIZE 10
typedef struct {
	...
}item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

// consumer process
item next_consumed;

while (true) {
	while (out == in)
		; // do nothing
	next_consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE;
	// consume the item in next consumed
}

// producer process
// solution is correct, but can only use BUFFER_SIZE - 1 elements
item next_produced;

while(true) {
	// produce an item in next produced
	while (((in + 1) % BUFFER_SIZE) == out)
		; // do nothing
	buffer[in] = next_produced;
	in = (in + 1) % BUFFER_SIZE;
}
```

empty condition: `in == out`
full condition: `(in + 1) % BUFFER_SIZE == out`
"if moving in forward would collide with out, the buffer is full"

## filling all the buffers

-  int counter keeps track of the number of full buffers
-  set to 0 initially
-  incremented by producer after it produces a new buffer
-  decremented by consumer after it consumes a buffer

```c
// consumer
while (true) {
	while (counter == 0)
		; // do nothing
	next_consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE;
	counter--;
	// consume the item in next consumed
}

// producer
while (true) {
	// produce an item in next produced
	while (counter == BUFFER_SIZE)
		; // do nothing
	buffer[in] = next_produced;
	in = (in + 1) % BUFFER_SIZE;
	counter++;
}
```

# solution 2 - message passing

-  processes communicate with each other without resorting to shared variables
-  send(message) & receive(message)
-  message either fixed or variable

processes P and Q wish to communicate
-  establish a communication link between them
-  exchange messages via send / receive

direct - the sender names the receiver explicitly
-  send(P, message) - send a message to process P
-  receive(Q, message) - receive a message from process Q

indirect - messages directed and received from mailboxes (ports) - intermediary entity:
-  each mailbox has unique id
-  processes can communicate only if they share a mailbox

blocking - synchronous
-  blocking send() - sender is blocked until the message is received
-  blocking receive() - receiver is blocked until a message is available

non-blocking - asynchronous
-  non-blocking send - sender sends the message and continue
-  non-blocking receive - receiver receives valid message or null message

different combinations possible
-  rendezvous - both send and receive block

```c
// producer
message next_produced;
while (true) {
	// produce an item in next_produced
	send(next_produced);
}

// consumer
message next_consumed;
while (true) {
	receive(next_consumed)
	// consume the item in next_consumed
}
```

queue of messages attached to the link

implemented in one of three ways
1.  zero capacity - no messages are queued on a link (sender must wait for receiver - rendezvous)
2.  bounded capacity - finite length of n messages (sender must wait if link full)
3.  unbounded capacity - infinite length (sender never waits - but consider RAM memory issues)

# solution 3 - semaphore

-  n buffers, each can hold one item
-  semaphore mutex initialised to 1 (protects critical section)
-  semaphore full initialised to 0 (goes from 0 to n)
-  semaphore empty initialised to the value n (goes from n to 0)

```c
// producer
while (true) {
	...
	// produce an item in next_produced
	...
	wait(empty);
	wait(mutex);
	...
	// add next produced to the buffer
	...
	signal(mutex);
	signal(full);
}

// consumer
while (true) {
	wait(full);
	wait(mutex);
	...
	// remove an item from buffer to next_consumed
	...
	signal(mutex);
	signal(empty);
	...
	// consume the item in next consumed
	...
}
```