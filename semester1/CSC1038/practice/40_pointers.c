#include <stdio.h>

void birthday(int *age);

int main() {

    // pointer = A variable that stores the memory address of another variable.
    //           Benefit: They help avoid wasting memory by allowing you to pass
    //           the address of a large data structure instead of copying the entire data.


    int age = 25;

    birthday(&age);

    printf("You are %d years old\n", age);

    // output is the same
    //printf("%p\n", pAge);
    //printf("%p\n", &age);
    return 0;
}

void birthday(int *age){
    // pass by reference
    (*age)++;
}