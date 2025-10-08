/*
Write a C program to demonstrate the difference between, call-by-value and call-by-reference, by applying to simple banking functions deposit() and withdraw(). 
Both functions work with the integer parameters 'balance' and 'amount'. In the main() function, display the balances before and after calling these two functions. 
Also write the output of the program.
*/

#include <stdio.h>

int deposit(int *n, int m);
int withdraw(int *x, int y);

int main(){
    int bal = 0;
    int depAmt = 500;
    int withAmt = 350;
    
    printf("Balance before deposit: %d\n", bal);
    
    // Depositing 500 rs
    deposit(&bal, depAmt);
    
    printf("Balance after deposit: %d\n", bal);

    // Withdrawing 350rs
    withdraw(&bal, withAmt);

    printf("Balance after transaction: %d\n", bal);
    
    return 0;
}

int deposit(int *n, int m){
    // Here m is call by value and *n is call by reference
    printf("Depositing amount: %d\n", m);
    return *n += m;
}

int withdraw(int *x, int y){
    // Here y is call by value and *x is call by reference
    printf("Withdrawing amount: %d\n", y);
    return *x -= y;
}