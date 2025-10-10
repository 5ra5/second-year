#include <stdio.h>
#include <stdlib.h>

int points() {
    int tryy, conversion, penalty, drop, total;
    printf("Input number of tries: ");
    scanf("%d", &tryy);
    printf("Input number of conversions: ");
    scanf("%d", &conversion);
    printf("Input number of penalties: ");
    scanf("%d", &penalty);
    printf("Input number of drop-goals: ");
    scanf("%d", &drop);

    if(tryy < 0 || conversion < 0 || penalty < 0 || drop < 0) {
        printf("Please input a positive value!\n");
            return -1;
    
    }

    total = tryy*5 + conversion*2 + penalty*3 + drop*3;
}

int main(){
    int total = points();
    if (total == -1){
        return 1;
    }

    printf("%d\n", total);

    return(0);
}