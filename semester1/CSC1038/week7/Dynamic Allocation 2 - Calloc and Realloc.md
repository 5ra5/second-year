# `calloc()`

- stdlib.h
- improved version of malloc()
- it allocates memory as a number of elements of a given size
- it initialises the memory that is allocated so that all bytes are zero
- requires 2 argument values: number of data items for which space is required and the size of each data item
- if you want everything to be clear use this:
```c
int *pNumber = (int*)calloc(50, sizeof(int)); /*here we typecast the returned value of calloc to int* */
```

- simplified version
```c
int *pNumber = calloc(50, sizeof(int));
```

# `realloc()` - extending dynamically allocated memory

- enables you to reuse or extend memory that you previously allocated using `malloc()`, `calloc()` or `realoc()`
- you need to include 2 argument values
1. A pointer containing an address that was previously returned
2. The size in bytes of the new memory that you want allocated
- avoid reallocating many times - don't increase capacity one by one

example:
```c
int main(int argc, char *argv[])
{
	int capacity = 10;
	int oldCapacity
	int* pNumber = calloc(capacity, sizeof(int));
	if (!pNumber){
		printf("Failed to allocate memory\n");
	}
	
	printf("Original data:");
	for(int i = 0; i < capacity; ++i){
		printf("%d", *(pNumber + i));
	}
	print("\n");
	
	capacity += 5;
	int *pTemp = NULL;
	pTemp = realloc(pNumber, sizeof(int));
	if (!pTemp){
		printf("Failed to reallocate memory");
		free(pNumber);
	}
	
	return 0;
}

printf("New data after reallocation:")
pNumber = pTemp;
for (int i = oldCapacity); i < capacity; i++){
	pNumber
}
```

