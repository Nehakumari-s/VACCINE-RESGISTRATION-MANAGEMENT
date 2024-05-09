#include<stdio.h>
#include "vaccine.h"
#include "register.c"
#include "display.c"

int main() {
    int choice;

    do {
        printf("\nVaccine Registration Application\n");
        printf("1. Register Person\n");
        printf("2. Display Registrations\n");
        printf("3. Search Registration by ID\n");
        printf("4. Update Registration\n");
        printf("5. Delete Registration\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerPerson();
                break;
            case 2:
                displayRegistrations();
                readRegistrationsFromFile("registrations.txt");
                writeRegistrationsToFile("registrations_backup.txt");
                break;
            /*case 3:
                searchRegistrationById();
                break;
            case 4:
                updateRegistration();
                break;
            case 5:
                deleteRegistration();
                break;
            case 6:
                printf("Exiting program.\n");
                break;*/
            default:
                printf("Invalid choice. Please try again.\n");
            }
    } while (choice != 2);

    return 0;
}


