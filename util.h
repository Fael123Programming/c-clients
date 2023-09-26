#include <stdlib.h>

// Clears the given string.
void clearString(char* str, int size) {
    for (int i = 0; i < size - 1; i++)
        *(str + i) = ' ';
}

// Takes all leading and trailing spaces out of the given string.
void strip(char* str) {
    int size = -1;
    while (str[++size] != '\0');
    int p1 = -1, p2 = -1, i;
    char s, e;
    for (i = 0; i < size; i++) {
        s = str[i];
        e = str[size - 1 - i];
        if (p1 == -1 && s != ' ' && s != '\n' && s != '\t')
            p1 = i;
        if (p2 == -1 && e != ' ' && e != '\n' && e != '\t' && e != '\0')
            p2 = size - 1 - i;
    }
    char* temp = malloc(sizeof(char) * (p2 - p1 + 2));
    for (i = p1; i <= p2; i++)
        temp[i - p1] = str[i];
    temp[i - p1] = '\0';
    strcpy(str, temp);
    free(temp);
}

// Clears terminal.
void clearTerminal() {
    system("cls");
}

// Draw a row of symbols 'symb' with size 'size' and an endline.
char* drawRow(int size, char symb) {
    char* row = malloc(size + 2);
    for (int i = 0; i < size; i++)
        *(row + i) = symb;
    *(row + size) = '\n';
    *(row + size + 1) = '\0';
    return row;
}

int isBlank(char* str) {
    int blank = 1, curr, i;
    for (i = 0; str[i] != '\0'; i++) {
        curr = str[i];
        if (curr != ' ' && curr != '\n' && curr != '\r' && curr != '\0') {
            blank = 0;
            break;
        }
    }
    return blank;
}