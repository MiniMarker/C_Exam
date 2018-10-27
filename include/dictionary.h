#ifndef __MAIN_H__
#define __MAIN_H__

int getHashFromFile(int mode);
int lookupHashInDictionary(char salt[13], char hash[22], char fullHash[35]);
int bruteforce(char salt[13], char hash[22], char fullHash[35]);

#endif //__MAIN_H__