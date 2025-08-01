#include <stdio.h>
#include <stdbool.h>

int main(){

    // ternary operator ?= shorthand for if-else statements

    // (condition) ? value_if_true : value_if_false;

    int x = 5;
    int y = 6;
    int max = (x > y) ? x : y;

    printf("%d\n", max);

    bool isOnline = false;
    printf("%s\n", (isOnline) ? "online" : "offline");

    int number = 7;
    printf("%d is %s\n", number, (number%2 == 0) ? "even" : "odd");

    int age = 18;
    printf("%s\n", (age >= 18) ? "adult" : "minor");

    int hours = 11;
    int minutes = 40;
    char *meridiem = (hours < 12) ? "AM" : "PM";
    printf("%02d:%02d %s", hours, minutes, meridiem);

    return 0;
}