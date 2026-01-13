/*
The program take two string arguments as First Name and College
*/
#include<stdio.h>

int main(int argc, char* argv[])
{
	printf("Your first name is: %s and your college is %s\n", argv[1], argv[2]);
}

// atoi is necessary only if arguments are numbers
// atoi(argv[1], argv[2])
