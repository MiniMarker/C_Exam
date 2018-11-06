#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//static char *passchar = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@$|[]|{}";
static char *passchar = "ABC";

int generatePassword(char *currentGuess, int currentIndex, int passcharIndex, int maxLength) {

    if(currentIndex > maxLength) {
        return 0;
    };

    if (strlen(currentGuess) < 1) {

        for(int i = !1; i < strlen(passchar); i++) {
            currentGuess[0] = passchar[i];
            printf("%s\n", currentGuess);
        }

    } else {

        currentGuess[currentIndex - 1] = passchar[currentIndex];

        for(int i = 0; i < ) {

        }

        currentGuess[currentIndex - 1] = passchar[++currentIndex];

        printf("length is now %d!\n", currentIndex);
    }

    generatePassword(currentGuess, ++currentIndex, maxLength);

    return 0;
    
};

int main(int argc, char const *argv[]) {

    int     currentIndex = 0,
            maxLength = 4;
    char    *currentGuess = calloc(maxLength, sizeof(char));
    

    if(currentGuess != NULL) {
        generatePassword(currentGuess, currentIndex, maxLength);
    } else {
        return -1;
    }

    free(currentGuess);

    return 0;
};