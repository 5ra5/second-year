/*lab5-average-population.c
Author: Petra Sartori*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining Country as a type name
typedef struct Country Country;


struct Country
{
    char name[50];
    char capital[50];
    float population;
    float size;
};

// Function read_countries which reads countries from command line
int read_countries(int argc, char *argv[], Country countries[])
{
    // total of countries provided (4 arguments per country)
    int total = (argc - 1) / 4;

    // the point we start the loop from to read multiple countries from a single line
    int index = 1; 


    for (int i = 0; i < total; ++i)
    {
        // adding to the index to read all data
        strcpy(countries[i].name, argv[index]);
        strcpy(countries[i].capital, argv[index + 1]);
        countries[i].population = atof(argv[index + 2]);
        countries[i].size = atof(argv[index + 3]);

        // moving 4 positions forward to read the next countries data
        index += 4;
    }

    return total;
}

// Function print_countries which prints values of countries in a table
void print_countries(Country countries[], int count)
{
    // \t used for spaces inbetween each column
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    // Printing values
    for (int i = 0; i < count; ++i)
    {
        printf("%s\t\t\t%s\t\t\t%.0f\t\t\t%.2f\n", countries[i].name, countries[i].capital, countries[i].size, countries[i].population);
    }
}

// Function average which calculates and prints population average of all countries
void average(Country countries[], int count)
{
    float total = 0.0;

    // Getting the total populations of all countries
    for (int i = 0; i < count; ++i)
    {
        total += countries[i].population;
    }

    // Dividing the total with the number of countries
    float average = total / count;
    printf("Population average: %.2f\n", average);
}


int main(int argc, char*argv[])
{
    // Max 50 countries
    Country countries[50];
    int total = read_countries(argc, argv, countries);
    print_countries(countries, total);

    // Adding the population average at the end
    average(countries, total);

    return 0;
}