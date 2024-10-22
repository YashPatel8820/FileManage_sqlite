
#include <stdio.h>
#include "user_auth.h"
#include "file_management.h"
#include "input_parsing.h"

int main() {
    printf("Welcome to the Complex Vulnerable Project\n");
    sqlite3 *db;
    initDatabase(&db);

    int choice;
    do {
        printf("\n1. Register User\n");
        printf("2. Login User\n");
        printf("3. Upload File\n");
        printf("4. Download File\n");
        printf("5. Parse Input\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                registerUser(db);
                break;
            case 2:
                loginUser(db);
                break;
            case 3:
                uploadFile();
                break;
            case 4:
                downloadFile();
                break;
            case 5:
                parseInput();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    sqlite3_close(db);
    return 0;
}
