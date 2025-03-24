# Address Book using C

This project implements a simple Address Book using C, where contact details such as name, phone number, and email are stored and managed efficiently. The program uses structures to store data and provides various functionalities for contact management.

## Features
- **Create Contact**: Add new contacts to the address book.
- **Search Contact**: Look up contacts by name, phone number, or email.
- **Edit Contact**: Modify existing contact details.
- **Delete Contact**: Remove contacts from the address book.
- **Store Data in CSV**: Contact details are stored in a `.csv` file for easy retrieval and persistence.

## File Format
Contacts are stored in a `.csv` file where each entry consists of:
```
Name,Phone Number,Email
```

## Compilation and Execution
```sh
gcc addressbook.c -o addressbook
./addressbook
```

## Usage
Users can interact with the program through a menu-driven interface to perform the desired operations.
