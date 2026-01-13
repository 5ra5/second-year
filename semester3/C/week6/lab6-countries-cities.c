// Section 1: Necessary headers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Section 2: Struct and function declarations
typedef struct City
{
    char name[50];
    float size;
} City;

typedef struct Country
{
    char name[50];
    City cities[3]; // Including elements from City structure
} Country;

int read_countries(int argc, char *argv[], Country *countires);
City *find_city(Country *country);
void print_countries(Country *countries, int count);

// Section 3: Main() function
int main(int argc, char*argv[])
{
    Country countries[50];
    int total = read_countries(argc, argv, countries);
    print_countries(countries, total);
    return 0;
}

// Section 4: Other functions

// Function read_countries() which reads info of countries from the command line
int read_countries(int argc, char *argv[], Country *countries)
{
    // total of countries provided (7 arguments per country)
    int total = (argc - 1) /7;

    // the argument we start reading the first country from
    int index = 1;

    Country *p = countries;

    for (int i = 0; i < total; ++i, ++p)
    {
        // Reading country name
        strcpy(p->name, argv[index]);
        ++index;

        // Read 3 cities
        for (int j = 0; j < 3; ++j)
        {
            strcpy(p->cities[j].name, argv[index]);
            p->cities[j].size = atof(argv[index + 1]);
            index += 2;

        }
    }

  
    return total;
}

City *find_city(Country *country)
{
    City *largest = &country->cities[0];
    for (City *c = country->cities + 1; c < country->cities + 3; ++c)
    {
        if (c->size > largest->size)
        {
            largest = c;
        }
    }

    return largest;
}

// Function that prints each country and its largest city by size
void print_countries(Country *countries, int count)
{
    for (Country *p = countries; p < countries + count; ++p)
    {
        // Calling the find_city function before printing
        City *largest = find_city(p);
        printf("%s: %s\n", p->name, largest->name);
    }
}