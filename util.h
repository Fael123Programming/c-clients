#include <stdlib.h>

// Clears the given string.
void clearString(char* str, int size) {
    for (int i = 0; i < size; i++)
        *(str + i) = ' ';
}

// Takes all leading and trailing spaces out of the given string.
void strip(char* str, int size) {
    int firstSymb, lastSymb;
    int i, curr;
    for (i = 0; i < size; i++) {
        curr = *(str + i);
        if (curr != ' ') {
            firstSymb = i;
            break;
        }
    }
    for (i = size - 1; i > firstSymb; i--) {
        curr = *(str + i);
        if (curr != ' ') {
            lastSymb = i;
            break;
        }
    }
    char* temp = malloc(size + 1);
    for (i = firstSymb; i <= lastSymb; i++)
        *(temp + (i - firstSymb)) = *(str + i);
    strcpy(str, temp);
}

// Clears terminal.
void clearTerminal() {
    system("cls");
}

// Draw a row of symbols 'symb' with size 'size' and an endline.
char* draw_row(int size, char symb) {
    char* row = malloc(size + 1);
    for (int i = 0; i < size; i++)
        *(row + i) = symb;
    *(row + size) = '\0';
    return row;
}

int is_blank(char* str, int size) {
    int blank = 1, curr;
    for (int i = 0; i < size; i++) {
        curr = *(str + i);
        if (curr != ' ' && curr != '\n' && curr != '\0') {
            blank = 0;
            break;
        }
    }
    return blank;
}