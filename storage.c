#include <stdio.h>
#include "vaccine.h"

void saveRecords(Registration records[], int count) {
    FILE *file = fopen("records.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, file);
    fwrite(records, sizeof(Registration), count, file);
    fclose(file);
    printf("Records saved successfully.\n");
}

void loadRecords(Registration records[], int *count) {
    FILE *file = fopen("records.dat", "rb");
    if (file == NULL) {
        printf("No existing records found.\n");
        return;
    }
    fread(count, sizeof(int), 1, file);
    fread(records, sizeof(Registration), *count, file);
    fclose(file);
    printf("Records loaded successfully.\n");
}
