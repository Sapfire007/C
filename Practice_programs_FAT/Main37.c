/*
Create a program that defines multiple arithmetic functions - addition, subtraction, multiplication,
and division. Use a pointer to function to call the selected operation based on user input.
Demonstrates how pointers can be used to reference and invoke different functions dynamically.
*/

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) { 
    return a - b; 
}
int mul(int a, int b) { 
    return a * b; 
}
int divide(int a, int b) { 
    if(b == 0){
        printf("Error! Division by zero\n");
        return 1;
    }
    return a / b; 
}

int main() {
    int a, b, choice;
    int (*operation)(int, int);    // function pointer declaration

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\n=== MENU ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Choose operation: ");
    scanf("%d", &choice);

    // Select operation using function pointer
    switch(choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = sub;
            break;
        case 3:
            operation = mul;
            break;
        case 4:
            operation = divide;
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    // Invoke selected function using the function pointer
    int result = operation(a, b);
    printf("\nResult = %d\n", result);

    return 0;
}