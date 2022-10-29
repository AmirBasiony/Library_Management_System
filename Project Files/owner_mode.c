#include<stdio.h>
#include<string.h>
#include"debug.h"
#include"owner.h"

void Owner_Login()
{
#ifdef debug
	DPRINTF(2,"Owner_Login start\n");
#endif
	struct login check;
	printf("Enter your username: ");
	scanf("%s",check.name);
	printf("Enter your password: ");
	scanf("%d",&check.pass);
	if(!(stricmp(check.name,OwnerLog.name))  && check.pass == OwnerLog.pass)
	{
		printf("login is done successfully\n");
		printf("------------------------------------------\n");	
		do{
			printf("\t\t\t\3Welcome Owner\3\n");
			printf("what do you want to do?\n");
			printf("1- Add Admins\n");
			printf("2- Remove Admins\n");
			printf("3- Give/Deny permissions from admins\n");
			printf("choose any number above: ");
			scanf("%d",&choice);
			printf("your choice is : %d\n",choice);
			switch(choice)
			{
			case 1:
				printf("=====================================\n");
				printf("\t\t\tAdd/Add Admins\n");
				printf("=====================================\n");
				Add_Admin();
				break;
			case 2 : 
				printf("=====================================\n");
				printf("\t\t\tRemove Admins\n");
				printf("=====================================\n");
				Remove_Admins();
				break;
			case 3 : 
				printf("=====================================\n");
				printf("\t\t\t**Give/Deny permissions**\n");
				printf("=====================================\n");
				permission();
				break;	
			default :
				printf("Your choice is invalid \n");
				break;
			}
			printf("=====================================\n");
			printf("Do you want to do any thing again ?\n");
			printf("1- yes\n");
			printf("2- no\n");
			scanf("%d",&choice);
		}while(choice ==1);
	}
	else
	{
		printf(" your username or password is wrong!!!\n");
		printf("Try again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
		if(choice==1)
			Owner_Login();
	}

#ifdef debug
	DPRINTF(2,"Owner_Login exit\n");
#endif
}

