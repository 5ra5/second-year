#include<stdio.h>
#include<stdlib.h>
// #define a constant here if you want


int main(int argc, char* argv[])
{
    int storage[100];
    int length = atoi(argv[1]); 
    for(int i = 0; i < length; i++){
        storage[i] = atoi(argv[i+2]);
    }

    for(int i = 0; i < length; i++){
        printf("Element storage [%d] is: %d\n", i, storage[i]);
    }

    return 0;
}