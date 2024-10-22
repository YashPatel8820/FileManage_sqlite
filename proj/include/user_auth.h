
#ifndef USER_AUTH_H
#define USER_AUTH_H

#include <sqlite3.h>

void initDatabase(sqlite3 **db);
void registerUser(sqlite3 *db);
void loginUser(sqlite3 *db);

#endif
