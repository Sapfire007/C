/*
Write a C program that defines a function to detect duplicate elements in an integer array. Use pointers
to traverse the array and identify duplicates. Print each duplicate element, number of times it is
repeated and its position.
*/


#include <stdio.h>

void findDuplicates(int arr[], int size) {
    printf("Duplicate elements found:\n");
    
    for (int i = 0; i < size; i++) {
        int count = 0;
        int alreadyPrinted = 0;
        
        // Check if this element was already counted as duplicate
        for (int k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                alreadyPrinted = 1;
                break;
            }
        }

        if (alreadyPrinted) continue;  // Skip if already processed
        
        // Count occurrences using pointer
        int *ptr = arr;
        for (int j = 0; j < size; j++) {
            if (*(ptr + j) == arr[i]) {
                count++;
            }
        }
        
        // If duplicate found (appears more than once)
        if (count > 1) {
            printf("\nElement: %d\n", arr[i]);
            printf("\tAppears %d times\n", count);
            printf("\tPositions: ");
            
            // Print all positions using pointer
            int *p = arr;
            for (int j = 0; j < size; j++) {
                if (*(p + j) == arr[i]) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int arr[] = {4, 2, 7, 4, 9, 2, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    findDuplicates(arr, size);
    
    return 0;
}