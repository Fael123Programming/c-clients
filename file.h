#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORD_PATH "C:/Users/Rafae/OneDrive/Documentos/dev/c/clients/record.csv"

// Creates the file to register all customers if not existent.
void createRecordIfNotExist() {
    FILE* record;
    record = fopen(RECORD_PATH, "r");
    if (record == NULL) {
        record = fopen(RECORD_PATH, "w");
        fprintf(record, "name,phone_number\n"); 
    }
    fclose(record);
}

char* serialize(char* name, char* phoneNumber) {
    char* tuple = (char*) calloc(strlen(name) + strlen(phoneNumber) + 3, sizeof(char));
    strcpy(tuple, name);
    strcat(tuple, ",");
    strcat(tuple, phoneNumber);
    strcat(tuple, "\n");
    return tuple;   
}

int customerExists(char* name, char* phoneNumber) {
    FILE* record;
    record = fopen(RECORD_PATH, "r");
    if (record == NULL) {
        printf("Can't open file at '%s'\n", RECORD_PATH);
	exit(-1);
    }
    char* ser = serialize(name, phoneNumber);
    char* line = NULL;
    size_t s = 0;
    int resp = 0;
    while (getline(&line, &s, record) != EOF) {
        if (!strcmp(line, ser)) {
	    resp = 1;
	    break;
	}
    }
    fclose(record);
    if (line) {
        free(line);
    }
    return resp;
}

int appendToRecord(char* name, char* phoneNumber) {
    createRecordIfNotExist();
    if (customerExists(name, phoneNumber)) {
        return 0;
    }
    FILE* record; 
    record = fopen(RECORD_PATH, "a");
    if (fputs(serialize(name, phoneNumber), record) == EOF) {
        printf("Error in fputs");
	exit(-1);
    }
    fclose(record);
    return 1;
}
