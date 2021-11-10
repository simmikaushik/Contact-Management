#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
struct contact
{
    double ph;
    char name[20],add[20],email[30];
}
list;
char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

int main()
{
	int main_exit;
	char pass[10],password[10]="12345";
    char user[10],user_name[10]="Sumita";
    int i=0;
    printf("\n\n\t\t\t\t\tUser name: ");
    scanf("%s",user);
    printf("\n\t\t\t\t\tPassword:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0 && strcmp(user,user_name)==0)
        {
			printf("\n\n\t\t\t\tVerifying please wait");
			for(i=0;i<=6;i++)
			{
				fordelay(100000000);
				printf(".");
			}
			
			printf("\n\n\t\t\t\tLogin Successful!\n\t\t\t\tLOADING");
			for(i=0;i<=6;i++)
			{
				fordelay(100000000);
			}
               system("cls");
            goto main;
        }
    else
        {
			printf("\n\n\t\t\t\tVerifying please wait");
			for(i=0;i<=6;i++)
			{
				fordelay(100000000);
				printf(".");
			}
			printf("\n\n\t\t\t\tIncorrect username or password!!\a\a\a");
            login_try:
            printf("\n\t\t\t\tEnter 1 to try again and 0 to exit:");
           scanf("%d",&main_exit);
            if (main_exit==1){
                        system("cls");
                        main();}
            else if (main_exit==0){
                    system("cls");
                    exit(0);}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }

main:
    system("cls");    /* *****Main menu ********  */
    printf("\n   ** Welcome to Contact Management System **");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3]");
	printf(" Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=====================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 0:
		exit(0);
        /* ********Add new contacts*****  */
    case 1:
        system("cls");
        fp=fopen("contact.dll","a");
        for(;;)
        {
            fflush(stdin);
            printf("To exit enter blank space in the name input\nName (Use identical):");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("Phone:");
            scanf("%lf",&list.ph);
            fflush(stdin);
            printf("address:");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            printf("email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;
        /* ********list of contacts********  */
    case 2:
        system("cls");
		for(i=97; i<=122; i=i+1)
        {
            fp=fopen("contact.dll","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.name[0]==i || list.name[0]==i-32)
                {
                    printf("\nName\t: %s\nPhone\t: %.0lf\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);
                    found++;
                }
            }
            if(found!=0)
            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
            }
            fclose(fp);
        }
        break;
        /* ******search contacts*******  */
    case 3:
        system("cls");
        do
        {
            found=0;
            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");
            fflush(stdin);
            scanf("%[^\n]",&query);
            l=strlen(query);
            fp=fopen("contact.dll","r");
            system("cls");
            printf("\n\n..::Search result for '%s' \n===================================================\n",query);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,query)==0)
                {
                    printf("\n..::Name\t: %s\n..::Phone\t: %lf\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);
                    found++;
                    if (found%4==0)
                    {
                        printf("..::Press any key to continue...");
                        getch();
                    }
                }
            }
            if(found==0)
                printf("\n..::No match found!");
            else
                printf("\n..::%d match(s) found!",found);
            fclose(fp);
            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
        while(ch==1);
        break;
        /* ********edit contacts*********/
    case 4:
        system("cls");
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");
        scanf("%[^\n]",name);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\n..::Editing '%s'\n\n",name);
        printf("..::Name(Use identical):");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("..::Phone:");
        scanf("%lf",&list.ph);
        fflush(stdin);
        printf("..::address:");
        scanf("%[^\n]",&list.add);
        fflush(stdin);
        printf("..::email address:");
        gets(list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
        /* *******delete contacts*******/
    case 5:
        system("cls");
        fflush(stdin);
        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");
        scanf("%[^\n]",&name);
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (strcmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
		printf("Contact deleted successfully!");
        break;
    default:
        printf("Invalid choice");
        break;
    }
    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
	{
    case 1:
        goto main;
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;
    }
    return 0;
}