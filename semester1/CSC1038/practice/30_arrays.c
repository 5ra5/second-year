#include <stdio.h>

int main() {

    // array = A fixed-size collection of elements of the same data type
    //         (Similar to a variable, but it holds more than 1 value)


    int numbers[] = {10, 20, 30, 40, 50, 5, 10};

    // to get the length of the array divide sizeof(array) with sizeof(first element)
    int length = sizeof(numbers) / sizeof(numbers[0]);
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    char name[] = "Petra Sartori";

    numbers[0] = 100;
    numbers[1] = 90;
    numbers[2] = 80;
    numbers[3] = 70;
    numbers[4] = 60;

    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);
    printf("%d\n", numbers[3]);
    printf("%d\n", numbers[4]);

    for(int i = 0; i < length; i++){
        printf("%d\n", numbers[i]);
    }

    for(int i = 0; i < sizeof(name); i++){
        printf("%c ", name[i]);
    }

    printf("%c\n", name[0]);
    return 0;
}