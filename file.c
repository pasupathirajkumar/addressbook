#include <stdio.h>
#include "file.h"

void saveContacts(AddressBook *addressBook)
{
    FILE *fptr = fopen("contact.csv", "w");

    fprintf(fptr, "#%d\n", addressBook->contactCount);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fptr);
}

void loadContacts(AddressBook *addressBook)
{

    FILE *fptr = fopen("contact.csv", "r");
    if (fptr == NULL)
    {
        printf("Contact not found");
        printf("\n");
        return;
    }
    else
    {
        printf("Loading contacts....\n");
        printf("\n");

        fscanf(fptr, "#%d\n", &(addressBook->contactCount));

        printf("Number of contacts: %d\n", addressBook->contactCount);

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            fscanf(fptr, "%[^,],%[^,],%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        fclose(fptr);
    }
}
