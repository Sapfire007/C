/*
Write a C program that should take two operands and any of the given operations 
to be performed (left shift, right shift, ternary operator, increment and decrement). 
Use a switch statement to perform the corresponding operation and display the result.

Sample Input:
Enter first operand: 8
Enter second operand: 2
Choose operation: 
1. Left Shift 
2. Right Shift 
3. Ternary Operator (greater value) 
4. Increment 
5. Decrement

Your choice: 3

Expected Output:
Greater value is: 8
*/

#include <stdio.h>

int main() {
    int a, b, choice;

    // Input operands
    printf("Enter first operand: ");
    scanf("%d", &a);
    printf("Enter second operand: ");
    scanf("%d", &b);

    // Display menu
    printf("Choose operation:\n");
    printf("1. Left Shift\n");
    printf("2. Right Shift\n");
    printf("3. Ternary Operator (greater value)\n");
    printf("4. Increment\n");
    printf("5. Decrement\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    // Perform operation
    switch (choice) {
        case 1:
            printf("Result of Left Shift (a << b): %d\n", a << b);
            break;
        case 2:
            printf("Result of Right Shift (a >> b): %d\n", a >> b);
            break;
        case 3:
            printf("Greater value is: %d\n", (a > b ? a : b));
            break;
        case 4:
            printf("Incremented values: a = %d, b = %d\n", a + 1, b + 1);
            break;
        case 5:
            printf("Decremented values: a = %d, b = %d\n", a - 1, b - 1);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}