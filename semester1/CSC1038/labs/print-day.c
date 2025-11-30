#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int number = atoi(argv[1]);
    char days[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for(int i = 1; i <= 7; i++)
    {
        if(i == number)
        {
            printf("%s\n", days[i - 1]);
        }
        
    }
}