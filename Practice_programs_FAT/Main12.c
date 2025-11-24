/*
You are building a simple grading system for a class. The number of students varies each semester,
and you don't know the exact count at the start of the program.

1. Ask the user to enter the number of students initially.
2. Use malloc to allocate memory for an array of float values to store grades for each student.
3. Allow the user to add grades, and if needed, use realloc to expand the array if more students
join the class.
4. At the end, calculate and display the average grade, the highest grade, and the lowest grade.
5. Define a function swap to interchange the values of highest grade with lowest grade and
display it.
6. Free the allocated memory at the end.

Write a C program to implement the above task.
*/

#include <stdio.h>
#include <stdlib.h>

// swap two floats
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, extra;
    printf("Enter initial number of students: ");
    scanf("%d", &n);

    float *grades = (float*) malloc(n * sizeof(float));
    printf("Enter %d grades:\n", n);
    for(int i=0; i<n; i++)
        scanf("%f", grades + i);

    printf("Do more students join? Enter count (0 if none): ");
    scanf("%d", &extra);
    if(extra > 0) {
        grades = (float*) realloc(grades, (n+extra)*sizeof(float));
        printf("Enter %d more grades:\n", extra);
        for(int i=n; i<n+extra; i++)
            scanf("%f", grades + i);
        n += extra;
    }

    // calculate average, highest, lowest, and positions
    float sum=0;
    int maxIndex=0, minIndex=0;
    for(int i=0; i<n; i++) {
        sum += grades[i];
        if(grades[i] > grades[maxIndex]) maxIndex = i;
        if(grades[i] < grades[minIndex]) minIndex = i;
    }

    printf("\nAverage: %.2f, Highest: %.2f, Lowest: %.2f\n", sum/n, grades[maxIndex], grades[minIndex]);

    // swap highest and lowest
    swap(&grades[maxIndex], &grades[minIndex]);

    printf("Grades after swapping highest and lowest:\n");
    for(int i=0; i<n; i++)
        printf("%.2f ", grades[i]);

    free(grades);
    return 0;
}