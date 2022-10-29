#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"debug.h"
#include"books.h"

void list_Books_data()
{	
	current_Book = head_book;
	if(current_Book == NULL)
	{
		printf("--------------------------\n");
		printf("The library is empty\n");
		printf("--------------------------\n");
	}
	else
	{
		printf("\n-----------------------------------------------------------------------------------------------------------\n");
		printf("ID\tBook Name\t\t\t\tAuthor Name\t\tPrice\t\tStatus Of The Book\n",current_Book->id ,current_Book->bookname,current_Book->authorname,current_Book->price,current_Book->available);
		printf("-----------------------------------------------------------------------------------------------------------\n");

		while(current_Book != NULL)
		{
			if( current_Book->available )
			{
				// To Handle the list of books
				if(strlen(current_Book->bookname) < 24)
				{
					printf("%d-\t%s\t\t%s\t\t%d $\t\tAvailable\n",current_Book->id ,current_Book->bookname,current_Book->authorname,current_Book->price);
				}	
				else if(strlen(current_Book->bookname) < 20)
				{
					printf("%d-\t%s\t\t\t%s\t\t%d $\t\tAvailable\n",current_Book->id ,current_Book->bookname,current_Book->authorname,current_Book->price);
				}
			}
			else if(list_just_available)
			{
				// To Handle the list of books
				if(strlen(current_Book->bookname) < 24)
				{
					printf("%d-\t%s\t\t%s\t\t%d $\t\tNon-Available\n",current_Book->id ,current_Book->bookname,current_Book->authorname,current_Book->price);
				}	
				else if(strlen(current_Book->bookname) < 20)
				{
					printf("%d-\t%s\t\t\t%s\t\t%d $\t\tNon-Available\n",current_Book->id ,current_Book->bookname,current_Book->authorname,current_Book->price);
				}				
			}
			current_Book = current_Book->next_book;
		}
		printf("-----------------------------------------------------------------------------------------------------------\n");
	}
}
void default_books()
{
#ifdef debug
	DPRINTF(2,"default_books start\n");
#endif
	head_book = (struct SBook *)malloc(sizeof(struct SBook));
	current_Book = head_book;
	head_book->id=1;
	head_book->available =1;
	head_book->price = 20;
	strcpy(head_book->authorname,"William Shakespeare");
	strcpy(head_book->bookname,"Hamlet");	
	head_book->next_book = NULL;

	current_Book = add_book(current_Book,2,1,30,"Richard II","William Shakespeare");
	current_Book = add_book(current_Book,3,1,20,"As You Like It","William Shakespeare");
	current_Book = add_book(current_Book,4,0,15,"King Lear","William Shakespeare");
	current_Book = add_book(current_Book,5,1,40,"The Tempest","William Shakespeare");

	current_Book = add_book(current_Book,6,1,20," Ulysses","James Joyce");
	current_Book = add_book(current_Book,7,0,60,"Finn's Hotel","James Joyce");
	current_Book = add_book(current_Book,8,1,25,"Finnegans Wake","James Joyce");
	current_Book = add_book(current_Book,9,0,30,"Dubliners","James Joyce");
	current_Book = add_book(current_Book,10,0,10,"Chamber Music","James Joyce");
	current_Book = add_book(current_Book,11,1,12,"Stephen Hero","James Joyce");

	current_Book = add_book(current_Book,12,1,90,"Tomb of Sand","Geetanjali Shree's");
	current_Book = add_book(current_Book,13,1,200,"Between Two Worlds","Geetanjali Shree's");

	current_Book = add_book(current_Book,14,1,70,"War and Peace","Leo Tolstoy");
	current_Book = add_book(current_Book,15,0,60,"The Great Gatsby ","F. Scott Fitzgerald");
	current_Book = add_book(current_Book,16,1,300,"Don Quixote ","Miguel de Cervantes");
	current_Book = add_book(current_Book,17,1,1000,"Hear Yourself","Prem Rawat");
	current_Book = add_book(current_Book,18,0,90,"Lal Salam","Smriti Irani");
	current_Book = add_book(current_Book,19,1,30,"Queen of Fire ","Devika Rangachari");
	current_Book = add_book(current_Book,20,1,17,"When Breath Becomes Air","Paul Kalanithi");
	current_Book = head_book;
#ifdef debug
	DPRINTF(2,"default_books exit\n");
#endif
}
// add a default book
struct SBook * add_book(struct SBook *head_book,int id,int available,int price,char bookname[30],char authorname[30])
{
	struct SBook *temp_book = (struct SBook *)malloc(sizeof(struct SBook));
	temp_book->id=id;
	temp_book->available =available;
	temp_book->price = price;
	strcpy(temp_book->authorname,authorname);
	strcpy(temp_book->bookname,bookname);	
	temp_book->next_book = NULL;

	head_book->next_book = temp_book;
	return temp_book;
}
// Add a books using admin
void Add_Book()
{
#ifdef debug
	DPRINTF(2,"Add_Book start\n");
#endif
	struct SBook *new_book = (struct SBook *)malloc(sizeof(struct SBook));
	current_Book = head_book;
	do{
		printf("Enter the data of the new book .\n");
		printf("ID >> ");
		scanf("%d",&new_book-> id);
		printf("Price >> ");
		scanf("%d",&new_book->price);
		printf("Book Name >> ");
		scanf("%s",new_book->bookname);
		printf("Book's Author Name >> ");
		scanf("%s",new_book->authorname);
		new_book->next_book = NULL;
		if(head_book == NULL) // if no book in the library.(that happened when admin remove all the default books.)
		{
			head_book = malloc(sizeof(struct SBook));
			head_book = new_book;
			printf("Adding new Book done successfully\n");
			printf("---------------------------------------\n");
		}
		else
		{
			while(current_Book->id != new_book->id && current_Book->next_book != NULL)
			{
				current_Book = current_Book->next_book;
			}
			if(current_Book->id == new_book->id)
			{
				printf("---------------------------------------\n");
				printf("The ID you entered equal a current ID in the library!!!\n");  
				printf("Adding a new book has not been completed\n");
				printf("---------------------------------------\n");
			}
			else //if(current_Book->id != new_book->id && current_Book->next_book == NULL)
			{
				current_Book = add_book(current_Book,new_book-> id,1,new_book->price,new_book->authorname,new_book->bookname);
				current_Book = head_book;
				printf("Adding new Book done successfully\n");
				printf("---------------------------------------\n");
			}
		}
		printf("Do you want to add any Book again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice == 1);

#ifdef debug
	DPRINTF(2,"Add_Book exit\n");
#endif

}
// Remove a book using admin
void Remove_Book()
{
#ifdef debug
	DPRINTF(2,"Remove_Book start\n");
#endif
	do{
		current_Book = head_book;
		struct SBook *prev_book = NULL;
		printf("Enter the ID of the Book you want to remove: ");
		scanf("%d",&ID);
		//=========================================================
		if(head_book == NULL) // if no book in the library.(that happened when admin remove all the default books.)
		{
			printf("No users in the library to remove\n");
		}
		else
		{		
			while(current_Book != NULL)
			{
				if(ID == current_Book->id)
				{
					if(head_book == current_Book)
					{
						head_book = head_book->next_book;
						free(current_Book);
						printf("Removing The book (%s) done successfully\n",current_Book->bookname);
						printf("------------------------------------------------------------\n");
						break;
					}
					else
					{
						prev_book->next_book = current_Book->next_book;
						free(current_Book);
						prev_book = NULL ;
						printf("Removing The book (%s) done successfully\n",current_Book->bookname);
						printf("------------------------------------------------------------\n");
						break;
					}
				}
				prev_book = current_Book ;
				current_Book = current_Book->next_book;
			}
		}
		printf("Do you want to remove any book again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice ==1);

#ifdef debug
	DPRINTF(2,"Remove_Book exit\n");
#endif	
}
void search_for__book()
{
#ifdef debug
	DPRINTF(2,"search_for__book start\n");
#endif
	do{
		printf("How would you like to search for a book ?\n");
		printf("1- using  book name\n");
		printf("2- using  book id\n");
		printf("3- using  book author\n");
		printf("Choose any number above : ");
		scanf("%d",&choice);
		printf("your choice is : %d\n",choice);
		switch(choice)
		{
		case 1:
			printf("\t\t\tSearch for book using name\n");
			book_name_search();
			break;
		case 2 : 
			printf("\t\t\tSearch for book using ID\n");
			book_ID_search();
			break;
		case 3 : 
			printf("\t\t\tSearch for book using author\n");
			book_author_search();
			break;	
		default :
			printf("Your choice is invalid \n");
			break;
		}
		printf("Do you want to search for any book again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);	
	}while(choice == 1);
#ifdef debug
	DPRINTF(2,"search_for__book exit\n");
#endif	
}
void book_name_search()
{
#ifdef debug
	DPRINTF(2,"book_name_search start\n");
#endif	
	char BookName[30];
	do{
		current_Book = head_book;
		printf("Enter the name of the book to search for : ");
		fflush (stdin); fflush(stdout);
		gets(BookName);
		if(head_book == NULL) // if no book in the library.(that happened when admin remove all the default books.)
		{
			printf("Sorry, No books in the library at the moment.\n");
			printf("---------------------------------------\n");
		}
		else
		{
			while((stricmp(current_Book->bookname , BookName)) != 0 && current_Book->next_book != NULL)
			{
				current_Book = current_Book->next_book;
			}
			if(!(stricmp(current_Book->bookname , BookName)))
			{
				printf("---------------------------------------\n");
				printf("The Book (%s) has been found.\n",BookName);  
				printf("---------------------------------------\n");
				printf("The Information of the Book (%s):\n",BookName);
				printf("ID : %d\n",current_Book->id);
				printf("The Book Name : %s\n",current_Book->bookname);
				printf("The Author Name : %s\n",current_Book->authorname);
				printf("The price : %d $\n",current_Book->price);
				if(current_Book->available)
					printf("The Status : Available\n");
				else
					printf("The Status : Non-Available\n");
				printf("------------------------------------\n");
			}
			else if((stricmp(current_Book->bookname , BookName)) != 0)
			{
				printf("---------------------------------------------------------------\n");
				printf("The Book (%s) you entered does not found in the library!!!\n",BookName);
				printf("---------------------------------------------------------------\n");
			}
			printf("Do you want to search using the book name again ?\n");
			printf("1- yes\n");
			printf("2- no\n");
			scanf("%d",&choice);
		}
	}while(choice == 1);
#ifdef debug
	DPRINTF(2,"book_name_search exit\n");
#endif		
}
void book_ID_search()
{
#ifdef debug
	DPRINTF(2,"book_ID_search start\n");
#endif	
	do{
		current_Book = head_book;
		printf("Enter the ID of the book to search for : ");
		scanf("%d",&ID);
		if(head_book == NULL) // if no book in the library.(that happened when admin remove all the default books.)
		{
			printf("Sorry, No books in the library at the moment.\n");
			printf("---------------------------------------\n");
		}
		else
		{
			if(current_Book->id == ID)
			{
				printf("---------------------------------------\n");
				printf("The book has been found.\n");  
				printf("---------------------------------------\n");
				printf("The Information of the Book :\n");
				printf("---------------------------------------\n");
				printf("ID : %d\n",current_Book->id);
				printf("The Book Name : %s\n",current_Book->bookname);
				printf("The Author Name : %s\n",current_Book->authorname);
				printf("The price : %d $\n",current_Book->price);
				if(current_Book->available)
					printf("The Status : Available\n");
				else
					printf("The Status : Non-Available\n");
			}
			else
			{
				while(current_Book->id != ID && current_Book->next_book != NULL)
				{
					current_Book = current_Book->next_book;
				}
				if(current_Book->id == ID)
				{
					printf("---------------------------------------\n");
					printf("The book has been found.\n");  
					printf("---------------------------------------\n");
					printf("The Information of the Book :\n");
					printf("---------------------------------------\n");
					printf("ID : %d\n",current_Book->id);
					printf("The Book Name : %s\n",current_Book->bookname);
					printf("The Author Name : %s\n",current_Book->authorname);
					printf("The price : %d $\n",current_Book->price);
					if(current_Book->available)
						printf("The Status : Available\n");
					else
						printf("The Status : Non-Available\n");
				}
				else //if(current_Book->id != id && current_Book->next_book == NULL)
				{
					printf("---------------------------------------------------------------\n");
					printf("The Book ID you entered does not found in the library!!!\n");
					printf("---------------------------------------------------------------\n");
				}
			}
			printf("Do you want to search using ID of the book again ?\n");
			printf("1- yes\n");
			printf("2- no\n");
			scanf("%d",&choice);
		}
	}while(choice == 1);
#ifdef debug
	DPRINTF(2,"book_ID_search exit\n");
#endif	
}
void book_author_search()
{
#ifdef debug
	DPRINTF(2,"book_author_search start\n");
#endif	

	do{
		list_Books_data();
		current_Book = head_book;
		printf("Enter the name of the author to search for : ");
		fflush (stdin); fflush(stdout);
		gets(AuthorName);
		if(head_book == NULL) // if no book in the library.(that happened when admin remove all the default books.)
		{
			printf("Sorry, No books in the library at the moment.\n");
			printf("---------------------------------------\n");
		}
		else
		{
			if((stricmp(current_Book->authorname , AuthorName)) == 0)
			{
				current_Book = List_Author_Book(current_Book);
			}
			else
			{	
				while((stricmp(current_Book->authorname , AuthorName)) != 0 && current_Book->next_book != NULL)
				{
					current_Book = current_Book->next_book;
				}
				if((stricmp(current_Book->authorname , AuthorName)) == 0)
				{
					current_Book = List_Author_Book(current_Book);
				}
				else if((stricmp(current_Book->authorname , AuthorName)) != 0 && current_Book->next_book == NULL)
				{
					printf("---------------------------------------------------------------\n");
					printf("The Author (%s) you entered does not found in the library!!!\n",AuthorName);
					printf("---------------------------------------------------------------\n");
				}
			}
			printf("Do you want to search using the book name again ?\n");
			printf("1- yes\n");
			printf("2- no\n");
			scanf("%d",&choice);
		}
	}while(choice == 1);
#ifdef debug
	DPRINTF(2,"book_author_search exit\n");
#endif	
}
struct SBook *List_Author_Book(struct SBook *current_Book)
{
#ifdef debug
	DPRINTF(2,"List_Author_Book exit\n");
#endif
	int counter=0;
	printf("---------------------------------------\n");
	printf("The author (%s) has been found in the library\n",current_Book->authorname);  
	printf("---------------------------------------\n");
	printf("The list of the Books belongs to The author (%s) :\n",current_Book->authorname);
	printf("---------------------------------------\n");
	while(stricmp(current_Book->authorname , AuthorName) == 0)
	{
		counter++;
		printf("\t\t\t**%dst Book**\n",counter);
		printf("ID : %d\n",current_Book->id);
		printf("The Book Name : %s\n",current_Book->bookname);
		printf("The Author Name : %s\n",current_Book->authorname);
		printf("The price : %d $\n",current_Book->price);
		if(current_Book->available)
			printf("The Status : Available\n");
		else
			printf("The Status : Non-Available\n");
		printf("----------------------------------------------------------\n");
		if(current_Book->next_book ==NULL)
			return current_Book;
		else
			current_Book = current_Book->next_book;
	}
#ifdef debug
	DPRINTF(2,"List_Author_Book exit\n");
#endif
	return current_Book;
}
void reqeust_available_book()
{
#ifdef debug
	DPRINTF(2,"reqeust_available_book start\n");
#endif	
	if(remove_head && head_request == NULL)
	{
		struct Make_request * head_request_again = (struct Make_request *)malloc(sizeof(struct Make_request));
		head_request = head_request_again;
	}
	do{
		temp_request = (struct Make_request *)malloc(sizeof(struct Make_request));
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
			if(current_Book->id == ID && current_Book->available == 1)
			{
				if((ptr_user->requestbook < 2 && ptr_user->borrowbook == 0 )||( ptr_user->requestbook < 1 && ptr_user->borrowbook == 1))
				{
					ptr_user->requestbook++;
					printf("----------------------------------------------------------\n");
					printf("The number of requested books from you,until now = %d\n",ptr_user->requestbook);
					printf("The name of the requested book is (%s)\n",current_Book->bookname);
					printf("your request is in the waiting list until admin approvement\n");
					printf("----------------------------------------------------------\n");
					status_of_reservation = 2;
					//=========================================================================
					current_Book->available = 0;
					temp_request->id_of_user = ptr_user->id;
					temp_request->id_of_book = current_Book->id;
					temp_request->book_status = current_Book->available;
					strcpy(temp_request->name_of_book,current_Book->bookname);
					strcpy(temp_request->author_name_of_book,current_Book->authorname);
					temp_request->request_state = status_of_reservation;
					temp_request->next_request = NULL;
					//=========================================================================
					if(head_request == NULL && check_null == 0) // AtToEmpty linkedlist
					{
						head_request = temp_request;
					}
					else // AddAtEnd
					{
						ptr_request = head_request;
						while(ptr_request->next_request != NULL)
							ptr_request = ptr_request->next_request;
						ptr_request->next_request = temp_request;
					}
					check_null++;
				}
				else if(ptr_user->requestbook = 1 && ptr_user->borrowbook == 1)
				{
					printf("Sorry, you can not borrow one book and request more than one book to borrow \n");
					printf("---------------------------------------------------------------------------\n");
					break;
				}
				else 
				{
					printf("Sorry, you can not request to borrow more than two books\n");
					printf("----------------------------------------------------------\n");
					break;
				}
			}
			else if(current_Book->id == ID && current_Book->available == 0 )
			{
				printf("Sorry, the book is not available, at the moment\n");
			}
			else if(current_Book->id != ID )
			{
				printf("The ID you Enter is Invalid ID!!!\n");
			}
		}
		printf("Do you want to borrow any book again ?\n");
		printf("1- yes\n");
		printf("2- no\n");
		scanf("%d",&choice);
	}while(choice == 1);
#ifdef debug
	DPRINTF(2,"reqeust_available_book exit\n");
#endif	
}
