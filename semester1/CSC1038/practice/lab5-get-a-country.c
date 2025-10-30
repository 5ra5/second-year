#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    char capital[50];
    float population;
    float size;
}Country;

void printCountry(Country country);

int main(int argc, char*argv[]){

    Country country;
    strcpy(country.name, argv[1]);
    strcpy(country.capital, argv[2]);
    country.population = atof(argv[3]);
    country.size = atof(argv[4]);
    printCountry(country);

}

void printCountry(Country country){

    printf("%s\n", country.name);
    printf("%s\n", country.capital);
    printf("%.2f million people\n", country.population);
    printf("%.0f km2\n", country.size);
}

