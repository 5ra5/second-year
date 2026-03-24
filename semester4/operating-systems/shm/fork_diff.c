#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int var = 5;

int main(int argc, char**argv)
{
	pid_t fork_ret;
	
	fork_ret = fork();
	
	if (fork_ret == 0) // in the child
	{
		var = 100;
		printf("In the child with pid %d, and the value of var is %d\n", getpid(), var);
	}
	else // in the parent
	{
		sleep(4); // sleep in the parent so child has had a chance to run for a while
		printf("In the parent with pid %d, and the value of var is %d\n", getpid(), var);
		wait(NULL);
		
	}
	
	return 0;
}
