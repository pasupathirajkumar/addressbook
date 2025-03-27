#include "contact.h"

// Function to edit a contact
void editContact(AddressBook *addressBook)
{
    // Display the menu
    printf("\n+------------------------------------+\n");
    printf("|        Edit a contact              |\n");
    printf("+------------------------------------+\n\n");

    // Search for the contact to edit
    int index = searchContact(addressBook);

    // If the contact is not found, return
    if (index == -1)
    {
        return;
    }

    // Get the new contact details
    char name[50];
    char phone[15];
    char email[50];

    char flag = 1;

    // Display the options to edit
    printf("Enter the option to edit\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");

    int choice;
    // Get the user choice
    scanf(" %d", &choice);

    // Process the user choice
    switch (choice)
    {
    case 1:
    {
        flag = 1;

        // Get the new name
        do
        {
            printf("Enter name: ");
            scanf("%s", name);
            flag = name_validate(name, addressBook);

        } while (flag);

        // Copy the new name to the contact details if the name is valid
        strcpy(addressBook->contacts[index].name, name);
        break;
    }
    case 2:
    {
        flag = 1;
        do
        {
            // Get the new phone number
            printf("Enter phone: ");
            scanf("%s", phone);
            flag = phone_validate(phone, addressBook);

        } while (flag);

        // Copy the new phone number to the contact details if the phone number is valid
        strcpy(addressBook->contacts[index].phone, phone);
        break;
    }
    case 3:
    {
        flag = 1;
        do
        {
            // Get the new email
            printf("Enter email: ");
            scanf("%s", email);
            flag = email_validate(email, addressBook);

        } while (flag);

        // Copy the new email to the contact details if the email is valid
        strcpy(addressBook->contacts[index].email, email);
        break;
    }
    default:
        break;
    }

    // Display the edited contact details if the choice is valid (1-3)
    if (choice >= 1 && choice <= 3)
    {

        printf("\n\n+---------------------- --------Contacts----------------------------------+\n");
        printf("|         Name          |       Phone      |              E-mail          |\n");
        printf("+-------------------------------------------------------------------------+\n");

        // Display the edited contact details in a tabular format after editing the contact details
        printf("|     %-15s   |     %-12s |     %-25s|\n", addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);

        printf("+------------------------------------------------------------------------+\n\n");

        printf("\n+------------------------------------+\n");
        printf("|    Contact edited successfully     |");
        printf("\n+------------------------------------+\n\n");
    }
    // Display an error message if the choice is invalid
    else
    {
        printf("\n+------------------------------------+\n");
        printf("|            invalid choice          |");
        printf("\n+------------------------------------+\n\n");
    }
}
