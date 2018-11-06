#include <stdlib.h>
#include <stdio.h>

#include "../include/dictionary.h"

int main(int argc, char *argv[]) {

    // TODO if no argument is sent in with main, look up all hashes in file. Else look up given hash
    // TODO Threads

    // argv[1] NEEDS TO BE IN SINGLE QUOTES!!
        // ./bin/dictionary '$1$ckvWM6T@$H6H/R5d4a/QjpB02Ri/V01'

    argv[1] == NULL ? getHashFromFile(1) : lookupGivenHash(argv[1]);

    return 0;
};