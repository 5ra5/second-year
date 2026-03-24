#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 0; // shared memory (same address space)

void* writer(void* arg)
{
	sleep(1); // give reader time to start
	shared = 42;
	printf("Writer: set shared = %d\n", shared);
	return NULL;
}

void* reader(void* arg)
{
	printf("Reader: initial shared = %d\n", shared);
	
	while (shared == 0) {
		// busy wait
	}
	
	printf("Reader: saw shared change to %d\n", shared);
	return NULL;
}

int main()
{
	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, reader, NULL);
	pthread_create(&t2, NULL, writer, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}
