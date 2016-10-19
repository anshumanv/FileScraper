#include"prototyping.cpp"



// MAIN MENU
void mainmenu()
{
	printf("WELCOME TO QUICK SEARCH !\n\n");
	printf("1..Search Inbuilt Directories\n");
	printf("2..Directories Operations\n");
	printf("3..Search History\n");
	printf("4..Exit\n");
	
	int choice;
	scanf("%d",&choice);
	switch(choice)
		{
			case 1 : system("cls"); strcount(); break;
			
			
			case 2 : system("cls"); 
				
					printf("DIRECTORY OPERATIONS\n\n");
					printf("1..Show Directories\n");
					printf("2..Create New Drectory\n");
					printf("3..Delete Existing Drectory\n");
					
					int dchoice;
					scanf("%d",&dchoice);
					switch(dchoice)
						{
						case 1 : system("cls"); sd(); break;
						case 2 : system("cls"); createdirectory();  break; 	
						case 3 : system("cls"); deletedirectory(); break; 		
						}
					
					 break;
			
			
			
			case 3 : system("cls"); 
			
					printf("SEARCH HISTORY OPERATIONS\n\n");
					printf("1..Display Search History\n");
					printf("2..Clear Search History\n");
					
					int shchoice;
					scanf("%d",&shchoice);
					switch(shchoice)
						{
						case 1 : system("cls"); sh(); break;
						case 2 : system("cls"); clearsearch(); break; 		
						}
										
			case 4 : exit(0) ; break;
		}
	
	
}



//SEARCH INBUILT DIRECTORIES

int strcount(void)   
{
	FILE *fp;		
	fp = fopen("one.txt","r");
	
	
	char a[25],b[25];
	printf("Enter String to be Searched\n");
	scanf("%s",b);
	searchadd(b);
	int count=0,temp;
	
	
	if(fp==NULL)
		{printf("Unable to Open File!");}
	
	else 
		{
		while(!feof(fp))
			{
			fscanf(fp,"%s",a);
			if(strcmp(a,b)==0){count++;}
			}	
		}

	printf("%d\n",count);
	
 	printf("DO YOU WANT TO CONTINUE? (Y/N)");
 	char response;
 	scanf("%c",&response);
 	if(response == 'Y' || response == 'y')
 		{ mainmenu(); }
 	
	
	
}


//  SHOW DIRECTORIES

void sd()
{	
	FILE *sd;
	sd = fopen("Directories.txt","r");

	printf("Search Directories are as Follows:-\n");

	char ch;
	while(!feof(sd))
		{
			ch = fgetc(sd);
			printf("%c",ch);
		}
		
	fclose(sd);
}

// SEARCH HISTORY

void sh()
{	
	FILE *sh;
	sh = fopen("sh.txt","r");

	char ch;
	while(!feof(sh))
		{
			ch = fgetc(sh);
			printf("%c",ch);
		}
		
	fclose(sh);
}

 // APPEND TO SEARCH HISTORY
 
void searchadd(char ch[])
{
	FILE *sa;
	sa = fopen("sh.txt","a");
	
	char temp[100]; 
        time_t current_time = time(NULL);
        struct tm *tm = localtime(&current_time);
        strftime(temp, sizeof(temp), "%c", tm);
       
		fprintf(sa, "%s \t %s\n" , ch, temp);
		fclose(sa);
}


//CLEARING SEARCH HISTORY
void clearsearch()
{
	remove("sh.txt");
	FILE *sh;
	sh = fopen("sh.txt","w");
	fclose(sh);
	printf("Search History Has Been Cleared !");
	
}


// DELETE DIRECTORIES

void deletedirectory()
{
	printf("Enter the name of file to be deleted");
	char ch[20],a[25],b[25];
	scanf("%s",ch);
	FILE *p;
	p = fopen(ch,"r");
	remove(ch);
	
	
	
	printf("%s was deletd successfully",ch);
	
	while(!feof(p))
			{
			fscanf(p,"%s",a);
			if(strcmp(a,ch)==0){ch='/0';}
			}
	
	fclose(p);	
	
}


void createdirectory()
{
	printf("Enter Name of File\n");
	char ch[20];
	scanf("%s",ch);
	
	FILE *fp,*fp1;
	
	fp = fopen(ch,"w");
	
	fclose(fp);
	
	fp1 = fopen("Directories.txt","a");
	fputs("\n",fp1);
	fputs(ch,fp1);
	fclose(fp1);
	
	printf("%s was created successfully",ch);
	
}


// USER AUTHENTICATION

void user()
{	
	char password[10] = "1234";
	char pass[10],user[10],ch;
	int i;
	printf("Enter Username");
	gets(user);
	printf("Enter Password");
	
	
	for( i=0;i<10;i++)
		{
			ch = getchar();
			pass[i] = ch;
			ch = '*';
			printf("%c",ch);	
		}
	
	
}

