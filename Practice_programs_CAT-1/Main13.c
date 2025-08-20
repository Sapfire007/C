/*
    Write C program that creates two matrices A and B and take left diagonal values from both A and B
    matrices and display sum (diagonal value)
    Sample Input:
    Enter elements of Matrix A (3x3):
    123
    456
    789
    Enter elements of Matrix B (3x3):
    987
    654
    321

    Sample Output:
    Sum of Left Diagonal Elements:
    10 10 10
*/

#include <stdio.h>

int main(){

    int arr1[3][3];
    int arr2[3][3];

    printf("Enter elements of Matrix A (3x3):\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of Matrix B (3x3):\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("Sum of Left Diagonal Elements:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i==j){
                printf("%d\t", (arr1[i][j] + arr2[i][j]));
            }
        }
    }

    return 0;
}