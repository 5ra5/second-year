/*
ex1-show-inventory.c
Author: Petra Sartori
Date: 30/10/2025
This program is to read information about available products and print them out in one line.
*/

/* Required libraries for this task */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Product structure which has 4 elements: name, stock, price, and discount */
typedef struct Product
{
    char name[20];
    unsigned int stock;
    float price;
    bool discount;
} Product;

/* Function prototypes */
/* addProducts function reads information about every product and stores them in an array
printProducts prints the information about every product in their respective lines*/
void addProducts(Product product[], int argc, char*argv[], int n);
void printProducts(Product product[], int n);

/* Main function calls the other two functions*/
int main(int argc, char*argv[])
{
    Product product[100];
    
    // Total of products provided (4 arguments per product).
    int n = (argc - 1) / 4;

    addProducts(product, argc, argv, n);
    printProducts(product, n);

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

/*printProducts displays product information
if the input shows 1 for the discount, it prints "Discounted"
if it shows 0, it prints "No Discount"*/
void printProducts(Product product[], int n){

    for (int i = 0; i < n; i++)
    {
        printf("%s,%d,%.2f,", product[i].name, product[i].stock, product[i].price);
        if(product[i].discount == 1)
        {
            printf("Discounted\n");
        }else
        {
            printf("No Discount\n");
        }
    }
    
}