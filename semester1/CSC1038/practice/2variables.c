#include <stdio.h>
#include <stdbool.h>

int main(){

    // variable = A reusable container for a value.
    //            Behaves as if it were the value it contains.

    // int = whole numbers (4 bytes in modern systems)
    int age = 25;
    int year = 2025;
    int quantity = 1;

    // float = single-precision decimal number (4 bytes)
    float gpa = 2.5;
    float price = 19.99;
    float temperature = -10.1;

    // double = double-precision decimal number (8 bytes)
    double pi = 3.14159265358979;
    double e = 2.7182818284590;

    // char = single character (1 byte)
    char grade = 'A';
    char symbol = '!';
    char currency = '$';

    // char[] = array of characters (size varies)
    char name[] = "Petra";
    char food[] = "pizza";
    char email[] = "fake123@gmail.com";

    // bool = true or false (1 byte, requires <stdbool.h>)
    bool isOnline = true;
    bool isStudent = false;
    bool forSale = 1;

    printf("You are %d years old\n", age);
    printf("The year is %d\n", year);
    printf("You have ordered %d x items\n\n", quantity);
    
    printf("Your gpa is %.1f\n", gpa);
    printf("The price is $%.2f\n", price);
    printf("The temperature is %.1f degrees\n\n", temperature);

    printf("The value of pi is %.15lf\n", pi);
    printf("The value of e is %.15lf\n\n", e);

    printf("Your grade is %c\n", grade);
    printf("Your favourite symbol is %c\n", symbol);
    printf("The currency is %c\n\n", currency);

    printf("Hello %s\n", name);
    printf("Your favourite food is %s\n", food);
    printf("Your email is %s\n\n", email);

    printf("%d\n", isOnline);

    if(isOnline){
        printf("You are ONLINE\n");
    }
    else{
        printf("You are OFFLINE\n");
    }

    if(isStudent){
        printf("You are a student.\n");
    }
    else{
        printf("You are not a student.\n");
    }

    if(forSale){
        printf("That item is for sale.\n");
    }
    else{
        printf("That item is not for sale.\n\n");
    }

    return 0;
}