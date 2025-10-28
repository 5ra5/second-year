#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
int main() {

    // while loop = Continue some code WHILE the condition remains true
    //              Condition must be true for us to enter while loop

    int number = 0;
    
    // escaping the while loop when the user provides a number greater than 0
    while(number <= 0){
        printf("Enter a number greater than 0: ");
        scanf("%d", &number);
    }

    return 0;
}
*/

/*
// do while loop - checking a condition at the end rather than at the start
int main() {

    int number = 0;

    // do something once, and then check the condition
    do{
        printf("Enter a number greater than 0: ");
        scanf("%d", &number);
    }while(number <= 0);

    return 0;
}
*/

/*
int main() {

    char name[50] = "";
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    while(strlen(name) == 0){
        printf("Name cannot be empty! Please enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';
    }

    printf("Hello %s\n", name);

    return 0;
}
*/

int main() {

    bool isRunning = true;
    char response = '\0';

    while(isRunning){
        printf("You are playing a game\n");
        printf("Would you like to continue? (Y = yes, N = no): ");
        scanf(" %c", &response);

        if(response != 'Y' && response != 'y'){
            isRunning = false;
        }
    }

    printf("You exit the game\n");

    return 0;
}