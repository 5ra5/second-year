// lab11-lis.c
// Author: Petra Sartori
// 25/11/2025

// This program takes a sequence of ints and outputs the length of the longest increasing subsequence.

// libraries needed for this task
#include <stdio.h>
#include <stdlib.h>

// function prototype
int max(int a, int b);

int main(int argc, char *argv[]){

    int n = argc - 1;
    int *arr = malloc(n *sizeof(int));
    if (!arr){
        printf("Memory allocation failed.\n");
        return 1;
    }

    // putting input into the arr
    for (int i = 0; i < n; i++){
        arr[i] = atoi(argv[i + 1]);
    }

    // dp helps us to compute the length of the longest increasing subsequence
    // we compute LIS up until dp[i]
    // first: allocate memory
    int *dp = malloc(n * sizeof(int));
    if (!dp) {
        printf("Memory allocation failed.\n");
        free(arr); // preventing a memory leak
        return 1;
    }

    // each element alone has LIS length 1
    for (int i = 0; i < n; i++){
        dp[i] = 1;
    }

    // first loop stores the len of the LIS for a current position
    // second loop goes through previous elements of current
    // we check if we can extend the point to where we stop counting the length
    // this can happen only if previous < current
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                // updating dp[i] - extending
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // maximum length in dp
    int lis = dp[0];
    for(int i = 1; i < n ; i++){
        lis = max(lis, dp[i]);
    }

    printf("%d\n", lis);

    free(arr);
    free(dp);
    return 0;


}

// max function finds a max of two integers a and b
// if a > b is true, it returns a
// otherwise it returns b
// ? is a short way to do an if-else statement
int max(int a, int b){
    return (a > b) ? a : b;
}