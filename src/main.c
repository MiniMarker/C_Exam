#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <crypt.h>


void* readFile(char inputHash[40]){
    char password[20], line[20], *filePath;
    FILE *dictionary_file;

    filePath = calloc(40, sizeof(char));
    
    snprintf(filePath, 31, "./src/resources/dictionary.txt");
    
    dictionary_file = fopen(filePath, "r");
    assert(dictionary_file != NULL);
    /*
    // TODO why doesnit it match?!
    while (fgets(line, sizeof(line), dictionary_file) != 0) { 

        printf("%s", line);

        if(strcmp(inputHash, line) == 0) {
            printf("FOUND: %s", line);
            break;
        }
    }
    */
    
    for(int i = 0; i < 10000; i++) {

        fscanf(dictionary_file, "%s", password);
        //printf("%d: %s\n", i, password);
        
        if(strcmp(inputHash, password) == 0){
            printf("%d: %s\n", i, password);
            break;
        }
        
    }


    fclose(dictionary_file);
    free(filePath);
    return NULL;
};


int main(int argc, char const *argv[]) {

    readFile("oi");

    return 0;
}
