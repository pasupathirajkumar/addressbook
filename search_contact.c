#include"contact.h"

int searchContact(AddressBook *addressBook)
{
    if (addressBook->contactCount == 0)
    {
        printf("\n+------------------------------------+\n");
        printf("|        No contacts found           |");
        printf("\n+------------------------------------+\n");
        return -1;
    }

    printf("\n+------------------------------------+\n");
    printf("|        Search for a contact        |");
    printf("\n+------------------------------------+\n");

    printf("Enter the option to search\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    int choice, serial = 1, index = -1;
    scanf(" %d", &choice);

    char search[50];
    printf("Enter the search term: ");
    scanf(" %s", search);

    printf("\n\n+----------------------------------Contacts--------------------------------------+\n");
    printf("| S.No |         Name          |       Phone      |              E-mail          |\n");
    printf("+--------------------------------------------------------------------------------+\n");

    switch (choice)
    {
    case 1:
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
        printf("Invalid choice\n");
        break;
    }

    if (serial == 1)
    {
        printf("\t\t\t\tNo contacts found\n");
        printf("+--------------------------------------------------------------------------------+\n");
        return -1;
    }

    printf("+--------------------------------------------------------------------------------+\n");

    if (serial == 2)
    {
        printf("\n\n\n");
        return index;
    }

    printf("Enter the serial number to display the particular contact\n");

    int serial_number;

    scanf(" %d", &serial_number);

    if (serial < serial_number)
    {
        printf("Invalid serial number\n");
        return -1;
    }

    serial = 1;

    printf("\n\n+---------------------- --------Contacts----------------------------------+\n");
    printf("|         Name          |       Phone      |              E-mail          |\n");
    printf("+-------------------------------------------------------------------------+\n");

    switch (choice)
    {
    case 1:
        for (int i = 0; i < addressBook->contactCount; i++)
        {
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
            if (strcasestr(addressBook->contacts[i].email, search) != NULL)
            {
                if (serial_number == serial)
                    index = i;
                serial++;
            }
        }
        break;
    }

    printf("|     %-15s   |     %-12s |     %-25s|\n", addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);

    printf("+-------------------------------------------------------------------------+\n\n\n");

    return index;
}
