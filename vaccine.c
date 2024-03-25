
// VACCINE  REGISTRATION VACCINATION 
#include<stdio.h>
#include<string.h>
void display_user();
void register_user();

int maxRegistrations = 100;
int nameLength = 50;
int registrationIds[100];
char names[100][50];
int ages[100];
int numRegistrations = 0;


//function to register the user

void register_user()
{
	if(numRegistrations == maxRegistrations)
	{
		printf("registration limit reached.\n");
	}
	 int id;
	 int i;
	 printf("enter id:");
	 scanf("%d",&id);
	 
	 for (i = 0; i < numRegistrations; i++) {
        if (registrationIds[i] == id) {
            printf("ID already exists. Please enter a different ID.\n");
            return;
        }
    }

    registrationIds[numRegistrations] = id;
    printf("Enter Name: ");
    scanf("%s", names[numRegistrations]);
    printf("Enter Age: ");
    scanf("%d", &ages[numRegistrations]);

    numRegistrations++;
    printf("Registration successful.\n");
}


//function to display user
void display_users()
{
	
}



int main() 
 {
    int choice;
    do {
        printf("\nVaccine Registration Management\n");
        printf("1. Register User\n");
        printf("2. Display Registered Users\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                display_users();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);


}
