#include<stdio.h>
#include<stdlib.h>
#include"structs_definitions.h"
char AuthorName[30];
extern int ID;
extern int choice;
extern int Admin_permission_book;
extern int status_of_reservation;
struct SBook *head_book = NULL;
struct SBook *current_Book;
//====================================================
extern struct Slogin *head_user;
extern struct Slogin *ptr_user;
extern struct SBook *borrowed_books;
extern struct Make_request *head_request;
struct Make_request *ptr_request = NULL;
struct Make_request *temp_request ;
int check_null;
extern int remove_head;
extern int list_just_available;
//====================================================
void default_books();
struct SBook * add_book(struct SBook *head_book,int id,int available,int price, char authorname[30],char bookname[30] );

void Add_Book();
void Remove_Book();

void search_for__book();
void book_name_search();
void book_ID_search();
void book_author_search();
void reqeust_available_book();
struct SBook *List_Author_Book(struct SBook *current_Book);

void Permission_of_reservation();