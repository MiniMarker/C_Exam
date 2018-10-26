#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <crypt.h>

int getHashFromFile();
int lookupHashInDictionary(char salt[13], char hash[22], char fullHash[35]);

typedef struct {
    char    salt[13];
    char    hash[22];
} HashedPassword;

int getHashFromFile() {
    FILE    *hashFile;
    char    *hashFilePath = "./src/resources/hashes.txt";
    char    readPasswordBuffer[35];
    
    hashFile = fopen(hashFilePath, "r");
    
    for(int i = 0; i < 9; i++) {
        
        fscanf(hashFile, "%s", readPasswordBuffer);

        // only lookup line 2 in list for now
        if(i == 1) {
            char    hashedPassword[22], 
                    salt[13];

            //printf("%s\n", readPasswordBuffer);
        
            //extract salt and hash
            //strrchr reads the char* from back until it hits a specified delimiter
            snprintf(salt, 13, readPasswordBuffer);
            strncpy(hashedPassword, (strrchr(readPasswordBuffer, '$') + 1), 22);
 
            //printf("salt: %s\n", salt);
            //printf("hash: %s\n", hashedPassword);
            //printf("------------\n");

            lookupHashInDictionary(salt, hashedPassword, readPasswordBuffer);
        }
    }

    fclose(hashFile);
    
    return 0;
}

int lookupHashInDictionary(char salt[13], char hash[22], char fullHash[35]){
    char    line[20], 
            encryptedLookup[35], 
            hashPassLookup[22];
    FILE    *dictionary_file;

    //open file and assert it`s success
    dictionary_file = fopen("./src/resources/dictionary.txt", "r");
    assert(dictionary_file != NULL);
    
    while (fgets(line, sizeof(line), dictionary_file) != 0) { 

        //remove \n from the end of the line
        strtok(line, "\n");

        //encrypt line with salt from hash file and save result in encryptedLookup
        strncpy(encryptedLookup, crypt(line, salt), 35);
        
        //printf("encrypted: %s   -   original: %s\n", encryptedLookup, line);

        if(strcmp(encryptedLookup, fullHash) == 0) {
            printf("FOUND: %s    =   %s\n", encryptedLookup, line);
            break;
        }
    }

    fclose(dictionary_file);
    return 0;
};


int main(int argc, char const *argv[]) {

    getHashFromFile();

    return 0;
}
