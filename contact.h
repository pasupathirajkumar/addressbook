#ifndef CONTACT_H
#define CONTACT_H

// Define the maximum number of contacts that can be stored in the address book
#define MAX_CONTACTS 100
#define _GNU_SOURCE

// Include the necessary header files
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Define the structure for a contact
typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Define the structure for an address book
typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

// Declare the function prototypes
int name_validate(char name[], AddressBook *addressBook);
int phone_validate(char phone[], AddressBook *addressBook);
int email_validate(char email[], AddressBook *addressBook);
void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);

// Include the function definitions
#endif
