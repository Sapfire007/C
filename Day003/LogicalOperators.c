#include <stdio.h>
#include <stdbool.h>

void main(){
    // logical operators = Used to combine or modify boolean expressions.

    // && = AND
    // || = OR
    // ! = NOT

    int temp = 1000000;

    if(temp > 0 && temp < 30){
        printf("The temperature is GOOD\n");
    }
    else{
        printf("The temperature is BAD\n");
    }
    
    int temp2 = 20;
    if(temp2 <= 0 || temp2 >= 30){
        printf("The temperature is BAD\n");
    }
    else{
        printf("The temperature is GOOD\n");
    }

    bool isSunny = true;
    if(!isSunny){
        printf("It is CLOUDY outside");
    }
    else{
        printf("It is SUNNY outside");
    }
}