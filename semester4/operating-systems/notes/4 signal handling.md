signals are used in UNIX systems to notify a process that a particular even has occurred

a signal handler is used to process signals

user-defined signal handler overwrite default handlers - we can use them when we are running a program and press CTRL+C to exit it so we can do something else, but we want it to finish up the process before actually exiting

when a signal is sent to a process, it interrupts its normal execution and it either
-  uses the default signal handler
-  uses a process defined signal handler

see a list of available signals
```shell
kill -l
```


```
SIGNIT = ctrl + c
SIGQUIT = ctrl + \
SIGTERM = tell the process to terminate (gracefully)
SIGFPE = illegal arithmetic error (divide by 0)
```

`SIGTERM` = pressing an X in an GUI app

we are able to catch a lot of these signal except for kill
kill is not only for killing processes, it is also to send a signal

```shell
kill 123456
kill -SIGTERM 123456 (DEFAULT IS SIGTERM)
```

in C
```c
kill(pid, SIGTTERM);
```

## setup

user defined signal to catch when we press CTRL+C while the infinite loop is running
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signhandler(int signum)
{
	printf("Received a signal %d\n", signum);
}

int main()
{
	signal(SIGINT, signhandler);
	while(1);
	return 0;
}
```

this program doesn't exit after CTRL+C is pressed, so we kill it like this
```bash
ps a
kill -SIGINT 28556
```

