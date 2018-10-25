#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>

int readFile(char input[40]){
    char password[20], *filePath;

    filePath = calloc(40, sizeof(char));
    
    snprintf(filePath, 40, "./resources/dictionary.txt");

    printf("%s\n", input);

    FILE *dictionary_file;
    dictionary_file = fopen(filePath, "r");

    for(int i = 0; i < 100; i++) {

        fscanf(dictionary_file, "%s", password);
        printf("%s\n", password);

    }

    fclose(dictionary_file);
    free(filePath);
    return 0;
};




int main(int argc, char const *argv[]) {

    readFile("test");

    return 0;
}
