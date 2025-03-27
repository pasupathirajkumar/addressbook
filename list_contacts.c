#include "contact.h"

// Function to list all contacts in the address book with their details in a tabular format
void listContacts(AddressBook *addressBook)
{
    // Check if the address book is empty and display a message if it is empty
    if (addressBook->contactCount == 0)
    {
        printf("No contacts found\n");
        return;
    }

    // Display the contacts in a tabular format
    printf("\n\n+----------------------------------Contacts--------------------------------------+\n");
    printf("| S.No |         Name          |       Phone      |              E-mail          |\n");
    printf("+--------------------------------------------------------------------------------+\n");

    // Loop through the contacts in the address book and display the contact details in a tabular format
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("|  %02d  |     %-15s   |     %-12s |     %-25s|\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    printf("+--------------------------------------------------------------------------------+\n\n\n");
}
