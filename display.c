#include <stdio.h>
#include "vaccine.h"


// Global array of registrations
struct Registration registrations[100];

//Function to display all registrations
void displayRegistrations() {
	int numRegistrations = 0;

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
