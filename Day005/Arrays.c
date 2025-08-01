#include <stdio.h>

int main(){
    // array = A fixed-size collection of elements of the same data type
    //         (Similar to a variable, but it holds more than 1 value)

    int numbers[] = {10, 20, 30, 40, 50};
    printf("%d\n", numbers);
    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);
    printf("%d\n", numbers[3]);
    printf("%d\n", numbers[4]);
    
    printf("%d\n", numbers[5]);  // Garbage value

    printf("\n");

    
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    char name[] = "Saptarshi Bose";
    
    printf("%c\n", grades[0]);
    printf("%c\n", grades[1]);
    printf("%c\n", grades[2]);
    printf("%c\n", grades[3]);
    printf("%c\n", grades[4]);
    
    printf("%c\n", grades[7]);

    printf("\n");

    
    printf("%c\n", name[0]);
    printf("%c\n", name[1]);
    printf("%c\n", name[2]);
    printf("%c\n", name[3]);
    printf("%c\n", name[4]);
    printf("%c\n", name[5]);
    printf("%c\n", name[6]);
    printf("%c\n", name[7]);
    printf("%c\n", name[8]);
    printf("%c\n", name[9]);
    printf("%c\n", name[10]);
    printf("%c\n", name[11]);
    printf("%c\n", name[12]);
    printf("%c\n", name[13]);
    
    printf("%c\n", name[14]);

    printf("\n");
    
    
    numbers[0] = 4;
    numbers[1] = 7;
    numbers[2] = 14;
    numbers[3] = 17;
    numbers[4] = 25;
    printf("%d\n", numbers);
    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);
    printf("%d\n", numbers[3]);
    printf("%d\n", numbers[4]);

    printf("\n");
    
    printf("%d\n", sizeof(numbers));
    printf("%d\n", sizeof(numbers[0]));
    printf("%d\n", sizeof(numbers[1]));
    printf("%d\n", sizeof(numbers[2]));
    printf("%d\n", sizeof(numbers[3]));
    printf("%d\n", sizeof(numbers[4]));

    printf("%d\n", sizeof(numbers[8]));

    printf("\n");
    
    printf("%d\n", sizeof(grades));
    printf("%d\n", sizeof(grades[0]));
    printf("%d\n", sizeof(grades[1]));
    printf("%d\n", sizeof(grades[2]));
    printf("%d\n", sizeof(grades[3]));
    printf("%d\n", sizeof(grades[4]));

    printf("%d\n", sizeof(grades[19]));

    printf("\n");
    
    printf("%d", sizeof(name));

    printf("\n");

    int size = (sizeof(numbers) / sizeof(numbers[0]));
    for(int i = 0; i < size; i++){
        printf("%d\t", numbers[i]);
    }
    
    return 0;
}