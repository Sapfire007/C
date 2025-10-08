/*
A university needs a program to manage the marks of students in six subjects. 
Since the number of students (n) is not fixed, the program should allocate memory dynamically at runtime using a double pointer (int ** marks). 
Each student will have marks for exactly 6 subjects. 
The program must use pointer arithmetic (instead of array indexing) to: Accept the marks of all students.
Calculate the average percentage of each student across the 6 subjects. 
Display the results in a neat format.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // number of students
    int i, j;
    int **marks; // double pointer for 2D array

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Allocate memory for 'n' students (rows)
    marks = (int **)malloc(n * sizeof(int *));
    if (marks == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Each student has marks in 6 subjects
    for (i = 0; i < n; i++) {
        *(marks + i) = (int *)malloc(6 * sizeof(int));
        if (*(marks + i) == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    // Accept marks using pointer arithmetic
    printf("\nEnter marks for each student (6 subjects each):\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        for (j = 0; j < 6; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", (*(marks + i) + j));
        }
    }

    // Calculate and display results
    printf("\nStudent\tTotal Marks\tAverage (%)\n");
    printf("----------------------------------------\n");

    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = 0; j < 6; j++) {
            sum += *(*(marks + i) + j);
        }
        float avg = sum / 6.0;
        printf("%d\t%d\t\t%.2f\n", i + 1, sum, avg);
    }

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(*(marks + i));
    }
    free(marks);

    return 0;
}