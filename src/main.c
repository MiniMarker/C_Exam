#include <stdlib.h>
#include <stdio.h>

#include "../include/dictionary.h"

int main(int argc, char *argv[]) {

    if(argv[1] == NULL) {
        printf("ERROR! Please add a hash to decrypt\n");
        printf("Please see README for instructions\n");
        return -1;
    } else {
        splitGivenHash(argv[1]);
    }

    return 0;
};