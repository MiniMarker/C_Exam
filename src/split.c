#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/dictionary.h"

SplittedPassword splitHash(char hash[35]) {

    SplittedPassword res;

    snprintf(res.salt, 13, "%s", hash);

    //strrchr reads the char* from back until it hits a specified delimiter
    char *hashextract = (strrchr(hash, '$') + 1);
    strncpy(res.hash, hashextract, 22);

    return res;
}

int splitGivenHash(char *hash) {

    SplittedPassword passStruct = splitHash(hash);
    char hackyHash[23];
    
    printf("Now searching for %s\n", hash);

    //Bug in code, the returned value in passStruct was of length 25 when user inputted a hash, needed to hack a solution...
    snprintf(hackyHash, 23, "%s", passStruct.hash);

    lookupHashInDictionary(passStruct.salt, hackyHash);

    return 0;
}