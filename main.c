#include "contact.h"
#include "file.h"

int main()
{
    // all function calls should be inside the main

    AddressBook addressBook;
    // initialize(&addressBook);
    
    addressBook.contactCount = 0;
    
    loadContacts(&addressBook);

    while (1)
    {
        int choice;
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

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createContact(&addressBook);
            break;
        case 2:
            listContacts(&addressBook);
            break;
        case 3:
            searchContact(&addressBook);
            break;
        case 4:
            editContact(&addressBook);
            break;
        case 5:
            deleteContact(&addressBook);
            break;
        case 6:
            saveContacts(&addressBook);
            printf("\n+------------------------------------+\n");
            printf("|      Exiting the program...        |\n");
            printf("+------------------------------------+\n\n");
            sleep(1);
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
