#define _GNU_SOURCE char *strcasestr(const char *haystack,const char *needle);
//to remove the warning stracsestr
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
//find name*****************
int fname(AddressBook *ab,char *str)
{
    //function to find the name in the string passed is present in the structure or not
    //return the position of if found
    //else return -1
    int i;
    for(i = 0;i < ab->contactCount;i++)
    {
        if(strcasecmp(ab->c[i].name,str) == 0)
        {
           //if the name is found 
            return i+1;
        }
    }
    return -1; //if name is not found
}
//to find phone number
int fphone(AddressBook *ab,char *str)
{
    //funtion to find the postion of the phone number
    //if found return the postion
    //else the return -1
    int i;
    for(i = 0;i < ab->contactCount;i++)
    {
        if(strcmp(ab->c[i].phone,str) == 0)
        {
            //element found return position
            return i+1;
        }
    }
    //element not found return -1
    return -1;

}
//to find email
int femail(AddressBook *ab,char *str)
{
    int i;
    //function to find the email id from file 
    //if found return position
    //else return -1
    for(i = 0;i < ab->contactCount;i++)
    {
        if(strcmp(ab->c[i].email,str) == 0)
        {
            //element found so return position
            return i+1;
        }
    }
    //element not found return -1
    return -1;

}
void suggestContact(AddressBook *ab,char *str)
{
    //to if the entered name is not matched 
    //this function will give suggestion base on the entered name

    char *ptr;
    for(int i = 0;i < ab->contactCount;i++)
    {
        //to check entire contact book
        ptr = strcasestr(ab->c[i].name,str);
        if(ptr != NULL) // if simillar elemnet found 
        {
            printele(ab,i + 1);//print the element
        }
    }
}
int searchContact(AddressBook *ab,int n) 
{
    //this function have to charactertic if called by the option 2-search contact n will equal to 0
    //in this case we will not return any thing
    //
    //if n = 1 : to serach the postion of contact for edit contact and delect contact
    //in this case we return position
    int f = 1,i;
    //decalare a dummy string to read name, phone number, email id
    char str[50];
    do
    {
        //print search menu
        printf("\n*****************SEARCH CONTACT**********************\nsearch via\n1.Name\n2.Phone\n3.email\n4.Back\nEnter your option: ");
        //reading the option
        scanf("%d",&f);
    
        if(f == 1)
        {
            printf("\nEnter the name: ");
            //printf("%s",ab->c[1].name);
            __fpurge(stdin);
            //read the dummy string
            scanf("%49[^\n]",str);
            //finding the position 
            i = fname(ab,str);
            //printing the position  
            if(i == -1)
            {
                printf("\nDo you mean?");
                suggestContact(ab,str);
            }
            printele(ab,i);
            if(n == 1)
            {
                //returning position
                return i;
            }
        }
        else if(f == 2)
        {
            printf("\nEnter the phone number: ");
            __fpurge(stdin);
            //enter the email for finding the match
            scanf("%49[^\n]",str);
             //finding the position 
            i = fphone(ab,str);
             //printing the position  
            printele(ab,i);
             if(n == 1)
            {
                //returning position
                return i;
            }
        }
        else if(f == 3)
        {
            printf("\nEnter the email: ");
            __fpurge(stdin);
             //enter the email for finding the match
            scanf("%49[^\n]",str);
             //finding the position 
            i = femail(ab,str);
            //printing the position 
            printele(ab,i);
             if(n == 1)
            {
                //returning position
                return i;
            }
        }
        if(i != -1)
        {
            f = 4;
        }
        else if(n != 1 )
        {
            if(f != 4)
            {
                printf("\nPress 1 search again and 4 to exit\n  ");
                scanf("%d",&f);
            }
        }
    } while (f != 4);
    

}