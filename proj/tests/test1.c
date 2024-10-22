
#include <stdio.h>
#include "user_auth.h"

int main() {
    sqlite3 *db;
    initDatabase(&db);
    registerUser(db);
    sqlite3_close(db);
    return 0;
}
