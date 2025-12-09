#include <stdio.h>
#include "include/Book.h"
#include "include/User.h"
#include "include/Borrow.h"
#include "include/SearchDisplay.h"

int main()
{
    printf("\n===== TEST LIBRARY SYSTEM =====\n");

    LibraryBook lib;
    UserManager users;

    initLibrary(&lib);
    initUserManager(&users);

    // ------------------ ADD BOOKS ------------------
    addBook(&lib, "C", "Nguyen Van A");
    addBook(&lib, "STM32 Embedded", "Nguyen Van B");
    addBook(&lib, "Python AI", "Tran Van C");

    printf("Number of books in the library: %d\n", lib.bookCount);

    // ------------------ ADD USERS ------------------
    addUser(&users, "Nguyen Van K");
    addUser(&users, "Tran Van M");

    printf("Number of users: %d\n\n", users.userCount);

    // ------------------ BORROW TEST ------------------
    printf("User 1 borrows book ID=1.\n");
    int ret = borrowBook(&users, &lib, 1, 1);
    printf(" => %s\n", ret == SUCCESS ? "Successful!" : "failure!");
    printf("Error: %d\n\n", ret);

    printf("User 2 borrows book ID=1.\n");
    ret = borrowBook(&users, &lib, 2, 1);
    printf(" => %s\n", ret == SUCCESS ? "Successful!" : "failure!");
    printf("Error: %d\n\n", ret);

    printf("User 1 return book ID=1.\n");
    ret = returnBook(&users, &lib, 1, 1);
    printf(" => %s\n", ret == SUCCESS ? "Successful!" : "failure!");
    printf("Error: %d\n\n", ret);

    printf("User 2 borrows book ID=1.\n");
    ret = borrowBook(&users, &lib, 2, 1);
    printf(" => %s\n", ret == SUCCESS ? "Successful!" : "failure!");
    printf("Error: %d\n\n", ret);

    printf("Status ID=1: %s\n\n",
           lib.books[0].status == AVAILBLE ? "AVAILABLE" : "BORROW");

    // ------------------ SEARCH TEST ------------------
    printf("===== TEST SEARCH =====\n\n");

    printf("\nSearch book by title 'STM32 Embedded':\n");
    searchBookByTitle(&lib, "STM32 Embedded");

    printf("\nSearch book by author 'Nguyen Ven C':\n");
    searchBookByAuthor(&lib, "Tran Van C");

    // ------------------ DISPLAY TEST ------------------
    printf("\n===== LIST BOOK =====\n");
    displayAllBooks(&lib);

    printf("===== INFORMATION USER =====\n");
    displayUserInfo(&users, &lib);

    printf("===== TEST END =====\n");
    return 0;
}
