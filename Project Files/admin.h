#include<stdio.h>
#include<stdlib.h>
#include"structs_definitions.h"
int Admin_permission_user = 1;
int Admin_permission_book = 1;
int Admin_permission_reservation_book = 1;
int status_of_reservation = 2;
extern int choice;
int try = 3;
int equal;
extern int ID;
int remove_head;
struct  AdminLog *head_admin =NULL;
struct  AdminLog *ptr_admin;
//====================================================
extern struct Slogin *head_user;
extern struct Slogin *ptr_user;
extern struct SBook *borrowed_books;
extern struct Make_request * head_request;
struct Make_request *print_request ;
//====================================================
struct SrefusedBook *head_rsfused_status = NULL;
struct SrefusedBook *ptr_rsfused_status;
//====================================================
extern struct SBook *head_book ;
extern struct SBook *current_Book;
//====================================================
void check_log(struct  AdminLog *ptr_admin , struct  AdminLog *check_admin);  
void default_admins();
void Edit_User_ID();
void list_user_data();
void list_Books_data(); 
void default_usersinfo();
void default_books();
void Add_Admin(void);
void Remove_Admins(void);
void Add_Book();
void Remove_Book();
void add_user();
void remove_user();
void search_for__book();
void permission(void);
void Permission_of_reservation();
struct Make_request * remove_request(struct Make_request *head_request);

