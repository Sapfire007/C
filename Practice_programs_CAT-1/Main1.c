/*
    Write a C program to rotate a given square matrix by 90 degrees clockwise using a 2D array. 
    The program should take a square matrix of size ‘n x n’ from the user, where ‘n’ is the dimension of the matrix. 
    Implement a function to perform the rotation in place (i.e., without using additional matrices), using array manipulations and swaps. 
    After performing the rotation, the program should display the matrix before and after the rotation. 
    Ensure the program handles any size of square matrix and validates the input properly.

    Example: n = 3

    Input matrix:
    1 2 3
    4 5 6
    7 8 9

    Output matrix after rotation:
    7 4 1
    8 5 2
    9 6 3
*/


#include <stdio.h>

int main() {
    // Write C code here
    int arr1[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    int arr2[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arr2[i][j] = arr1[j][i];
        }
    }
    for(int i = 0; i < 3; i++){
        int temp[3];
        for(int j = 2,k=0; j >= 0; j--,k++){
            temp[k] = arr2[i][j];
        }
        for(int k = 0; k < 3; k++){
            arr2[i][k] = temp[k];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}