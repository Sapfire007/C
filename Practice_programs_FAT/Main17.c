/*
Write a C program to check whether a given number is a perfect number or not.
A number is said to be perfect if the sum of ita proper divisors (excluding the number itself) is equal
to the number.
Examples:
6-> Divisors: 1, 2, 3 -> Sum = 6 -> Perfect number
8-> Divisors: 1, 2, 4 -> Sum = 7 -> Not perfect
*/

#include <stdio.h>
#include <stdbool.h>

bool perfect(int a){
    int sum = 0;

    for(int i = 1; i < a; i++){
        if(a%i==0){
            sum += i;
        }
    }

    if(sum==a){
        return true;
    }
    
    return false;
}

int main(){
    int a;
    printf("Input a number to check if it's perfect or not: ");
    scanf("%d", &a);
    bool result = perfect(a);
    if(result){
        printf("%d is a perfect number!", a);
    } else {
        printf("%d is not a perfect number!", a);
    }
    return 0;
}