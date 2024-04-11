#include <stdio.h>
#include"vaccine.h"


//int MAX_REGISTRATIONS = 100;
//int NAME_LENGTH = 50;
// Structure to represent a registration
struct Registration {
    int id;
    char name[50];
    int age;
};

// Global array of registrations
struct Registration registrations[100];
int numRegistrations = 0;


//Function to display all registrations
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
