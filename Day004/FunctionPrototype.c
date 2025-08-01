#include <stdio.h>
#include <stdbool.h>

void hello(char name[], int age);
bool ageCheck(int age);

int main(){
    // function prototype = Provide the compiler w/ information about a function's:
    //                      name, return type, and parameters before its actual definition.
    //                      Enables type checking and allows functions to be used before they're defined.
    //                      Improves readibility, organization, and helps prevent errors. 

    hello("Saptarshi", 18);
    if(ageCheck(30)){
        printf("You're an adult");
    }
    else{
        printf("You're a minor");
    }
    return 0;
}

void hello(char name[], int age){
    printf("Hello %s\n", name);
    printf("You are %d years old\n", age);
}

bool ageCheck(int age){
    if(age>=18){
        return true;
    }
    else{
        return false;
    }
}