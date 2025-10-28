/*
Implement a linked list where each node represents an employee.

Each employee has:
ID, Name, Department, Salary.

You must:
Insert a new employee at the end.
Delete an employee by ID.
Search for an employee using pointers.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Employee
struct Employee {
    int id;
    char name[50];
    char dept[30];
    float salary;
    struct Employee *next; // Pointer to next node
};

// Function to create a new node
struct Employee* createEmployee(int id, char name[], char dept[], float salary) {
    struct Employee* newEmp = (struct Employee*)malloc(sizeof(struct Employee)); // allocate memory for new node
    newEmp->id = id;
    strcpy(newEmp->name, name);
    strcpy(newEmp->dept, dept);
    newEmp->salary = salary;
    newEmp->next = NULL;
    return newEmp;
}

// Function to insert employee at the end of the list
void insertEmployee(struct Employee **head, int id, char name[], char dept[], float salary) {
    struct Employee *newEmp = createEmployee(id, name, dept, salary);

    // if list is empty, new employee becomes the first node
    if (*head == NULL) {
        *head = newEmp;
        printf("\nEmployee added as first record.\n");
        return;
    }

    // else traverse till the end
    struct Employee *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newEmp;
    printf("\nEmployee inserted successfully at the end.\n");
}

// Function to delete an employee by ID
void deleteEmployee(struct Employee **head, int id) {
    struct Employee *temp = *head;
    struct Employee *prev = NULL;

    // if list is empty
    if (*head == NULL) {
        printf("\nList is empty. No employee to delete.\n");
        return;
    }

    // if head node itself needs to be deleted
    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("\nEmployee with ID %d deleted successfully.\n", id);
        return;
    }

    // search for employee to delete
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // if not found
    if (temp == NULL) {
        printf("\nEmployee with ID %d not found.\n", id);
        return;
    }

    // unlink and delete
    prev->next = temp->next;
    free(temp);
    printf("\nEmployee with ID %d deleted successfully.\n", id);
}

// Function to search employee by ID
void searchEmployee(struct Employee *head, int id) {
    struct Employee *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nEmployee Found!\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n",
                   temp->id, temp->name, temp->dept, temp->salary);
            return;
        }
        temp = temp->next;
    }

    printf("\nEmployee with ID %d not found.\n", id);
}

// Function to display all employees
void displayAll(struct Employee *head) {
    struct Employee *temp = head;

    if (temp == NULL) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n--- Employee Records ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Department: %s | Salary: %.2f\n",
               temp->id, temp->name, temp->dept, temp->salary);
        temp = temp->next;
    }
    printf("-------------------------\n");
}

int main() {
    struct Employee *head = NULL; // initially, list is empty
    int choice, id;
    char name[50], dept[30];
    float salary;

    while (1) {
        printf("\n\n--- Employee Management Menu ---");
        printf("\n1. Insert Employee");
        printf("\n2. Delete Employee");
        printf("\n3. Search Employee");
        printf("\n4. Display All Employees");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Department: ");
                scanf("%s", dept);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                insertEmployee(&head, id, name, dept, salary);
                break;

            case 2:
                printf("\nEnter Employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(&head, id);
                break;

            case 3:
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &id);
                searchEmployee(head, id);
                break;

            case 4:
                displayAll(head);
                break;

            case 5:
                printf("\nExiting Program. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}