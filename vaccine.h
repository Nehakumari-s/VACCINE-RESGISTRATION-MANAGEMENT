#ifndef VACCINE_H
#define VACCINE_H

#define MAX_NAME_LENGTH 100
#define MAX_CONTACT_LENGTH 15
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char contact[MAX_CONTACT_LENGTH];
    char appointmentDate[11];  // Format: YYYY-MM-DD
} Registration;

void registerPerson();
void displayRegistrations();
void searchRegistrationById();
void updateRegistration();
void deleteRegistration();
void saveRecords(Registration records[], int count);
void loadRecords(Registration records[], int *count);

#endif // VACCINE_H
