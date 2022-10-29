#include<stdio.h>
#include"debug.h"
void Owner_Login();
void admin_login();
void default_usersinfo();
void user_login();
void  default_books();
void default_admins();
int choice;

int main()
{
#ifdef debug
	DPRINTF(2,"main start\n");
#endif
	default_usersinfo();
	default_books();
	default_admins();
	do{  
		printf("\t\t\t\3Welcome To Library Management System\3\n");
		printf("please, choose your mode \n");
		printf("1- User Mode\n");
		printf("2- Admin Mode\n");
		printf("3- Owner Mode\n");
		printf("choose any number above: ");
		scanf("%d",&choice);
		printf("your choice is : %d\n",choice);
		switch(choice)
		{
		case 1:
			printf("=====================================\n");
			printf("\t\t\tUser Mode\n");
			printf("=====================================\n");
			user_login();
			break;
		case 2 : 
			printf("=====================================\n");
			printf("\t\t\tAdmin Mode\n");
			printf("=====================================\n");
			admin_login();
			break;
		case 3 : 
			printf("=====================================\n");
			printf("\t\t\tOwner Mode\n");
			printf("=====================================\n");
			Owner_Login();
			break;	
		default :
			printf("Your choice is invalid \n");
			break;
		}
		printf("=====================================\n");
		printf("Login again or exit ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);	
	}while(choice == 1);
	printf("\t\t\t\3End Program\3\n");
	printf("\t\t\t\3Good-Bye\3\n");
#ifdef debug
	DPRINTF(2,"main exit\n");
#endif
}