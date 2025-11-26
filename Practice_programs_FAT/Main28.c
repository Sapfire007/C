/*
Implement a C program that stores employee records (ID, name, salary) using dynamic
memory allocation. Use an array of pointers to hold multiple records, allowing users to add,
update, and delete records. Ensure the program handles memory efficiently, freeing unused
memory when a record is deleted.

Sample Input:
Add employee: ID = 1, Name = Ram, Salary = 50000
Add employee: ID = 2, Name = Mohan, Salary = 60000
Display all employees
Delete employee ID 1
Sample Output:
ID: 2, Name: Mohan, Salary: 60000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void addEmployee(Employee **arr, int *count) {
    Employee *newEmp = (Employee *)malloc(sizeof(Employee));
    printf("Enter ID: ");
    scanf("%d", &newEmp->id);
    printf("Enter Name: ");
    scanf("%s", newEmp->name);
    printf("Enter Salary: ");
    scanf("%f", &newEmp->salary);
    
    arr[*count] = newEmp;
    (*count)++;
}

void displayEmployees(Employee **arr, int count) {
    if(count == 0) {
        printf("No records found.\n");
        return;
    }
    for(int i=0; i<count; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", arr[i]->id, arr[i]->name, arr[i]->salary);
    }
}

// Function to delete an employee by ID
void deleteEmployee(Employee **arr, int *count, int id) {
    int found = 0;
    for(int i=0; i<*count; i++) {
        if(arr[i]->id == id) {
            free(arr[i]);  // Free memory
            for(int j=i; j<*count-1; j++)  // Shift remaining
                arr[j] = arr[j+1];
            (*count)--;
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Employee ID %d not found.\n", id);
    }
}

int main() {
    Employee *employees[100];  // Array of pointers
    int count = 0;
    int choice, id;

    while(1) {
        printf("\n1. Add Employee\n2. Display Employees\n3. Delete Employee\n4. Exit\nChoose: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addEmployee(employees, &count); break;
            case 2: displayEmployees(employees, count); break;
            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(employees, &count, id);
                break;
            case 4:
                for(int i=0; i<count; i++){
                    free(employees[i]);
                }
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}