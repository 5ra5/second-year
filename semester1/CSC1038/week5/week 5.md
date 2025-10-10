# EDITING
# Pointers in use - Function
**PASS BY REFERENCE**
Swapping two elements in an array (important because it's used in many sorting algorithms)
```
// Passing by value doesn't work in this case, we need to use pointers to pass by the reference
// If we pass by value, the function wont change anything since two new temporary variables are made for the function
// int* is an address of a
void swap(int* a, int* b){
	int temp;
	temp = *a; // *a is a value of a
	*a = *b; // put address of b to address of a
	*b = temp; // put address of temp to address of b
}

int main(int argc, char *argv[])
{
	int a = 5;
	int b = 6;
	
	swap(&a, &b) // assesing the address
	
	print("Value of a = %d\n", a);
	print("Value of b = %d\n", b);
	return 0;
}

-> value of a = 6
   value of b = 5	
```

the same example with arrays (swap 2 elements of an array)
```
int main(int argc, char *argv[])
{
	int a[3] = {10, 30, 20}
	
	swap(&a[1], &a[2]; OR swap(a + 1, a + 2); // these are the same thing
	
	print("Value of a = %d\n", a[1]);
	print("Value of a[2] = %d\n", a[2]);
	return 0;
}

-> Value of a[1] = 20
-> Value of a[2] = 30
```

**Return more than one value with different types**
Find the maximum value in an floating array. Return the max value and its position in the array and print them. 
```
float findMax(float a[], int length, int* pos){
	float max = a[0];
	int i;
	for(int i = 1; i < length, i++){
	if(a[i] > *value)
	{
	*value = a[i];
	*position = i;
	}
	
	*pos = i - 1;
	return max;
}

int main(// add the regular expression we use)
{
	float a[4] = {10, 30, 20, 99};
	float max = -999;
	int pos = -999;
	
	max = findMax(a, 4, &pos);
	printf("Value of max = %.2f at the position of %d\n", max, pos);
}
```

# Struct

-  Struct enables us to define a collection of variables of various data types called a structure that you can treat as a single unit.

- Declaring a struct
-  Note: You have to include a semi-colon at the end of every structure or the program will not compile
-  You are not initialising a new variable, you are defining a new **data type**
-  A variable holds a specific dynamic value/instance that can be modified
```
struct <struct_name>
{
	<type> <field_name>;
	<type> <field_name>;
	...
};
```

- Example
```
struct Player
{
  char name[30];
  int goal_scored;
};
```

 -  Initialising a variable with the type we made
 ```
 struct Player player1;
 ```

-  Think of object-oriented programming in python - Player would be class, and player1 would be an instance of that class.


-  If you don't want to use "struct Player" every time you are referencing it, you can  use typedef
```
typedef struct Player Player;
```

-  So when you use Player again while initialising a variable, you can do it like this:
```
Player player1;
```


**Accessing Structure Members**

- You can initialise values in this way as well
```
Player player3 = {
	.name = "Kante", .position = "CM", .goal_scored = 10, .price = "60"
};
```

**Example:** Write a program to manage a list of football players. The program accepts a player detail input from keyboard, and print it out.
```
#include<stdio.h>
#include<stdlib.h>

typedef struct Player Player;

struct Player {
	char name[30];
	char position[2];
	char goal_scored;
	float price;
};

int main(){
	Player player1;
	
	printf("Enter name:\n")
	scanf("%s", player1.name);
	
	printf("Enter position:\n");
	scanf("%s", player1.position);
	
	printf("Goal scored:\n");
	scanf("%d", &player1.goal_scored);
	
	printf("Market price:\n");
	scanf("%f", &player1.price);
	
	printf("Player information as follows:\n")
	printf("Name: %s\n", player1.name);
	printf("Position: %s\n", player1.position);
	printf("Goal scored: %d\n", player1.goal_scored);
	printf("Market price: %.2f\n", player1.price);
	
	return 0;
}
```

-  Struct helps us to write our code in a more organised way
-  It is actually older than OOP, OOP just evolved from struct

**Arrays of structures**

```
Player player[50]; //Let's assume that the programm can manage a squad up to 50 players
```

- Improving the previous code to take as many players as the user wants to, we can use for loop, while loop, or do-while
```
#include<stdio.h>
#include<stdlib.h>

typedef struct Player Player; //Define Player as a type name

struct Player //Structure type definition
{
  char name[30];
  int goal_scored;
  char position[5];
  float price;
};

int main(int argc, char*argv[])
{

	Player player[50];

	//Input a player
	int pcount = 0; //to count the player
	int selection;
	do
	{
		printf("Player name:\n");
		scanf("%s", player[pcount].name);

		printf("Preferred position:\n");
		scanf("%s", player[pcount].position);

		printf("Market price:\n");
		scanf("%f", &player[pcount].price);

		printf("Goal scored:\n");
		scanf("%d", &player[pcount].goal_scored);

		++pcount; //Increase the player count variable by 1;

		printf("Do you want to add more player (1 = Y, 0 = N)?\n");
		scanf("%d", &selection);

		if(selection == 0)
			break;

	} while (pcount < 50);

	//Print all players:
	printf("Players information as follows:\n");

	for(int i = 0; i < pcount; ++i)
	{
		printf("Player %d:\n", i+1); //Just a signal
		printf("Name: %s\n", player[i].name);
		printf("Position: %s\n", player[i].position);
		printf("Goal scored: %d\n", player[i].goal_scored);
		printf("Market price: %.2f\n", player[i].price);
		printf("\n");
	}

	return 0;
}
```
