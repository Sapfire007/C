/*
Write a recursive C program that generates all possible permutations of a given string. The program
should take a string as input and output all unique arrangements of the characters in that string.
program should ensure that duplicate permutations are not printed, even if the input string contains
duplicate characters.
Sample Input and Output:
Enter a string: "ABC"
Output: "ABC", "ACB", "BAC", "BCA", "CBA", "CAB"
Sample Input and Output:
Enter a string: AAC
All unique permutations are: AAC ACA CAA
*/


#include <stdio.h>
#include <string.h>

// swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// check if a character is repeated in the current position
int shouldSwap(char str[], int start, int curr) {
    for(int i = start; i < curr; i++) {
        if(str[i] == str[curr])
            return 0;   // duplicate found → don’t swap
    }
    return 1;
}

void permute(char str[], int l, int r) {
    if(l == r) {
        printf("%s ", str);
        return;
    }

    for(int i = l; i <= r; i++) {
        if(shouldSwap(str, l, i)) { // only swap if not duplicate
            swap(&str[l], &str[i]);
            permute(str, l + 1, r);
            swap(&str[l], &str[i]); // backtrack
        }
    }
}

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);

    printf("All unique permutations are: ");
    permute(str, 0, n - 1);

    return 0;
}