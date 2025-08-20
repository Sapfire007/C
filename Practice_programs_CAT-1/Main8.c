/*
    Write a C program to create an array that takes ten elements as input. 
    Define a user-defined function named `searchCount(int arr[], int key)` to find the number of occurrences of a given key value in the array. 
    Also, define another function named `check(int key)` to determine whether the key value exists in the array or not. 
    If the key is found, the program should call the `searchCount(int arr[], int key)` function to display the number of occurrences of the key in the array; 
    otherwise, it should display "Not Found" as output. 
    For example, 
    if the input array is A = [2, 9, 5, 5, 7, 9, 5, 8, 9] 
    and the key value = 5, 
    the output should display that the key is found and the number of occurrences is 3.
*/


#include <stdio.h>

int n;

int check(int key){
    if(key==0){
        printf("Not Found.");
        return 1;
    }else{
        printf("Key is found and the number of occurrences is: %d", key);
        return 0;
    }
}

int searchCount(int arr[], int key){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(key == arr[i]){
            count++;
        }
    }
    return check(count);
}

int main(){
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int key = 0;
    printf("Enter the key value: ");
    scanf("%d", &key);
    searchCount(arr, key);
    return 0;
}