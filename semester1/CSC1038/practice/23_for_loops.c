#include <stdio.h>
#include <unistd.h> //Linux/Mac

int main() {

    // for loop = Repeat some code a limited # of times
    //            for(Initialization; Condition; Update)


    // increment i by 1: i++
    // increment i by 2: i += 2
    // same with decrement i-- OR i -= 2

    for(int i = 10; i >= 0; i--){
        sleep(1); // sleep function, pass the argument in seconds
        printf("%d\n", i);
    }

    printf("HAPPY NEW YEAR!\n");

    return 0;
}