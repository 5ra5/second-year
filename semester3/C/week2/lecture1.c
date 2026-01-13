#include <stdio.h>
#include <stdlib.h>

int main(){
    int i; //decalre i so you can use it outside of a loop
    for(i = 0; i < 10; i++) //you can decalre i within the function if you are not going to use it outside of the loop
    {
        printf("The value of i is: ");
        printf("%d\n", i);
    }
    printf("The value of i after the loop ends: %d\n", i); //10

    return 0;
}