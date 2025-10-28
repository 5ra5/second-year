#include <stdio.h>

void checkBalance(float balance);
float deposit();
float withdraw(float balance);

int main(){

    // BANKING PROGRAM
    int choice = 0;
    float balance = 0.0f;
    printf("\n**WELCOME TO THE BANK**\n");

    do{
        printf("Select an option:\n");
        printf("Option 1: Check balance\n");
        printf("Option 2: Deposit money\n");
        printf("Option 3: Withdraw money\n");
        printf("Option 4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Thank you for using the bank!\n");
                break;
            default:
                printf("Invalid choice. Please select 1 - 4\n");
        }
    }while(choice != 4);

    return 0;
}

void checkBalance(float balance){
    printf("Your balance is $%.2f\n", balance);
}

float deposit(){
    float amount = 0.0f;
    printf("How much would you like to deposit?: ");
    scanf("%f", &amount);

    return amount;
}

float withdraw(float balance){
    
    float amount = 0.0f;
    printf("How much would you like to withdraw?: ");
    scanf("%f", &amount);

    if(amount > balance){
        printf("Insufficient balance.\n");
        return balance;
    }
    else{
        balance = balance - amount;
        return balance;
    }
}
