/*
Write a program that generates the first n Fibonacci numbers using a recursive function. Store the
generated numbers in an array and display them. Demonstrate how recursion works internally by
tracing the values passed at each recursive call.
*/

#include <stdio.h>

int fib(int x){
    printf("fib(%d) called\n", x);   // Trace recursive call
    if (x == 0){
        return 0;
    }
    if (x == 1){
        return 1;
    }
    return fib(x-1) + fib(x-2);
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int arr[n];

    for(int i = 0; i < n; i++){
        arr[i] = fib(i);
    }

    printf("\nFibonacci series: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}