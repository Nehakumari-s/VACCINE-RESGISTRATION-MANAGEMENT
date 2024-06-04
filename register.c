#include <stdio.h>
#include <string.h>
#include "vaccine.h"

extern Registration records[MAX_RECORDS];
extern int count;

void registerPerson() {
    if (count >= MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
        return;
    }

    records[count].id = count + 1;

    printf("Enter name: ");
    fgets(records[count].name, MAX_NAME_LENGTH, stdin);
    strtok(records[count].name, "\n"); // Remove newline character

    printf("Enter age: ");
    scanf("%d", &records[count].age);
    getchar(); // Consume newline character

    printf("Enter contact number: ");
    fgets(records[count].contact, MAX_CONTACT_LENGTH, stdin);
    strtok(records[count].contact, "\n"); // Remove newline character

    strcpy(records[count].appointmentDate, "Not scheduled");

    count++;
   // printf("User registered successfully with ID %d.\n", records[count - 1].id);
}
