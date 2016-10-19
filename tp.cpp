#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

{	
	char password[10] = "1234";
	char pass[10],user[10],ch;
	int i;
	printf("Enter Username\n");
	gets(user);
	printf("Enter Password\n");
	
	
	for( i=0;i<10;i++)
		{
			ch = getchar();
			pass[i] = ch;
			ch = '*';
			printf("%c",ch);	
		}
	
	
}


return 0;
}

