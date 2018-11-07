#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

#define SIZE 5

int main(int argc, char const *argv[]) {

    nonRecursive();
    return 0;

};



int nonRecursive() {

    char pw[SIZE + 1] = "";
    char *ppw = NULL;
    char *pch = NULL;
    char characters[] = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int used = 0;
    int last = strlen ( characters) - 1;
    char salt[13] = "$1$ivGZShhu$";
    char encryptedWord[35];

    //set pw
    pw[used] = characters[0];
    pw[used + 1] = '\0';

    while (used < SIZE) {//loop until all elements of pw have been used
        ppw = &pw[used];//set ppw to point to last used element of pw
        while (ppw >= pw) {//so ppw always points to an element of pw
            if (( pch = strchr ( characters, *ppw)) != NULL) {//get pointer into characters for current value that ppw point to
                
                if ( pch < &characters[last]) {//pch does not point to last element of characters
                    ++pch;//pch points to next element of characters
                    *ppw = *pch;//set what ppw points to to be the same as what pch points to
                    if ( ppw != &pw[used]) {//ppw is not pointing to last element of pw
                        ppw = &pw[used];
                    }

                    strcpy(encryptedWord, crypt(pw, salt));

                    if(strcmp(encryptedWord, "$1$ivGZShhu$L/NLEkmbLWOSUTOm3cnmO/") == 0) {
                        printf("FOUND: %s    =   %s\n", encryptedWord, pw);
                        return 1;
                    }
                }
                else {//pch is pointing to last element of characters
                    *ppw = characters[0];//set what ppw points to to be the first element of characters
                    ppw--;//ppw points to next lower element of pw. ex from pw[n] to pw[n-1]
                }
            }
        }//exit loop when ppw points to address less than pw
        used++;//increase elements in use
        memset ( pw, characters[0], used);//reset all elements to first element of characters
        pw[used + 1] = '\0';//just in case, terminate
    }//exit loop when all elements have been used

    exit ( 0);

	return 0;

};