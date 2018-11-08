#ifndef __MAIN_H__
#define __MAIN_H__

typedef struct SplittedPassword {
    char    salt[13];
    char    hash[22];
} SplittedPassword;

SplittedPassword splitHash(char *hash);
int generateQuesses(char passchars[], char* currentGuess, int index, int maxPasswordLength);
int getHashFromFile();
int lookupHashInDictionary(char salt[13], char hash[22]);
int splitGivenHash(char *hash);
int loop(char *str, int index, char *salt, char *hash);
int bruteforceEntry(char *salt, char *hash);

#endif //__MAIN_H__