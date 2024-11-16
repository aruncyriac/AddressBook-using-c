#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

//creating contacts struct
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

//creating array of contacts structure
typedef struct {
    Contact c[MAX_CONTACTS];
    int contactCount; //to maintain the count of contacts
} AddressBook;

//funtion decalration for create contacts
void createContact(AddressBook *addressBook);
//funtion decalration for serach contacts
int searchContact(AddressBook *addressBook,int i);
//funtion decalration for edit contacts
void editContact(AddressBook *addressBook);
//funtion decalration for del contacts
void deleteContact(AddressBook *addressBook);
//funtion decalration for list contacts
void listContacts(AddressBook *addressBook);
//funtion decalration for initialize the contacts to structure
void initialize(AddressBook *addressBook);
//to validate the name
int valname(char *ch);
//function to validate the phone number
int valp(AddressBook *ab,char *ch);
//funtion to validare the email id
int vale(AddressBook *ab,char *ch);
//to write the valid element to structure
void write(AddressBook *ab,char *n,char *p,char *e);
//print entire address book
void print(AddressBook *ab);
//print given elemet in structure
void printele(AddressBook *ab,int i);
//to find name
int fname(AddressBook *ab,char *str);
//to find phone number
int fphone(AddressBook *ab,char *str);
//to find email
int femail(AddressBook *ab,char *str);
//function to sort address book
void sort(AddressBook *ab);
//to swap to struct element with two index is passing
void swap(AddressBook *ab,int i,int j);
//to find which letter has more prioraty and sent the index back
void top(AddressBook *ab,int i,int j);
//void saveContactsToFile(AddressBook *AddressBook);
void suggestContact(AddressBook *ab,char *str);

#endif
