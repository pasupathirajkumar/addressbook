#include "contact.h"
#include "file.h"

int main()
{
    // all function calls should be inside the main

    AddressBook addressBook;
    // initialize(&addressBook);

    addressBook.contactCount = 0; // initialize the contact count to 0

    loadContacts(&addressBook); // load contacts from file

    while (1)
    {
        int choice;

        // display menu

        printf("\n+============= Address Book Menu===========+\n");
        printf("|  Option  |          Description          |\n");
        printf("+===========================================\n");
        printf("|     1    |  Add Contact                  |\n");
        printf("|     2    |  Display All Contacts         |\n");
        printf("|     3    |  Search Contact               |\n");
        printf("|     4    |  Edit Contact                 |\n");
        printf("|     5    |  Delete Contact               |\n");
        printf("|     6    |  Save and Exit                |\n");
        printf("============================================\n");

        // get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user choice
        switch (choice)
        {
        case 1:
            // add contact
            createContact(&addressBook);
            break;
        case 2:
            // display all contacts
            listContacts(&addressBook);
            break;
        case 3:
            // search contact
            searchContact(&addressBook);
            break;
        case 4:
            // edit contact
            editContact(&addressBook);
            break;
        case 5:
            // delete contact
            deleteContact(&addressBook);
            break;
        case 6:
            // save and exit the program store contacts in file
            saveContacts(&addressBook);
            printf("\n+------------------------------------+\n");
            printf("|      Exiting the program...        |\n");
            printf("+------------------------------------+\n\n");
            sleep(1);
            return 0;
        default:
            // invalid choice
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
