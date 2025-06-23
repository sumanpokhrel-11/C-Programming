#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randint(int max) {
    return (rand() % max) + 1; 
}
int main() {
    srand(time(NULL)); // Seed the random number generator
    int randomNumber = randint(100);
    int num;
    printf("Enter a number between 1 and 100: ");
    scanf("%d", &num);
   do {
    if(num < 1 || num > 100) {
        printf("Please enter a valid number between 1 and 100.\n");
    } else if(num < randomNumber) {
        printf("Too low! Try again: ");
    } else if(num > randomNumber) {
        printf("Too high! Try again: ");
    }
    scanf("%d", &num);
   }
   while(num!= randomNumber);

    printf("Congratulations! You guessed the number %d.\n", randomNumber);
    return 0;
}
