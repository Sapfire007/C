/*
    Imagine you are developing a fan speed control system in C programming. The fan has four states:
    OFF (0), LOW (1), MEDIUM (2), and HIGH (3). 
    Depending on the current state, the system should determine the next speed level in a cyclic manner (OFF - LOW - MEDIUM- HIGH - OFF).
    You can use selection statements to control the flow of this logic. 
    The delay between each state change can be simulated using dummy loops for up to 10 iterations and your program stops iterating when
    "The current fan speed is HIGH, next speed level is OFF."

    Input: current_state = 1

    Output: "The current fan speed is LOW, next speed level is MEDIUM."
    "The current fan speed is MEDIUM, next speed level is HIGH."
    "The current fan speed is HIGH, next speed level is OFF."

*/


#include <stdio.h>
#include <windows.h>

int main() {
    int current_state = 1; // starting from LOW
    int i;

    // Iterate maximum 10 times
    for (i = 0; i < 10; i++) {
        switch (current_state) {
            case 0: // OFF
                printf("The current fan speed is OFF, next speed level is LOW.\n");
                current_state = 1;
                break;

            case 1: // LOW
                printf("The current fan speed is LOW, next speed level is MEDIUM.\n");
                current_state = 2;
                break;

            case 2: // MEDIUM
                printf("The current fan speed is MEDIUM, next speed level is HIGH.\n");
                current_state = 3;
                break;

            case 3: // HIGH
                printf("The current fan speed is HIGH, next speed level is OFF.\n");
                current_state = 0;
                break;
        }

        if (current_state == 0) {
            break;
        }
        
        Sleep(10000);
    }

    return 0;
}