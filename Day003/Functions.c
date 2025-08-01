#include <stdio.h>
#include <string.h>

int add(int num1, int num2){
    return num1 + num2;
}

void happyBirthday(char name[], int age){
    printf("\nHappy birthday to you!");
    printf("\nHappy birthday to you!");
    printf("\nHappy birthday dear %s!", name);
    printf("\nHappy birthday to you!");
    printf("\nYou are %d years old\n", age);
}

int getMax(int x, int y){
    if(x >= y){
        return x;
    }
    else{
        return y;
    }
}

int main(){

    // function = A resuable section of code that can be invoked "called"
    //            Arguments can be sent to a function so that it can use them

    printf("%d\n", add(2, 5));
    
    char name[50] = "";
    int age = 0;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("Enter your age: ");
    scanf("%d", &age);

    happyBirthday(name, age);

    int max = getMax(7, 45);
    printf("%d", max);

    return 0;
}