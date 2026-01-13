/*lab3-is-sorted.c
Author: Petra Sartori*/

#include <stdio.h>
#include <stdlib.h>

/*Function sorting which uses a bubble sort algorithm to sort
an array in an ascending order*/

void sorting(int arr[], int size){
    // looping twice to compare numbers
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            // If the current element is larger than the next one, swap them
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }
}

int main(int argc, char *argv[]){
    
    int size = argc - 1;
    int arr[size];
    int i;

    // Reading input
    for (i = 0; i < size; i++){
        arr[i] = atoi(argv[i + 1]);
    }

    //Calling the sorting function
    sorting(arr, size);

    // Printing the sorted array line by line using another for loop
    for (i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}