# include <stdio.h>

int main(){

    int option = 0;
    float kg = 0.0f;
    float pounds = 0.0f;

    printf("Weight Conversion Calculator\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &option);

    if(option == 1){
        // Kilograms to pounds
        printf("Enter the weight in kilograms: ");
        scanf("%f", &kg);
        pounds = kg * 2.20462;
        printf("%.2f kilograms is equal to %.2f pounds\n", kg, pounds);
    }
    else if(option == 2){
        // Pounds to kilograms
        printf("Enter the weight in pounds: ");
        scanf("%f", &pounds);
        kg = pounds / 2.20462;
        printf("%.2f pounds is equal to %.2f kilograms\n", pounds, kg);
    }
    else{
        printf("Invalid choice! Please enter 1 or 2\n");
    }

    return 0;
}