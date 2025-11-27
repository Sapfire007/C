/*
Implement a C program that uses an array to store n integers, with values taken from user
during run-time. The program should compute and display the sum of even and odd elements
separately. Use functions to manage array operations, including finding and printing all even
and odd numbers.

Sample Input: Enter value for n: 5
Numbers are: 12, 15, 14, 9, 8
Sample Output: Even numbers: 12. 14, 8
Sum of even numbers: 34
Odd numbers: 15, 9
Sum of odd numbers: 24
*/

#include <stdio.h>

void inputArray(int *p, int n) {
    for(int i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", p + i);
    }
}

int printEven(int *p, int n) {
    int sum = 0;
    printf("Even numbers: ");
    for(int i=0; i<n; i++) {
        if(*(p + i) % 2 == 0) {
            printf("%d ", *(p + i));
            sum += *(p + i);
        }
    }
    printf("\n");
    return sum;
}

int printOdd(int *p, int n) {
    int sum = 0;
    printf("Odd numbers: ");
    for(int i=0; i<n; i++) {
        if(*(p + i) % 2 != 0) {
            printf("%d ", *(p + i));
            sum += *(p + i);
        }
    }
    printf("\n");
    return sum;
}

int main() {
    int n;
    printf("Enter value for n: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr;

    inputArray(ptr, n);

    int evenSum = printEven(ptr, n);
    printf("Sum of even numbers: %d\n", evenSum);

    int oddSum = printOdd(ptr, n);
    printf("Sum of odd numbers: %d\n", oddSum);

    return 0;
}