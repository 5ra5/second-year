/*cylinder-area.c
author Petra Sartori*/

#include<stdio.h>
#include<stdlib.h>

#define PI 3.1415

/*Function: Main
  parameters: int argc
  char *argv[] an array of command-line arguments
  description: Takes two arugments and computes an area of a cylinder*/

int main(int argc, char *argv[])
{
    if (argc == 2) {
        printf("Two arguments needed!\n");
        return 1;
    } else if (argc == 1) {
        printf("No input given!\n");
        return 1;
    }

    float radius = atoi(argv[1]);
    float height = atoi(argv[2]);
    float area;


    if (radius < 0 || height < 0){
        printf("The radius or height cannot be negative!\n");
    } else{
    
        area = (2 * PI * radius * height) + (2 * PI * (radius * radius));
        printf("%.2f\n", area);
    }

    return 0;
}
