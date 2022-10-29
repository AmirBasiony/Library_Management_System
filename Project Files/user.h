#include<stdio.h>
#include<stdlib.h>
#include"structs_definitions.h"

int ID;
extern int Admin_permission_user;
struct Slogin *head_user = NULL;
struct Slogin *ptr_user;
struct SBook *borrowed_books;
struct Make_request * head_request = NULL;
struct Make_request *current_request ;
extern struct SBook *head_book ;
extern struct SBook *current_Book;
extern int status_of_reservation;
int price;
//========================================
extern struct SrefusedBook *head_rsfused_status;
extern struct SrefusedBook *ptr_rsfused_status;
//========================================
extern int choice;
extern int try;
extern int equal;
int counter;
//=============================================
void default_usersinfo();
struct Slogin * Add_user(struct Slogin *head_user,int id,int pass,int card_id,int balance,char username[20] );
struct Slogin * check_log2(struct  Slogin *ptr_user , struct  Slogin *check_user);
void list_user_data();
void list_specific_user_info();
void list_Books_data();
void change_user_password();
void Edit_User_ID();
void add_user();
void remove_user();
void search_for__book();
void reqeust_available_book();
void buy_available_book();
void list_Books_data();
void show_current_user_requests();
int list_just_available = 1;
void request_book_for_future();
struct rquest_future_book *head_fbook;


