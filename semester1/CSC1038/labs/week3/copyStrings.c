#include<stdio.h>
#include<string.h>

int main(int argc, char *argv)
{
	char source[] = "the brown fox jumped over the lazy dog";
	char destination[50]; // Make sure this is big enough to store the string we are copying
	strcpy(destination, source);

	printf("The source string is %s\n", source);
	printf("The destination string is %s\n", destination);

	return 0;
}