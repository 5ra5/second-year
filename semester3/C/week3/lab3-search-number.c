/*lab3-search-number.c
Author: Petra Sartori*/

#include <stdio.h>
#include <stdlib.h>

/*Function search which takes a number we're searching for and an array from input
and returns the number with its index*/

int search(int n, int arr[], int size){
    
    for(int i = 0; i < size; i++) {
        if(arr[i] == n){
            return i; // returning the index of the number we were looking for
        }
    }
}

int main(int argc, char *argv[]){

    int n = atoi(argv[1]); // Number we're looking for
    int size = argc - 2; // Size of array (argc - 2 beacuse we're skipping argv[0] and argv[1])
    int arr[size];

    for(int i = 0; i < size; i++){
        arr[i] = atoi(argv[i + 2]); // search starts from argv[2]
    }

    int result = search(n, arr, size);

    printf("Found %d at %d\n", n, result);

    return 0;
}