#include <stdio.h>
#include <windows.h> // Windows
// #include <unistd.h> // Linux/Mac

int main(){
    // for loop = Repeat some code a limited # of times
    //            for(Initialization; Condition; Update)

    for(int i = 0; i<= 10; i++){
        printf("%d\n", i);
    }
    for(int i = 20; i >= 0; i--){
        Sleep(1000);
        if(i==13) continue;
        printf("%d\n", i);
    }
    return 0;
}