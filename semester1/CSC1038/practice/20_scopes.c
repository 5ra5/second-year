#include <stdio.h>

// int result = 0; // GLOBAL SCOPE (hard to debug - best to avoid)

int add(int x, int y){
    int result = x + y;
    return result;
}

int subtract(int x, int y){
    int result = x - y;
    return result;
}

int main(){

    int x = 5; // LOCAL
    int y = 6;

    // variable scope = Refers to where a variable is recognized and accessible.
    //                  Variables can share the name if
    //                  they're in different scopes {}


    int result = subtract(x, y);
    printf("%d\n", result);

    return 0;
}