/*
Write a C program to dynamically allocate memory for storing the marks of 'n' number of students in a class. 
Read the marks of students and store them in the allocated memory. 
Increase the size of allocated memory to store the marks of additional students added to the class. 
Read the marks of additional students and store them in the newly allocated memory. 
Calculate the total marks and average marks of students and display that values.
*/

// Malloc: int *ptr = (int *)malloc(10*sizeof(int));
// Calloc: int *ptr = (int *)calloc(10, sizeof(int));
// Realloc: int *ptr = (int *)realloc(ptr, <new_total_size_blocks>*sizeof(int));
/*
free(ptr);
ptr = NULL;
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    char name[50];
    printf("Enter username: ");
    scanf("%[^\n]", name);
    printf("Enter the total number of students: ");
    scanf("%d", &n);
    int *ptr = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Enter marks for student %d: ",(i+1));
        scanf("%d", (ptr+i));
    }
    int old_n = n;
    int x = 0;
    printf("For how many more number of students do you want to input marks: ");
    scanf("%d", &x);
    n += x;
    ptr = (int *)realloc(ptr, n*sizeof(int));
    for(int i = old_n; i < n; i++){
        printf("Enter marks for student %d: ",(i+1));
        scanf("%d", (ptr+i));
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(ptr+i);
    }
    printf("Total marks obtained by the class: %d\n", sum);
    printf("Average marks of the class: %.2f\n", ((float)sum/n));

    free(ptr);
    ptr = NULL;
    return 0;
}