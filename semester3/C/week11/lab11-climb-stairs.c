// lab11-climb-stairs.c
// Petra Sartori
// 25/11/2025

// This program calculates how many distinct ways you can climb to the top of the stairs
// given that it takes n steps to reach the top - Fibonacci sequence

// libraries needed for this task
#include <stdio.h>
#include <stdlib.h>

// function prototype
int stairs(int n);

int main(int argc, char *argv[]){

    int n = atoi(argv[1]);

    printf("%d\n", stairs(n));

    return 0;
}

// stairs function takes integer n and returns a number of ways we can climb the n steps
int stairs(int n){
    
    // base cases
    // if n is 0 or 1, there will be only one way to climb (with 0 we can't do anything)
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2; // 1 + 1 steps or 2 at once

    // initialising previous values
    int prev2 = 1; // number of ways to climb (n - 2) steps
    int prev1 = 2; // number of ways to climb (n - 1) steps
    int current; // number of ways to climb current step i

    for (int i = 3; i <= n; i++){
        current = prev1 + prev2;

        // now the old (n - 1) becomes (n - 2) for next iteration
        // and current becomes prev1
        prev2 = prev1;
        prev1 = current;
    }

    // returning prev1 because it contains the number of ways to climb n steps
    return prev1;
}



