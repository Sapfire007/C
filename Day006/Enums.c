#include <stdio.h>

enum Day{
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
    // 0,     1,       2,       3,         4,       5,        6
};

int main(){
    // enum = A user-defined data type that consists 
    //        of a set of named integert constants.
    //        Benefit: Replaces numbers with readable names

    // SUNDAY = 0;
    // MONDAY = 1;
    // TUESDAY = 2;

    enum Day today = FRIDAY;
    printf("%d", today);


    return 0;
}