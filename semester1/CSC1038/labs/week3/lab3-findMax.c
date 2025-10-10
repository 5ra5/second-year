/*lab3-findMax.c
Author: Petra Sartori*/

#include <stdio.h>
#include <stdlib.h>

//Function maximum which takes an array from input and returns a maximum value
int maximum(int arr[], int n){
    // A variable that's going to keep the biggest number initialised to 0
    int max = arr[0];

    // Iterating through the array and storing the biggest number in max
    for (int i = 0; i < n; i++) {
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

// Getting the input from the command line and calling the maximum in Main() function
int main(int argc, char *argv[]) {
    
    int n = argc - 1;
    int arr[n];

    // Reading input from command line
    for(int i = 0; i < n; i++){
        arr[i] = atoi(argv[i + 1]);
    }

    // Calling the function
    int max = maximum(arr, n);

    // Printing the biggest number
    printf("%d\n", max);

    return 0;
}