/*
Develop a program to store prices of n products entered by the user. Use calloc() to initialize all
prices to zero and later allow the user to update them. Implement a feature to expand or reduce the
product list dynamically. Demonstrate pointer traversal to display all prices after modification.
*/

#include <stdio.h>
#include <stdlib.h>

void displayPrices(float *ptr, int n) {
    printf("\nUpdated Product Prices:\n");
    for (int i = 0; i < n; i++) {
        printf("Product %d: %.2f\n", i + 1, *(ptr + i));
    }
}

int main() {
    int n;
    printf("Enter initial number of products: ");
    scanf("%d", &n);

    // Allocate memory using calloc
    float *prices = (float *)calloc(n, sizeof(float));
    if (prices == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nAll prices initialized to 0.00 by calloc.\n");

    // User enters the initial prices
    for (int i = 0; i < n; i++) {
        printf("Enter price of product %d: ", i + 1);
        scanf("%f", (prices + i));
    }

    // Resize option
    int new_n;
    printf("\nEnter new number of products (can be greater or smaller): ");
    scanf("%d", &new_n);

    float *temp = (float *)realloc(prices, new_n * sizeof(float));
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(prices);
        return 1;
    }
    prices = temp;

    // If expanded: ask prices for new products
    if (new_n > n) {
        printf("\nList expanded. Enter prices for new products:\n");
        for (int i = n; i < new_n; i++) {
            printf("Enter price of product %d: ", i + 1);
            scanf("%f", (prices + i));
        }
    }
    else if (new_n < n) {
        printf("\nList reduced. Extra product prices removed.\n");
    }

    // Display using pointer traversal
    displayPrices(prices, new_n);

    free(prices);
    return 0;
}