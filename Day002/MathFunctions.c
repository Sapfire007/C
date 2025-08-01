#include <stdio.h>
#include <math.h>

int main(){
    int x = 49;
    x = sqrt(x);
    printf("%d\n", x);
    x = pow(x, 2);
    printf("%d\n", x);
    float y = 3.14159;
    y = round(y);
    printf("%f\n", y);
    y = ceil(3.14159);
    printf("%f\n", y);
    y = floor(3.99);
    printf("%f\n", y);
    y = abs(-3);
    printf("%f\n", y);
    y = log(3);
    printf("%f\n", y);
    y = sin(3);
    printf("%f\n", y);
    y = cos(45);
    printf("%f\n", y);
    y = tan(45);
    printf("%f\n", y);
    return 0;
}