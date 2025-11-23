/*
Design a C program to perform basic mathematical operations using pointers to functions. Create
functions for addition, subtraction, multiplication, and division, each taking two integers as
parameters and returning the result. Use a pointer to function to dynamically select and call the
appropriate operation based on user input. Implement a menu-driven interface where the user chooses
the operation, inputs two numbers, and the program uses the function pointer to execute the chosen
operation. In main), demonstrate the program by allowing multiple calculations in a loop until the
user chooses to exit.
*/


#include <stdio.h>

void add(int a, int b, int *res){
    *res = a + b;
}

void sub(int a, int b, int *res){
    *res = a - b;
}

void mul(int a, int b, int *res){
    *res = a * b;
}

void div(int a, int b, int *res){
    if(b != 0){
        *res = a / b;
    } else {
        printf("Error! Division by zero!\n");
        *res = 0;
    }
}

int main(){
    void (*calc)(int, int, int *) = NULL;
    
    int choice, n1, n2, result;

    while (1) {
        printf("\n=== Calculator ===\n");
        printf("1. Add 2. Sub 3. Mul 4. Div 5. Exit: ");
        scanf("%d", &choice);

        if (choice == 5) break; 
        
        if (choice < 1 || choice > 5) {
            printf("Invalid choice.\n");
            continue;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &n1, &n2);

        switch(choice) {
            case 1: 
                calc = add; 
                break;
            case 2: 
                calc = sub; 
                break;
            case 3: 
                calc = mul; 
                break;
            case 4: 
                calc = div; 
                break;
        }

        calc(n1, n2, &result); 

        printf("Result: %d\n", result);
    }
    return 0;
}