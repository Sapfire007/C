/*
Create a program that maintains student details using nested structures. Each student has personal
details (id, name, address). Create a nested structure inside student structure to maintain academic
details (marks in three subjects as an array). Read details of maximum three students, calculate
their total and average marks, and display their results in a structured format.
*/

#include <stdio.h>

struct Student {
    int id;
    char name[50];
    char address[100];
    struct Academic {
        int marks[3];
    }acad;   // nested structure
};

int main() {
    struct Student s[3];
    int n;

    printf("Enter number of students (max 3): ");
    scanf("%d", &n);

    if (n > 3) {
        printf("Limit is 3 students only!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Enter details of Student %d ---\n", i + 1);

        printf("ID: ");
        scanf("%d", &s[i].id);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);   // reads full string

        printf("Address: ");
        scanf(" %[^\n]", s[i].address);

        printf("Enter 3 subject marks:\n");
        for (int j = 0; j < 3; j++) {
            printf("Mark %d: ", j + 1);
            scanf("%d", &s[i].acad.marks[j]);
        }
    }

    printf("\n=========== STUDENT RESULTS ===========\n");
    for (int i = 0; i < n; i++) {
        int total = 0;

        for (int j = 0; j < 3; j++) {
            total += s[i].acad.marks[j];
        }

        float avg = total / 3.0;

        printf("\nStudent %d:\n", i + 1);
        printf("ID      : %d\n", s[i].id);
        printf("Name    : %s\n", s[i].name);
        printf("Address : %s\n", s[i].address);

        printf("Marks   : %d, %d, %d\n", s[i].acad.marks[0], s[i].acad.marks[1], s[i].acad.marks[2]);

        printf("Total   : %d\n", total);
        printf("Average : %.2f\n", avg);
    }

    return 0;
}