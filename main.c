#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "file.h"

// The application loop.
void loop();

// Register new clients.
void registerClient();

// Prints out an error msg.
void error(const char*);

// Checks whether user is sure or not for their decision.
int userIsSure(const char*);

// Reads a client's name and returns it.
char* readName();

// Reads a client's phone number and returns it.
char* readPhoneNumber();

int main() {
    loop();
    return 0;
}

void loop() {
    createRecord();
    char option;
    while (1) {
        printf("-------------------- Clients ---------------------\n");
        printf("(1) - Register\n");
        printf("(2) - Search\n");
        printf("(3) - Exit\n");
        printf("--------------------------------------------------\n");
        printf("-> ");
        scanf("%c", &option);
        fflush(stdin);
        clearTerminal();
        if (option == '1') {
            registerClient();
        } else if (option == '2') {
            printf("\n- Search Client -\n");
        } else if (option == '3') { 
            if (userIsSure("Clients")) {
                exit(0);
            }
        } else {
            error("\n- Unknown option -\n");
        }
        clearTerminal();
    }
}

void registerClient() {
    char* name = readName();
    if (!strcmp(name, "-1")) {
        return;
    }
    clearTerminal();
    char* phoneNumber = readPhoneNumber();
    if (!strcmp(phoneNumber, "-1")) {
        return;
    }
    char opt;
    while (1) {
        clearTerminal();
        printf("\n - Register client -\n");
        printf("%s", drawRow(50, '-'));
        printf("Name: %s\n", name);
        printf("Phone number: %s\n", phoneNumber);
        printf("%s", drawRow(50, '-'));
        printf("(1) Create          (2) Edit          (3) Cancel\n");
        printf("%s", drawRow(50, '-'));
        printf("-> ");
        scanf("%c", &opt);
        fflush(stdin);
        clearTerminal();
        if (opt == '1') {
            // Write to file.
            free(name);
            free(phoneNumber);
            printf("- Created Successfully -\n");
            system("pause");
            break;
        } else if (opt == '2') {
            char opt2;
            while (1) {
                printf("- Edit Client -\n");
                printf("%s", drawRow(50, '-'));
                printf("(1) - Name\n");
                printf("(2) - Phone number\n");
                printf("(3) - Exit\n");
                printf("%s", drawRow(50, '-'));
                printf("-> ");
                scanf("%c", &opt2);
                fflush(stdin);
                clearTerminal();
                if (opt2 == '1') {
                    char* editName = readName();
                    if (strcmp(editName, "-1")) {
                        strcpy(name, editName);
                    }
                    free(editName);
                    clearTerminal();
                } else if (opt2 == '2') {
                    char* editPhoneNumber = readPhoneNumber();
                    if (strcmp(editPhoneNumber, "-1")) {
                        strcpy(phoneNumber, editPhoneNumber);
                    }
                    free(editPhoneNumber);
                    clearTerminal();
                } else if (opt2 == '3') {
                    if (userIsSure("Edit")) {
                        break;
                    }
                } else {
                    error("\n- Unknown option -\n");
                }
            }
        } else if (opt == '3') {
            if (userIsSure("Register")) {
                break;
            }
        } else {
            error("\n- Unknown option -\n");
        }
    }
    clearTerminal();
}

void error(const char* msg) {
    clearTerminal();
    printf("%s", msg);
    system("pause");
    clearTerminal();
}

int userIsSure(const char* msg) {
    int sure = -1;
    char exit;
    while (sure == -1) {
        printf("\n- Exit %s -\n", msg);
        printf("Are you sure? (y/n) ");
        scanf("%c", &exit);
        fflush(stdin);
        clearTerminal();
        if (exit == 'y' || exit == 'Y') {
            sure = 1;
        } else if (exit == 'n' || exit == 'N') {
            sure = 0;
        } else {
            error("\n- Unknown option -\n");
        }
    }
    return sure;
}

char* readName() {
    char* name = NULL;
    size_t len = 0;
    while (1) {
        printf("Name [up to %d chars] ('-1' to decline): ", NAME_SIZE);
        getline(&name, &len, stdin);
        if (isBlank(name)) {
            error("\n- Name cannot be empty -\n");
        } else {
            strip(name);
            if (strlen(name) <= NAME_SIZE) {
                break;
            } else {
                error("\n- Name too long -\n");
            }
        }
    }
    return name;
}

char* readPhoneNumber() {
    char* phoneNumber = NULL;
    size_t len = 0;
    while (1) {
        printf("Phone number [up to %d chars] ('-1' to decline): ", PHONE_NUMBER_SIZE);
        getline(&phoneNumber, &len, stdin);
        if (isBlank(phoneNumber)) {
            error("\n- Phone number cannot be empty -\n");
        } else {
            strip(phoneNumber);
            if (strlen(phoneNumber) <= PHONE_NUMBER_SIZE) {
                break;
            } else {
                error("\n- Phone number too long -\n");
            }
        }
    }
    return phoneNumber;
}