#include <stdio.h>

int main(){
    // TEMPERATURE CONVERSION PROGRAM
    
    char choice = '\0';
    float fahrenheit = 0.0f;
    float celsius = 0.0f;

    printf("Temperature Conversion Program");
    printf("C. Celcius to Fahrenheit");
    printf("F. Fahrenheit to Celcius");
    printf("Is the temp in Celsius (c) or Fahrenheit(f)?: ");
    scanf("%c", &choice);

    if(choice=='c'){
        // C to F
        printf("Enter the temperature in Celcius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9/5) + 32; // C to F
        printf("%.1f Celcius is equal to %.1f Fahrenheit.\n", celsius, fahrenheit);
    }
    else if(choice=='f'){
        // F to C
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32)*(5/9.0);
        printf("%.1f Fahrenheit is equal to %.1f Celcius.\n", fahrenheit, celsius);
    }
    else{
        printf("Invalid choice! Please select C or F\n");
    }

    return 0;
}