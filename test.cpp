

#include <stdio.h>
#include <string.h>
 
int main()
{
   char string[1000];
 
   printf("Input a string to convert to lower case\n");
   gets(string);
 	char b[1000];
 	
   printf("Input string in lower case: \"%s\"\n",strlwr(string));
 
   return  0;
}
