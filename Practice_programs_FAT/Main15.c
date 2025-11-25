/*
You need to create a payroll system that stores information about employees using C, including
their name, age, hours worked, and hourly wage.

. Define a structure Employee with fields for name (string), age (int), hours Worked (float), and
hourly Wage (float).
· Create an array of 25 Employee structures to hold records of 25 employees.
· Write a program that reads information for each employee.
· Implement a function sortByWage that takes n and an array of Employee structures as
pointers, sorting them in descending order by hourly wage.
. Display the sorted list of employees.
· Free all dynamically allocated memory at the end of the program.
*/

#include <stdio.h>
#include <stdlib.h>

struct Employee{
    char name[50];
    int age;
    float hoursWorked;
    float hourlyWage;
};

void sortByWage(struct Employee *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((arr+i)->hourlyWage < (arr+j)->hourlyWage){
                struct Employee temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp; 
            }
        }
    }
}

int main(){
    int n = 25;
    struct Employee *employees = (struct Employee *)malloc(n*(sizeof(struct Employee)));
    if(employees == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    for(int i=0;i<n;i++) {
        printf("\nEmployee #%d\n", i+1);
        printf("Enter name: ");
        scanf(" %[^\n]", (employees+i)->name);
        printf("Enter age: ");
        scanf("%d", &(employees+i)->age);
        printf("Enter hours worked: ");
        scanf("%f", &(employees+i)->hoursWorked);
        printf("Enter hourly wage: ");
        scanf("%f", &(employees+i)->hourlyWage);
    }

    sortByWage(employees, n);

    printf("\n--- Employees Sorted by Hourly Wage (Descending) ---\n");
    for(int i=0;i<n;i++) {
        printf("\nName: %s\nAge: %d\nHours Worked: %.2f\nHourly Wage: %.2f\n",
               (employees+i)->name,
               (employees+i)->age,
               (employees+i)->hoursWorked,
               (employees+i)->hourlyWage);
    }

    free(employees);
    return 0;
}