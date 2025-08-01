#include <stdio.h>

int main(){
    // break = Break out of a loop (STOP)
    // continue = Skip current cycle of a loop (SKIP)

    for(int i = 1; i <= 10; i++){
        if(i==4){
            break;
        }

        printf("%d\n", i);
    }
    for(int i = 1; i <= 20; i++){
        if(i==13) continue;
        printf("%d\n", i);
    }
    return 0;
}