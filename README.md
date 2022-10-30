# Library_Management_System

## It is a final project in C programming with Starks MU team 
This project is to build a Library Management System to manage how the admins of the library and users manage their accounts

### Systems Modes
* Owner Mode
* Admin Mode
* User Mode

### Owner Mode
#### Login : 

      User Name : Owner
      Password  : 1234
      
#### Owner Permissions : 

      * add admins
      * remove admins
      * give or deny permissions from admins : 
                     • add or remove member 
                     • add or remove book
                     • make a book reservation 
                     
      * all permissions are given by default    
      
### Admin Mode
#### Login : 

      User Name : Admin1 , Admin2 , Admin3
      Password  : 1010   , 2020   , 3030
      
#### Admin Permissions : 

      * view all users data
      * view all books with all data
      * add or remove book
      * add or remove user
      * edit user id
      * search for a book with : 
               • book name 
               • book id
               • book author name 
                         *in this case list all books of that author 
      * make a reservation of book :
               • requested books from users
               • reserve a book
      * make a reserved book available in stock agin
      * logout 
      
### User Mode 
#### Login :  

      User Name : user1 , user2 , user3
      Password  : 1111  , 1212 , 1313 
      
#### User Permissions : 

     * view the user data
     * change user password 
     * view all books 
     * search for a book with : 
               • book name 
               • book id
               • book author name 
                         *in this case list all books of that author 
     * make a request to borrow an available book
     * buy an available book 
     * request a new book to be provided in the future 
     * show current user borrow requests 
     * logout
