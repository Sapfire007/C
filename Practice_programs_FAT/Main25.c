/*
Write a C program that simulates a smart energy meter for a household. The program should
calculate the bill based on the following:

a. Input: Number of units consumed (float) and user type (Residential/Commercial).
b. Billing:
· Residential: First 100 units at Rs. 2.50/unit, above 100 at Rs. 3.50/unit.
· Commercial: First 200 units at Rs. 5.00/unit, above 200 at Rs. 6.00/unit.
c. Discount: 10% discount if consumption exceeds 500 units.
d. Check if the final bill is within the budget of Rs. 650.

Sample Input:
Enter number of units consumed: 120
Enter user type (Residential/Commercial): Residential
Sample Output:
Final Bill: Rs. 320.00 Discount: Rs. 0.00
The bill is within the budget of Rs. 650.
*/

#include <stdio.h>
#include <string.h>

int main() {
    float units, bill = 0, discount = 0;
    char type[20];

    printf("Enter number of units consumed: ");
    scanf("%f", &units);

    printf("Enter user type (Residential/Commercial): ");
    scanf("%s", type);

    // Billing calculation
    if (strcmp(type, "Residential") == 0) {
        if (units <= 100){
            bill = units * 2.50;
        }
        else{
            bill = (100 * 2.50) + ((units - 100) * 3.50);
        }
    }
    else if (strcmp(type, "Commercial") == 0) {
        if (units <= 200){
            bill = units * 5.00;
        }
        else{
            bill = (200 * 5.00) + ((units - 200) * 6.00);
        }
    }
    else {
        printf("Invalid User Type!");
        return 1;
    }

    // Discount if units > 500
    if (units > 500) {
        discount = bill * 0.10;
        bill = bill - discount;
    }

    // Output
    printf("Final Bill: Rs. %.2f  Discount: Rs. %.2f\n", bill, discount);

    // Budget check
    if (bill <= 650){
        printf("The bill is within the budget of Rs. 650.\n");
    }
    else{
        printf("The bill exceeds the budget of Rs. 650.\n");
    }

    return 0;
}