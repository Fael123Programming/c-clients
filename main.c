#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "client.h"
#include "file.h"

// The application loop.
void loop();

// Register new clients.
void register_client();

// Prints out an error msg.
void error(const char*);

int main() {
    // loop();
    char str[5] = " a  ";
    strip(str, 5);
    printf("'%s'\n", str);

    return 0;
}

void loop() {
    createRecord();
    char option;
    char exit;
    while (true) {
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
            register_client();
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
            printf("\n- Unknown option -\n");
        clearTerminal();
    }
}

void register_client() {
    struct client c;
    clearString(c.name, NAME_SIZE);
    clearString(c.phoneNumber, PHONE_NUMBER_SIZE);
    while (1) {
        printf("\n- Register New Client -\n");
        printf("Name [up to %d chars] ('-1' to get back): ", NAME_SIZE);
        fgets(c.name, NAME_SIZE + 1, stdin);
        fflush(stdin);
        if (is_blank(c.name, NAME_SIZE))
            error("\n- Name cannot be empty -\n");
        else {
            strip(c.name, NAME_SIZE);
            printf("%s\n%d\n", c.name, strlen(c.name));
            if (strlen(c.name) <= NAME_SIZE)
                break;
            else
                error("\n- Name too long -\n");
        }
    }
    if (!strcmp(c.name, "-1"))
        return;
    while (1) {
        printf("Phone number [up to %d chars] ('-1' to get back): ", PHONE_NUMBER_SIZE);
        fgets(c.phoneNumber, PHONE_NUMBER_SIZE + 1, stdin);
        fflush(stdin);
        if (is_blank(c.phoneNumber, PHONE_NUMBER_SIZE))
            error("\n- Phone number cannot be empty -\n");
        else {
            strip(c.phoneNumber, PHONE_NUMBER_SIZE);
            if (strlen(c.phoneNumber) <= PHONE_NUMBER_SIZE)
                break;
            else
                error("\n- Phone number too long -\n");
        }
    }
    if (!strcmp(c.phoneNumber, "-1"))
        return;
    clearTerminal();
    printf("%s", draw_row(50, '-'));
    printf("\n - New client registered -\n");
    system("pause");
    clearTerminal();
}

void error(const char* msg) {
    clearTerminal();
    printf("%s", msg);
    system("pause");
    clearTerminal();
}