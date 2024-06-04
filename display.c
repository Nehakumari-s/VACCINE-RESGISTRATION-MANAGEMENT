#include <stdio.h>
#include <string.h>
#include "vaccine.h"

extern Registration records[MAX_RECORDS];
extern int count;

void displayRegistrations() {
    for (int i = 0; i < count; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("Contact: %s\n", records[i].contact);
        printf("Appointment Date: %s\n", records[i].appointmentDate);
    }
}

void searchRegistrationById() {
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            printf("\nRecord found\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Contact: %s\n", records[i].contact);
            printf("Appointment Date: %s\n", records[i].appointmentDate);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}

void updateRegistration() {
    int id, found = 0;

    printf("Enter ID to update: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            printf("Enter new name: ");
            fgets(records[i].name, MAX_NAME_LENGTH, stdin);
            strtok(records[i].name, "\n"); // Remove newline character

            printf("Enter new age: ");
            scanf("%d", &records[i].age);
            getchar(); // Consume newline character

            printf("Enter new contact number: ");
            fgets(records[i].contact, MAX_CONTACT_LENGTH, stdin);
            strtok(records[i].contact, "\n"); // Remove newline character

            printf("Enter new appointment date (YYYY-MM-DD): ");
            fgets(records[i].appointmentDate, 11, stdin);
            strtok(records[i].appointmentDate, "\n"); // Remove newline character

            printf("Record with ID %d updated successfully.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}

void deleteRegistration() {
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                records[j] = records[j + 1];
            }
            count--;
            printf("Record with ID %d deleted successfully.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}
