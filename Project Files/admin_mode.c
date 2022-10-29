#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"debug.h"
#include"admin.h"

void admin_login()
{
#ifdef debug
	DPRINTF(2,"admin_login start\n");
#endif
	try = 3;
	struct  AdminLog *check_admin = (struct AdminLog *)malloc(sizeof(struct AdminLog));
	printf("3- First try to login.\n");
	printf("Enter your username: ");
	scanf("%s",check_admin->name);
	printf("Enter your password: ");
	scanf("%d",&check_admin->pass);
	check_log(head_admin,check_admin);

	while(try)
	{
		if(equal)
		{
			printf("login is done successfully\n");
			printf("------------------------------------------\n");	
			do{
				printf("\t\t\t\3Welcome Admin\3\n");
				printf("what do yot want to do?\n");
				printf("1- View all users with all data\n");
				printf("2- View all books with all data\n");
				printf("3- Add a Users\n");
				printf("4- Remove a Users\n");
				printf("5- Add a book to the library\n");
				printf("6- Remove a book from the library\n");
				printf("7- Edit user id\n");
				printf("8- Search for a book\n");
				printf("9- Make a reservation for books\n");
				printf("choose number above: ");
				scanf("%d",&choice);
				printf("your choice is : %d\n",choice);
				switch(choice)
				{
				case 1:
					printf("=====================================\n");
					printf("\t\tList user data\n");
					printf("=====================================\n");
					list_user_data();
					break;
				case 2 :
					printf("=====================================\n");
					printf("\t\tList Of Books\n");
					printf("=====================================\n");
					list_Books_data();
					break;
				case 3 :
					printf("=====================================\n");
					printf("\t\tAdd a Users\n");
					printf("=====================================\n\n");
					if(Admin_permission_user)
						add_user();
					else 
					{
						printf("\n----------------------------------------------\n");
						printf("The owner has denied you from adding any users!!!");
						printf("\n----------------------------------------------\n");
					}
					break;	
				case 4 :
					printf("=====================================\n");
					printf("\t\tRemove a Users\n");
					printf("=====================================\n\n");
					if(Admin_permission_user)
						remove_user();
					else 
					{
						printf("\n----------------------------------------------\n");
						printf("The owner has denied you from removing any users!!!");
						printf("\n----------------------------------------------\n");
					}
					break;	
				case 5 :
					printf("=====================================\n");
					printf("\t\tAdd a book \n");
					printf("=====================================\n");
					if(Admin_permission_book)
						Add_Book();
					else 
					{
						printf("\n----------------------------------------------\n");
						printf("The owner has denied you from adding any book!!!");
						printf("\n----------------------------------------------\n");
					}
					break;
				case 6 :
					printf("=====================================\n");
					printf("\t\tRemove a book \n");
					printf("=====================================\n");
					if(Admin_permission_book)
						Remove_Book();
					else 
					{
						printf("\n----------------------------------------------\n");
						printf("The owner has denied you from removing any book!!!");	
						printf("\n----------------------------------------------\n");
					}
					break;	
				case 7 :
					printf("=====================================\n");
					printf("\t\tEdit User ID\n");
					printf("=====================================\n");
					Edit_User_ID();
					break;	
				case 8 :
					printf("=====================================\n");
					printf("\t\tSearch for a book\n");
					printf("=====================================\n");
					search_for__book();
					break;
				case 9 :
					printf("=====================================\n");
					printf("\t\tReservation for books\n");
					printf("=====================================\n");
					if(Admin_permission_reservation_book)
						Permission_of_reservation();
					else 
					{
						printf("\n----------------------------------------------\n");
						printf("The owner has denied you from reservation any book to users!!!");	
						printf("\n----------------------------------------------\n");
					}
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
			}while(choice==1);
			break;
		}
		else   
		{
			try--;
			printf(" your username or password is wrong!!!\n");	
			printf("\n------------------------------------------\n");			
			if(try==0)
			{
				printf(" No more try\n");
				break;
			}
			else
			{
				printf("%d- Try again.\n",try);
				printf("Enter your username: ");
				scanf("%s",check_admin->name);
				printf("Enter your password: ");
				scanf("%d",&check_admin->pass);
				printf("\n------------------------------------------\n");			
				check_log(head_admin,check_admin);
			}
		}
	}
#ifdef debug
	DPRINTF(2,"admin_login exit\n");
#endif
}
void default_admins()
{
#ifdef debug
	DPRINTF(2,"default_admins start\n");
#endif

	head_admin = malloc(sizeof(struct AdminLog));
	strcpy((head_admin->name), "Admin1");
	head_admin -> pass = 1010;
	head_admin -> next_admin = NULL;
	//============================================================
	ptr_admin =(struct AdminLog *)malloc(sizeof(struct AdminLog));
	strcpy((ptr_admin -> name), "Admin2");
	ptr_admin -> pass = 2020;
	ptr_admin -> next_admin = NULL;

	head_admin -> next_admin = ptr_admin;
	//============================================================
	ptr_admin =(struct AdminLog *)malloc(sizeof(struct AdminLog));
	strcpy((ptr_admin -> name), "Admin3");
	ptr_admin->pass = 3030;
	ptr_admin->next_admin = NULL;

	head_admin->next_admin->next_admin = ptr_admin ;
	ptr_admin = head_admin;
	while(ptr_admin != NULL)
	{
		ptr_admin->id = ptr_admin->pass;
		ptr_admin = ptr_admin->next_admin;
	}
	ptr_admin = head_admin;

#ifdef debug
	DPRINTF(2,"default_admins exit\n");
#endif
}
void check_log(struct  AdminLog *ptr_admin , struct  AdminLog *check_admin)
{
	while(ptr_admin->next_admin != NULL && (strcmp(ptr_admin->name,check_admin->name)) != 0 && ptr_admin->pass != check_admin->pass)
	{
		ptr_admin = ptr_admin->next_admin ;
	}
	if((strcmp(ptr_admin->name,check_admin->name)) == 0 && ptr_admin->pass == check_admin->pass)
		equal = 1;
	else
		equal = 0;
}
void Remove_Admins()
{
#ifdef debug
	DPRINTF(2,"Remove_Admins start\n");
#endif
	do{
		char RemovedAdminName[20];
		struct AdminLog *current_admin = head_admin;
		struct AdminLog *prev_admin = head_admin ;
		printf("Enter the ID of the admin you want to remove: ");
		scanf("%d",&ID);;
		if(head_admin == NULL)
		{
			printf("No users in the library to remove\n");
		}
		else
		{
			if(current_admin->id == ID)
			{
				strcpy(RemovedAdminName,current_admin->name);
				head_admin = current_admin->next_admin;
				free(current_admin);
				current_admin = NULL;
				printf("Removing %s done successfully\n",RemovedAdminName);
				//===============================================================
				ptr_admin = head_admin;
				printf("\t\tAll Admins\n");
				while(ptr_admin != NULL)
				{
					printf("ID >> %d \n",ptr_admin->id );
					printf("pass>> %d \n",ptr_admin->pass );
					printf("name >> %s \n",ptr_admin->name );
					printf("---------------------------------------\n");
					ptr_admin = ptr_admin->next_admin;
				}
			}
			else
			{
				while(current_admin->id != ID && current_admin->next_admin != NULL)
				{
					prev_admin = current_admin;
					current_admin = current_admin->next_admin;
				}
				if(current_admin->id != ID)
				{
					printf("The Id you Enter ID Invalid!!!\n");
				}
				else
				{
					strcpy(RemovedAdminName,current_admin->name);
					prev_admin->next_admin = current_admin->next_admin;
					free(current_admin);
					current_admin = NULL;
					printf("Removing %s done successfully\n",RemovedAdminName);
					//===============================================================
					ptr_admin = head_admin;
					printf("\t\tAll Admins\n");
					while(ptr_admin != NULL)
					{
						printf("ID >> %d \n",ptr_admin->id );
						printf("pass>> %d \n",ptr_admin->pass );
						printf("name >> %s \n",ptr_admin->name );
						printf("---------------------------------------\n");
						ptr_admin = ptr_admin->next_admin;
					}
				}
			}
		}
		printf("Do you want to remove any admin again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice ==1);
#ifdef debug
	DPRINTF(2,"Remove_Admins exit\n");
#endif
}
void Add_Admin()
{
#ifdef debug
	DPRINTF(2,"Add_Admin start\n");
#endif
	do{
		struct AdminLog *new_admin = (struct AdminLog *)malloc(sizeof(struct AdminLog));
		ptr_admin = head_admin;
		printf("Enter the data of the new admin:\n");
		printf("ID >> ");
		scanf("%d",&new_admin->id);
		printf("Password >> ");
		scanf("%d",&new_admin->pass);
		printf("UserName >> ");
		scanf("%s",new_admin->name);
		new_admin->next_admin = NULL;
		while(ptr_admin->next_admin != NULL)
		{
			ptr_admin = ptr_admin->next_admin;
		}
		ptr_admin->next_admin = new_admin;


		printf("---------------------------------------\n");
		printf("Adding new Admin done successfully\n");
		printf("---------------------------------------\n");
		ptr_admin = head_admin;
		printf("\t\tAll Admins\n");
		while(ptr_admin != NULL)
		{
			printf("ID >> %d \n",ptr_admin->id );
			printf("pass>> %d \n",ptr_admin->pass );
			printf("name >> %s \n",ptr_admin->name );
			printf("---------------------------------------\n");
			ptr_admin = ptr_admin->next_admin;
		}
		printf("Do you want to add any admin again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice ==1);
#ifdef debug
	DPRINTF(2,"Add_Admin exit\n");
#endif	
}
void permission()
{
#ifdef debug
	DPRINTF(2,"permission start\n");
#endif
	do{
		printf("Enter the permission you want to manage\n");
		printf("1- Add/remove member\n");
		printf("2- Add/remove book\n");
		printf("3- Make a book reservation\n");	
		printf("choose any number above: ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("\t\t\t**permission on members**\n");
			printf("What do you want to do ?\n");
			printf("1- Give Permission\n");
			printf("2- Deny Permission\n");
			printf("choose any number above: ");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1 :
				Admin_permission_user = 1;
				break;
			case 2 :
				Admin_permission_user = 0;
				break;	
			}
			break;
			case 2 :	
				printf("\t\t\t**permission on book**\n");
				printf("What do you want to do ?\n");
				printf("1- Give Permission\n");
				printf("2- Deny Permission\n");
				printf("choose any number above: ");
				scanf("%d",&choice);
				switch(choice)
				{
				case 1 :
					Admin_permission_book = 1;
					break;
				case 2 :
					Admin_permission_book = 0;
					break;	
				}
				break;
				case 3 :
					printf("\t\t\t**Make a book reservation**\n");
					printf("What do you want to do ?\n");
					printf("1- Give Permission\n");
					printf("2- Deny Permission\n");
					printf("choose any number above:  ");
					scanf("%d",&choice);
					switch(choice)
					{
					case 1 :
						Admin_permission_reservation_book = 1;
						break;
					case 2 :
						Admin_permission_reservation_book = 0;
						break;	
					}
					break;
		}
		printf("Do you want to do any thing again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice == 1);
#ifdef debug
	DPRINTF(2,"permission exit\n");
#endif
}
void Permission_of_reservation()
{
#ifdef debug
	DPRINTF(2,"Permission_of_reservation start\n");
#endif		
	print_request = head_request;	
	if(	print_request !=NULL)
	{
		printf("The Requested Books\n");
		printf("========================\n");
		equal = 0;        
		while(print_request != NULL)
		{
			equal++;
			ptr_user = head_user;
			while(ptr_user->id != print_request->id_of_user)
			{
				ptr_user = ptr_user->next_user;
			}
			struct SBook *temp_borrowed_book =(struct SBook *)malloc(sizeof(struct SBook));
			borrowed_books = ptr_user->borrowedBook;
			printf("----------------------------------------\n");
			printf("\t\t\tThe Requested Book Number (%d)\n",equal);
			printf("The Book ID >> %d \n",print_request->id_of_book);
			printf("The Book Name >> %s \n",print_request->name_of_book);
			printf("The Author >> %s \n",print_request->author_name_of_book);
			//=======================================================
			if(ptr_user->borrowbook == 0)
				printf("No borrowed books from %s .\n",ptr_user->username,ptr_user->borrowbook);
			else if(ptr_user->borrowbook == 1)
				printf("The number of borrowed books from %s = %d \n",ptr_user->username,ptr_user->borrowbook);
			//========================================================
			if(print_request->request_state == 2)
				printf("(Waiting for your permission)\n");
			printf("=============================\n");
			printf("What is your dicission ?\n");
			printf("1- Approve\n");
			printf("2- Not approve\n");
			printf("Choose a number above: ");
			scanf("%d",&choice);
			//===========================================================
			while(ptr_user != NULL && ptr_user->id != print_request->id_of_user)
			{	
				ptr_user = ptr_user->next_user;
			}
			switch(choice)
			{
			case 1 :
				if(ptr_user->id == print_request->id_of_user)
				{		
					ptr_user->borrowbook++;

					temp_borrowed_book->id = print_request->id_of_book;
					strcpy(temp_borrowed_book->bookname,print_request->name_of_book);
					strcpy(temp_borrowed_book->authorname,print_request->author_name_of_book);
					temp_borrowed_book->available = 1;
					temp_borrowed_book->price = 0;
					print_request->request_state = 0;
					if(ptr_user->borrowedBook == NULL) // AtToEmpty linkedlist
					{
						ptr_user->borrowedBook = temp_borrowed_book;
					}
					else // AddAtEnd
					{
						borrowed_books = ptr_user->borrowedBook;
						while(borrowed_books->next_book != NULL)
							borrowed_books = borrowed_books->next_book;
						borrowed_books->next_book = temp_borrowed_book;
					}
					if(borrowed_books != NULL) // && ptr_user->borrowbook != 0
						printf("Giving the book to the user done successfully.\n");
				}
				break;
			case 2 :
				if(ptr_user->id == print_request->id_of_user)
				{
					print_request->request_state = 0;
					struct SrefusedBook *temp_rsfused_status = (struct SrefusedBook *)malloc(sizeof(struct SrefusedBook));
					temp_rsfused_status->user_id = ptr_user->id;
					temp_rsfused_status->book_id = print_request->id_of_book;
					temp_rsfused_status->next_refBook = NULL;
					if(head_rsfused_status == NULL) // AtToEmpty linkedlist
					{
						head_rsfused_status = temp_rsfused_status;
					}
					else // AddAtEnd 
					{
						ptr_rsfused_status = head_rsfused_status;
						while(ptr_rsfused_status->next_refBook != NULL)
							ptr_rsfused_status = ptr_rsfused_status->next_refBook;
						ptr_rsfused_status->next_refBook = temp_rsfused_status;
					}
					if(head_rsfused_status != NULL)
						printf("Permission to give the book to the user has been successfully denied.\n");
				}
				break;	
			}
			ptr_user->requestbook = 0;
			print_request = print_request->next_request;
		}
		head_request = remove_request(head_request);
		print_request = head_request;
		if(head_request == NULL)
		{
			printf("---------------------------------------------------------------------\n");
			printf("Removing the entire requests of books from the list was done successfully.\n");
		}
		//Make a reserved book available in stock again
		default_books();
	}
	else
	{
		printf("---------------------------------\n");
		printf("NO Requested Books ,at the moment\n");	
	}
#ifdef debug
	DPRINTF(2,"Permission_of_reservation exit\n");
#endif		
}
struct Make_request * remove_request(struct Make_request *head_request)//int id_of_user,int id_of_book
{
#ifdef debug
	DPRINTF(2,"remove_request start\n");
#endif
	remove_head++;
	char RemovedBookName[30];
	struct Make_request *temp_request = head_request;
	while(temp_request != NULL)
	{			
		temp_request = temp_request->next_request;
		free(head_request);
		head_request = temp_request;
	}
	return head_request;
#ifdef debug
	DPRINTF(2,"remove_request exit\n");
#endif	
}
