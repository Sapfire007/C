#include <stdio.h>

int lucky = 7; // GLOBAL SCOPE

int add(int x, int y){
    int result = x + y;
    return result;
}

int subtract(int x, int y){
    int result = x - y;
    return result;
}

int main(){
    // variable scope = Refers to where a variable is recognized and accessible.
    //                  Variables can share the same name if
    //                  they're in different scopes {}

    int result1 = 0; // LOCAL
    int result2 = 1;
    int result = add(3, 4);
    printf("%d\n", result);
    int result3 = subtract(3, 4);
    printf("%d\n", result3);
    return 0;
}