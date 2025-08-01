#include <stdio.h>

int main(){

    // format specifier = Special tokens that begin with a % symbol,
    //                    followed by a character that specifies the data type
    //                    and optional modifiers (width, precision, flags).
    //                    They control how data is displayed or interpreted.

    int age = 25;
    int price = 19.99;
    double pi = 3.1415926535;
    char currency = '$';
    char name[] = "Saptarshi Bose";

    printf("%d\n", age);
    printf("%f\n", price);
    printf("%lf\n", pi);
    printf("%s\n", name);

    // width

    int num1 = 1;
    int num2 = 10;
    int num3 = 100;
    
    printf("%3d\n", num1);
    printf("%3d\n", num2);
    printf("%3d\n", num3);
    
    printf("%-3d\n", num1);
    printf("%-3d\n", num2);
    printf("%-3d\n", num3);
    
    printf("%03d\n", num1);
    printf("%03d\n", num2);
    printf("%03d\n", num3);
    
    int num4 = 7;
    int num5 = 14;
    int num6 = -75;

    printf("%+d\n", num4);
    printf("%+d\n", num5);
    printf("%+d\n", num6);

    // precision 

    float price1 = 19.99;
    float price2 = 1.50;
    float price3 = -100.00;
    
    printf("%.1f\n", price1);
    printf("%f\n", price2);
    printf("%f\n", price3);
    
    // width precision flag
    
    float price4 = 19.99;
    float price5 = 1.50;
    float price6 = -100.00;
    printf("%+7.2f\n", price4);
    printf("%+7.2f\n", price5);
    printf("%+7.2f\n", price6);

    return 0;
}