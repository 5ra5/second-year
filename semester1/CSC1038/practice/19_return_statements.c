#include <stdio.h>
#include <stdbool.h>

double square(double num){

    return num * num;
}

double cube(double num){

    return num * num * num;
}

bool ageCheck(int age){
    if(age >= 18){
        return true;
    }
    else{
        return false;
    }
}

int getMax(int a, int b){
    
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

int main() {

    // return = returns a value back to where you call a function

    double x = square(2.1);
    double y = square(3.2);
    double z = square(4.3);

    double xx = cube(2);
    double yy = cube(3);
    double zz = cube(4);

    int age = 21;

    int max = getMax(4, 3);

    printf("%lf\n", x);
    printf("%lf\n", y);
    printf("%lf\n", z);

    printf("\n%lf\n", xx);
    printf("%lf\n", yy);
    printf("%lf\n", zz);

    if(ageCheck(age)){
        printf("\nYou may sign up\n");
    }
    else{
        printf("\nYou must be 18+ to sign up\n");
    }
    
    printf("\n%d\n", max);
    
    return 0;
}