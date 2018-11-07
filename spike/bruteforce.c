#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//static char *passchar = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@$|[]|{}";
static char *passchar = "ABC";

char *sconcat(const char *s1, const char *s2)
{
  char *s0 = malloc(strlen(s1)+strlen(s2)+1);
  strcpy(s0, s1);
  strcat(s0, s2);
  return s0;
}

void loop(char *currentGuess, int index, int length){
    
    if(length == 0) {
        printf("current guess = %s\n", currentGuess);
    } else {
        for(int i = index; i < strlen(passchar); i++) {

            char c = passchar[i];
            char combined[12], test[12];

            strcpy(test, sconcat(currentGuess, &c));

            loop(test, index, length - 1);
        }
    }
}


int main(int argc, char const *argv[]) {

    int     currentIndex = 0,
            maxLength = 3;
    //char    *currentGuess = calloc(maxLength, sizeof(char));
    char    currentGuess[] = "";

    //assert(currentGuess != NULL);

    for(int i = 0; i <= maxLength; i++) {
        loop(currentGuess, currentIndex, i);
    }
   
    //free(currentGuess);

    return 0;
};