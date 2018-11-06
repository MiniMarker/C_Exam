#ifndef __MAIN_H__
#define __MAIN_H__

typedef struct SplittedPassword {
    char    salt[13];
    char    hash[22];
} SplittedPassword;

//int bruteforce(char salt[13], char hash[22], char fullHash[35]);
int generateQuesses(char passchars[], char* currentGuess, int index, int maxPasswordLength);
int getHashFromFile(int mode);
int lookupHashInDictionary(char salt[13], char hash[22]); // char salt[13], char hash[22]
SplittedPassword splitHash(char *hash);





#endif //__MAIN_H__