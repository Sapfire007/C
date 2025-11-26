/*
Write a C program using a non-recursive function int isPalindrome (int num) to check whether the
input number is a palindrome
*/

#include <stdio.h>
#include <stdbool.h>

bool palindrome(int a){
    int temp = a;
    int result = 0;
    while(temp > 0){
        int rem = temp%10;
        result = (result*10) + rem;
        temp = temp / 10;
    }

    if(result == a){
        return true;
    }
    return false;
}

int main(){
    int a;
    printf("Enter number to check for palindrome: ");
    scanf("%d", &a);
    bool result = palindrome(a);
    if(result){
        printf("%d is a palindrome number!", a);
    } else {
        printf("%d is not a palindrome number!", a);
    }
    return 0;
}