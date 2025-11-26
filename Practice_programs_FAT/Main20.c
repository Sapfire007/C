/*
Write a C program to input a character array. Using a pointer, access all the elements of the array and
print their ASCII equivalents. In addition, print the characters that possess the largest and lowest
ASCII values respectively.
*/

#include <stdio.h>

int main(){
    int a;
    printf("Enter the size of the array: ");
    scanf("%d", &a);
    char arr1[a];
    printf("Enter the characters to be input in the array: ");
    for(int i = 0; i < a; i++){
        scanf(" %c", &arr1[i]);
    }
    char *p = arr1;
    char *max = arr1;
    char *min = arr1;
    printf("ASCII equivalents for the elements in the array: ");
    for(int i = 0; i < a; i++){
        printf("%d ", *(p+i));
        if(*(max) < *(p+i)){
            max = p+i;
        }
        if(*(min) > *(p+i)){
            min = p+i;
        }
    }
    printf("\nCharacter with the maximum ASCII value: %c; It's ASCII value: %d", *(max), *(max));
    printf("\nCharacter with the minimum ASCII value: %c; It's ASCII value: %d", *(min), *(min));
    return 0;
}