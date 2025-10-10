#include<stdio.h>

int main()
{
	char my_name[25];
	printf("Input your name from keyboard: ");
	fgets(my_name, sizeof(my_name), stdin); /* fgets helps to get a string from keyboad    */
	printf("Your name is: %s\n", my_name);

    return 0;
}