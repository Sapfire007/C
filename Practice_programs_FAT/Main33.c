/*
Develop a program to simulate a simple bank system where a user can perform multiple
transactions such as deposit, withdrawal, and balance inquiry. Use a looping statement to
repeatedly show a menu until the user chooses to exit. Use compound statements to ensure that
withdrawal operations do not exceed the available balance and display an "Insufficient Balance"
message when necessary.
*/

#include <stdio.h>

int main(){
    int inp;
    int bal = 0;
    int amt = 0;
    while(1){
        printf("=== BANK APP ===\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &inp);

        switch(inp){
            case 1:
                printf("Deposit amount: ");
                scanf("%d", &amt);
                bal += amt;
                break;
            case 2:
                printf("Withdrawal amount: ");
                scanf("%d", &amt);
                if(amt > bal){
                    printf("Insufficient credits!\n");
                } else {
                    bal -= amt;
                }
                break;
            case 3:
                printf("Current balance: %d\n", bal);
                break;
            case 4:
                printf("Exiting app!");
                return 0;
            default:
                printf("Invalid input!");

        }
    }

    return 0;
}