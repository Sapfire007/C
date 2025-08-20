/*
    In a Smart Library System, each book has a unique numeric code printed on it. When a book is returned, the system calculates the sum of all digits in the book’s code.
    If the sum of digits is even, the book is placed in the East Section.
    If the sum of digits is odd, the book is placed in the West Section.

    Write a program to:
    Read the book code as input.
    Calculate the sum of its digits.
    Determine and display the section where the book should be placed.
    
    Input Example:
    34561
    Output Example:
    West Section
*/


#include <stdio.h>

int main(){

    int n = 0;
    scanf("%d", &n);

    do {
        if(n < 0) printf("Invalid code! Please re-input: ");
        scanf("%d", &n);
    } while(n < 0);

    int temp = n;
    int sum = 0;

    while(temp > 0){
        int rem = temp%10;
        temp /= 10;
        sum += rem;
    }

    (sum % 2 == 0) ? printf("East Section") : printf("West Section");

    return 0;
}