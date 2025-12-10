#include "../include/SearchDisplay.h"

int searchBookByTitle(LibraryBook *lib, const char *title)
{
    if (lib == NULL || title == NULL ) 
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i =0; i < lib->bookCount; i++)
    {
        if (strcmp(lib->books[i].title, title) == 0)
        {
            printf ("ID : %d\nTitle : %s\nAuthor : %s\nStatus : %s\n",
                    lib->books[i].id,
                    lib->books[i].title,
                    lib->books[i].author,
                    lib->books[i].status == AVAILBLE ? "AVAILABLE" : "BORROWED");
            
            return SUCCESS;
        }
    }

    return ERROR_BOOK_NOT_FOUND;
}

int searchBookByAuthor(LibraryBook *lib, const char *author)
{
    if (lib == NULL || author == NULL ) 
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i =0; i < lib->bookCount; i++)
    {
        if (strcmp(lib->books[i].author, author) == 0)
        {
            printf ("ID : %d\nTitle : %s\nAuthor : %s\nStatus : %s\n",
                    lib->books[i].id,
                    lib->books[i].title,
                    lib->books[i].author,
                    lib->books[i].status == AVAILBLE ? "AVAILABLE" : "BORROWED");
            
            return SUCCESS;
        }
    }

    return ERROR_BOOK_NOT_FOUND;
}

int displayAllBooks(LibraryBook *lib)
{
    if (lib == NULL ) 
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i =0; i < lib->bookCount; i++)
    {
        printf ("ID : %d\nTitle : %s\nAuthor : %s\nStatus : %s\n\n",
                lib->books[i].id,
                lib->books[i].title,                    
                lib->books[i].author,
                lib->books[i].status == AVAILBLE ? "AVAILABLE" : "BORROWED");
    }
    
    return 0;
}

int displayUserInfo(UserManager *user, LibraryBook *lib)
{
    if (user == NULL || lib == NULL) 
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i =0; i < user->userCount; i++)
    {
        printf ("ID : %d\nName : %s\nBorrowedCount : %d\n",
                user->Users[i].id,
                user->Users[i].name,                    
                user->Users[i].borrowedCount);

    if (user->Users[i].borrowedCount == 0)
    {
        printf ("No books borrowed\n\n");
    }else
    {
        printf ("List of borrowed books:\n");
        for (int j = 0; j < user->Users[i].borrowedCount; j++)
        {
            int bookId = user->Users[i].borrowedBooks[j];

            for (int k = 0; k < lib->bookCount; k++)
            {
                if (lib->books[k].id == bookId)
                {
                    printf ("    - ID: %d  |  /%s/  |  (%s)\n\n",
                            lib->books[k].id,
                            lib->books[k].title,
                            lib->books[k].author);
                    break;
                }
            }
        }
    }
    }
    return 0;
}