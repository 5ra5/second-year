#include <stdio.h>

typedef struct {
    char model[25];
    int year;
    int price;
}Car;

int main(){

    Car cars[] = {{"Toyota", 2006, 5000}, {"Mustang", 2025, 32000}, {"Nissan", 2019, 25000}};

    // array of structs = Array where each element contains a struct {}
    //                    Helps organize and groups together related data


    int number = sizeof(cars) / sizeof(cars[0]);

    for(int i = 0; i < number; i++){
        printf("%s %d $%d\n", cars[i].model, cars[i].year, cars[i].price);
    }

    return 0;
}