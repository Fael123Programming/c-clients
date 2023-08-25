#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "client.h"
#include "file.h"
// #include "util.h"

// The application loop.
void loop();

int main() {
    loop();

    return 0;
}

void loop() {
    createRecord();
    char option;
    char exit;
    while (true) {
        printf("-------------------- Clients --------------------\n");
        printf("(1) - Register\n");
        printf("(2) - Search\n");
        printf("(3) - Exit\n");
        printf("-------------------------------------------------\n");
        printf("-> ");
        scanf("%c", &option);
        fflush(stdin);
        clearTerminal();
        if (option == '1')
            printf("\n - Register New Client -\n");
        else if (option == '2')
            printf("\n - Search Client -\n");
        else if (option == '3') {
            clearTerminal();
            printf("\n - Exit Clients -\n");
            printf("Are you sure? [y/n] ");
            scanf("%c", &exit);
            fflush(stdin);
            clearTerminal();
            if (exit == 'y' || exit == 'Y')
                return;
        } else
            printf("\n- Unknown option -\n");
    }
}
