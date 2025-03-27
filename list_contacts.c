#include "contact.h"


void listContacts(AddressBook *addressBook)
{
    if (addressBook->contactCount == 0)
    {
        printf("No contacts found\n");
        return;
    }

    printf("\n\n+----------------------------------Contacts--------------------------------------+\n");
    printf("| S.No |         Name          |       Phone      |              E-mail          |\n");
    printf("+--------------------------------------------------------------------------------+\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("|  %02d  |     %-15s   |     %-12s |     %-25s|\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    printf("+--------------------------------------------------------------------------------+\n\n\n");
}
