#include "contact.h"

void createContact(AddressBook *addressBook)
{
    // create a new contact
    char name[50];  // name of the contact
    char phone[15]; // phone number of the contact
    char email[50]; // email of the contact

    printf("\n+----------------------------------+\n"); // displaying the menu
    printf("|        Create a new contact      |\n");
    printf("+----------------------------------+\n\n");

    char flag = 1;
    do
    {
        // get name from user

        printf("Enter name: ");
        scanf("%s", name);
        flag = name_validate(name, addressBook);
        // validating the name
    } while (flag);

    printf("✅ Name is valid\n\n");

    flag = 1;
    do
    {
        printf("Enter phone: ");
        scanf("%s", phone);
        flag = phone_validate(phone, addressBook);

    } while (flag);

    printf("✅ Phone is valid\n\n");

    flag = 1;
    do
    {
        printf("Enter email: ");
        scanf("%s", email);
        flag = email_validate(email, addressBook);

    } while (flag);

    printf("✅ Email is valid\n");

    // add the contact to the address book
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);

    // increment the contact count
    addressBook->contactCount++;

    // display success message
    printf("\n+------------------------------------+\n");
    printf("|    Contact created successfully    |");
    printf("\n+------------------------------------+\n");

    // wait for 1 second
    sleep(1);
}
