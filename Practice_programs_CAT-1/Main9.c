/*
    A warehouse inventory system maintains a list representing the number of items in each box of a shipment. 
    Since each box contains bundled sets of items, the total count of items in the shipment is obtained by multiplying the number of items in all the boxes together.
    Write a recursive C program to calculate the product of all items in the shipment.

    Example:
    Input:
    Enter number of boxes: 4
    Enter number of items in each box: 4 3 7 2
    Output:
    Total items in shipment: 168
*/


#include <stdio.h>

int prod(int arr[], int n){

    if(n == 0){
        return 0;
    }

    if(n == 1){
        return arr[0];
    }

    return arr[n-1] * prod(arr, n-1);
}

int main(){

    int n = 0;
    printf("Enter number of boxes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter number of items in each box: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Total items in shipment: %d", prod(arr, n));

    return 0;
}