#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])

{
    int lower_bound = 30;
    int upper_bound = 50;
    int count = 0;

    for (int centimeters = lower_bound; centimeters < upper_bound; centimeters++) {
        float inches = centimeters/2.54;
        printf("%6.2f", inches);
        count++;

        if (count % 5 == 0) {
            printf("\n");
        }
    }

    return(0);
}

/*If we declare both inches and centimeters as int, we will get a rounded answer,
for example, if centimeters is 3, we will get a result of 1, instead of 1.18*/
/*If inches are int and centimeters are float, we'll get the same result*/
/*If inches are float and centimeters are int, we will get the non-rounded result
of 1.18*/
