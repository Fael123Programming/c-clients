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

int main() {
    loop();

    return 0;
}

void loop() {
    createRecord();
    char option;
    char exit;
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
        if (option == '1')
            registerClient();
        else if (option == '2')
            printf("\n- Search Client -\n");
        else if (option == '3') {
            clearTerminal();
            printf("\n- Exit Clients -\n");
            printf("Are you sure? [y/n] ");
            scanf("%c", &exit);
            fflush(stdin);
            clearTerminal();
            if (exit == 'y' || exit == 'Y')
                return;
        } else
            error("\n- Unknown option -\n");
        clearTerminal();
    }
}

void registerClient() {
    char* name = NULL;
    int nameLen;
    size_t len = 0;
    while (1) {
        printf("\n- Register New Client -\n");
        printf("%s", drawRow(50, '-'));
        printf("Name [up to %d chars] ('-1' to decline): ", NAME_SIZE);
        getline(&name, &len, stdin);
        strip(name, strlen(name));
        nameLen = strlen(name);
        if (isBlank(name, nameLen))
            error("\n- Name cannot be empty -\n");
        else {
            if (nameLen <= NAME_SIZE)
                break;
            else
                error("\n- Name too long -\n");
        }
    }
    if (!strcmp(name, "-1"))
        return;
    char* phoneNumber = NULL;
    int phoneLen;
    while (1) {
        printf("Phone number [up to %d chars] ('-1' to decline): ", PHONE_NUMBER_SIZE);
        getline(&phoneNumber, &len, stdin);
        strip(phoneNumber, strlen(phoneNumber));
        phoneLen = strlen(phoneNumber);
        if (isBlank(phoneNumber, phoneLen))
            error("\n- Phone number cannot be empty -\n");
        else {
            if (phoneLen <= PHONE_NUMBER_SIZE)
                break;
            else
                error("\n- Phone number too long -\n");
        }
    }
    if (!strcmp(phoneNumber, "-1"))
        return;
    char opt;
    while (1) {
        clearTerminal();
        printf("\n - New client -\n");
        printf("%s", drawRow(50, '-'));
        printf("Name: %s\n", name);
        printf("Phone number: %s\n", phoneNumber);
        printf("%s", drawRow(50, '-'));
        printf("[1] Create          [2] Edit          [3] Cancel\n");
        printf("%s", drawRow(50, '-'));
        printf("-> ");
        scanf("%c", &opt);
        fflush(stdin);
        clearTerminal();

        if (opt == '1') {
            printf("- Created Successfully -\n");
            system("pause");
            break;
        } else if (opt == '2') {
            printf("- Edit Client -\n");
            system("pause");
        } else if (opt == '3')
            break;
        else
            error("\n- Unknown option -\n");
    }
    clearTerminal();
}

void error(const char* msg) {
    clearTerminal();
    printf("%s", msg);
    system("pause");
    clearTerminal();
}