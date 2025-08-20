/*
    Write a c program using functions to print list of elements in array (a 1D array ) with largest and
    smallest values in the list and sum the largest and smallest value in the array and return the sum to
    calling function.

    Sample input:
    Array elements: 12 45 7 89 23 7
    Largest element: 89
    Smallest element: 7
    Sum of largest and smallest: 96
*/


#include <stdio.h>

void printArray(int arr[], int n) {
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findLargest(int arr[], int n) {
    int largest = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int findSmallest(int arr[], int n) {
    int smallest = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int sumLargestSmallest(int largest, int smallest) {
    return largest + smallest;
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);

    int largest = findLargest(arr, n);
    int smallest = findSmallest(arr, n);

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    int sum = sumLargestSmallest(largest, smallest);
    printf("Sum of largest and smallest: %d\n", sum);

    return 0;
}