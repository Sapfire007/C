#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Pseudo-random = Appear random but are determined by a
    //                 mathematical formula that uses a seed value
    //                 to generate a predictable sequence of numbers.
    //                 advanced: Mersenne Twister or /dev/random

    printf("%d\n", rand());
    
    srand(time(NULL));
    printf("%d\n", rand());
    printf("%d\n", RAND_MAX);


    // int min = 1;
    // int max = 6;
    // int randomNum = (rand() % max) + min;
    int min = 50;
    int max = 100;
    int randomNum = (rand() % (max - min + 1)) + min;
    printf("%d\n", randomNum);

    return 0;
}