#include <stdio.h>
#include <string.h>

int main(){
    // Array of Strings
    char fruits[][10] = {
        "Apple",
        "Banana",
        "Coconut"
    };

    char fruit[][10] = {
        {'A', 'p', 'p', 'l', 'e', '\0', '\0', '\0', '\0'},
        {'B', 'a', 'n', 'a', 'n', 'a', '\0', '\0', '\0', '\0'},
        {'C', 'o', 'c', 'o', 'n', 'u', 't', '\0', '\0', '\0'}
    };

    fruits[0][0] = 'e';
    fruits[0][4] = 'A';

    fruits[2][0] = 't';
    fruits[2][6] = 'C';

    int size = sizeof(fruits) / sizeof(fruits[0]);
    for(int i = 0; i < size; i++){
        printf("%s\n", fruits[i]);
    }

    // EXERCISE

    char names[3][25] = {0};   // Can hold 3 names of string length 25
    // printf("Enter a name: ");
    // fgets(names[0], sizeof(names[0]), stdin);
    // names[0][strlen(names[0]) - 1] = '\0';
    
    int rows = sizeof(names) / sizeof(names[0]);
    for(int i = 0; i < rows; i++){
        printf("Enter a name: ");
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strlen(names[i]) - 1] = '\0';
    }

    for(int i = 0; i < rows; i++){
        printf("%s\n", names[i]);
    }

    return 0;
}