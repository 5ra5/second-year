#include <stdio.h>
#include <stdbool.h>

/*int main() {

    // logical operators = Used to combine or modify boolean expressions.

    // && = AND
    // || OR
    // ! = NOT

    int temp = -5;

    if(temp <=0 || temp >= 30){
        printf("The temperature is BAD\n");
    }
    else{
        printf("Temperature is GOOD\n");
    }

    return 0;
}*/

int main(){

    bool isSunny = true;

    // if it's not isSunny
    if(!isSunny){
        printf("It is SUNNY outside.\n");
    }
    else{
        printf("It is CLOUDY outside.\n");
    }

    return 0;
}