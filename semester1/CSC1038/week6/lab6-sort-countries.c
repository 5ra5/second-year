/*lab6-sort-countries.c
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

int read_countries(int argc, char *argv[], Country *countires);
void sort_countries(Country *countries, int count);
void print_countries(Country *countries, int count);

// Section 3: Main() function
int main(int argc, char*argv[])
{
    Country countries[50];
    int total = read_countries(argc, argv, countries);
    sort_countries(countries, total);
    print_countries(countries, total);
    return 0;
}

// Section 4: Other functions

// Function read_countries() which reads info of countries from the command line
int read_countries(int argc, char *argv[], Country *countries)
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
        ++p; // move on to the next struct instance
    }

    return total;
}

// Function sort_countries which compares populations of countries and sorts them
void sort_countries(Country *countries, int count)
{
    for (Country *i = countries; i < countries + count - 1; ++i)
    {
        for (Country *j = i + 1; j < countries + count; ++j)
        {
            if (i->population < j->population)
            {
                Country temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

// Function that prints countries
void print_countries(Country *countries, int count)
{
    // Print this first
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    // Loop through instances of Countries
    for (Country *p = countries; p < countries + count; ++p)
    {
        printf("%s\t\t\t%s\t\t\t%.0f\t\t\t%.2f\n", p->name, p->capital, p->size, p->population);   
    }
}