#include "error.h"

int borrowBook (UserManager *user, LibraryBook *lib, unsigned int userId, unsigned int bookId);
int returnBook (UserManager *user, LibraryBook *lib, unsigned int userId, unsigned int bookId);
int findUserById (UserManager *user, unsigned int id);
int findBookById (LibraryBook *book, unsigned int id);
