/*
Write a C program to store employee contact details using a structure containing a union. The
employee can have either a phone number or an email. Input employee name and contact type, then
display the stored contact.
*/


#include <stdio.h>

typedef struct {
    char name[50];
    int type;
    union{
        long int phone;
        char email[50];
    } Contact;
} Employee;

int main(){
    Employee e;
    printf("Enter employee name: ");
    scanf(" %[^\n]", &e.name);

    printf("Enter contact type (1 = phone, 2 = email): ");
    scanf("%d", &e.type);

    if(e.type==1){
        printf("Enter phone number: ");
        scanf("%ld", &e.Contact.phone);
    } else {
        printf("Enter email: ");
        scanf("%s", &e.Contact.email);
    }

    printf("Displaying employee details: \n");
    printf("Employee name: %s\n", e.name);
    if (e.type == 1) {
        printf("Phone: %ld\n", e.Contact.phone);
    } 
    else {
        printf("Email: %s\n", e.Contact.email);
    }

    return 0;
}