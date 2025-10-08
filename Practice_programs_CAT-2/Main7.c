/*
A software company wants to implement a simple name-to-number converter for user authentication.
The program should read a name entered by the user and calculate a numeric key by converting each
character into its alphabetical value (A=1, B=2, ... , Z=26) and summing them up using pointer
arithmetic instead of array indexing. 
If the input contains any non-alphabetic character (such as digits, spaces, or symbols), the program should immediately display "Invalid name". 
Otherwise, it should display the original name along with the calculated sum.
*/

#include <stdio.h>
#include <ctype.h>   // for isalpha(), toupper()

int main() {
    char name[100];
    char *ptr;     // pointer to traverse the string
    int sum = 0;

    printf("Enter a name: ");
    scanf("%[^\n]", name);   // read full name including spaces

    ptr = name;  // initialize pointer to start of string

    while (*ptr != '\0') {  // loop till end of string
        if (!isalpha(*ptr)) {
            printf("Invalid name\n");
            return 0;  // terminate program immediately
        }

        // Convert character to uppercase and then to its alphabetical value
        sum += (toupper(*ptr) - 'A' + 1);
        ptr++;  // move pointer to next character
    }

    printf("Name: %s\n", name);
    printf("Numeric key: %d\n", sum);

    return 0;
}
