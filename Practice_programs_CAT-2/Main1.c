/*
Write a C program using a pointer to an array to perform the following operations: 
a) Read a list of values into the array 
b) Increase each value in the array by 20 
c) Display the updated values in the array 
*/

#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = arr;
    
    for(int i = 0; i < n; i++){
        printf("Enter element number %d of the array: ", (i+1));
        scanf("%d", (ptr+i));
    }
    
    for(int i = 0; i < n; i++){
        *(ptr+i) += 20; 
    }
    
    for(int i = 0; i < n; i++){
        printf("Element number %d of the array: %d\n", (i+1), *(ptr+i));
    }
    
    return 0;
}