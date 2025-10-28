/*
Create a class BankAccount with:
accountNumber, holderName, balance
You need to:
Prevent withdrawal beyond balance.
Use static variable to track total accounts created.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a Bank Account
struct BankAccount {
    int accountNumber;
    char holderName[50];
    float balance;
    struct BankAccount *next; // pointer for linked list connection
};

// Global pointer to head of list
struct BankAccount *head = NULL;

// Static variable to count total accounts
static int totalAccounts = 0;

// Function to create a new account
void createAccount() {
    struct BankAccount *newAcc = (struct BankAccount *)malloc(sizeof(struct BankAccount));
    if (newAcc == NULL) {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &newAcc->accountNumber);

    // Check if account already exists
    struct BankAccount *temp = head;
    while (temp != NULL) {
        if (temp->accountNumber == newAcc->accountNumber) {
            printf("\nAccount with this number already exists!\n");
            free(newAcc);
            return;
        }
        temp = temp->next;
    }

    printf("Enter Holder Name: ");
    scanf("%s", newAcc->holderName);
    printf("Enter Initial Balance: ");
    scanf("%f", &newAcc->balance);

    newAcc->next = NULL;

    // Add to end of list
    if (head == NULL)
        head = newAcc;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newAcc;
    }

    totalAccounts++;
    printf("\nAccount created successfully!\n");
}

// Function to deposit money
void depositMoney() {
    int accNum;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    struct BankAccount *temp = head;
    while (temp != NULL) {
        if (temp->accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid deposit amount!\n");
                return;
            }
            temp->balance += amount;
            printf("Deposited %.2f successfully.\n", amount);
            return;
        }
        temp = temp->next;
    }
    printf("Account not found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    int accNum;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    struct BankAccount *temp = head;
    while (temp != NULL) {
        if (temp->accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid withdrawal amount!\n");
                return;
            }
            if (amount > temp->balance) {
                printf("Insufficient balance! Withdrawal not allowed.\n");
                return;
            }
            temp->balance -= amount;
            printf("Withdrawn %.2f successfully.\n", amount);
            return;
        }
        temp = temp->next;
    }
    printf("Account not found!\n");
}

// Function to display account details
void displayAccount() {
    int accNum;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    struct BankAccount *temp = head;
    while (temp != NULL) {
        if (temp->accountNumber == accNum) {
            printf("\n--- Account Details ---\n");
            printf("Account Number: %d\n", temp->accountNumber);
            printf("Holder Name   : %s\n", temp->holderName);
            printf("Balance       : %.2f\n", temp->balance);
            printf("------------------------\n");
            return;
        }
        temp = temp->next;
    }
    printf("Account not found!\n");
}

// Function to close (delete) an account
void closeAccount() {
    int accNum;
    printf("\nEnter Account Number to close: ");
    scanf("%d", &accNum);

    struct BankAccount *temp = head;
    struct BankAccount *prev = NULL;

    while (temp != NULL && temp->accountNumber != accNum) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Account not found!\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    totalAccounts--;
    printf("Account closed successfully.\n");
}

// Function to show total accounts
void showTotalAccounts() {
    printf("\nTotal accounts created: %d\n", totalAccounts);
}

// Function to display all accounts
void displayAllAccounts() {
    if (head == NULL) {
        printf("\nNo accounts found!\n");
        return;
    }

    printf("\n--- All Account Details ---\n");
    struct BankAccount *temp = head;
    while (temp != NULL) {
        printf("Account Number: %d | Name: %s | Balance: %.2f\n",
               temp->accountNumber, temp->holderName, temp->balance);
        temp = temp->next;
    }
    printf("-----------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n====== BANK MANAGEMENT SYSTEM ======");
        printf("\n1. Create New Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Display Account Details");
        printf("\n5. Display All Accounts");
        printf("\n6. Close an Account");
        printf("\n7. Show Total Accounts Created");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccount(); break;
            case 5: displayAllAccounts(); break;
            case 6: closeAccount(); break;
            case 7: showTotalAccounts(); break;
            case 8:
                printf("\nThank you for banking with us!\n");
                exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}