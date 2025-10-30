/*
Author: Petra Sartori
Date: 30/10/2025
The program is to calculate the standard deviation of grades of students.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* function prototypes */
/* We notice that to calculate standard deviation, we need average.
To calculate average, we need summary of grades
So we will need the three following functions: */
int sumCal(int grades[], int length);
double averageCal(int grades[], int length);
double sdCal(int grades[], int length);

/*main function */
int main(int argc, char*argv[])
{
	int length = argc - 1;
	int grades[length];
	int sum = 0;
	double average = 0.0;
	double sd = 0;

	/* Read the input and store into an array */
	for(int i = 0; i < length; ++i)
	{
		grades[i] = atoi(argv[i+1]);
	}

	sum = sumCal(grades, length);
	average = averageCal(grades, length);
	sd = sdCal(grades, length);

	printf("The sum of the grades of students is: %d\n", sum);
	printf("The average of the grades of students is: %lf\n", average);
	printf("The standard deviation of the grades of students is: %lf\n", sd);
	return 0;
}


int sumCal(int grades[], int length)
{
	int sum = 0;
	for(int i = 0; i < length; ++i)
	{
		sum += grades[i];
	}
	return sum;
}

double averageCal(int grades[], int length)
{
	int sum = sumCal(grades, length);
	return (double)sum/length; /* converts sum from an interger to double */
}

double sdCal(int grades[], int length)
{
	double sd = 0.0;
	double average = 0.0;

	average = averageCal(grades, length);
	for(int i = 0; i < length; ++i)
	{
		sd += pow(grades[i] - average, 2); /* The pow function is in the math library,
		the first number is the number we're trying to multiply, and the second to the power of n */
	}
	sd = sqrt(sd/length); /* The sqrt function is in the math library */

	return sd;
}
