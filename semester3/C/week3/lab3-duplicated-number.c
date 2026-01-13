/*lab3-duplicated-number.c
Author: Petra Sartori*/

#include <stdio.h>
#include <stdlib.h>

/*Function duplicate which takes an array and iterates through it to find a duplicate
and returns it*/

int duplicate(int arr[], int size){
    // we have to loop twice to compare numbers
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (arr[i] == arr[j]){
                return arr[i]; // Returning the duplicate number
            }
        }
    }
    return -1; // if no duplicates are found
}

int main(int argc, char *argv[]){

    int size = argc - 1;
    int arr[size];

    // Reading input
    for (int i = 0; i < size; i++){
        arr[i] = atoi(argv[i]);
    }

    // Calling the duplicate function
    int result = duplicate(arr, size);

    if (result != -1){ // If we have a duplicate (the result is not -1)
        printf("%d\n", result);
    } else {
        printf("no duplicated number\n");
    }

    return 0;
}