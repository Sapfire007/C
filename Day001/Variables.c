#include <stdio.h>
#include <stdbool.h> // This is a standard header file; This is added to use boolean in our program

int main(){

    // variable = A reusable container for a value.
    //            Behaves as if it were the value it contains.

    int age = 18;
    int year = 2025;
    int quantity = 7.5;

    printf("You are %d years old\n", age);
    printf("The year is %d\n", year);
    printf("You have ordered %d x items\n", quantity);
    
    float gpa = 8.5;
    float temp = 36.78432;
    float price = 19.99;
    printf("Your gpa is %.2f\n", gpa);
    printf("The temperature outside is %.1fdegC\n", temp);
    printf("The price is $%f\n", price);

    double pi = 3.14159265358979;
    printf("The value of pi is %lf\n", pi); // %lf means long float
    printf("The value of pi is %.15lf\n", pi);
    
    char grade = 'A';
    printf("You scored an %c grade\n", grade);

    // There is no string datatype in C programming language

    char name[] = "Saptarshi Bose";
    printf("Hello %s\n", name); // %s means string

    char email[] = "sapx007@yahoo.com";
    printf("Your email is: %s\n", email);

    bool isOnline = 1;
    bool isActive = true;
    printf("User status: %d\n", isOnline);
    printf("User status: %d\n", isActive);
    bool isTexting = 0;
    bool isIdling = 0;
    printf("Texting status: %d\n", isTexting);
    printf("Idling status: %d\n", isIdling);

    /*
        In Summary:
            int = whole numbers (4 bytes in modern systems)
            float = single-precision decimal number (4 bytes)
            double = double-precision decimal number (8 bytes)
            char = single character (1 byte)
            char[] = array of characters (size varies)
            bool = true or false (1 byte, requires <stdbool.h>)
    */

    return 0;
}