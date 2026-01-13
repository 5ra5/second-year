#include <stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    int my_height, your_height;

    printf("My height: ", my_height);
    scanf("%d", &my_height);

    printf("Your height: ", your_height);
    scanf("%d", &your_height);

    if(your_height > my_height){
        printf("You are taller than me.\n");
    }

    else if(your_height < my_height){
        printf("I am taller than you.\n");
    }

    else{
        printf("We are exactly the same height. \n");
    }

    return(0);
}