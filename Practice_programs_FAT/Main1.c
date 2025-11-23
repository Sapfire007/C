#include <stdio.h>

int main(){
    int a = 5, b = 3;
    printf("result 1 = %d\n", a+b*2);
    printf("result 2 = %d\n", a > b && b < 4);
    printf("result 3 = %d\n", !(a == b) || (b > 2));
    printf("result 4 = %d\n", ++a * b-- + a / 2);
}

// Output:
// 11
// 1
// 1
// 21