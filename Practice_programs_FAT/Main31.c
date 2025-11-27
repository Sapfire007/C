/*
Write a C program that defines a structure to store bank account details, including an integer
for account number, a float for account balance, a character array for account holder's name,
and account type (e.g., "Savings" or "Current"). Inside the structure, use a union to store type-
specific details: an interest rate for "Savings" accounts or an overdraft limit for "Current"
accounts. Assign values to all fields and display the general and type-specific account
information based on the account type.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int accNo;
    float balance;
    char name[50];
    char type[10];
    
    union {
        float interestRate;
        float overdraftLimit;
    } info;
} Bank;

int main() {
    Bank b;

    printf("Enter Account Number: ");
    scanf("%d", &b.accNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", b.name);

    printf("Enter Balance: ");
    scanf("%f", &b.balance);

    printf("Enter Account Type (Savings/Current): ");
    scanf("%s", b.type);

    if(strcmp(b.type, "Savings") == 0) {
        printf("Enter Interest Rate: ");
        scanf("%f", &b.info.interestRate);
    } else {
        printf("Enter Overdraft Limit: ");
        scanf("%f", &b.info.overdraftLimit);
    }

    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", b.accNo);
    printf("Name: %s\n", b.name);
    printf("Balance: %.2f\n", b.balance);
    printf("Type: %s\n", b.type);

    if(strcmp(b.type, "Savings") == 0)
        printf("Interest Rate: %.2f\n", b.info.interestRate);
    else
        printf("Overdraft Limit: %.2f\n", b.info.overdraftLimit);

    return 0;
}