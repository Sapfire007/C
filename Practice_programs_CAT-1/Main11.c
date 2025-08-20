/*
    Write a C program that takes three integers as input and print greatest and smallest of three integers.

    Sample input:
    Enter first number: 25 Enter second number: 17 Enter third number: 42

    Expected Output:
    Greatest number: 42 Smallest number: 17
*/

#include <stdio.h>

int main(){
    int a = 0, b = 0, c = 0;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);
    if(a>b && a>c)
        printf("Greatest number: %d\n", a);
    if(b>a && b>c)
        printf("Greatest number: %d\n", b);
    if(c>b && c>a)
        printf("Greatest number: %d\n", c);
    if(a<b && a<c)
        printf("Smallest number: %d\n", a);
    if(b<a && b<c)
        printf("Smallest number: %d\n", b);
    if(c<b && c<a)
        printf("Smallest number: %d\n", c);

    return 0;
}