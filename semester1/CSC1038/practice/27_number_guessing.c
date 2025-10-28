#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // NUMBER GUESSING GAME

    srand(time(NULL));

    int guess = 0;
    int tries = 0;
    int min = 1;
    int max = 100;
    int answer = (rand() % (max - min + 1)) + min;

    printf("****GUESSING GAME****\n");

    do{
    printf("Guess a number between 1-100: ");
    scanf("%d", &guess);
    if(guess > answer){
        printf("Too high!\n");
    }
    else if(guess < answer){
        printf("Too low!\n");
    }
    tries++;
    }while(guess != answer);

    printf("CORRECT!\n");
    printf("It took you %d tries\n", tries);
    printf("The answer is %d\n", answer);
    
    return 0;
}