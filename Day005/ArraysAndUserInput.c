#include <stdio.h>

int main(){

    int scores[5];
    for(int i = 0; i < 5; i++){
        printf("%d\t", scores[i]);
    }

    printf("\n");
    
    int scores2[5] = {0};
    for(int i = 0; i < sizeof(scores2)/sizeof(scores2[0]); i++){
        printf("%d\t", scores2[i]);
    }
    
    printf("\n");
    
    for(int i = 0; i < sizeof(scores2)/sizeof(scores2[0]); i++){
        printf("Enter a score for index position %d: ", i);
        scanf("%d", &scores2[i]);
    }
    printf("\n");
    printf("Your array: ");
    for(int i = 0; i < sizeof(scores2)/sizeof(scores2[0]); i++){
        printf("%d\t", scores2[i]);
    }

    return 0;
}