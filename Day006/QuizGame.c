#include <stdio.h>
#include <ctype.h>

int main(){

    // QUIZ GAME

    char questions[][100] = {
        "1. What is the largest planet in the solar system", 
        "2. What is the hottest planet of the solar system?",
        "3. What planet has the most moons in our solar system?",
        "4. Which planet is known as the \"Red Planet\"?"
    };

    char options[][100] = {
        "A. Jupiter\nB. Saturn\nC. Uranus\nD. Neptune",
        "A. Mercury\nB. Venus\nC. Earth\nD. Mars",
        "A. Earth\nB. Mars\nC. Jupiter\nD. Saturn",
        "A. Venus\nB. Mars\nC. Jupiter\nD. Saturn"
    };

    char answerKey[] = {'A', 'B', 'D', 'B'};

    int questionCOunt = sizeof(questions) / sizeof(questions[0]);

    char guess = '\0';
    int score = 0;

    printf("*** QUIZ GAME ***\n");
    for(int i = 0; i < questionCOunt; i++){
        printf("\n%s\n", questions[i]);
        printf("\n%s\n\n", options[i]);
        printf("Enter your choice: ");
        scanf(" %c", &guess);

        guess = toupper(guess);  // requires: #include <ctype.h>

        if(guess == answerKey[i]){
            printf("CORRECT!\n\n");
            score++;
        }
        else{
            printf("WRONG!\n\n");
        }
    }

    printf("\nYour score is %d out of %d points.\n", score, questionCOunt);

    return 0;
}