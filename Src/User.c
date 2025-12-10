#include "../include/User.h"

void initUserManager(UserManager *manager)
{
    manager->userCount = 0;
    manager->nextUserId = 1;   
}

int addUser (UserManager *manager, char *name)
{
    if (manager == NULL || name == NULL) {
        return ERROR_INVALID_INPUT;
    }

    if (manager->userCount >= MAX_USERS) {
        return ERROR_DATABASE_FULL;
    }

    strcpy(manager->Users[manager->userCount].name,name);
    manager->Users[manager->userCount].id = manager->nextUserId++;
    manager->Users[manager->userCount].borrowedCount = 0;
    manager->userCount++;
    return 0;

}   

int editUser (UserManager *manager, unsigned int userid, char *name)
{
    if (manager == NULL || name == NULL) 
    {
        return ERROR_INVALID_INPUT;
    }

    for (int i = 0; i < manager->userCount; i++)
    {
        if (manager->Users[i].id == userid)
        {
            //edit User
            strcpy(manager->Users[i].name, name);
            return SUCCESS;
        }
    }
    return ERROR_BOOK_NOT_FOUND;

}

int deleteUser (UserManager *manager, unsigned int userid)
{
    if (manager == NULL) 
    {
        return ERROR_INVALID_INPUT;
    }

        for (int i = 0; i < manager->userCount; i++)
    {
        if (manager->Users[i].id == userid)
        {
            // delete Book
            for (int j = i; j < manager->userCount - 1; j++)
            {
                manager->Users[j] = manager->Users[j + 1];
            }
            manager->userCount--;
            return SUCCESS;
        }
    }
    return ERROR_BOOK_NOT_FOUND;
}











