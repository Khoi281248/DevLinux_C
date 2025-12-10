#include "../include/Borrow.h"

int findUserById (UserManager *user, unsigned int id)
{
    if (user == NULL)
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i = 0; i < user->userCount; i++)
    {
        if (user->Users[i].id == id)
            return i;
    }

    return -1;
}

int findBookById (LibraryBook *book, unsigned int id)
{
    if (book == NULL)
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i = 0; i < book->bookCount; i++)
    {
        if (book->books[i].id == id)
            return i;
    }

    return -1;
}

int borrowBook (UserManager *user, LibraryBook *lib, unsigned int userId, unsigned int bookId)
{
    if (lib == NULL || user == NULL) {
        return ERROR_INVALID_INPUT;
    }
    int temp1 = findUserById(user,userId);
    int temp2 = findBookById(lib,bookId);
    
    if (temp1 == -1)
        return ERROR_USER_NOT_FOUND;

    if (temp2 == -1)
        return ERROR_BOOK_NOT_FOUND;

    if (lib->books[temp2].status == BORROWED)
        return ERROR_BOOK_UNAVAILABLE;

    if (user->Users[temp1].borrowedCount >= MAX_BORROWED_BOOKS)
        return ERROR_MAX_BORROWED;

    user->Users[temp1].borrowedBooks[user->Users[temp1].borrowedCount] = bookId;
    user->Users[temp1].borrowedCount++;

    lib->books[temp2].status = BORROWED;

    return SUCCESS;
}


int returnBook (UserManager *user, LibraryBook *lib, unsigned int userId, unsigned int bookId)
{
    if (lib == NULL || user == NULL) {
        return ERROR_INVALID_INPUT;
    }
    int temp1 = findUserById(user,userId);
    int temp2 = findBookById(lib,bookId);
    int temp3 = -1;

    if (temp1 == -1)
        return ERROR_USER_NOT_FOUND;

    if (temp2 == -1)
        return ERROR_BOOK_NOT_FOUND;
    
    for (int i = 0; i < user->Users[temp1].borrowedCount; i++)
    {
        if (user->Users[temp1].borrowedBooks[i] == bookId ){
            temp3 = i;
            break;
        }
    }

    if (temp3 == -1)
        return ERROR_BOOK_NOT_FOUND;

    for (int i = temp3; i < user->Users[temp1].borrowedCount - 1; i++)
    {
        user->Users[temp1].borrowedBooks[i] = user->Users[temp1].borrowedBooks[i +1];
    }

    user->Users[temp1].borrowedCount--;

    lib->books[temp2].status = AVAILBLE;

    return SUCCESS;
}





