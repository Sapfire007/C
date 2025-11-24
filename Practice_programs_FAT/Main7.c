/*
Design a C program to maintain a student management system using an array of structures. Define a
structure named Student with data members including rollNumber, name, age, marks, and grade.
Implement functions to input data for each student, ensuring unique rollNumber validation. Add
functionality to display all student records, calculate and display the average marks of the class, and
identify students with the highest and lowest marks. In main(), initialize an array to store up to 30
student records and demonstrate all functionalities with at least five sample entries.
*/

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 30

struct Student {
    int rollNumber;
    char name[30];
    float marks;
    char grade;
};

void inputStudentData(struct Student students[], int *count);
void displayAllRecords(const struct Student students[], int count);
void calculateAndDisplayAverageMarks(const struct Student students[], int count);
void findHighLowMarks(const struct Student students[], int count);
char simpleCalculateGrade(float marks);

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    printf("Welcome to the Student Management System (Minimal).\n");
    printf("----------------------------------------\n");

    printf("--- Entering 5 Sample Student Data ---\n");
    for (int i = 0; i < 5; i++) {
        inputStudentData(students, &studentCount);
    }
    
    if (studentCount == 0) {
        printf("\nNo student records to process.\n");
        return 0;
    }

    printf("\n========================================\n");
    displayAllRecords(students, studentCount);

    printf("\n========================================\n");
    calculateAndDisplayAverageMarks(students, studentCount);

    printf("\n========================================\n");
    findHighLowMarks(students, studentCount);

    printf("\n========================================\n");
    printf("Program execution complete.\n");

    return 0;
}

char simpleCalculateGrade(float marks) {
    if (marks >= 90.0) return 'A';
    if (marks >= 75.0) return 'B';
    if (marks >= 60.0) return 'C';
    return 'D';
}

void inputStudentData(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Maximum students reached.\n");
        return;
    }

    struct Student newStudent;
    
    printf("\n--- Input Data for Student %d ---\n", *count + 1);

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    
    printf("Enter Name (one word): ");
    scanf("%s", newStudent.name);

    printf("Enter Marks (0-100): ");
    scanf("%f", &newStudent.marks);

    newStudent.grade = simpleCalculateGrade(newStudent.marks);

    students[*count] = newStudent;
    (*count)++;
    printf("Record added (Roll: %d, Grade: %c).\n", newStudent.rollNumber, newStudent.grade);
}

void displayAllRecords(const struct Student students[], int count) {
    printf("## All Student Records ##\n");
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("Roll\tName\t\t\tMarks\tGrade\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t%c\n",
               students[i].rollNumber,
               students[i].name,
               students[i].marks,
               students[i].grade);
    }
}

void calculateAndDisplayAverageMarks(const struct Student students[], int count) {
    printf("## Class Average ##\n");
    if (count == 0) {
        printf("No students to calculate average.\n");
        return;
    }

    float totalMarks = 0.0;
    for (int i = 0; i < count; i++) {
        totalMarks += students[i].marks;
    }

    float averageMarks = totalMarks / count;

    printf("Average Marks of the Class: %.2f (Total students: %d)\n", averageMarks, count);
}

void findHighLowMarks(const struct Student students[], int count) {
    printf("## Scorers Analysis ##\n");
    if (count == 0) {
        printf("No data for analysis.\n");
        return;
    }

    float maxMarks = students[0].marks;
    float minMarks = students[0].marks;

    for (int i = 1; i < count; i++) {
        if (students[i].marks > maxMarks) {
            maxMarks = students[i].marks;
        }
        if (students[i].marks < minMarks) {
            minMarks = students[i].marks;
        }
    }

    printf("\nHighest Marks (%.2f):\n", maxMarks);
    for (int i = 0; i < count; i++) {
        if (students[i].marks == maxMarks) {
            printf("- Roll %d, Name: %s\n", students[i].rollNumber, students[i].name);
        }
    }

    printf("\nLowest Marks (%.2f):\n", minMarks);
    for (int i = 0; i < count; i++) {
        if (students[i].marks == minMarks) {
            printf("- Roll %d, Name: %s\n", students[i].rollNumber, students[i].name);
        }
    }
}