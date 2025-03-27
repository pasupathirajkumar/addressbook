#include"contact.h"


void createContact(AddressBook *addressBook)
{
    char name[50];
    char phone[15];
    char email[50];

    printf("\n+----------------------------------+\n");
    printf("|        Create a new contact      |\n");
    printf("+----------------------------------+\n\n");

    char flag = 1;
    do
    {
        printf("Enter name: ");
        scanf("%s", name);
        flag = name_validate(name, addressBook);

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

    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);

    addressBook->contactCount++;

    printf("\n+------------------------------------+\n");
    printf("|    Contact created successfully    |");
    printf("\n+------------------------------------+\n");
    
    sleep(1);
}
