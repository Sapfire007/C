#include <stdio.h>
#include <time.h>
#include <stdbool.h>
// #include <unistd.h>
#include <windows.h>

int main(){
    // DIGITAL CLOCK

    time_t rawtime = 0; // Jan 1 1970 (Epoch)
    struct tm *pTime = NULL;
    bool isRunning = true;

    printf("DIGITAL CLOCK\n");

    while (isRunning)
    {
        time(&rawtime);
        
        // printf("%ld\n", rawtime);
        // printf("Test run\n");
        pTime = localtime(&rawtime);

        printf("\r%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);

        Sleep(1000); 
    }
    
    return 0;
}