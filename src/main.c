#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <crypt.h>

int decrypt();
int readFile(char salt[13], char hash[22], char fullPassword[35]);

typedef struct {
    char salt[13];
    char hash[22];
} HashedPassword;

int decrypt() {
    FILE *hashFile;
    char* hashFilePath = "./src/resources/hashes.txt";
    char readPasswordBuffer[35];
    
    hashFile = fopen(hashFilePath, "r");
    
    for(int i = 0; i < 9; i++) {
        
        fscanf(hashFile, "%s", readPasswordBuffer);

        if(i == 2) {
            char hashedPassword[22], salt[13];

            //printf("%s\n", readPasswordBuffer);
        
            //extract salt and hash
            //strrchr reads the char* from back until it hits a specified delimiter
            snprintf(salt, 13, readPasswordBuffer);
            strncpy(hashedPassword, (strrchr(readPasswordBuffer, '$') + 1), 22);
 
            //printf("salt: %s\n", salt);
            //printf("hash: %s\n", hashedPassword);
            //printf("------------\n");

            readFile(salt, hashedPassword, readPasswordBuffer);
        }
    }

    fclose(hashFile);
    
    return 0;
}

int readFile(char salt[13], char hash[22], char fullPassword[35]){
    char line[20], encryptedLookup[35];
    FILE *dictionary_file;

    dictionary_file = fopen("./src/resources/dictionary.txt", "r");
    
    assert(dictionary_file != NULL);
    
    while (fgets(line, sizeof(line), dictionary_file) != 0) { 

        line[strcspn(line, "\n")] = 0;

        strncpy(encryptedLookup, crypt(line, salt), 35);
        
        //printf("encrypted: %s   -   original: %s\n", encryptedLookup, line);

        if(strcmp(encryptedLookup, fullPassword) == 0) {
            printf("FOUND: %s    =   %s\n", encryptedLookup, line);
            break;
        }
    }


    fclose(dictionary_file);
    return 0;
};


int main(int argc, char const *argv[]) {

    decrypt();

    //Password pass = splitHash("$1$JTXmp2C4$nS9ySJPUyya/0ChXbDeeB.");

    return 0;
}
