#include <stdio.h>
#include <stdbool.h>

void hello(char name[], int age); // function prototype
bool ageCheck(int age);

int main() {

    // function prototype = Provide the compiler w/ information about a function's:
    //                      name, return type, and parameters before its acutal definition.
    //                      Enables type checking and allows functions to be used before
    //                      they're defined.
    //                      Improves readability, organization, and helps prevent errors.

    hello("Spongebob", 30);

    if(ageCheck(2)){
        printf("You are old enough to work in Krusty Krab\n");
    }
    else{
        printf("You are too young to work in Krusty Krab!\n");
    }

    return 0;
}

void hello(char name[], int age){
    printf("Hello %s\n", name);
    printf("You are %d years old\n", age);
}

bool ageCheck(int age){
   return age >= 16;
}