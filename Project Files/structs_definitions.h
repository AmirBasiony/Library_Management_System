#include<stdio.h>

// Books
struct SBook{
	int id;
	int available;
	int price;
	char authorname[30];
	char bookname[30];
	struct SBook *next_book;
};
// Users mode
struct Make_request
{
	int id_of_book; 
	int id_of_user; 
	int book_status;
	int request_state;
	char name_of_book[30] ;
	char author_name_of_book[30];
	struct Make_request *next_request ;
};
 
struct Slogin{
	char username[20];
	int  id;	
	int pass;
	int library_card_id;
	int card_balance;
	int borrowbook;
	int requestbook;
	struct SBook *borrowedBook;
	struct Slogin *next_user;
};

struct SrefusedBook{
	int user_id;
	int book_id;
	struct SrefusedBook *next_refBook;
};


// Admins mode
struct AdminLog{
	int id;
    char name[20];
	int pass;
struct AdminLog *next_admin;
};
// Owner mode
struct login{
	char name[20];
	int pass;
};

struct rquest_future_book{
	char book_name[30];
	char author_book[30];
	struct future_book *next_fbook;
};