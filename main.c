/*
Name : Arun Cyriac
Date : 08 oct 2024
Project name : Address Book

Discription: In this project we use strurcture  to store datas like name, phone, email of each 
person.The features includes create contact, search contact,edit contacts,delect contants etc. 
All the datas are stored in .csv file
*/
#include <stdio.h>
#include "contact.h"
#include "file.h"

int main() {
    int choice;
    AddressBook addressBook;
    //initialize(&addressBook); 
    //addressBook.contactCount = 0;
    loadContactsFromFile(&addressBook);
    // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        //printf("6. Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        
        switch (choice) 
		{
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook,0);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                sort(&addressBook);
                print(&addressBook);
                break;
            case 6:
                //saveContactsToFile(&addressBook);
                saveContactsToFile(&addressBook);
                printf("Saving and Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
       return 0;
}
