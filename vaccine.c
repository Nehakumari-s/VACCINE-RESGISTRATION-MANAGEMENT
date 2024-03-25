
// VACCINE  REGISTRATION VACCINATION 
#include<stdio.h>
int main() 
 {
    char name[100];
    int age;
    char address[100];
    char vaccineType[100];
    printf("Please provide the following information:\n");
    printf("Name: ");   //user provides their name
    scanf("%s", name);
    printf("Age: ");    //user provides their age 
    scanf("%d", &age);
    printf("Address: ");
    scanf("%s", address);
    printf("Vaccine Type: ");
    scanf("%s", vaccineType);
    printf("\nThank you for registering!\n");
    printf("Your registration details:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Address: %s\n", address);
    printf("Vaccine Type: %s\n", vaccineType);
return 0;
}
