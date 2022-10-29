#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"debug.h"
#include"user.h"

void user_login()											
{
#ifdef debug
	DPRINTF(2,"user_login start\n");
#endif
	try = 3;
	struct  Slogin *check_user = (struct Slogin *)malloc(sizeof(struct Slogin));
	printf("3- First try to login.\n");
	printf("Enter your username: ");
	scanf("%s",check_user->username);
	printf("Enter your password: ");
	scanf("%d",&check_user->pass);
	ptr_user = check_log2(head_user,check_user);
	while(try)
	{
		if(equal)
		{
			printf("logging in is done successfully\n");
			printf("------------------------------------------\n");			
			do{
				printf("\t\t\t\3Welcome User\3\n");		
				if(ptr_user -> card_balance)
				{
					printf("------------------------------------------\n");	
					printf("The balance in your library card >>  %d $\n",ptr_user -> card_balance);
					printf("------------------------------------------\n");
				}
				printf("what do you want to do?\n");
				printf("1- View the user data\n");
				printf("2- Change user password\n");
				printf("3- View all books with all data\n");
				printf("4- Search for a book\n");
				printf("5- Make a request to borrow an available book\n");
				printf("6- Buy an available book\n");
				printf("7- Request a new book to be provided in the future\n");
				printf("8- Show current user borrow requests\n");
				printf("choose number above: ");
				scanf("%d",&choice);
				printf("your choice is : %d\n",choice);
				switch(choice)
				{
				case 1:
					printf("=====================================\n");
					printf("\t\t**User Data**\n");
					printf("==========================================================\n");
					list_specific_user_info();
					break;
				case 2 :
					printf("=====================================\n");
					printf("\t\t\tChange User Password\n");
					printf("==========================================================\n");
					change_user_password(check_user->pass);
					user_login();
					exit(0);
					break;
				case 3 :
					printf("==========================================================\n");
					printf("\t\tList Of Books\n");
					printf("==========================================================\n");
					list_Books_data();
					break;
				case 4 :
					printf("==========================================================\n");
					printf("\t\tSearch for a Book\n");
					printf("==========================================================\n");
					search_for__book();
					break;
				case 5 :
					if(ptr_user->borrowbook == 0 && ptr_user->requestbook < 2 || ptr_user->requestbook < 1 && ptr_user->borrowbook == 1 )
					{
						printf("\t\tMake a request to borrow an available book\n");
						printf("==========================================================\n");
						reqeust_available_book();
					}		
					else if(ptr_user->requestbook == 1 && ptr_user->borrowbook == 1)
					{
						printf("\n===================================================================================\n");
						printf("you have already borrowed one book and have requested one book to borrow, so no more requests!!!\n");
						printf("===================================================================================\n\n");
					}
					else if(ptr_user->borrowbook == 2 )
					{
						printf("\n===================================================================================\n");
						printf("you has already borrowed two books, so the request will be automatically rejected !!!\n");
						printf("===================================================================================\n\n");
					}
					else if( ptr_user->requestbook == 2)
					{
						printf("\n======================================================\n");
						printf("you can not request to borrow more than two books!!!\n");
						printf("========================================================\n\n");
					}						
					break;
				case 6 :
					printf("==========================================================\n");
					printf("\t\tBuy an available book\n");
					printf("==========================================================\n");
					buy_available_book();
					break;
				case 7 :
					printf("==========================================================\n");
					printf("\tRequest a new book to be provided in the future\n");
					printf("==========================================================\n");
					request_book_for_future();
					break;
				case 8 :
					printf("==========================================================\n");
					printf("\t\tShow current user borrow requests\n");
					printf("==========================================================\n");
					show_current_user_requests();
					break;
				default :
					printf("Your choice is invalid \n");
					break;
				}
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
				scanf("%s",check_user->username);
				printf("Enter your password: ");
				scanf("%d",&check_user->pass);
				printf("\n------------------------------------------\n");			
				ptr_user = check_log2(head_user,check_user);
			}
		}
	}	
#ifdef debug
	DPRINTF(2,"user_login exit\n");
#endif
}
void default_usersinfo()
{
#ifdef debug
	DPRINTF(2,"default_usersinfo start\n");
#endif
	head_user = (struct Slogin *)malloc(sizeof(struct Slogin));
	ptr_user = head_user;
	strcpy((head_user->username), "user1");
	head_user -> id = 1111;	
	head_user -> pass = 1111;
	head_user -> library_card_id = 1111;
	head_user -> card_balance = 900;
	head_user->borrowbook =0;
	head_user->requestbook =0;
	head_user->borrowedBook = NULL;
	head_user -> next_user = NULL;

	ptr_user = Add_user(ptr_user,1212,1212,1212,50,"user2");
	ptr_user = Add_user(ptr_user,1313,1313,1313,200,"user3");
	ptr_user = Add_user(ptr_user,1414,1414,0,0,"user4");

#ifdef debug
	DPRINTF(2,"default_usersinfo exit\n");
#endif
}
struct Slogin * Add_user(struct Slogin *head_user,int id,int pass,int card_id,int balance,char username[20] )
{
	struct Slogin *temp_user = (struct Slogin *)malloc(sizeof(struct Slogin));

	temp_user->id=id;
	temp_user->pass =pass;
	temp_user -> library_card_id = card_id;
	temp_user->card_balance = balance;
	strcpy(temp_user->username,username);
	temp_user->borrowbook = 0;
	temp_user->requestbook = 0;
	temp_user->next_user = NULL;
	temp_user->borrowedBook = NULL;

	head_user->next_user = temp_user;
	return temp_user;
}
struct Slogin * check_log2(struct  Slogin *ptr_user , struct  Slogin *check_user)
{
#ifdef debug
	DPRINTF(2,"check_log2 start\n");
#endif
	while(ptr_user->next_user != NULL && (strcmp(ptr_user->username,check_user->username)) != 0 && ptr_user->pass != check_user->pass)
	{
		ptr_user = ptr_user->next_user ;
	}
	if((strcmp(ptr_user->username,check_user->username)) == 0 && ptr_user->pass == check_user->pass)
		equal = 1;
	else
		equal = 0;
	return ptr_user;
#ifdef debug
	DPRINTF(2,"check_log2 exit\n");
#endif
}
void list_specific_user_info()
{
	counter = 0;
	borrowed_books = ptr_user->borrowedBook;

	printf("UserName >> %s\n",ptr_user->username);
	printf("ID >> %d\n",ptr_user->id);
	if(ptr_user -> card_balance)
	{
		printf("Library Card ID >> %d \n",ptr_user->library_card_id);
	}
	//===================================
	// List the borrowed books if available
	if(ptr_user->borrowbook == 2)
	{
		printf("-------------------------------------------\n");
		printf("\t\t**The Borrowed Books**\n");
		printf("-------------------------------------------\n");
		while(borrowed_books!= NULL)
		{
			counter++;
			printf("\t\t**%dst Book**\n",counter);
			printf("ID : %d\n",borrowed_books->id);
			printf("The Book Name : %s\n",borrowed_books->bookname);
			printf("The Author Name : %s\n",borrowed_books->authorname);
			printf("-------------------------------------------\n");
			borrowed_books = borrowed_books->next_book;
		}
	}
	else if(ptr_user->borrowbook == 1)
	{
		printf("\t\t**The Borrowed Book**\n");
		printf("-------------------------------------------\n");
		printf("ID : %d\n",borrowed_books->id);
		printf("The Book Name : %s\n",borrowed_books->bookname);
		printf("The Author Name : %s\n",borrowed_books->authorname);
		printf("-------------------------------------------\n");
	}
	else //if(ptr_user->borrowbook == 0)
	{
		printf("-----------------------\n");
		printf("No Borrowed Books\n");
		printf("-----------------------\n\n");
	}

}	
// All user data seen by admins
void list_user_data()
{
#ifdef debug
	DPRINTF(2,"list_user_data start\n");
#endif
	int user_num=0;
	if(head_user == NULL)
	{
		printf("--------------------------\n");
		printf("No users in The library\n");
		printf("--------------------------\n");
	}
	else
	{
		ptr_user = head_user;
		while(ptr_user != NULL)
		{  
			current_request = head_request;
			user_num++;
			counter = 0;
			borrowed_books = ptr_user->borrowedBook;
			if(user_num != 3) printf("-------------------------------------------\n");
			printf("\t\t User Number (%d) Informations\n",user_num);		
			printf("UserName : %s\n",ptr_user->username);
			printf("ID : %d\n",ptr_user->id);			
			printf("Password : %d\n",ptr_user->pass);			
			printf("-------------------------------------------\n");
			if(ptr_user->borrowbook == 2)
			{	
				printf("\t\t**The Borrowed Books**\n");
				while(borrowed_books!= NULL)
				{
					counter++;
					printf("\t\t**%dst Book**\n",counter);
					printf("ID : %d\n",borrowed_books->id);
					printf("The Book Name : %s\n",borrowed_books->bookname);
					printf("The Author Name : %s\n",borrowed_books->authorname);
					borrowed_books = borrowed_books->next_book;
				}
				if(ptr_user->requestbook != 0)
				{
					while(current_request != NULL)
					{
						if(current_request->id_of_user == ptr_user->id)
						{
							printf("-------------------------------------------\n");
							printf("\t\t**The Requested Book**\n");
							printf("ID : %d\n",current_request->id_of_book);
							printf("The Book Name : %s\n",current_request->name_of_book);
							printf("The Author Name : %s\n",current_request->author_name_of_book);
						}
						current_request = current_request->next_request;
					}
				}
				else
				{
					printf("-------------------------------------------\n");
					printf("\t\t**No Requested Books**\n");
				}				
			}
			else if(ptr_user->borrowbook == 1)
			{
				printf("\t\t**The Borrowed Book**\n");
				printf("ID : %d\n",borrowed_books->id);
				printf("The Book Name : %s\n",borrowed_books->bookname);
				printf("The Author Name : %s\n",borrowed_books->authorname);
				if(ptr_user->requestbook != 0)
				{
					while(current_request != NULL)
					{
						if(current_request->id_of_user == ptr_user->id)
						{
							printf("-------------------------------------------\n");
							printf("\t\t**The Requested Book**\n");
							printf("ID : %d\n",current_request->id_of_book);
							printf("The Book Name : %s\n",current_request->name_of_book);
							printf("The Author Name : %s\n",current_request->author_name_of_book);
						}
						current_request = current_request->next_request;
					}
				}
				else
				{
					printf("-------------------------------------------\n");
					printf("\t\t**No Requested Books**\n");
				}				
			}
			else if(ptr_user->borrowbook == 0)
			{
				printf("\t\t**No Borrowed Books**\n");
				if(ptr_user->requestbook != 0)
				{
					printf("-------------------------------------------\n");
					printf("\t\t**The Requested Book**\n");
					while(current_request != NULL)
					{
						if(current_request->id_of_user == ptr_user->id && counter<2)
						{
							counter++;
							if(counter==1)
								printf("\t\t**%dst Book**\n",counter);
							else if(counter==2)
								printf("\t\t**%dnd Book**\n",counter);
							printf("ID : %d\n",current_request->id_of_book);
							printf("The Book Name : %s\n",current_request->name_of_book);
							printf("The Author Name : %s\n",current_request->author_name_of_book);
						}
						current_request = current_request->next_request;
					}
				}
				else //if(ptr_user->requestbook == 0)
				{
					printf("\t\t**No Requested Books**\n");
				}	
			}
			else
			{
				printf("\t\t**No Borrowed Books**\n");
				printf("\t\t**No Requested Books**\n");
				break;
			}
			if(user_num == 3) printf("-------------------------------------------\n");
			ptr_user = ptr_user->next_user;
		}	
	}
#ifdef debug
	DPRINTF(2,"list_user_data exit\n");
#endif
}
void change_user_password(int pass)
{
#ifdef debug
	DPRINTF(2,"change_user_password start\n");
#endif
	ptr_user = head_user;

	while(ptr_user->pass != pass && ptr_user->next_user != NULL)
	{
		ptr_user = ptr_user->next_user;
	}
	if(ptr_user->pass != pass)
		printf("You Entered Invalid user password !!!!\n");
	else
	{
		printf("Enter the new password: ");
		scanf("%d",&ptr_user->pass);
		printf("----------------------------------------------------\n");
		printf("Changing your password done successfully\n");
		printf("Please, login again.\n"); 
		printf("----------------------------------------------------\n");
	}
#ifdef debug
	DPRINTF(2,"change_user_password exit\n");
#endif
}
void Edit_User_ID()
{
#ifdef debug
	DPRINTF(2,"Edit_User_ID start\n");
#endif
	ptr_user = head_user;

	printf("Enter the id you want to change: ");
	scanf("%d",&ID);
	while(ptr_user->id != ID && ptr_user->next_user != NULL)
	{
		ptr_user = ptr_user->next_user;
	}
	if(ptr_user->id != ID)
		printf("You Entered Invalid user ID !!!!\n");
	else
	{
		printf("Enter the new ID: ");
		scanf("%d",&ptr_user->id);
		printf("----------------------------------------------------\n");
		printf("Changing user ID done successfully\n");
		printf("----------------------------------------------------\n");
	}
#ifdef debug
	DPRINTF(2,"Edit_User_ID exit\n");
#endif
}
// Add a users using admin
void add_user() 
{
#ifdef debug
	DPRINTF(2,"add_user start\n");
#endif
	struct Slogin *new_user = (struct Slogin *)malloc(sizeof(struct Slogin));
	ptr_user = head_user;	
	do{
		printf("Enter the data of the new user:\n");
		printf("ID >> ");
		scanf("%d",&new_user->id);
		printf("Password >> ");
		scanf("%d",&new_user->pass);
		printf("UserName >> ");
		scanf("%s",new_user->username);
		printf("Is %s have a library card ?\n",new_user->username);
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Library Card ID >> ");
			scanf("%d",&new_user->library_card_id);
			printf("Enter the balance of %s library card: ",new_user->username);
			scanf("%d",&new_user->card_balance);
		}
		else
		{
			new_user->library_card_id = 0;
			new_user->card_balance = 0;
		}
		new_user->borrowbook = 0;
		new_user -> requestbook =0;
		new_user->borrowedBook = NULL;
		new_user->next_user = NULL;
		//==========================================================
		if(head_user == NULL) // if no user in the library.(that happened when admin remove all the default users.)
		{
			head_user = malloc(sizeof(struct Slogin));
			head_user = new_user;
			printf("Adding new user done successfully\n");
			printf("---------------------------------------\n");
		}
		else
		{
			while(ptr_user->id != new_user->id && ptr_user->next_user != NULL)
			{
				ptr_user = ptr_user->next_user;
			}
			if(ptr_user->id == new_user->id) 
			{
				printf("---------------------------------------\n");
				printf("The ID you entered equal a current ID of one of the users!!!\n");  
				printf("Adding a new user has not been completed\n");
				printf("---------------------------------------\n");
			}
			else //if(ptr_user->id != new_user->id && ptr_user->new_user == NULL)
			{
				ptr_user = Add_user(ptr_user,new_user->id,new_user->pass,new_user->library_card_id,new_user->card_balance,new_user->username);
				ptr_user = head_user;	
				printf("Adding new user done successfully\n");
				printf("---------------------------------------\n");        				
			}
		}
		printf("Do you want to add any user again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice ==1);

#ifdef debug
	DPRINTF(2,"add_user exit\n");
#endif	
}
// Remove a users using admin
void remove_user()
{
#ifdef debug
	DPRINTF(2,"remove_user start\n");
#endif
	do{
		char RemovedUserName[20];
		struct Slogin *current_user = head_user;
		struct Slogin *prev_user = head_user ;
		printf("Enter the ID of the user you want to remove: ");
		scanf("%d",&ID);
		if(head_user == NULL)
		{
			printf("No users in the library to remove\n");
		}
		else
		{
			if(current_user->id == ID)
			{
				strcpy(RemovedUserName,current_user->username);
				head_user = current_user->next_user;
				free(current_user);
				current_user = NULL;
				printf("Removing %s done successfully\n",RemovedUserName);
			}
			else
			{
				while(current_user->id != ID && current_user->next_user != NULL)
				{
					prev_user = current_user;
					current_user = current_user->next_user;
				}
				if(current_user->id != ID)
				{
					printf("The Id you Enter ID Invalid!!!\n");
				}
				else
				{
					strcpy(RemovedUserName,current_user->username);
					prev_user->next_user = current_user->next_user;
					free(current_user);
					current_user = NULL;
					printf("Removing %s done successfully\n",RemovedUserName);
				}
			}
		}
		printf("Do you want to remove any admin again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice ==1);

#ifdef debug
	DPRINTF(2,"remove_user exit\n");
#endif	
}
void buy_available_book()
{
#ifdef debug
	DPRINTF(2,"buy_available_book start\n");
#endif
	price = 0;
	list_just_available = 0;
	if(ptr_user->library_card_id != 0)
		printf("The balance in your library card >>  %d $\n",ptr_user -> card_balance);
	do{
		list_Books_data();
		current_Book = head_book;
		printf("Enter the ID of the book you want: ");
		scanf("%d",&ID);
		if(head_book == NULL) //  this case when admin remove all books from the library.
		{
			printf("No Book in the library to borrow\n");
		}
		else
		{
			while(current_Book->id != ID && current_Book->next_book != NULL)
			{
				current_Book = current_Book->next_book;
			}
			if(current_Book->id == ID && current_Book->available)
			{
				price += current_Book->price;
				printf("The name of the selected book to buy is (%s)\n",current_Book->bookname);
			}
			else if(!(current_Book->available))
				printf("sorry, you entered the ID of non-available Book!!!\n");
			else
				printf("The ID you entered is invalid in the list of books!!!\n");
		}
		printf("=========================================\n");		
		printf("Do you want to buy any book again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice ==1);
	printf("---------------------------------------\n");
	if(ptr_user->library_card_id != 0)
	{
		printf("The total price : %d $\n",price);
		if(price <= ptr_user->card_balance)
		{
			ptr_user->card_balance = ptr_user->card_balance - price ; 
			printf("The balance in your Library card became: %d $\n",ptr_user->card_balance);
		}
		else // if(price == ptr_user->card_balance)
		{
			printf("------------------------------------------\n");
			printf("your library card balance is not enough!!!\n");
			printf("------------------------------------------\n");
			printf("What is the type of paying you want ?\n");
			printf("1- all price cash\n");
			printf("2- the rest of price cash \n");
			printf("choose a number above : ");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				printf("please, pay (%d $) cash.\n",price);
				break;
			case 2 : 
				price -= ptr_user->card_balance;
				ptr_user->card_balance = 0;
				printf("please, pay (%d $) cash.\n",price);
				break;
			default :
				printf("Your choice is invalid \n");
				break;
			}
			printf("The balance in your Library card : %d $\n",ptr_user->card_balance);
		}
	}
	else if(ptr_user->library_card_id == 0)
	{
		printf("The total price : %d $\n",price);
		printf("please, pay (%d $) cash.\n",price);
	}
	printf("---------------------------------------\n");
	list_just_available = 1;	
#ifdef debug
	DPRINTF(2,"buy_available_book exit\n");
#endif	
}
void show_current_user_requests()
{
#ifdef debug
	DPRINTF(2,"show_current_requests start\n");
#endif
	current_request = head_request;
	if(ptr_user->requestbook != 0)
	{
		counter = 0;
		while(current_request->id_of_user != ptr_user->id)
		{
			current_request = current_request->next_request;
		}
		if(current_request->request_state == 2)
		{
			printf("\t\t**The current Requested Books**\n");
			while(current_request != NULL)
			{
				if(current_request->id_of_user == ptr_user->id)
				{
					counter++;
					printf("\t\tThe Book Number(%d): \n",counter);
					printf("ID : %d\n",current_request->id_of_book);
					printf("The Book Name : %s\n",current_request->name_of_book);
					printf("The Author Name : %s\n",current_request->author_name_of_book);
				}
				current_request = current_request->next_request;	
			}
			printf("your requests  in the waiting list until admin approvement\n");
			printf("==========================================================\n");
		}			
	}
	else
	{
		printf("Not Found Requested Books, at the moment\n");
		printf("-------------------------------------------\n");
	}
	ptr_rsfused_status = head_rsfused_status;
	if(ptr_rsfused_status != NULL)
	{
		printf("\t**All the following books are denied borrowing it**\n");
		while( ptr_rsfused_status->user_id != ptr_user->id && ptr_rsfused_status->next_refBook != NULL)
		{
			ptr_rsfused_status = ptr_rsfused_status->next_refBook;
		}
		if(ptr_rsfused_status->user_id == ptr_user->id)
		{
			current_Book = head_book;
			while( ptr_rsfused_status->book_id != current_Book->id  && current_Book->next_book != NULL)
			{
				current_Book = current_Book->next_book;
			}
			if(ptr_rsfused_status->book_id == current_Book->id)
			{
				counter = 0;
				while(ptr_rsfused_status != NULL)
				{
					if(ptr_rsfused_status->book_id == current_Book->id )
					{
						counter++;
						printf("\t\tThe Book Number(%d): \n",counter);
						printf("ID : %d\n",current_Book->id);
						printf("The Book Name : %s\n",current_Book->bookname);
						printf("The Author Name : %s\n",current_Book->authorname);
					}
					ptr_rsfused_status = ptr_rsfused_status->next_refBook;
				}
			}
			printf("==========================================================\n");
		}
	}
	else
	{
		printf("Not Found Denied Books, at the moment\n");
		printf("-------------------------------------------\n");
	}
	borrowed_books = ptr_user->borrowedBook;
	if(ptr_user->borrowbook != 0)
	{	
		printf("\t\t**The Borrowed Books**\n");
		while(borrowed_books!= NULL)
		{
			counter++;
			printf("The Book Number(%d): \n",counter);
			printf("ID : %d\n",borrowed_books->id);
			printf("The Book Name : %s\n",borrowed_books->bookname);
			printf("The Author Name : %s\n\n",borrowed_books->authorname);
			borrowed_books = borrowed_books->next_book;
		}
	}
	else
	{
		printf("Not Found Borrowed Books, at the moment\n");
		printf("-------------------------------------------\n");
	}
	printf("==========================================================\n");

#ifdef debug
	DPRINTF(2,"show_current_requests exit\n");
#endif	
}
void request_book_for_future()
{
#ifdef debug
	DPRINTF(2,"request_book_for_future start\n");
#endif
	char bookname[30],authorname[30];
	struct rquest_future_book *temp_fbook;
	struct rquest_future_book *ptr_fbook;
	do{
		temp_fbook = (struct rquest_future_book *)malloc(sizeof(struct rquest_future_book));
		printf("Enter the data of the future book\n");
		printf("Book name >>  ");
		fflush(stdin); fflush(stdout);
		gets(bookname);
		printf("author name >>  ");
		fflush(stdin); fflush(stdout);
		gets(authorname);
		//===========================================
		strcpy(temp_fbook->book_name,bookname);
		strcpy(temp_fbook->author_book,authorname);
		temp_fbook->next_fbook = NULL;
		//===========================================
		if(head_fbook ==NULL)
			head_fbook = temp_fbook;
		else
		{
			ptr_fbook = head_fbook;
			while(ptr_fbook->next_fbook != NULL)
				ptr_fbook = ptr_fbook->next_fbook;
			ptr_fbook->next_fbook = temp_fbook;
		}
		printf("=======================================\n");
		printf("Do you want to request any new book again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice ==1);
	ptr_fbook = head_fbook;
	counter =0;
	printf("-----------------------------------------\n");
	printf("The new books that you want in the future \n");
	while(ptr_fbook != NULL)
	{
		counter++;
		printf("\t\tBOOK (%d)\n",counter);
		printf("The Book Name : %s\n",ptr_fbook->book_name);
		printf("The Author Name : %s\n",ptr_fbook->author_book);
		printf("-----------------------------------------\n");
		ptr_fbook = ptr_fbook->next_fbook;
	}
#ifdef debug
	DPRINTF(2,"request_book_for_future exit\n");
#endif	
}