#include <stdio.h>

#define RECORD_PATH "C:\\Users\\Rafae\\OneDrive\\Documentos\\dev\\c\\clients\\record.csv"

// Creates the file to register all customers if not existent.
void createRecord() {
    FILE* record;
    record = fopen(RECORD_PATH, "r");
    if (record == NULL)
        record = fopen(RECORD_PATH, "w");
    fclose(record);
}
