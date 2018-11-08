#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <crypt.h>

#include "../include/dictionary.h"

SplittedPassword splitHash(char hash[35]) {

    SplittedPassword res;

    //extract salt and hash
    //strrchr reads the char* from back until it hits a specified delimiter
    snprintf(res.salt, 13, "%s", hash);

    char *hashextract = (strrchr(hash, '$') + 1);
    strncpy(res.hash, hashextract, 22);

    return res;
}

int splitGivenHash(char *hash) {

    SplittedPassword passStruct = splitHash(hash);
    char hackyHash[23];
    
    printf("Now searching for %s\n", hash);

    //Bug in code, the returned value in passStruct was of length 25, needed to hack a solution...
    snprintf(hackyHash, 23, "%s", passStruct.hash);

    lookupHashInDictionary(passStruct.salt, hackyHash);

    return 0;
}

int getHashFromFile(int mode) {
    FILE    *hashFile;
    char    *hashFilePath = "./src/resources/hashes.txt";
    char    readPasswordBuffer[35];
    
    hashFile = fopen(hashFilePath, "r");
    assert(hashFile != NULL);
    
    for(int i = 0; i < 9; i++) {

        printf("Looking for matches for line %d\n", i);
        
        fscanf(hashFile, "%s", readPasswordBuffer);

        // only lookup line 2 in list for now
        // TODO remove this if closure
        if(i == 1) {

            SplittedPassword passStruct = splitHash(readPasswordBuffer);

            lookupHashInDictionary(passStruct.salt, passStruct.hash);
        }
    }
    
    fclose(hashFile);
    return 0;
}

int lookupHashInDictionary(char salt[13], char hash[22]){
    char    line[40], 
            encryptedLookup[35];
    FILE    *dictionary_file;

    dictionary_file = fopen("./src/resources/dictionary.txt", "r");
    assert(dictionary_file != NULL);

    while (fgets(line, sizeof(line), dictionary_file) != 0) { 

        //remove \n from the end of the line
        strtok(line, "\n");

        strncpy(encryptedLookup, crypt(line, salt), 35);
        
        // only chext the last 22 chars to compare the hash
        if(strcmp(&encryptedLookup[12], hash) == 0) {
            printf("FOUND: %s    =   %s\n", encryptedLookup, line);
            break;
        }
    }

    fclose(dictionary_file);
    return 0;
};