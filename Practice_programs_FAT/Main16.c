/*
Write a C program to check whether a given two-digit number is a special two-digit number or not.
Write the program without considering any loop control statements. A number is called a special two-
digit number if the sum of its digits and the product of its digits added together equals the number
itself.
Examples:
59 -> (5+9) + (5×9) = 14 + 45 = 59 -> Special Number
23 -> (2+3) + (2×3) = 5 + 6 = 11 -> Not Special
*/





#include <stdio.h>
#include <stdbool.h>

bool special(int a){
    int x = a % 10;
    int y = (a - x)/10;

    if(((x+y)+(x*y))==a){
        return true;
    }
    return false;
}

int main(){
    int a;

    do{
        printf("Enter a 2-digit number to check if it's a special number: ");
        scanf("%d", &a);
    }while(a<10 || a>99);

    bool result = special(a);

    if(result){
        printf("%d is a special number!", a);
    } else {
        printf("%d is not a special number", a);
    }

    return 0;
}