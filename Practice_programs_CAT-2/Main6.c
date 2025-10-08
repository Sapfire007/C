/*
Define a structure 'Employee' by including the fields: name, id, contact-type. 
Also define a union 'Contact' inside the 'Employee' structure and include the fields: email, phone-number in the 'Contact' union. 
In the main() function, read name, id and contact-type of an employee. 
Based on the value of contact-type, read the corresponding contact information of the employee. 
Display the name, id, contact-type and contact information of the employee.
*/

#include <stdio.h>
#include <string.h>

struct Employee{
    char name[50];
    int id;
    char contact_type[10];

    union Contact{
        char email[50];
        long long phone;
    }contact;
};

int main(){
    struct Employee emp;

    printf("Enter employee name: ");
    scanf("%[^\n]", emp.name);
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);

     printf("Enter contact type (email/phone): ");
    scanf("%s", emp.contact_type);

    // Check which contact type user chose
    if (strcmp(emp.contact_type, "email") == 0) {
        printf("Enter email: ");
        scanf("%s", emp.contact.email);
    } 
    else if (strcmp(emp.contact_type, "phone") == 0) {
        printf("Enter phone number: ");
        scanf("%lld", &emp.contact.phone);
    } 
    else {
        printf("Invalid contact type entered!\n");
        return 0;
    }

    // Display employee details
    printf("\n--- Employee Details ---\n");
    printf("Name: %s\n", emp.name);
    printf("ID: %d\n", emp.id);
    printf("Contact Type: %s\n", emp.contact_type);

    if (strcmp(emp.contact_type, "email") == 0)
        printf("Email: %s\n", emp.contact.email);
    else
        printf("Phone Number: %lld\n", emp.contact.phone);

    return 0;
}