#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
void write(AddressBook *ab,char *n,char *p,char *e)
{
    //this is function is used to write the dummy strings value to the structure elements
    strcpy(ab->c[ab->contactCount].name,n);
    strcpy(ab->c[ab->contactCount].phone,p);
    strcpy(ab->c[ab->contactCount].email,e);
    ab->contactCount++;

}
//print given elemet in structure
void printele(AddressBook *ab,int i)
{
    //funtion to print a contact if the index is passed
    int f = 1;
    
    
    //if it is an invalid index print error message 
    if(i == -1)
    {
        printf("\nElement not found!!!!");

    }
    else
    {
        //printing the element if the index is given
        i--;
        //printf("**********************ADDRESS BOOK******************************");
        printf("\n%-3d. %-20s %-15s %-35s",i,ab->c[i].name,ab->c[i].phone,ab->c[i].email);
       
    }

    
}
void print(AddressBook *ab)
{
    //function to list the entire file
    int i = 1;
    do
    {
        printf("\n*******************ADDRESS BOOK*************************\n");
        printf("\n---------------------------------------------------------");
        printf("\nN.o %-20s %-15s %-35s","NAME","PHONE NUMBER","EMAIL i.d");
        printf("\n---------------------------------------------------------\n");
        for(int i = 0;i < ab->contactCount;i++)
        {
            printf("\n%-3d %-20s %-15s %-35s",i,ab->c[i].name,ab->c[i].phone,ab->c[i].email);
        }
        printf("\nClick 0 for go back\n");
        scanf("%d",&i);
    }while(i != 0);
}
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    //Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

/*void createContact(AddressBook *addressBook)
{
	/* 1. read name
       2. validate name only alpha
       3. read 
}*/






