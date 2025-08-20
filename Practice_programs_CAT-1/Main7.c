/*
    Write a C program to perform the following tasks:
    Accept the heights (in cm) of N persons and store them in a float array.
    Sort the array in ascending order.
    Display the sorted list of heights.
    Display the smallest height and the largest height from the array.

    Example Input:
    165.5, 172.3, 158.0, 180.0, 169.8

    Expected Output:
    Smallest value is 158.0
    Largest value is 180.0
*/

#include <stdio.h>

int main(){
    int n = 0;
    printf("Enter the count of people: ");
    scanf("%d", &n);
    float arr[n];
    float tempArr[n];
    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
        tempArr[i] = arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[i]>arr[j]){
                float tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp; 
            }
        }
    }
    printf("Input array of heights: ");
    for(int i = 0; i < n; i++){
        printf("%f\t", tempArr[i]);
    }
    printf("\n");
    printf("Sorted array of heights: ");
    for(int i = 0; i < n; i++){
        printf("%f\t", arr[i]);
    }
    printf("\n");
    printf("Smallest value is %.2f\n", arr[0]);
    printf("Largest value is %.2f\n", arr[n-1]);
    return 0;
}