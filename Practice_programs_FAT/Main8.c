/*
Let us write a simple C program that will read in a sequence of ASCII characters and write out a
sequence of encoded characters in its place. If a character is a letter or a digit, we will replace it with
the next character in the character set, except that Z will be replaced by A, z by a, and 9 by 0. Thus 1
becomes 2, C becomes D, p becomes q, and so on. Any character other than a letter or a digit will be
replaced by a period(.).
Sample Input and Output:
Enter a line of text below:
The White House
Uif.Xijuf.Ipvtf.
*/

#include <stdio.h>
#include <ctype.h>

int main(){
    char str[200];
    printf("Enter a line of text below: \n");
    scanf("%[^\n]", &str);

    for(int i = 0; str[i] != '\0'; i++){
        char c = str[i];

        if(isdigit(c)){
            if(c=='9'){
                printf("0");
            } else{
                printf("%c", c+1);
            }
        } else if (isalpha(c)){
            if(c == 'Z'){
                printf("A");
            } else if (c == 'z'){
                printf("a");
            } else{
                printf("%c", c+1);
            }
        } else {
            printf(".");
        }
    }

    return 0;
}