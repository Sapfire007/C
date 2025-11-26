/*
Write a C program that dynamically allocates memory for an array of integers based on user
input. Populate this array with random numbers taken from the user, then use pointer arithmetic
to find the maximum, minimum, and average values of the elements. Include comments explaining each use of pointers.

Sample Input: Enter the number of elements: 5 (10, 5, 7, 8, 6)
Sample Output: Array elements: 10, 5, 7, 8, 6
Maximum: 10, Minimum: 5, Average: 7.20
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    int *max = arr;
    int *min = arr;
    float sum = 0;

    // Traverse array using pointers
    for (int i = 0; i < n; i++) {
        int value = *(arr + i);   // *(arr + i) fetches ith element

        if (value > *(max))
            max = (arr+i);

        if (value < *(min))
            min = (arr+i);

        sum += value;
    }

    float avg = sum / n;

    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    printf("\nMaximum: %d, Minimum: %d, Average: %.2f\n", *(max), *(min), avg);

    free(arr);
    arr = NULL;

    return 0;
}