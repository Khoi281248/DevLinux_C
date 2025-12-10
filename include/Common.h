#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <string.h>

//Status book
#define AVAILBLE               1
#define BORROWED               0

//Max Book and max User
#define MAX_BOOKS              100
#define MAX_USERS              100
#define MAX_BORROWED           10

//Max char
#define MAX_TITLE_LENGTH       100
#define MAX_AUTHOR_LENGTH      100
#define MAX_NAME_LENGTH        100
#define MAX_BORROWED_BOOKS     20

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    unsigned int borrowedCount;
    unsigned int id;
    unsigned int borrowedBooks[MAX_BORROWED_BOOKS];
}User;

typedef struct 
{
    User Users[MAX_USERS];
    unsigned int userCount;
    unsigned int nextUserId;
}UserManager;

typedef struct 
{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    unsigned int id;
    unsigned int status;
}Book;

typedef struct 
{
    Book books[MAX_BOOKS]; 
    unsigned int bookCount;
    unsigned int nextBookid;
}LibraryBook;

//Error
#define SUCCESS                 0
#define ERROR_BOOK_NOT_FOUND   -1
#define ERROR_USER_NOT_FOUND   -2
#define ERROR_BOOK_UNAVAILABLE -3
#define ERROR_MAX_BORROWED     -4
#define ERROR_INVALID_INPUT    -5
#define ERROR_DATABASE_FULL    -6



#endif