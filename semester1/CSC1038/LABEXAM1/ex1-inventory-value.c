/*
ex1-inventory-value.c
Author: Petra Sartori
Date: 30/10/2025
This program is to calculate the total value of each product
in stock accounting for discounts
*/

/*required libraries for this task*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Product struct I defined in the last task: contains name, stock, price
if discount is applied or not*/
typedef struct Product
{
    char name[20];
    unsigned int stock;
    float price;
    bool discount;
} Product;

/* To get the total value of all stock first */
void addProducts(Product product[], int argc, char*argv[], int n);
float totalValue(Product product[], int n);

int main(int argc, char*argv[])
{
    Product product[100];
    
    // Total of products provided (4 arguments per product).
    int n = (argc - 1) / 4;

    addProducts(product, argc, argv, n);
    float total = totalValue(product, n);
    printf("%.2f", total);
    return 0;
}

/*addProducts reads each product from stdin and places them in the array, but returns nothing*/
void addProducts(Product product[], int argc, char*argv[], int n){

    // The argument we start reading the first product from.
    int index = 1;

    // Looping for each product
    for(int i = 0; i < n; ++i)
    {
        strcpy(product[i].name, argv[index]);
        product[i].stock = atoi(argv[index + 1]);
        product[i].price = atof(argv[index + 2]);
        product[i].discount = atoi(argv[index + 3]);

        index += 4; // Moving 4 positions forward
        
    }
    
}

/* Running out of time: totalValue function is supposed to take
values from each product[i].price and add them together.
There would also be an if statement before that action: if the
product[i].discount == 1, i would apply discount before adding it
to the total, otherwise add the number as it is */
float totalValue(Product product[], int n){

    float sum = 0.0f;

    for(int i = 0; i < n; ++i)
    {
        if (product[i].discount == 1)
        {
            sum = product[i].price * product[i].stock * 0.9;
        } else
        {
            sum = product[i].price * product[i].stock;
        }
    }
    return sum;

}
