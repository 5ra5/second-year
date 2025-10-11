/*lab5-get-a-country.c
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

// Reading and printing details of country by assigning it to the Country variable
int main(int argc, char*argv[])
{
    // Deaclaring a variable type Country
    Country country;

    // Reading input from command line and assigning values to country members
    strcpy(country.name, argv[1]);
    strcpy(country.capital, argv[2]);
    country.population = atof(argv[3]);
    country.size = atof(argv[4]);

    // Print details of country
    printf("%s\n", country.name);
    printf("%s\n", country.capital);
    printf("%.2f million people\n", country.population);
    printf("%.0f km2\n", country.size); //.0f used to print with no decimals

    return 0;
}