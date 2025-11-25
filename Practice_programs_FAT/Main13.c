/*
A company needs a flexible sorting solution for an array of integers. Sometimes, they want the
array sorted in ascending order, and sometimes in descending order. Other times, they want only
even numbers first, followed by odd numbers. Define different comparison functions to handle
these requirements. Use a pointer to function to allow the sorting function to choose the
appropriate comparison function dynamically. Write the C code for the solution and explain how
pointer to function are used to switch between sorting strategies.
*/

#include <stdio.h>

int asc(int a, int b){
    return a > b;
}

int dsc(int a, int b){
    return a < b;
}

int evenFirst(int a, int b){
    if(a%2==0 && b%2!=0){
        return 0;
    }
    if(a%2!=0 && b%2==0){
        return 1;
    }
    return a > b;
}

void sort(int arr[], int n, int (*cmp)(int, int)){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(cmp(arr[j], arr[j+1])){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n = 0;
    int choice;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr1[n];

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }

    printf("\n1-Ascending  2-Descending  3-Even First\nChoose: ");
    scanf("%d",&choice);

    if(choice==1){
        sort(arr1, n, asc);
    }
    else if(choice==2){
        sort(arr1, n, dsc);
    }
    else{
        sort(arr1, n, evenFirst);
    }

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr1[i]);
    }

    return 0;
}