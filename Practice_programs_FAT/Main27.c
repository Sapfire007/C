/*
Write a C program that accepts a matrix of size N x M and performs matrix multiplication with another matrix of compatible size. 
The program should use functions for input, output, multiplication, and also provide the transpose of the resulting matrix. 
Display the transpose of the resulting matrix after multiplication.
*/

#include <stdio.h>

// Function to input a matrix
void inputMatrix(int r, int c, int mat[r][c]) {
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void printMatrix(int r, int c, int mat[r][c]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrix(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2], int res[r1][c2]) {
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++) {
            res[i][j] = 0;
            for(int k=0; k<c1; k++){
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to print transpose of a matrix
void transposeMatrix(int r, int c, int mat[r][c]) {
    printf("Transpose:\n");
    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++){
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    int mat1[r1][c1];
    inputMatrix(r1, c1, mat1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    if(c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }
    int mat2[r2][c2];
    inputMatrix(r2, c2, mat2);

    int res[r1][c2];
    multiplyMatrix(r1, c1, mat1, r2, c2, mat2, res);

    printf("Resulting Matrix:\n");
    printMatrix(r1, c2, res);
    transposeMatrix(r1, c2, res);

    return 0;
}