
# Dynamic Memory Allocation: Use Memory as you go

- Dynamic memory allocation usually goes along with pointers
- "Use memory as you go"  - whenever you need memory, you ask for it
- When you declare an array of integers with 1 million items, you need 4 million bytes for that array
- But what if we're not gonna use that many items?
- It is not good to reserve 4 million bytes beforehand, that's why we use dynamic memory allocation
- Sometimes we need more memory than we anticipated, so we can use dynamic memory allocation
- it is good to use it if our system doesn't have a lot of memory as well
- You are not supposed to declare an array at the start of the program, you create it while the program is running
- If you declare an array at the start, you reserve that memory for the variable and that memory can't be used by other variables


# The `malloc()` Function
- you have to include stdlib.h
-  a template to use malloc()
```c
<type> *<pointerName> = (<type>*)malloc(<number_of_bytes_allocated>);
```

- Declare a pointer and then allocate how many bytes we need
- We are pointing to the first byte of 200 bytes we're using
- (int*) is not necessary
- 200 bytes can hold up to 50 integers because each integer is 4 bytes and 25 doubles
- doubles need 8 bytes
```c
#include<stdio.h>
#include<stdlib.h>

int main():
{
	int *pNumbers = (int*)malloc(200);
	
	return 0;
}
```

- if you don't wanna do the maths to determine how many bytes you need
```c
#include<stdio.h>
#include<stdlib.h>

int main():
{
	int *pNumbers = malloc(50*sizeof(int));
	
	return 0;
}
```

- we can check if malloc() has enough memory to give us
```c
int *pNumber = (int*)malloc(50*sizeof(50*sizeof(int)));
if(!pNumber)
{
    //... Code to deal with memory allocation failure, for example:
    printf("Failed to allocate memory!");
}
```
# Releasing Dynamically Allocated Memory

- After we use the memory block and we don't need it anymore, we can release that memory block
```c
free(pNumber)
pNumber = NULL;
```
- Be careful not to free NULL pointers
# Example of using malloc and free

- Not declaring a fixed amount of memory we're using for the array
- The length of the array will simply be the number of arguments we get from the user
- array is allocated at run-time
- then we checked if malloc successfully allocated the memory
- `*(pNumbers + i)` a more natural way of writing arrays when dealing with dynamic allocation - slight over-complication
- after we get the input, we calculate the sum
- pResult holds only 4 bytes for the result
- after we print the result, we release the memory for other things to use
- when the program terminates, you release all memory
```c
#include<stdio.h>
#include<stdlib.h>

int sumOfArray(int* pNumbers, int length);
int productOfArray(int *pNumbers, int length);

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int *pNumbers = NULL;
    int *pResult = NULL;

    pNumbers = (int*)malloc(length*(sizeof(int)));
    if(!pNumbers)
    {
        //... Code to deal with memory allocation failure, for example:
        printf("Failed to allocate memory!");
        return 0;
    }

    for(int i = 0; i < length; ++i)
    {
        *(pNumbers+i) = atoi(argv[i+1]);
    }

    /*Calculate sum */
    pResult = (int*)malloc(1*(sizeof(int)));
    *pResult = sumOfArray(pNumbers, length);
    printf("Sum of the array is: %d\n", *pResult);
    free(pResult); //Free the memory
    pResult = NULL;

    printf("Now the programing is calculating the product of the array...\n");

    /* Calculate the product */
    pResult = (int*)malloc(1*(sizeof(int)));
    *pResult = productOfArray(pNumbers, length);
    printf("Product of the array is: %d\n", *pResult);
    free(pResult); //Free the memory
    free(pNumbers);
    pResult = NULL;
    pNumbers = NULL;

    return 0;
}

int sumOfArray(int* pNumbers, int length)
{
    *pResult = 0;
    for(int i = 0; i < length; ++i)
    {
        *pResult += *(pNumbers + i);
    }
    return *pResult;
}

int productOfArray(int *pNumbers, int length)
{
    int *pResult = 1;
    for(int i = 0; i < length; ++i)
    {
        *pResult *= *(pNumbers + i);
    }
    return *pResult;
}
```

