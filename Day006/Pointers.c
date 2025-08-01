#include <stdio.h>

void birthday(int *age);

int main(){

    // pointer = A variable that stores the memory address of another variable.
    //           Benefit: They help avoid wasting memory by allowing you to pass
    //           the address of a large data structure instead of copying the entire data.

    int age = 18;
    // printf("%p", &age); // %p is used to point a pointer addeess

    int *pAge = &age;   // * = dereference operator; & = gives you the address

    printf("%p\n", &age);
    printf("%p\n", pAge);

    birthday(pAge);
    printf("You are %d years old", age);

    return 0;
}

void birthday(int *age){
    // pass by reference
    (*age)++;
}