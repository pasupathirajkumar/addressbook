**AddressBook**
    The AddressBook project is a simple C-based application for managing contacts. It allows users to create, edit, delete, search, and list contacts, as well as save and load contact data from a file.

**Features**
**Add Contact:** Create a new contact with name, phone number, and email.
**Edit Contact:** Modify the details of an existing contact.
**Delete Contact:** Remove a contact from the address book.
**Search Contact:** Search for a contact by name, phone number, or email.
**List Contacts:** Display all contacts in the address book.
**Save and Load:** Save contacts to a file and load them when the application starts.

**Project Structure**
-> How to Compile and Run
-> Open a terminal in the AddressBook directory.

**Compile the project using gcc:**
-> gcc -o AddressBook Main_menu_and_function_call.c Add_contact.c Edit_contact.c Delete_contact.c Search_contact.c save_and_load.c Validations_file.c -Wall
-> Run the compiled program: ./AddressBook

**Usage**
-> When the program starts, you will see a menu with options to add, edit, delete, search, list, or exit.
-> Enter the corresponding number to perform an action.
-> Follow the prompts to input or modify contact details.
-> The program automatically saves changes to contact.dat.

**Validation Rules**
-> Name: Must be at least 3 characters long and contain only alphabetic characters.
-> Phone: Must be exactly 10 digits and unique.
-> Email: Must contain exactly one @ and at least one . and be unique.

**File Descriptions**
-> contact.dat: Stores the contact data in a binary format.
-> Headers.h: Contains type definitions for Contact and AddressBook, as well as function declarations.

**Future Enhancements**
-> Add support for exporting contacts to a CSV file.
-> Implement sorting of contacts by name, phone, or email.
-> Add a graphical user interface (GUI).

**License**
->This project is open-source and available under the MIT License.

Developed by Pasupathi raj kumar M
