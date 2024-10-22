
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_management.h"

void uploadFile() {
    char filename[128];
    char buffer[1024];

    printf("Enter the filename to upload: ");
    gets(filename); // Vulnerable function

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found!\n");
        return;
    }

    fread(buffer, sizeof(char), 1024, file);
    printf("File content: %s\n", buffer);
    fclose(file);
}

void downloadFile() {
    char filename[128];
    printf("Enter the filename to download: ");
    gets(filename); // Vulnerable function

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to create file!\n");
        return;
    }

    fprintf(file, "This is a downloaded file.\n");
    fclose(file);
    printf("File downloaded successfully\n");
}
