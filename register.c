#include <stdio.h>
#include <string.h>
#include "vaccine.h"

int MAX_REGISTRATIONS = 100;
int NAME_LENGTH = 50;


int numRegistrations = 0;

// Function to register a person
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


