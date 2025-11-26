/*
Write a C program to sort a binary array so that all 0s appear before 1s.
Example:
Input: {1, 0, 1, 0, 0, 1}
Output: {0, 0, 0, 1, 1, 1}
*/

#include <stdio.h>

int main(){
    int a;
    printf("Enter the size of your array: ");
    scanf("%d", &a);
    int arr1[a];
    printf("Enter elements to be inserted in the array: ");
    for(int i = 0; i < a; i++){
        scanf("%d", &arr1[i]);
        if(arr1[i] != 1 && arr1[i] != 0){
            printf("Not a binary input!");
            return 1;
        }
    }
    for(int i = 0; i < a - 1; i++){
        for(int j  = 0; j < a - i - 1; j++){
            if(arr1[j] > arr1[j+1]){
                int temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for(int i = 0; i < a; i++){
        printf("%d ", arr1[i]);
    }
}