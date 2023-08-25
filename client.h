#include "util.h"

#define NAME_SIZE 50
#define PHONE_NUMBER_SIZE 20

struct client {
    char name[NAME_SIZE];
    char phoneNumber[PHONE_NUMBER_SIZE];
};

// Reads the attributes of a client.
char* readClient(struct client c) {
    char* result = malloc(NAME_SIZE + PHONE_NUMBER_SIZE + 5);
    clearString(result, NAME_SIZE + PHONE_NUMBER_SIZE);
    strcpy(result, c.name);
    strcat(result, " \t\t ");
    strcat(result, c.phoneNumber);
    result[NAME_SIZE + PHONE_NUMBER_SIZE + 4] = '\0';
    return result;
}
