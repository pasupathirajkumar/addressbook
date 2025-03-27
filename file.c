#include <stdio.h>
#include "file.h"

// Function to save the contacts to a file named contact.csv in the current directory
void saveContacts(AddressBook *addressBook)
{
    // Open the file in write mode to save the contacts to the file contact.csv in the current directory
    FILE *fptr = fopen("contact.csv", "w");

    // Check if the file was opened successfully
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Save the number of contacts to the file with a '#' symbol before it to indicate the start of the contact list
    fprintf(fptr, "#%d\n", addressBook->contactCount);

    // Save each contact to the file in the format "name,phone,email"
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    // Close the file
    fclose(fptr);
}

// Function to load the contacts from a file named contact.csv in the current directory
void loadContacts(AddressBook *addressBook)
{

    // Open the file in read mode to load the contacts from the file contact.csv in the current directory
    FILE *fptr = fopen("contact.csv", "r");

    // Check if the file was opened successfully and display an error message if it was not
    if (fptr == NULL)
    {
        printf("Contact not found");
        printf("\n");
        return;
    }
    // If the file was opened successfully, load the contacts from the file
    else
    {
        // Read the number of contacts from the file   
        printf("Loading contacts....\n");
        printf("\n");

        // Read the number of contacts from the file with a '#' symbol before it to indicate the start of the contact list
        fscanf(fptr, "#%d\n", &(addressBook->contactCount));

        printf("Number of contacts: %d\n", addressBook->contactCount);

        // Read each contact from the file in the format "name,phone,email"
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            fscanf(fptr, "%[^,],%[^,],%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        
        // Close the file
        fclose(fptr);
    }
}
