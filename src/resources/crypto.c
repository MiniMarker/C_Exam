#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <sys/random.h>

char saltchars[]="abcdefghikjlmnopqrstuvWxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+@£[]}";
int main(int argc, char** argv)
{
	if(argc!=2)	return -1;
	char* passwd=argv[1];

	char salt[13]="$1$abcdefgh$";
	getrandom(salt+3,8,0);
	for(unsigned int i=3;i<11;i++){
		salt[i]=saltchars[salt[i] & 0x3f];
	}
	char* encrypted=crypt(passwd,salt);
	printf("%s\n", encrypted);
	//free(encrypted);
	return 0;
}






