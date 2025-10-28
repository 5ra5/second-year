#include <stdio.h>
#include <stdbool.h>

int main(){

    int age = 21;
    float balance = 9.99;
    double e = 2.7182818284590;
    char grade = 'A';
    char name[] = "Petra";
    bool pass = true;

    printf("My age is %d\n", age);
    printf("My bank account balance is %.2f\n", balance);
    printf("The value of e is %.10lf\n", e);
    printf("My grade on the exam is %c\n", grade);
    printf("My name is %s\n", name);
    if(pass){
        printf("I passed!\n");
    }
    else{
        printf("I failed!\n");
    }

    return 0;
}