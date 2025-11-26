/*
Write a C program to dynamically allocate memory for n integers using malloc(), input the values,
and print the second largest integer. Use only pointers (no array indexing).
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    printf("Enter the number of intergers you want to input: ");
    scanf("%d", &n);

    int *numbers = (int *)malloc(n*sizeof(int));

    if(numbers == NULL){
        printf("Error! Memory Allocation Failed!");
        return 1;
    }

    printf("Enter the input integers: ");
    int *temp = numbers;
    for(int i = 0; i < n; i++){
        scanf("%d", (temp+i));
    }

    for(int i = 0; i < n-1; i++){
        int *a = numbers;
        int *b = numbers+1;
        for(int j = 0; j < n - i - 1; j++){
            if(*a < *b){
                int temp = *a;
                *a = *b;
                *b = temp;
            }
            a++;
            b++;
        }
    }
    
    printf("Second largest input entered is: %d", *(numbers+1));
    free(numbers);
    numbers = NULL;
    return 0;
}