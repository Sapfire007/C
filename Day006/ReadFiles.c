#include <stdio.h>

int main(){

    // READ A FILE

    FILE *pFile = fopen("FilesDir\\input.txt", "r");
    char buffer[1024] = {0}; 

    if(pFile == NULL){
        printf("Could not open file\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), pFile) != NULL)
    {
        printf("%s", buffer);
    }
    

    fclose(pFile);

    return 0;
}