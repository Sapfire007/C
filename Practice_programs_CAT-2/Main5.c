/*
Define a structure 'Student' with three fields: name, rollno, and marks in three subjects. 
Write a C program to read the data of a list of students and calculate the total and average marks of each student.
Display the name, rollno, total marks and average marks of each student.
*/

#include <stdio.h>

struct Student {
    char name[50];
    int rollno;
    float marks[3];  // marks in 3 subjects
    float total;
    float average;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);   // reads name (without spaces)
        printf("Roll No: ");
        scanf("%d", &s[i].rollno);

        s[i].total = 0;
        for (int j = 0; j < 3; j++) {
            printf("Marks in subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].average = s[i].total / 3.0;
    }

    printf("\n--- Student Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s", s[i].name);
        printf("\nRoll No: %d", s[i].rollno);
        printf("\nTotal Marks: %.2f", s[i].total);
        printf("\nAverage Marks: %.2f\n", s[i].average);
    }

    return 0;
}