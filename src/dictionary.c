#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <crypt.h>

#include "../include/dictionary.h"

int lookupHashInDictionary(char salt[13], char hash[22]){
    char    line[40], 
            encryptedLookup[35];
    FILE    *dictionary_file;

    dictionary_file = fopen("./src/resources/dictionaryFull.txt", "r");
    assert(dictionary_file != NULL);

    while (fgets(line, sizeof(line), dictionary_file) != 0) { 

        //remove \n from the end of the line
        strtok(line, "\n");

        strncpy(encryptedLookup, crypt(line, salt), 35);
        
        // only chext the last 22 chars to compare the hash
        if(strcmp(&encryptedLookup[12], hash) == 0) {
            printf("FOUND: %s    =   %s\n", encryptedLookup, line);
            return 0;
        }
    }

    printf("End of dictionary file, no match found\n");
    printf("Starting bruteforce...\n");
    
    bruteforceEntry(salt, hash);

    fclose(dictionary_file);
    return 0;
};

/*
//This is a method for getting hashes from a file, for reason why this isnt implemented please see README

int getHashFromFile() {
    FILE    *hashFile;
    char    *hashFilePath = "./src/resources/hashes.txt";
    char    readPasswordBuffer[35];
    
    hashFile = fopen(hashFilePath, "r");
    assert(hashFile != NULL);
    
    for(int i = 0; i < 9; i++) {

        if(i == 1) {

            printf("Looking for matches for line %d\n", i);
        
            fscanf(hashFile, "%s", readPasswordBuffer);

            SplittedPassword passStruct = splitHash(readPasswordBuffer);

            lookupHashInDictionary(passStruct.salt, passStruct.hash);

        }
    }
    
    fclose(hashFile);
    return 0;
}
*/