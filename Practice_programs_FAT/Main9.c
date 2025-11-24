/*
Imagine you are developing a fan speed control system in C programming. The fan has four states:
OFF (0), LOW (1), MEDIUM (2), and HIGH (3). Depending on the current state, the system should
determine the next speed level in a cyclic manner (OFF -> LOW - MEDIUM - HIGH - OFF).
You can use selection statements to control the flow of this logic. The delay between each state change
can be simulated using dummy loops for up to 10 iterations and your program stops iterating when
'The current fan speed is HIGH, next speed level is OFF."
Input: current_state = 1
Output: "The current fan speed is LOW, next speed level is MEDIUM."
"The current fan speed is MEDIUM, next speed level is HIGH."
"The current fan speed is HIGH, next speed level is OFF."
*/

#include <stdio.h>
#include <time.h>
#include <Windows.h>

int main(){
    int state;
    printf("Enter current fan state (0=OFF, 1=LOW, 2=MEDIUM, 3=HIGH): ");
    scanf("%d", &state);

    for(int i = 0; i < 5; i++){

        int next;
        
        switch(state){
            case 0:
                next = 1;
                break;
            case 1:
                next = 2;
                break;
            case 2:
                next = 3;
                break;
            case 3:
                next = 0;
                break;
            default:
                printf("Invalid state.\n");
                return 1;
        }

        if(state == 0){
            printf("The current fan speed is OFF, next speed level is LOW.\n");
        }
        else if(state == 1){
            printf("The current fan speed is LOW, next speed level is MEDIUM.\n");
        }
        else if(state == 2){
            printf("The current fan speed is MEDIUM, next speed level is HIGH.\n");
        }
        else{
            printf("The current fan speed is HIGH, next speed level is OFF.\n");
        }

        if(state==3){
            break;
        }

        Sleep(1000);

        state = next;
    }
    return 0;
}