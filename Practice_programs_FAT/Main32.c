/*
Imagine you are designing a simple vending machine control system in C programming. The
vending machine accepts three types of coins: 1 rupee, 2 rupees, and 5 rupees. Each time a coin is
inserted, the machine should add it to the total amount collected so far. After updating the total,
the machine should display the current amount to the user. Using selection statements, the program
must also check whether the total amount is a prime number when total is greater than 10. If it is
prime, the machine should display a special message indicating that the user has reached a prime
total amount. The main function should accept the input from the user until total amount reaches 10.
*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int total = 0;
    int inp;
    printf("Insert 1 Rs / 2Rs / 5 Rs coin: \n");

    do{
        scanf("%d", &inp);
        if(inp != 1 && inp!= 2 && inp!= 5){
            printf("Insert a valid coin!\n");
            continue;
        }
        total += inp;

        printf("Current total: %d\n", total);

        if(total > 10){
            bool chkPrime = true;
            for(int i = 2; i <= total/2; i++){
                if(total % i == 0){
                    chkPrime = false;
                    break;
                }
            }
            if(chkPrime){
                printf("You have reached a PRIME total (%d)!\n", total);
            }
        }
    } while(total<10);

    printf("Total amount entered: %d\n", total);

    bool chk = true;
    for(int i = 2; i <= total/2; i++){
        if(total % i == 0){
            chk = false;
            break;
        }
    }

    if(chk){
        printf("You have entered a prime total of: Rs. %d", total);
    }

    return 0;
}