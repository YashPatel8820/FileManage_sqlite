
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "user_auth.h"

void initDatabase(sqlite3 **db) {
    char *errMsg = 0;
    int rc = sqlite3_open("users.db", db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
        return;
    }

    char *sql = "CREATE TABLE IF NOT EXISTS USERS("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                "USERNAME TEXT NOT NULL,"
                "PASSWORD TEXT NOT NULL);";
    rc = sqlite3_exec(*db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully\n");
    }
}

void registerUser(sqlite3 *db) {
    char username[128], password[128], sql[256];
    printf("Enter username: ");
    gets(username); // Vulnerable function
    printf("Enter password: ");
    gets(password); // Vulnerable function

    sprintf(sql, "INSERT INTO USERS (USERNAME, PASSWORD) VALUES ('%s', '%s');", username, password);

    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("User registered successfully\n");
    }
}

void loginUser(sqlite3 *db) {
    char username[128], password[128], sql[256];
    printf("Enter username: ");
    gets(username); // Vulnerable function
    printf("Enter password: ");
    gets(password); // Vulnerable function

    sprintf(sql, "SELECT * FROM USERS WHERE USERNAME='%s' AND PASSWORD='%s';", username, password);

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc == SQLITE_OK && sqlite3_step(stmt) == SQLITE_ROW) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password\n");
    }

    sqlite3_finalize(stmt);
}
