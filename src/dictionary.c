#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <crypt.h>

#include "../include/dictionary.h"

SplittedPassword splitHash(char *hash) {

    SplittedPassword res;

    //extract salt and hash
    //strrchr reads the char* from back until it hits a specified delimiter
    snprintf(res.salt, 13, "%s", hash);
    strncpy(res.hash, (strrchr(hash, '$') + 1), 22);

    return res;
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

            //printf("salt: %s\n", passStruct.salt);
            //printf("hash: %s\n", passStruct.hash);

            // TODO reomove this
            if(mode == 1) {
                lookupHashInDictionary(passStruct.salt, passStruct.hash);
            } else {
                printf("bruteforce");
                //bruteforce(salt, hashedPassword, readPasswordBuffer);
            }
        }
    }

    //free()
    fclose(hashFile);
    return 0;
}

int lookupHashInDictionary(char salt[13], char hash[22]){
    char    line[20], 
            encryptedLookup[35];
    FILE    *dictionary_file;

    dictionary_file = fopen("./src/resources/dictionary.txt", "r");
    assert(dictionary_file != NULL);

    printf("salt: %s\n", salt);
    printf("hash: %s\n", hash);

    
    while (fgets(line, sizeof(line), dictionary_file) != 0) { 

        //remove \n from the end of the line
        strtok(line, "\n");

        //encrypt line with salt from hash file and save result in encryptedLookup
        strncpy(encryptedLookup, crypt(line, salt), 35);
        
        //printf("encrypted: %s   -   original: %s\n", encryptedLookup, line);
        // only chext the last 22 chars to compare the hash
        if(strcmp(&encryptedLookup[12], hash) == 0) {
            printf("FOUND: %s    =   %s\n", encryptedLookup, line);
            break;
        }
    }

    fclose(dictionary_file);
    return 0;
};

int main(int argc, char const *argv[]) {

    // TODO if no argument is sent in with main, look up all hashes in file. Else look up given hash
    // TODO Threads

    argv[1] == NULL ? getHashFromFile(1) : printf("Now looking up given hash\n");

    //getHashFromFile(1);
    //bruteforce();
    return 0;
};