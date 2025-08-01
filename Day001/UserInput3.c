#include <stdio.h>
#include <string.h>

int main(){

    int age = 0;
    float gpa = 0.0f;
    double x = 0.0;
    char grade = '\0';  // \0 = null terminator character
    char name[30] = "";
    char fullName[30] = ""; 

    printf("Enter your age: ");
    scanf("%d", &age);  // & is the address-of operator
    printf("Enter your gpa: ");
    scanf("%f", &gpa);
    printf("Enter your grade: ");
    scanf(" %c", &grade);
    printf("Enter your first name: ");
    scanf(" %s", &name);

    getchar(); // Clear new line character before the input buffer
    printf("Enter your full name: ");
    fgets(fullName, sizeof(fullName), stdin);  // fullName = "Saptarshi Bose\n"
    fullName[strlen(fullName) - 1] = '\0';     // fullName = "BroCode\0"

    printf("%s\n", fullName);
    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);
    printf("%s\n", name);

    return 0;
}