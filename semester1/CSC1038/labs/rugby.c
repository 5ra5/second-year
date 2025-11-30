# include <stdio.h>
# include <stdlib.h>

int calculateTotal();

int main(int argc, char *argv[])
{
    int total = calculateTotal();
    printf("%d\n", total);
    return 0;
}

int calculateTotal()
{
    int try, conversion, penalty, dropGoal;
    
    printf("Type in number of tries: ");
    scanf("%d", &try);

    printf("Type in number of conversions: ");
    scanf("%d", &conversion);

    printf("Type in number of penalties: ");
    scanf("%d", &penalty);

    printf("Type in number of drop-goals: ");
    scanf("%d", &dropGoal);

    if(try < 0 || conversion < 0 || penalty < 0 || dropGoal < 0)
    {
        printf("Values must be greater than 0!\n");
        return 1;
    }
   
    int total = 5*try + 2*conversion + 3*penalty + 3*dropGoal;
    return total;
}