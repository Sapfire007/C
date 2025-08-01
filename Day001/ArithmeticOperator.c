#include <stdio.h>

int main(){

    // arithmetic operators = + - * / % ++ --

    int x = 2;
    // int y = 3;
    float y = 3;
    // int z = 0;
    float z = 0;

    z = x + y;
    printf("%f\n",z);
    z = x - y;
    printf("%f\n",z);
    z = x * y;
    printf("%f\n",z);
    z = x / y;
    printf("%f\n",z);
    
    int a = 10;
    int b = 3;
    int c = 0;
    
    c = a % b;
    printf("%d\n", c);
    
    b++;
    printf("%d\n", b);
    b--;
    printf("%d\n", b);
    b+=2;
    printf("%d\n", b);
    b-=2;
    printf("%d\n", b);

    return 0;
}