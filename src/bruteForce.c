#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/dictionary.h"

int bruteforce(char salt[13], char hash[22], char fullHash[35]){
    printf("Entered bruteforce!\n");

    char    c;
    int     passwordLength = 50,
            passwordStartIndex = 0;
    char    *bruteforceGuess = calloc(passwordLength, sizeof(char));

    //const char passchars[80] = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@$|[]|{}";
    char *passchars = "ABC";
    char buffer[3];

    free(bruteforceGuess);
    return 0;
}