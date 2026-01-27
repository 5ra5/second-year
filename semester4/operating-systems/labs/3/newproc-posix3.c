/**
 * This program forks a separate process 
 * using the fork()/exec() system calls.
 *
 * Figure 3.08
 *
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    int status; // passed to the wait() system call
    pid_t cpid;

	/* fork a child process */
	/* fork splits the process into a parent and a child */
	/* we make the fork system call, one of the processes remains a parent
	(it's the one that got the value of pid being greater than 0) */
	pid = fork();

	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	/* if we are in the process, then pid == 0 */
	else if (pid == 0) { /* child process */
		/* the parent gets the child PID*/
		/* creates a child process that runs an ls command */
		printf("I am the child %d\n",pid);
		while(1);

		/* this line will not execute because after fork(), in the
		child process, the process image are replaced, meaning
		the code to print this line has been replaced*/
		printf("Do I execute?\n");
        return 0;

	}
	/* if we are in the parent process, then pid > 0 */
	else { /* parent process */
		/* parent will wait for the child to complete */
		printf("I am the parent %d\n",pid);
	}
    
    return 0;
}
