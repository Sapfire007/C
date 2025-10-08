/*
A company needs an Employee Database Management System that allows the administrator to insert and display employee records. 
Each employee has an empid, name, phone_num, and salary, which should be stored in a structure. 
To manage memory efficiently, the system must allocate memory dynamically only when a new employee is inserted, expanding the database using malloc or realloc as required. 
The administrator can insert multiple employees one by one, and the display option should neatly list all stored employee details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store employee details
struct Employee {
    int empid;
    char name[50];
    long long phone_num;
    float salary;
};


int main() {
    struct Employee *db = NULL;  // pointer to employee database
    int choice;
    int count = 0;  // number of employees stored

    do {
        printf("\n--- Employee Database Menu ---\n");
        printf("1. Insert Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                // Allocate memory for new employee
                struct Employee *temp;
                temp = (struct Employee *)realloc(db, (count + 1) * sizeof(struct Employee));
                if (temp == NULL) {
                    printf("Memory allocation failed!\n");
                    free(db);
                    return 1;
                }
                db = temp;

                // Input employee details
                printf("Enter Employee ID: ");
                scanf("%d", &db[count].empid);
                getchar(); // consume newline
                printf("Enter Name: ");
                scanf("%[^\n]", db[count].name);
                getchar(); // consume newline
                printf("Enter Phone Number: ");
                scanf("%lld", &db[count].phone_num);
                printf("Enter Salary: ");
                scanf("%f", &db[count].salary);

                count++;
                printf("Employee inserted successfully!\n");
                break;
            }

            case 2: {
                if (count == 0) {
                    printf("No employees to display.\n");
                    break;
                }

                printf("\n--- Employee Records ---\n");
                printf("EmpID\tName\t\tPhone Number\tSalary\n");
                printf("--------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-15s\t%lld\t%.2f\n", db[i].empid, db[i].name, db[i].phone_num, db[i].salary);
                }
                break;
            }

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    free(db);  // free allocated memory
    return 0;
}