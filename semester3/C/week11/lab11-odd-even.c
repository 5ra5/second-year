// lab11-odd-even.c
// Author: Petra Sartori
// 25/11/2025

// This program checks whether an input integer is off using stricly bitwise operations

#include <stdio.h>
#include<stdlib.h>

// function prototype
int odd(int n);

int main(int argc, char *argv[]){

    int num = atoi(argv[1]);

    // if the odd function returns 1, we print Odd
    // if it returns 0, we print even
    if (odd(num)){
        printf("Odd\n");
    }else{
        printf("Even\n");
    }

    return 0;
}

// odd function checks if the number is odd by getting it's least significant bit
// if the least significant bit is 1, the number is odd and function returns 1
// else the number is even so it returns 0
int odd(int n){
    return n & 1;
}