#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[50];
    int age;
    float gpa;
    bool isFullTime;
}Student;

void printStudent(Student student);

int main(){
    // struct = A custom container that holds multiple
    //          pieces of related information.
    //          Similar to Objects in other languages

    Student student1 = {"Saptarshi", 18, 9.2, true};
    Student student2 = {"Ankit", 19, 9.5, false};
    Student student3;
    Student student4 = {0}; 
    Student student5 = {0};

    strcpy(student5.name, "Ron");
    student5.age = 20;
    student5.gpa = 8.5;
    student5.isFullTime = true;

    printf("%s\n", student1.name);
    printf("%d\n", student1.age);
    printf("%.2f\n", student1.gpa);
    printf("%d\n", student1.isFullTime);
    printf("%s\n", (student1.isFullTime) ? "Yes" : "No");

    printf("\n");

    printf("%s\n", student2.name);
    printf("%d\n", student2.age);
    printf("%.2f\n", student2.gpa);
    printf("%d\n", student2.isFullTime);
    printf("%s\n", (student2.isFullTime) ? "Yes" : "No");

    printf("\n");

    printf("%s\n", student3.name);
    printf("%d\n", student3.age);
    printf("%.2f\n", student3.gpa);
    printf("%d\n", student3.isFullTime);
    printf("%s\n", (student3.isFullTime) ? "Yes" : "No");

    printf("\n");

    printf("%s\n", student4.name);
    printf("%d\n", student4.age);
    printf("%.2f\n", student4.gpa);
    printf("%d\n", student4.isFullTime);
    printf("%s\n", (student4.isFullTime) ? "Yes" : "No");

    printf("\n");
    
    printf("%s\n", student5.name);
    printf("%d\n", student5.age);
    printf("%.2f\n", student5.gpa);
    printf("%d\n", student5.isFullTime);
    printf("%s\n", (student5.isFullTime) ? "Yes" : "No");
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printStudent(student1);
    printStudent(student2);
    printStudent(student3);
    printStudent(student4);
    printStudent(student5);
    
    return 0;
}

void printStudent(Student student){
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %.2f\n", student.gpa);
    printf("Full-time: %d\n", student.isFullTime);
    printf("Full-time: %s\n", (student.isFullTime) ? "Yes" : "No");
    printf("\n");
}