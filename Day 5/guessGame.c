#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess, attempts = 0;
    
    /* initialize random seed and pick secret in [1,100] */
    #include <stdlib.h>
    #include <time.h>

    srand((unsigned)time(NULL));
    secret = rand() % 100 + 1;
    
    printf("I'm thinking of a number between 1 and 100.\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if(guess < secret) {
            printf("Too low! ");
        } else if(guess > secret) {
            printf("Too high! ");
        }
        
        if(guess != secret) {
            printf("Try again.\n");
        }
    } while(guess != secret);
    
    printf("Congratulations! You guessed it in %d attempts.\n", attempts);
    return 0;
}