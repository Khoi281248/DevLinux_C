#include "Error.h"

const char* errCode (int err)
{
    if (err == 0)
        return "SUCCESS";
    else if (err == -1)
        return "ERROR_BOOK_NOT_FOUND";
    else if (err == -2)
        return "ERROR_USER_NOT_FOUND";
    else if (err == -3)
        return "ERROR_BOOK_UNAVAILABLE";
    else if (err == -4)
        return "ERROR_MAX_BORROWED";
    else if (err == -5)
        return "ERROR_INVALID_INPUT";
    else if (err == -6)
        return "ERROR_DATABASE_FULL";
    else
        return "UNKNOWN";
}

