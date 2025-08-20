/*
    Write a C program to print a hollow square pattern using asterisks (*). 
    The program should prompt the user to input a positive integer n, which represents the size of the square (number of rows and columns). 
    The pattern should have a hollow center, with asterisks forming the outer boundary of the square.

    For example, for n = 5, the output should be:
    *****
    *   *
    *   *
    *   *
    *****

    Ensure that the program handles invalid inputs, such as non-positive integers, and prompts the user to enter a valid number. 
    The program should allow the user to print hollow square patterns for any size n.

*/

#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("Enter a valid size: ");
        scanf("%d", &n);
    }
    // if(n == 1){
    //     printf("*");
    //     return 0;
    // }
    // for(int i = 0; i < n; i++){
    //     printf("*");
    //     for(int j = 0; j < n-2; j++){
    //         if(i == 0 || i == n-1){
    //             printf("*");
    //         }else{
    //             printf(" ");
    //         }
    //     }
    //     printf("*\n");
    // }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || i == n-1 || j == 0 || j == n-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}