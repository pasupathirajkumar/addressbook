#include "contact.h"

void deleteContact(AddressBook *addressBook)
{

    printf("\n+------------------------------------+\n");
    printf("|        Delete a contact            |\n");
    printf("+------------------------------------+\n\n");

    int index = searchContact(addressBook);

    if (index == -1)
    {
        return;
    }

    printf("Are you sure you want to delete the contact? (y/n): ");

    char choice;

    scanf(" %c", &choice);

    if (!(choice == 'y' || choice == 'Y'))
    {
        printf("\n+------------------------------------+\n");
        printf("|        Contact not deleted         |");
        printf("\n+------------------------------------+\n");
        return;
    }

    for (int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf("\n+------------------------------------+\n");
    printf("|    Contact deleted successfully    |");
    printf("\n+------------------------------------+\n\n");
}
