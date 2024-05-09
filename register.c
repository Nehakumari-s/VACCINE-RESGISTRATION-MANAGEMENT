#include <stdio.h>
#include <string.h>
#include "vaccine.h"

#define MAX_REGISTRATIONS 100
#define NAME_LENGTH 50

/*struct Registration {
    int id;
    char name[NAME_LENGTH];
    int age;
};*/

struct Registration registrations[MAX_REGISTRATIONS];
int numRegistrations = 0;

// Function prototypes
void registerPerson();
void saveRegistrationsToFile(const char *filename);
void loadRegistrationsFromFile(const char *filename);






void registerPerson() {
    if (numRegistrations == MAX_REGISTRATIONS) {
        printf("Registration limit reached.\n");
        return;
    }

    struct Registration newRegistration;
    printf("Enter ID: ");
    scanf("%d", &newRegistration.id);
    int i;
    for (i = 0; i < numRegistrations; i++) {
        if (registrations[i].id == newRegistration.id) {
            printf("ID already exists. Please enter a different ID.\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf("%s", newRegistration.name);
    printf("Enter Age: ");
    scanf("%d", &newRegistration.age);

    registrations[numRegistrations++] = newRegistration;
    printf("Registration successful.\n");
}

void saveRegistrationsToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    int i;
    for (i= 0; i < numRegistrations; i++) {
        fprintf(file, "%d %s %d\n", registrations[i].id, registrations[i].name, registrations[i].age);
    }

    fclose(file);
}

void loadRegistrationsFromFile(const char *filename) {
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
