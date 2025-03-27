#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>


typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

int name_validate(char name[], AddressBook *addressBook);
int phone_validate(char phone[], AddressBook *addressBook);
int email_validate(char email[], AddressBook *addressBook);
void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);

#endif
