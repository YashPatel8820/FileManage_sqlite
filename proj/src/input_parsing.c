
#include <stdio.h>
#include <string.h>
#include "input_parsing.h"

void parseInput() {
    char buffer[128];
    printf("Enter input to parse: ");
    gets(buffer); // Vulnerable function

    char parsed[128];
    strcpy(parsed, buffer); // Vulnerable function
    printf("Parsed input: %s\n", parsed);
}
