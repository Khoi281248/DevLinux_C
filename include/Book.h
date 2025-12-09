#include "error.h"

void initLibrary(LibraryBook *library);
int addBook (LibraryBook *library, char *title, char *author);
int editBook (LibraryBook *library, unsigned int bookid, char *title, char *author);
int deleteBook (LibraryBook *library, unsigned int bookid);


//gcc Book/Book.c Book/testaddbook.c -IBook -o app
