/*
Write a C program to rotate a given square matrix by 90 degrees clockwise using a 2D array. The
program should take a square matrix of size 'n x n' from the user, where 'n' is the dimension of the
matrix. Implement a function to perform the rotation in place (i.e., without using additional matrices),
using array manipulations and swaps. After performing the rotation, the program should display the
matrix before and after the rotation. Ensure the program handles any size of square matrix and
validates the input properly.

Example: n = 3;

1 2 3       7 4 1
4 5 6   ->  8 5 2 
7 8 9       9 6 3
*/

#include <stdio.h>
#define MAX 100

void printMatrix(int n, int matrix[MAX][MAX]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void rotateMatrix(int n, int matrix[MAX][MAX]){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n/2); j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

int main(){
    int mat1[MAX][MAX];
    int n;

    printf("Enter the size of the square matrix (n x n): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid input. Size must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\n---------------------------------\n");

    printf("Original Matrix:\n");
    printMatrix(n, mat1);

    rotateMatrix(n, mat1);

    printf("\n---------------------------------\n");

    printf("Rotated Matrix (90 degrees clockwise):\n");
    printMatrix(n, mat1);

    return 0;
}