#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "vaccine.h"

extern Registration records[MAX_RECORDS];
extern int count;

// Function to validate that the input contains only alphabets and spaces
int isValidName(const char *name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && !isspace(name[i])) {
            return 0; // Invalid character found
        }
    }
    return 1; // Valid name
}

// Function to validate age
int isValidAge(int age) {
    return age >= 1 && age <= 115;
}

// Function to validate contact number
int isValidContact(const char *contact) {
    if (strlen(contact) != 10) {
        return 0; // Contact number is not 10 digits long
    }
    for (int i = 0; i < 10; i++) {
        if (!isdigit(contact[i])) {
            return 0; // Contact number contains a non-digit character
        }
    }
    return 1; // Valid contact number
}

void registerPerson() {
    if (count >= MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
        return;
    }

    records[count].id = count + 1;

    // Validate name
    while (1) {
        printf("Enter name: ");
        fgets(records[count].name, MAX_NAME_LENGTH, stdin);
        strtok(records[count].name, "\n"); // Remove newline character

        if (isValidName(records[count].name)) {
            break; // Valid name entered, exit loop
        } else {
            printf("Invalid name. Please enter only alphabets and spaces.\n");
        }
    }

    // Validate age
    while (1) {
        printf("Enter age: ");
        scanf("%d", &records[count].age);
        getchar(); // Consume newline character

        if (isValidAge(records[count].age)) {
            break; // Valid age entered, exit loop
        } else {
            printf("Invalid age. Please enter an age between 1 and 115.\n");
        }
    }

    // Validate contact number
    while (1) {
        printf("Enter contact number: ");
        fgets(records[count].contact, MAX_CONTACT_LENGTH, stdin);
        strtok(records[count].contact, "\n"); // Remove newline character

        if (isValidContact(records[count].contact)) {
            break; // Valid contact number entered, exit loop
        } else {
            printf("Invalid contact number. Please enter a 10-digit number.\n");
        }
    }

    strcpy(records[count].appointmentDate, "Not scheduled");

    count++;
    printf("User registered successfully with ID %d.\n", records[count - 1].id);
}

