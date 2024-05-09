
#include <stdio.h>
#include "vaccine.h"

#define MAX_REGISTRATIONS 100

// Global array of registrations
struct Registration registrations[MAX_REGISTRATIONS];
int numRegistrations = 0;

// Function to display all registrations
void displayRegistrations() {
    if (numRegistrations == 0) {
        printf("No registrations to display.\n");
        return;
    }

    printf("\nID\tName\tAge\n");
    int i;
    for (i = 0; i < numRegistrations; i++) {
        printf("%d\t%s\t%d\n", registrations[i].id, registrations[i].name, registrations[i].age);
    }
}

// Function to read registrations from a file
void readRegistrationsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    while (fscanf(file, "%d %s %d", &registrations[numRegistrations].id, registrations[numRegistrations].name, &registrations[numRegistrations].age) == 3) {
        numRegistrations++;
        if (numRegistrations >= MAX_REGISTRATIONS) {
            printf("Maximum registrations reached. Ignoring further entries.\n");
            break;
        }
    }

    fclose(file);
}

// Function to write registrations to a file
void writeRegistrationsToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
     int i;
    for (i = 0; i < numRegistrations; i++) {
        fprintf(file, "%d %s %d\n", registrations[i].id, registrations[i].name, registrations[i].age);
    }

    fclose(file);
}

