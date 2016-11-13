#include"prototyping.cpp"



// MAIN MENU
void mainmenu()
{	
	fflush(stdin);
	
	system("cls");
	printf("           -------------------------------------------------------------");
	printf("\t\t\t\t\tWELCOME TO QUICK SEARCH !\n\n\n");
	printf("\t\t\t1..Search Inbuilt Directories\n\n");
	printf("\t\t\t2..Directories Operations\n\n");
	printf("\t\t\t3..Search History\n\n");
	printf("\t\t\t4..Exit\n\n");
	printf("           -------------------------------------------------------------");

	int choice;
	printf("\n");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1 : loading(); system("cls");  strcount(); break;
			
			
			case 2 : loading(); system("cls"); 
			
					printf("           -------------------------------------------------------------");
					printf("\t\t\t\t\tDIRECTORY OPERATIONS\n\n\n");
					printf("\t\t\t1..Show Directories List\n\n");
					printf("\t\t\t2..Create New Directory\n\n");
					printf("\t\t\t3..Delete Existing Directory\n\n");
					printf("\t\t\t4..Update Directories\n\n");
					printf("           -------------------------------------------------------------");
	
					int dchoice;
					printf("\n");
					scanf("%d",&dchoice);
					switch(dchoice)
						{
						case 1 : loading(); system("cls"); sd(); break;
						case 2 : loading(); system("cls"); createdirectory();  break; 	
						case 3 : loading(); system("cls"); deletedirectory(); break;
						
						case 4 : loading(); system("cls"); 
								
								printf("\t\t\t1..Append to Existing File\n\n");
								printf("\t\t\t2..Delete Content From Existing File\n\n");
								
								 int nchoice;
								 scanf("%d",&nchoice);
								 
								 switch(nchoice)
								 {
								case 1 : loading(); system("cls"); dirappend(); break;
								case 2 : loading(); system("cls"); linedelete();  break;
								 }
						}
					
					 break;
			
			
			
			case 3 : loading(); system("cls"); 
					printf("           -------------------------------------------------------------");
					printf("\t\t\t\t\tSEARCH HISTORY OPERATIONS\n\n\n");
					printf("\t\t\t1..Display Search History\n\n");
					printf("\t\t\t2..Clear Search History\n\n");
					printf("           -------------------------------------------------------------");

					int shchoice;
					printf("\n");
					scanf("%d",&shchoice);
					switch(shchoice)
						{
						case 1 : loading(); system("cls"); sh(); break;
						case 2 : loading(); system("cls"); clearsearch(); break; 		
						}
										
			case 4 : exit(0) ; break;
		}
	
	
}



//SEARCH INBUILT DIRECTORIES

int strcount(void)   
{
	fflush(stdin);
	
	char a[25],b[25];
	printf("Enter String to be Searched\n\n");
	scanf("%s",b);
	int count=0,temp;
		
	printf("NAME OF FILE\tINSTANCES FOUND\n\n");
	
	FILE *fp1;		
	fp1 = fopen("Directories.txt","r");     //Reading List  of Files
	
	char file_name[20];
	
	while(!feof(fp1))
	
		{
		count=0;
		
		fscanf(fp1,"%s",file_name);
		FILE *fp = fopen(file_name,"r");		// Input text files one by one
		
		
		
		
			while(!feof(fp))
				{
				fscanf(fp,"%s",a);
				if(strcmp(a,b)==0){count++;}		//Comparsion of searched string with content in files files
				}	
			
		if(count!=0)
			{
			printf("%s \t %d\n",file_name,count);
			}
		}
		
		searchadd(b);
		response();
	
}


//  SHOW DIRECTORIES

void sd()
{	
	fflush(stdin);

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
	
	response();
}

// SEARCH HISTORY

void sh()
{	

	fflush(stdin);
	FILE *sh;
	sh = fopen("sh.txt","r");
	printf("STRING SEARCHED\t TIME&DATE \n\n");
	char ch;
	while(!feof(sh))
		{
			ch = fgetc(sh);
			printf("%c",ch);
		}
		
	fclose(sh);
	
	response();
}

 // APPEND TO SEARCH HISTORY
 
void searchadd(char ch[])
{
	fflush(stdin);
	
	FILE *sa;
	sa = fopen("sh.txt","a");
	
	char temp[100]; 
        time_t current_time = time(NULL);
        struct tm *tm = localtime(&current_time);
        strftime(temp, sizeof(temp), "%c", tm);
       
		fprintf(sa, "%s \t\t %s\n" , ch, temp);
		fclose(sa);
		
		response();
}


//CLEARING SEARCH HISTORY
void clearsearch()
{
	fflush(stdin);
	
	remove("sh.txt");
	FILE *sh;
	sh = fopen("sh.txt","w");
	fclose(sh);
	printf("Search History Has Been Cleared !\n");
	
	response();
	
}


// DELETE DIRECTORIES

void deletedirectory()
{
	//Take input of file name to delete
	
	fflush(stdin);
	
	printf("Enter the name of file to be deleted:-\n");
	char filename[20];
	scanf("%s",filename);
	
	int status = remove(filename);

	char a[20];
	if(status == 0)
		{
			printf("File was removed successfully\n");
			
			// Update Directories list in accordance 
			FILE *fp1;
			fp1 = fopen("Directories.txt","r");
			
			int travel=1,count=1;
			while(!feof(fp1) && travel==1)
			{
				fscanf(fp1,"%s",a);
				if(strcmp(a,filename)!=0){count++;}
				
				else travel = 0;
			}
				
			printf("line at which file name is found is %d \n",count);
			rewind(fp1);
			fclose(fp1);
	
	
	    
	    
	 FILE *fileptr1, *fileptr2;
    
    int delete_line=count, temp = 1;
	char ch;
	
	fflush(stdin);
    //open file in read mode
	fileptr1 = fopen("Directories.txt","r");
    fileptr2 = fopen("replica.c", "w");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        ch = getc(fileptr1);

        if (ch == '\n')

            temp++;

            //except the line to be deleted

            if (temp != delete_line)

            {

                //copy all lines in file replica.c

                putc(ch, fileptr2);

            }

    }

	fclose(fileptr1);
    fclose(fileptr2);

    remove("Directories.txt");

    //rename the file replica.c to original name

    rename("replica.c", "Directories.txt");


		}
		
	else 
		{
		printf("No such File was found!\n");
		response();
		}
	
	
	response();
	
}


void createdirectory()
{
	//taking file name and content
	
	fflush(stdin);
	
	printf("Enter Name of File\n");
	char new_file[20];
	scanf("%s",new_file);
	
	FILE *fp,*fp1;
	
	fp = fopen(new_file,"w+");
	
	char file_content[100];
	printf("Enter Content for file %s\n",new_file);
	fflush(stdin);
	scanf("%[^\n]s",file_content);
	fprintf(fp,"%s",file_content);

	fclose(fp);
	
	
	// Adding file name to list of files
		
	fp1 = fopen("Directories.txt","a");
	fprintf(fp1,"\n%s",new_file);
	fclose(fp1);
	
	printf("%s was created successfully",new_file);
	
	response();
	
}





// PROMPT SCREEN
void response()
{	
	fflush(stdin);
	
	char prompt;
	printf("\nDO YOU WISH TO CONTINUE ? (Y/N)");
	
	scanf("%c",&prompt);
	
	if(prompt == 'y' || prompt == 'Y')
	{
		printf("\nYou Picked Yes. : ) \n Redirecting you to Main Menu\n\n");
		loading();
		mainmenu();
	}
	
	else if(prompt == 'n' || prompt == 'N')
	{
		printf("You picked no. : ( \n Exitting Application...\n");
		exit(0);
	}
	
	else
	{
		printf("INVALID RESPONSE  : ( \n");
		response();
		
	}
}

//DELAY FUNCTION

void delay(unsigned int mseconds)
{
	
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


//LOADING

void loading()
{
	fflush(stdin);
	
	int i;
	printf("Loading");
    for(i=0;i<7;i++)
    {
    delay(150);
    printf(".");
	}
	
}

// Append to Directory
void dirappend()
{
	fflush(stdin);
		
	printf("Enter the name of file you wanna append to: ");
	char filename[20];
	scanf("%s",filename);
	
	FILE *fp = fopen(filename,"a");
	
	if(fp == NULL)
	{
		printf("No such file exists!");
		response();
	}
	
	else
		{
		
		char content[200];
		printf("\n\nEnter the content you wanna append:\n");
		fflush(stdin);
		scanf("%[^\n]s",content);
			
		fprintf(fp,"\n %s",content);
		
		printf("Content Successfully Added!");
		fclose(fp);
		response();
		}
}

// DELETE A PARTICULAR LINE FROM A FILE

void linedelete()
{
	fflush(stdin);
	
    FILE *fileptr1, *fileptr2;

    char filename[40];

    char ch;

    int delete_line, temp = 1;

 

    printf("Enter file name to delete content from: ");

    scanf("%s", filename);

    //open file in read mode

    fileptr1 = fopen(filename, "r");
	
	if(fileptr1==NULL)
		{
			printf("No such file exists !");
			response();
		}
	
	
    ch = getc(fileptr1);
	
	printf("\n File Content is as Follows:-\n");
   while (ch != EOF)

    {

        printf("%c", ch);

        ch = getc(fileptr1);

    }

    //rewind

    rewind(fileptr1);

    printf(" \n Enter line number to be deleted:");

    scanf("%d", &delete_line);

    //open new file in write mode

    fileptr2 = fopen("replica.c", "w");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        ch = getc(fileptr1);

        if (ch == '\n')

            temp++;

            //except the line to be deleted

            if (temp != delete_line)

            {

                //copy all lines in file replica.c

                putc(ch, fileptr2);

            }

    }

    fclose(fileptr1);

    fclose(fileptr2);

    remove(filename);

    //rename the file replica.c to original name

    rename("replica.c", filename);


    printf("\n\n The contents of file after being modified are as follows:\n");

    fileptr1 = fopen(filename, "r");

    ch = getc(fileptr1);

    while (ch != EOF)

    {

        printf("%c", ch);

        ch = getc(fileptr1);

    }

    fclose(fileptr1);
	
	response();
	
}



