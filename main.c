#include <stdio.h>
#include <string.h>

// Global variables
int MAX_REGISTRATIONS = 100;
int NAME_LENGTH = 50;

// Structure to represent a registration
struct Registration {
    int id;
    char name[50];
    int age;
};

// Global array of registrations
struct Registration registrations[100];
int numRegistrations = 0;

// Function prototypes
void registerPerson();
void displayRegistrations();
void searchRegistrationById();
void displayUserById(int id);
void updateRegistration();
void deleteRegistration();

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
                break;
            case 3:
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
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to register a person
void registerPerson() {
    if (numRegistrations == MAX_REGISTRATIONS) {
        printf("Registration limit reached.\n");
        return;
    }

    struct Registration newRegistration;
    printf("Enter ID: ");
    scanf("%d", &newRegistration.id);

    for (int i = 0; i < numRegistrations; i++) {
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

// Function to display all registrations
void displayRegistrations() {
    if (numRegistrations == 0) {
        printf("No registrations to display.\n");
        return;
    }

    printf("\nID\tName\tAge\n");
    for (int i = 0; i < numRegistrations; i++) {
        printf("%d\t%s\t%d\n", registrations[i].id, registrations[i].name, registrations[i].age);
    }
}


