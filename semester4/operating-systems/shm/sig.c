#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sighandler(int signum)
{
	printf("Received a signal %d\n", signum);
}

int main()
{
	signal(SIGINT, sighandler);
	while(1);
	return 0;
}
