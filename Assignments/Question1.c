/*
You are designing a university database where the number of students and subjects per student are not fixed. 
Use pointers to structures and dynamic memory allocation. 
Requirements: a. Create n students dynamically. 
              b. For each student, allocate space for m subjects. 
              c. Input and print total marks using pointers.
*/



#include <stdio.h>
#include <stdlib.h> // for malloc() and free()

// Structure to store student data
struct Student {
    char name[50];
    int roll;
    int numSubjects;
    int *marks; // pointer to dynamically allocated array of marks
};

int main() {
    int n; // number of students
    struct Student *students; // pointer to dynamically allocated array of students

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n students
    students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input data for each student
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].roll);

        printf("Enter number of subjects: ");
        scanf("%d", &students[i].numSubjects);

        // Allocate memory for marks based on number of subjects
        students[i].marks = (int *)malloc(students[i].numSubjects * sizeof(int));

        if (students[i].marks == NULL) {
            printf("Memory allocation failed for marks!\n");
            return 1;
        }

        printf("Enter marks for %d subjects:\n", students[i].numSubjects);
        for (int j = 0; j < students[i].numSubjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }

    // Display student details and total marks
    printf("\n--- STUDENT DETAILS ---\n");
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < students[i].numSubjects; j++) {
            total += students[i].marks[j];
        }

        printf("\nName: %s", students[i].name);
        printf("\nRoll No: %d", students[i].roll);
        printf("\nNumber of Subjects: %d", students[i].numSubjects);
        printf("\nTotal Marks: %d", total);
        printf("\n------------------------\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(students[i].marks); // free marks for each student
    }
    free(students); // free students array

    return 0;
}