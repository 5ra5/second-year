# AND operator &
- the result of this code will be 4 because and operator performs the AND operation on the binary values of x and y
- 1 AND 1 is 1
- 1 AND 0 is 0
- 0 AND 1 is 0
- 0 AND 0 is 0
```c
#include<stdio.h>
int main(){
	int x = 13;
	int y = 6;
	int z = x & y;
	
	printf("%d & %d = %d\n", x, y, z);
}
-> 13 & 6 = 4
```

# OR operator
- the result of same values of x and y will be 15 because
- 1 OR 1 is 1
- 0 OR 1 is 1
- 1 OR 0 is 1
- 0 OR 0 is 0

```c
#include<stdio.h>
int main(){
	int x = 13;
	int y = 6;
	int z = x | y;
	
	printf("%d & %d = %d\n", x, y, z);
}
-> 13 | 6 = 15
```

# XOR operator
- XOR = exclusive OR
- XOR produces a 1 if both bits are different
- XOR produces a 0 is bits are the same
the result of this will be 11

```c
#include<stdio.h>
int main(){
	int x = 13;
	int y = 6;
	int z = x ^ y;
	
	printf("%d & %d = %d\n", x, y, z);
}
-> 13 ^ 6 = 11
```

# NOT operator
- All bits are flipped
- If a bit is 1 it becomes 0
- If a bit is 0 it becomes 1
- It uses ~ as an operator and deals with only one variable x
```c
int x = 13;
int z = ~x;
```

# Shift operator

- Shift takes the bits of the number and moves them by N positions
- In this case it moves them by 3 positions
```c
#include<stdio.h>
int main(){
	int x = 12;
	int shiftcount = 3;
	int z = x << shiftcount;
	
	printf("%d << %d = %d\n", x, shiftcount);
}
-> 12 << 3 = 96
```


- you can left shift `<<<` or right shift `>>>`

# Adding two numbers using bitwise operators
- use OR if the sum is smaller than 10
- when the sum is greater than 10 - if we have carrying involved, then we have to include AND (a&b)
```c
int a = 5; //101
int b = 2; //010

printf("a + b = %d\n", a + b); //There is NO carry involved here
printf("a|b = %d\n", a|b);


a = 5;
b = 7;

printf("a + b = %d\n", a + b);
printf("a|b + a&b = %d\n", (a|b) + (a&b)); //There is carry involved here

-> 
```

# Swapping integers
- When we use bitwise operators, we don't need a temporary value to hold a value that is going to be exchanged
- Use XOR for this solution
```c
#include<stdio.h>
int main(){
	int x = 5;
	int y = 7;
	
	printf("Before x = %d, y = %d\n", x, y)
	
	x ^= y;
	y = x ^ y;
	x ^= y;
	
	printf("After x = %d, y = %d\n", x, y)
}
-> Before x = 5, y = 7
   After x = 7, y = 5
```