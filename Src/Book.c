#include "../include/Book.h"

void initLibrary(LibraryBook *library)
{
    library->bookCount = 0;
    library->nextBookid = 1;
}

int addBook (LibraryBook *library, char *title, char *author)
{
    if (library == NULL || title == NULL || author == NULL) 
    {
        return ERROR_INVALID_INPUT;
    }

    if (library->bookCount >= MAX_BOOKS)
    {
        return ERROR_DATABASE_FULL;
    }

    //add book
    strcpy(library->books[library->bookCount].title, title);
    strcpy(library->books[library->bookCount].author, author);
    library->books[library->bookCount].id = library->nextBookid++;
    library->books[library->bookCount].status = AVAILBLE;
    library->bookCount++;
    return SUCCESS;
}

int editBook (LibraryBook *library, unsigned int bookid, char *title, char *author)
{
    if (library == NULL || title == NULL || author == NULL) 
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i = 0; i < library->bookCount; i++)
    {
        if (library->books[i].id == bookid)
        {
            // edit book
            strcpy(library->books[i].title, title);
            strcpy(library->books[i].author, author);
            return SUCCESS;
        }
    }
    return ERROR_BOOK_NOT_FOUND;
}

int deleteBook (LibraryBook *library, unsigned int bookid)
{
    if (library == NULL) 
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i = 0; i < library->bookCount; i++)
    {
        if (library->books[i].id == bookid)
        {
            // delete Book
            for (int j = i; j < library->bookCount - 1; j++)
            {
                library->books[j] = library->books[j + 1];
            }
            library->bookCount--;
            return SUCCESS;
        }
    }
    return ERROR_BOOK_NOT_FOUND;
}











