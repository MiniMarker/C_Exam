#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <crypt.h>

//static char *passchar = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@$|[]|{}";
static char *passchar = "ikjlmnopqrstuvwxyzABCDEF";
static char *salt = "$1$9779ofJE$";

char *concatinateString(char *s1, char *s2) {
  char *res = malloc(sizeof(s1) + sizeof(s2));

  strcpy(res, s1);
  strcat(res, s2);

  return res;
}

void loop(char *currentGuess, int index, int length){
    char encryptedWord[35];
    
    if(length == 0) {

        printf("currentGuess: %s\n", currentGuess);

        /*
        strcpy(encryptedWord, crypt(currentGuess, salt));

        printf("currentGuess: %s, encrypted = %s\n", currentGuess, encryptedWord);

        if(strcmp(encryptedWord, "$1$9779ofJE$c.p.EwsI57yV2xjeorQbs1") == 0) {
            printf("FOUND: %s    =   %s\n", encryptedWord, currentGuess);
            return;
        }
        */

       //printf("index: %d....      currentGuess: %s....\n", index, currentGuess);

    } else {
        for(int i = 0; i < strlen(passchar); i++) {

            char c = passchar[i];
            //printf("c = %c\n", c);
            char *combined = concatinateString(currentGuess, &c);

            //printf("i: %d....      currentGuess: %s....      &c: %s....     combined: %s\n", i, currentGuess, &c, combined);
            loop(combined, index, length - 1);

            free(combined);
        }
    }
}


int main(int argc, char const *argv[]) {

    int     maxLength = 2;
    char    currentGuess[] = "";

    for(int i = 0; i <= maxLength; i++) {
        loop(currentGuess, 0, i);
    }

    return 0;
};