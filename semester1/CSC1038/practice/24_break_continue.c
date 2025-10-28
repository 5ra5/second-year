#include <stdio.h>

int main() {

    // break = Break out of a loop (STOP)
    // continue = Skip current cycle of a loop (SKIP)

    for(int i = 1; i <= 10; i++){
        
        // if i is 4, we stop the loop
        if(i == 4){
            break;
        }
        printf("%d\n", i);

    }
        
    printf("\n");
    
     for(int i = 1; i <= 10; i++){
        
        // if i is 4, we skip 4
        if(i == 4){
            continue;
        }
        printf("%d\n", i);

    }

    return 0;
}