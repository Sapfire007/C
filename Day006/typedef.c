#include <stdio.h>

typedef int Number;
typedef char String[50];
typedef char Initials[3]; // 3 :- 1 for 1st name 2 for 2nd name 3 for null terminator value '\0' 

int main(){

    // typedef = reserved keyword that gives an existing datatype a "nickname"
    //           Helps simplify complex types and improves code readability
    
    //           typedef existing_type new_name;

    Number x = 4;
    Number y = 7;
    Number z = x + y;
    printf("%d\n", z);

    // char name[] = "Saptarshi Bose";
    // printf("%s", name);
    String name = "Saptarshi Bose";
    printf("%s\n", name);

    Initials user1 = "SB";
    Initials user2 = "AR";
    Initials user3 = "RK";
    Initials user4 = "SM";

    printf("%s\n", user1);
    printf("%s\n", user2);
    printf("%s\n", user3);
    printf("%s\n", user4);

    return 0;
}