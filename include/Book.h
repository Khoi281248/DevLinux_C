#include "Common.h"

void initLibrary(LibraryBook *library);
int addBook (LibraryBook *library, char *title, char *author);
int editBook (LibraryBook *library, unsigned int bookid, char *title, char *author);
int deleteBook (LibraryBook *library, unsigned int bookid);



