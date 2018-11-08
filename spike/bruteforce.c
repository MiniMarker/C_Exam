#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <crypt.h>

//static char *passchar = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@$|[]|{}";
static char *passchar = "ABC";
static char *stringToFind = "BA";
//static char *salt = "$1$9779ofJE$";

int loop(char *str, int index){

    for(int i = 0; i < strlen(passchar); i++) {

        str[index] = passchar[i];

        printf("string: %s\n", str);

        if(index - 1 > 0) {
            loop(str, index - 1);
        }
    }

    return 1;
}


int main(int argc, char const *argv[]) {

    int     maxLength = 5;
    char    *currentGuess = calloc(maxLength + 1, sizeof(char));

    for(int i = 0; i < maxLength; i++) {

        if(loop(currentGuess, i) == 0) {
            printf("FOUND!!!!");
            return 0;
        }
    }

    free(currentGuess);

    return 0;
};




/*
        strcpy(encryptedWord, crypt(currentGuess, salt));

        printf("currentGuess: %s, encrypted = %s\n", currentGuess, encryptedWord);

        if(strcmp(encryptedWord, "$1$9779ofJE$c.p.EwsI57yV2xjeorQbs1") == 0) {
            printf("FOUND: %s    =   %s\n", encryptedWord, currentGuess);
            return;
        }
        */