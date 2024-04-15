#ifndef VACCINE_H
#define VACCINE_H

#include<stdio.h>
struct Registration {
    int id;
    char name[50];
    int age;
};
struct Registration registrations[100];
void registerPerson();

void displayRegistrations();

#endif
