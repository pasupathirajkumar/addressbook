#include "contact.h"

// Function to delete a contact
void deleteContact(AddressBook *addressBook)
{

    // Display the menu
    printf("\n+------------------------------------+\n");
    printf("|        Delete a contact            |\n");
    printf("+------------------------------------+\n\n");

    // Search for the contact to delete
    int index = searchContact(addressBook);

    // If the contact is not found, return
    if (index == -1)
    {
        return;
    }

    printf("Are you sure you want to delete the contact? (y/n): ");

    char choice;

    // Get the user choice
    scanf(" %c", &choice);

    // To confirm the deletion of the contact make sure the user enters 'y' or 'Y'
    if (!(choice == 'y' || choice == 'Y'))
    {
        printf("\n+------------------------------------+\n");
        printf("|        Contact not deleted         |");
        printf("\n+------------------------------------+\n");
        return;
    }

    // Shift the contacts to the left to remove the contact
    for (int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    // Decrement the contact count
    addressBook->contactCount--;

    printf("\n+------------------------------------+\n");
    printf("|    Contact deleted successfully    |");
    printf("\n+------------------------------------+\n\n");
}
