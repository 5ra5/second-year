## mutex locks
creating and initialising the lock
```c
#include <pthread.h>

pthread_mutex_t mutex;

// create and initialize the mutex lock
pthread_mutex_init(&mutex, NULL);
```

acquiring and releasing the lock
```c
// acquire the mutex lock
pthread_mutex_lock(&mutex);

// critical section

// release the mutex lock
pthread_mutex_unlock(&mutex);
```

## unnamed semaphores

creating and initialising the semaphore
```c
#include <semaphore.h>
set_t sem;

// create the semaphore and initialise it to 1
sem_init(&sem, 0, 1);
```

acquiring and releasing the semaphore
```c
// acquire the semaphore
sem_wait(&sem);

// critical section

// release the semaphore
sem_post(&sem);
```

## named semaphores

creating and initialising the semaphore
```c
#include <semaphore.h>
sem_t *sem;

// create the semaphore and initialize it to 1
sem = sem_open("SEM", O_CREAT, 0666, 1);
```

-  another process can access the semaphore by referring to its name SEM
-  can be used by unrelated processes, unlike unnamed semaphores

acquiring and releasing the semaphore
```c
// acquire the semaphore
sem_wait(sem);

// critical section

// release the semaphore
sem_post(sem);
```

## condition variables

creating and initialising the condition variable
```c
pthread_mutex_t mutex;
pthread_cond_t cond_var;

pthread_mutex_init(&mutex, NULL);
pthread_cond_init(&cond_var, NULL);
```

thread waiting for the condition a == b to become true
```c
pthread_mutex_lock(&mutex);
while (a != b)
	pthread_cond_wait(&cond_var, &mutex);
a = 100;
pthread_mutex_unlock(&mutex);
```

thread signalling another thread waiting on the condition variable
```c
pthread_mutex_lock(&mutex);
a = b;
pthread_cond_signal(&cond_var);
pthread_mutex_unlock(&mutex);
```

