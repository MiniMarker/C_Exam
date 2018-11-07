#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *sconcat(const char *s1, const char *s2)
{
  char *s0 = malloc(strlen(s1)+strlen(s2)+1);
  strcpy(s0, s1);
  strcat(s0, s2);
  return s0;
}

int main()
{
   const char *s = "hello";
   
   char *s2 = sconcat(s, " literal");
   
   puts(s2);
   free(s2);
}