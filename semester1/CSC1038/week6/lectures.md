# Struct and pointers


**Pointers to Structures**
-  accessing a member of a struct instance using a pointer
-  it is important to have () around the pointer for it to work
```
printf("Player name: %s", (*pPlayer1).name);
```

 -  cleaner way to do this
 - makes the code more readable and intuitive
 - () or * not needed
 ```
 printf("Player name: %s", pPlayer1->name);
 ```

example:
```
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
	Player player1 = {"Ronaldo", "ST", 500, 75.5}; //define a new instance of Player with initialised values
	Player *pPlayer1 = NULL;   //Declare the pointer
	pPlayer1 = &player1;  //Assign the pointer to the address of player1
	
	// All produce the same output
	printf("Player name: %s\n", player1.name)
	printf("Player name: %s\n", (*pPlayer1).name);
	printf("Player name: %s\n", pPlayer1->name);
}
```



**Structures As Members of a Structure**

- we can use struct in other structs
-  the structs that we're reusing have to be initialised before the struct we're using it in
- in this case DOB is referenced in Player, which means that three of its members are going to be used in Player
- Name holds two elements that are also used in Player
```
typedef struct Player Player;
typedef struct Date Date;
typedef struct Name Name;
typedef struct DOB DOB;

struct DOB
{
	int day;
	int month;
	int year;
};

struct Name
{
	char firstName[30];
	char lastName[30];
};


struct Player //Structure type definition
{
  Name name;   //the member name is an instance of the structure Name
  int goal_scored;
  char position[5];
  float price;
  DOB date_of_birth;  //the member date_of_birth is an instance of the structure DOB
};

int main(){
	Player player1;
	
	strcpy(player.name.firstName = "Ronaldo");
	player1.date_of_birth.day = 20;
	player.goal_scored = 1000;
	
	printf("Name: %s", player1.name.firstName);
	printf("Birth day: %d\n", player1.date_of_birth.day);
	printf("Goal scored: %d\n", player1.goal_scored)
	
	return 0;
}
```

- Accessing sub-values of structs
```
Player player1; //Declare a new instance of Player

strcpy(player1.name.firstName, "Cristiano");
strcpy(player1.name.lastName, "Ronaldo");
player1.goal_scored = 500;
player1.price = 100;
player1.date_of_birth.day = 5;
player1.date_of_birth.month = 2;
player1.date_of_birth.year = 1985;
```

**NOTE: impossible to assign a string to an array, you have to use strcpy() if you want to do that**


**Declaring a Structure Within a Structure**

```
struct Player //Structure type definition
{
  struct Name
  {
	char firstName[30];
	char lastName[30];
  } name;

  int goal_scored;
  char position[5];
  float price;

  struct DOB
  {
  	int day;
	int month;
	int year;
  } date_of_birth;
};
```

- Why do we need to use this method?
-  We need it if we want the structure Name and DOB only be accessible by the Player variables

**Struct and Function**

- A function to calculate the total goal scored by two players
```
typedef struct Player Player;
typedef struct Date Date;
typedef struct Name Name;
typedef struct DOB DOB;

struct DOB
{
	int day;
	int month;
	int year;
};

struct Name
{
	char firstName[30];
	char lastName[30];
};


struct Player //Structure type definition
{
  Name name;   //the member name is an instance of the structure Name
  int goal_scored;
  char position[5];
  float price;
  DOB date_of_birth;  //the member date_of_birth is an instance of the structure DOB
};

/*function prototype*/
int countGoal(Player p1, Player p2);

int main()
{
	Player p1, p2;
	int goals = 0;

	/* fill data for p1 */
	strcpy(p1.name.firstName, "Cristiano");
	strcpy(p1.name.lastName, "Ronaldo");
	p1.goal_scored = 500;

	/*fill data for p2 */
	strcpy(p2.name.firstName, "Lionel");
	strcpy(p2.name.lastName, "Messi");
	p2.goal_scored = 500;

	/* call the function to calculate the total of goals */
	goals = countGoal(p1, p2);

	return 0;
}

int countGoal(Player p1, Player p2)
{
	return p1.goal_scored + p2.goal_scored;
}
```