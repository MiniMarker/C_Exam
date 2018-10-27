#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/dictionary.h"

int bruteforce(char salt[13], char hash[22], char fullHash[35]){
    printf("Entered bruteforce!\n");

    char    c;
    int     passwordLength = 10,
            passwordStartIndex = 0;
    char    *bruteforceGuess = calloc(passwordLength, sizeof(char));

    const char passchars[80] = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@$|[]|{}";
    
    for(int i = 0; i < 80; i++) {

        printf("char[%d] = %c\n", i, passchars[i]);

    }

    /*

    for(int i = 0; i < 10; i++) {

        for(int j = 33; j < 127; j++) {

            bruteforceGuess[i] = j;

            printf("bruteforceGuess: %s\n", bruteforceGuess);

            // c = j;
            //printf("ASCII char: %c\n", c);

        }

    }
    */

    free(bruteforceGuess);
    return 0;
}