/*
circle-area-further.c
author Petra Sartori
*/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
/*When I changed PI to 3.14, the result was 28.26 instead of 28.27.
This is beacuse 9*3.1415 is 28.2735, and 9*3.14 is exactly 28.26*/

/*Function: Main
  parameters: int argc (argument count)
  char *argv[] an array of command-line arguments
  description: Takes a single argument and computes area of circle
*/

int main(int argc, char *argv[])
{
    unsigned int radius = 0;
    float area = 0.0;

    // radius = atoi(argv[1]);

    radius = radius*radius;

    area = radius*PI;

    if(radius > 0){
      printf("Please provide a positive input.");
    }

    else{
      printf("%.2f\n", area);
    }

    return(0);
}

/*If the input is negative, the program will return the same number as
it would if it is a positive because radius squared cancels the negative signs*/