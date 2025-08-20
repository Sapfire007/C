/*
    Write a C program that will read in a sequence of ASCII characters and write out a sequence of encoded characters in its place. 
    If a character is a letter or a digit, replace it with the next character in the character set, except that Z should be replaced by A, z by a, and 9 by 0. 
    Thus, 1 becomes 2, C becomes D, p becomes q, and so on. 
    Any character other than a letter or a digit should be replaced by a period (.).

    Sample Input and Output:
    Enter a line of text below:
    The White House
    Uif.Xijuf.Ipvtf.

*/


#include <stdio.h>
#include <ctype.h>   // for isalpha, isdigit

int main() {
    char text[1000];

    printf("Enter a line of text below:\n");
    fgets(text, sizeof(text), stdin);  // read a line including spaces

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z') {
            // Uppercase letters
            if (c == 'Z')
                text[i] = 'A';
            else
                text[i] = c + 1;
        }
        else if (c >= 'a' && c <= 'z') {
            // Lowercase letters
            if (c == 'z')
                text[i] = 'a';
            else
                text[i] = c + 1;
        }
        else if (c >= '0' && c <= '9') {
            // Digits
            if (c == '9')
                text[i] = '0';
            else
                text[i] = c + 1;
        }
        else if (c == '\n') {
            // keep newline as it is
            continue;
        }
        else {
            // Any other character -> period
            text[i] = '.';
        }
    }

    printf("%s", text);
    return 0;
}