#include "contact.h"

int name_validate(char name[], AddressBook *addressBook)
{
    if (strlen(name) < 3)
    {
        printf("Name should be at least 3 characters\n");
        return 1;
    }

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z'))
        {
            printf("Invalid name\n");
            return 1;
        }
    }

    return 0;
}

int phone_validate(char phone[], AddressBook *addressBook)
{
    if (strlen(phone) != 10)
    {
        printf("Phone number should be 10 digits\n");
        return 1;
    }

    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (!(phone[i] >= '0' && phone[i] <= '9'))
        {
            printf("Invalid phone number\n");
            return 1;
        }
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            printf("Phone number already exists\n");
            return 1;
        }
    }

    return 0;
}

int email_validate(char email[], AddressBook *addressBook)
{
    int at = 0;
    int dot = 0;

    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            at++;
        if (email[i] == '.')
            dot = 1;
    }

    if (at != 1 || dot != 1)
    {
        printf("Invalid email\n");
        return 1;
    }
    // before @ and after @ should be at least 1 character

    char *ptr;

    if (email[0] == '@' || email[0] == '.')
    {
        printf("Invalid email\n");
        return 1;
    }
    
    ptr = strchr(email, '@');

    if (!(*(ptr + 1) >= 'a' && *(ptr + 1) <= 'z' || *(ptr + 1) >= 'A' && *(ptr + 1) <= 'Z'))
    {
        printf("Invalid email\n");
        return 1;
    }

    // unique email
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(email, addressBook->contacts[i].email) == 0)
        {
            printf("Email already exists\n");
            return 1;
        }
    }

    return 0;
}
