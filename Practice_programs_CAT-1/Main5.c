/*
    An e-commerce store offers the following discount rules:

    | Purchase Amount (Rs) | Discount (%) |
    | -------------------- | ------------ |
    | 50,001 and more      | 15%          |
    | 25,001 to 50,000     | 10%          |
    | 10,001 to 25,000     | 8%           |
    | 5,001 to 10,000      | 5%           |
    | 0 to 5,000           | 0%           |

    Write a C program to accept the purchase amount in Rupees. Display how much amount has to be paid after discount and show the saved amount.
    Example:
    Input in Rs: 18250
    Output: Pay 16790 Amount Saved 1460
*/


#include <stdio.h>

int main(){
    float n = 0.0f;
    printf("Input in Rs: ");
    scanf("%f", &n);
    float save = 0.0f;
    if(n > 50000){
        save = (0.15 * n);
    }else if(n > 25000 && n<=50000){
        save = (0.10 * n);
    }else if(n > 10000 && n<=25000){
        save = (0.08 * n);
    }else if(n > 5000 && n <= 10000){
        save = (0.05 * n);
    }else if(n >=0 && n <= 5000){
        save = 0;
    }else{
        printf("Invalid purchase!");
        return 1;
    }
    printf("Pay: %.2f\tAmount saved: %.2f", (n-save), save);
    return 0;
}