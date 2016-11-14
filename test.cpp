#include <stdio.h>
#include <string.h>
 
int main()
{
 	printf("Enter name of anime u wanna leave \n\n");
   char name[50],temp[50];
   scanf("%s",name);
   
   FILE *fp1 = fopen("test.txt","r");
   FILE *fp2 = fopen("copy.txt","a");
   
   int status = 1;
   
   while(!feof(fp1))
	   	{
		fscanf(fp1,"%s",temp);
	 	status = strcmp(name,temp);
	   	
	   	if(status!=0)
	   		{
			   fprintf(fp2,"%s ",temp); }
	   	
		}
		
		fclose(fp1);
		fclose(fp2);
		
		
		
	 
return 0;  
   
}
