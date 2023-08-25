#include <stdlib.h>

// Clears the given string.
void clearString(char* str, int size) {
    for (int i = 0; i < size; i++)
        *(str + i) = ' ';
}

// Clears terminal.
void clearTerminal() {
    system("cls");
}
