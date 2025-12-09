#include "error.h"

int searchBookByTitle(LibraryBook *lib, const char *title);
int searchBookByAuthor(LibraryBook *lib, const char *author);

int displayAllBooks(LibraryBook *lib);

int displayUserInfo(UserManager *user, LibraryBook *lib);