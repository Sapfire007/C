/*
Create a derived data type to maintain employee type information either Full-time, Part-time and Contract. 
Full-time employee can have id, name, salary. Part-time employee can have properties such as id, name, salary_per_hour, number of hours worked. 
Contract-Employee can have id, name, amount. 
Write a e program to read and search of employee data based on id.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum to represent employee type
typedef enum {
    FULL_TIME,
    PART_TIME,
    CONTRACT
} EmpType;

// Union to store different employee info
typedef union {
    struct {  // Full-time
        float salary;
    } fulltime;
    struct {  // Part-time
        float salary_per_hour;
        int hours_worked;
    } parttime;
    struct {  // Contract
        float amount;
    } contract;
} EmpDetails;

// Employee structure
typedef struct {
    int id;
    char name[50];
    EmpType type;
    EmpDetails details;
} Employee;

// Function to print employee info
void print_employee(Employee e) {
    printf("\nID: %d\nName: %s\n", e.id, e.name);
    switch (e.type) {
        case FULL_TIME:
            printf("Type: Full-time\nSalary: %.2f\n", e.details.fulltime.salary);
            break;
        case PART_TIME:
            printf("Type: Part-time\nSalary/Hour: %.2f\nHours Worked: %d\n",
                   e.details.parttime.salary_per_hour, e.details.parttime.hours_worked);
            break;
        case CONTRACT:
            printf("Type: Contract\nAmount: %.2f\n", e.details.contract.amount);
            break;
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    Employee *employees = (Employee *)malloc(n * sizeof(Employee));
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input employee data
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        getchar(); // consume newline
        printf("Name: ");
        scanf("%[^\n]", employees[i].name);
        getchar(); // consume newline

        int type_choice;
        printf("Employee Type (0-Full-time, 1-Part-time, 2-Contract): ");
        scanf("%d", &type_choice);
        employees[i].type = (EmpType)type_choice;

        switch (employees[i].type) {
            case FULL_TIME:
                printf("Salary: ");
                scanf("%f", &employees[i].details.fulltime.salary);
                break;
            case PART_TIME:
                printf("Salary per hour: ");
                scanf("%f", &employees[i].details.parttime.salary_per_hour);
                printf("Hours worked: ");
                scanf("%d", &employees[i].details.parttime.hours_worked);
                break;
            case CONTRACT:
                printf("Contract amount: ");
                scanf("%f", &employees[i].details.contract.amount);
                break;
            default:
                printf("Invalid type!\n");
                i--;  // retry this employee
                break;
        }
    }

    // Search by ID
    int search_id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].id == search_id) {
            print_employee(employees[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", search_id);
    }

    free(employees);
    return 0;
}