/*lab6-find-country.c
Author: Petra Sartori*/

// Section 1: Necessary headers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Section 2: Struct and function declarations
typedef struct Country
{
    char name[50];
    char capital[50];
    float population;
    float size;
} Country;

int read_countries(int argc, char *argv[], Country countires[]);
void print_countries(Country countries[], int count);

// Section 3: Main() function
int main(int argc, char*argv[])
{
    Country countries[50];
    int total = read_countries(argc, argv, countries);
    print_countries(countries, total);
    return 0;
}

// Section 4: Other functions
int read_countries(int argc, char *argv[], Country countries[])
{
    // total of countries provided (4 arguments per country)
    int total = (argc - 1) /4;

    // the argument we start reading the first country from
    int index = 1;

    Country *p = countries;

    for (int i = 0; i < total; ++i)
    {
        strcpy(p->name, argv[index]);
        strcpy(p->capital, argv[index + 1]);
        p->population = atof(argv[index + 2]);
        p->size = atof(argv[index + 3]);

        // moving 4 positions forward to read the next country
        index += 4;
        ++p;
    }

    return total;
}

/*Function print_countries which finds countries whose size is smaller
than 100 000 km^2 and prints them */
void print_countries(Country countries[], int count)
{
    // Print this first
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    // Loop through instances of Countries
    for (Country *p = countries; p < countries + count; ++p)
    {
        // If a size of the current country is smaller than 100 000, print the info
        if (p->size < 100000)
        {
            printf("%s\t\t\t%s\t\t\t%.0f\t\t\t%.2f\n", p->name, p->capital, p->size, p->population);
        }
        
    }
}