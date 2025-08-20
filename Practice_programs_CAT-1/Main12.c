/*
    Write c program- for a vending machine. It needs to accept coins of 1, 2, 5, and 10 rupees. The
    program should prompt the user to insert coins until the total amount reaches a pre-defined product
    price (e.g., 50 rupees). and Once the required amount is reached, the program should display in total
    how many coins of 1,2,5,10 are inserted and it should print "Transaction complete. Dispensing
    product."
    Sample Input:
    Insert coin (1, 2, 5, or 10): 10
    Insert coin (1, 2, 5, or 10): 5
    Insert coin (1, 2, 5, or 10): 10
    Insert coin (1, 2, 5, or 10): 10
    Insert coin (1, 2, 5, or 10): 10
    Insert coin (1, 2,5, or 10): 5

    Expected output:
    Total coins inserted:
    1 rupee coins: 0
    2 rupee coins: 0
    5 rupee coins: 2
    10 rupee coins: 3
    Total:50 rupees
    Transaction complete. Dispensing product.
*/


#include <stdio.h>

int main(){

    int total = 50;

    int c1 = 0;
    int c2 = 0;
    int c5 = 0;
    int c10 = 0;

    while(total > 0){

        int n = 0;

        printf("Insert coin (1, 2, 5, or 10): ");
        scanf("%d", &n);

        while(n != 1 && n != 2 && n!= 5 && n!=10){
            printf("Input coin not recognized! Please try again!\n");
            printf("Insert coin (1, 2, 5, or 10): ");
            scanf("%d", &n);
        }

        while(n>total){
            printf("Input coin exceeds payable amount! Please try again with lesser coin value!\n");
            printf("Insert coin (1, 2, 5, or 10): ");
            scanf("%d", &n);
        }

        if(n==1) c1++;
        if(n==2) c2++;
        if(n==5) c5++;
        if(n==10) c10++;

        total -= n;

    }

    printf("Total coins inserted:\n");
    printf("1 rupee coins: %d\n", c1);
    printf("2 rupee coins: %d\n", c2);
    printf("5 rupee coins: %d\n", c5);
    printf("10 rupee coins: %d\n", c10);

    printf("Total:50 rupees\n");
    printf("Transaction complete. Dispensing product.");

    return 0;
}