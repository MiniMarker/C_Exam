#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/dictionary.h"

static char *passchar = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@$|[]|{}";

int loop(char *str, int index, char *salt, char *hash){

    char encryptedWord[35];

    for(int i = 0; i < strlen(passchar); i++) {

        str[index] = passchar[i];

        strcpy(encryptedWord, crypt(str, salt));

        //printf("str: %s, encrypted = %s\n", str, encryptedWord);
        
        if(strcmp(&encryptedWord[12], hash) == 0) {
            printf("FOUND: %s    =   %s\n", encryptedWord, str);
            exit(0);
            return 0;
        }

        if(index - 1 >= 0) {
            loop(str, index - 1, salt, hash);
        }
    }

    return 1;
}

int bruteforceEntry(char *salt, char *hash) {

    int     maxLength = 5;
    char    *currentGuess = calloc(maxLength + 1, sizeof(char));

    for(int i = 0; i < maxLength; i++) {
        loop(currentGuess, i, salt, hash);
    }

    free(currentGuess);
    return 0;
}