#include "contact.h"

// Function to search for a contact based on name, phone, or email and display the contact details
// Returns the index of the contact in the address book if found, otherwise returns -1
int searchContact(AddressBook *addressBook)
{
    // Check if the address book is empty and display a message if it is empty
    if (addressBook->contactCount == 0)
    {
        printf("\n+------------------------------------+\n");
        printf("|        No contacts found           |");
        printf("\n+------------------------------------+\n");
        return -1;
    }

    // Display the search menu
    printf("\n+------------------------------------+\n");
    printf("|        Search for a contact        |");
    printf("\n+------------------------------------+\n");

    // Get the search option from the user (name, phone, or email)
    printf("Enter the option to search\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");

    // Get the user choice for search option and the search term to search for in the contacts based on the search option chosen
    int choice, serial = 1, index = -1;
    scanf(" %d", &choice);

    char search[50];
    printf("Enter the search term: ");
    scanf(" %s", search);

    printf("\n\n+----------------------------------Contacts--------------------------------------+\n");
    printf("| S.No |         Name          |       Phone      |              E-mail          |\n");
    printf("+--------------------------------------------------------------------------------+\n");

    // Loop through the contacts in the address book and display the contact details based on the search option chosen
    switch (choice)
    {
    case 1:

        // Search for the contact based on the name and display the contact details if the search term is found in the name
        // Display the serial number, name, phone, and email of the contact
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasestr(addressBook->contacts[i].name, search) != NULL)
            {
                printf("|  %02d  |     %-15s   |     %-12s |     %-25s|\n", serial, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                index = i;
                serial++;
            }
        }
        break;
    case 2:
        // Search for the contact based on the phone number and display the contact details if the search term is found in the phone number
        // Display the serial number, name, phone, and email of the contact
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasestr(addressBook->contacts[i].phone, search) != NULL)
            {
                printf("|  %02d  |     %-15s   |     %-12s |     %-25s|\n", serial, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                index = i;
                serial++;
            }
        }
        break;
    case 3:

        // Search for the contact based on the email and display the contact details if the search term is found in the email
        // Display the serial number, name, phone, and email of the contact

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasestr(addressBook->contacts[i].email, search) != NULL)

            {
                printf("|  %02d  |     %-15s   |     %-12s |     %-25s|\n", serial, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                index = i;
                serial++;
            }
        }
        break;
    default:
        // Display an error message if the user choice is invalid
        printf("Invalid choice\n");
        break;
    }

    // Display a message if no contacts are found based on the search term and return -1
    if (serial == 1)
    {
        printf("\t\t\t\tNo contacts found\n");
        printf("+--------------------------------------------------------------------------------+\n");
        return -1;
    }

    printf("+--------------------------------------------------------------------------------+\n");

    // Return the index of the contact in the address book if found based on the search term
    // Otherwise, return -1
    if (serial == 2)
    {
        printf("\n\n\n");
        return index;
    }

    // Get the serial number of the contact to display the particular contact details based on the serial number entered by the user to select the contact to display from the search results displayed
    printf("Enter the serial number to display the particular contact\n");

    int serial_number;

    scanf(" %d", &serial_number);

    // Display an error message if the serial number entered is invalid
    if (serial < serial_number)
    {
        printf("Invalid serial number\n");
        return -1;
    }

    // Display the contact details of the contact selected based on the serial number entered by the user
    serial = 1;

    printf("\n\n+---------------------- --------Contacts----------------------------------+\n");
    printf("|         Name          |       Phone      |              E-mail          |\n");
    printf("+-------------------------------------------------------------------------+\n");

    // Loop through the contacts in the address book and display the contact details based on the search option chosen
    switch (choice)
    {
    case 1:
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // Search for the contact based on the name and display the contact details if the search term is found in the name
            if (strcasestr(addressBook->contacts[i].name, search) != NULL)
            {
                if (serial_number == serial)
                    index = i;
                serial++;
            }
        }
        break;
    case 2:
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // Search for the contact based on the phone number and display the contact details if the search term is found in the phone number
            if (strcasestr(addressBook->contacts[i].phone, search) != NULL)
            {
                if (serial_number == serial)
                    index = i;
                serial++;
            }
        }
        break;
    case 3:
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            // Search for the contact based on the email and display the contact details if the search term is found in the email
            if (strcasestr(addressBook->contacts[i].email, search) != NULL)
            {
                if (serial_number == serial)
                    index = i;
                serial++;
            }
        }
        break;
    }

    // Display the contact details of the contact selected based on the serial number entered by the user
    printf("|     %-15s   |     %-12s |     %-25s|\n", addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);

    printf("+-------------------------------------------------------------------------+\n\n\n");

    // Return the index of the contact in the address book if found based on the search term
    return index;
}
