#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <crypt.h>

typedef struct {
    char salt[13];
    char hash[22];
} Password;

int decrypt() {

    FILE *hashFile;
    char* hashFilePath = "./src/resources/hashes.txt";
    char readPasswordBuffer[35];
    
    hashFile = fopen(hashFilePath, "r");

    
    for(int i = 1; i < 2; i++) {

        char hashedPassword[22];

        fscanf(hashFile, "%s", readPasswordBuffer);

        printf("%s\n", readPasswordBuffer);

        readFile("oi");

        /*
        if(strcmp(inputHash, password) == 0){
            printf("%d: %s\n", i, password);
            break;
        }
        */
        
    }

    fclose(hashFile);
    /*
    char salt[13] = "$1$JTXmp2C4$";
    char* hash = "christian";

    char* encrypted = crypt(hash, salt);

    printf("%s\n", encrypted);
    */
    return 0;
}


int readFile(char* inputHash){
    char password[20], line[20], *filePath;
    FILE *dictionary_file;

    filePath = calloc(40, sizeof(char));
    
    snprintf(filePath, 31, "./src/resources/dictionary.txt");
    
    dictionary_file = fopen(filePath, "r");
    
    assert(dictionary_file != NULL);
    
    // TODO why doesnit it match?!
    while (fgets(line, sizeof(line), dictionary_file) != 0) { 

        line[strcspn(line, "\n")] = 0;

        printf("%s\n", line);
        
        if(strcmp(inputHash, line) == 0) {
            printf("FOUND: %s\n", line);
            break;
        }
        
    }


    fclose(dictionary_file);
    free(filePath);
    return 0;
};


int main(int argc, char const *argv[]) {

    decrypt();

    //Password pass = splitHash("$1$JTXmp2C4$nS9ySJPUyya/0ChXbDeeB.");

    return 0;
}
