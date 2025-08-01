#include <stdio.h>

typedef enum{
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
    // 0,     1,       2,       3,         4,       5,        6
}Day;

int main(){
    // enum = A user-defined data type that consists 
    //        of a set of named integert constants.
    //        Benefit: Replaces numbers with readable names

    // SUNDAY = 0;
    // MONDAY = 1;
    // TUESDAY = 2;

    Day today = FRIDAY;
    printf("%d\n", today);
    if(today == SUNDAY || today == SATURDAY){
        printf("It's the weekend");
    }
    else{
        printf("It's a weekday");
    }


    return 0;
}