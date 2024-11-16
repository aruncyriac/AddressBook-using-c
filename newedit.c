#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
void editContact(AddressBook *ab)
{
    //creating dummy string for name, phone number, email id
	char n[50];
    char p[20];
    char e[50];
    int i,f,t,l;
    //variable f - to store option
    //variable i - to store return value of serarchcontacts
    //variable t - to store return value of edit contact
    //to repeat each rentry wrong element
    do
    {
        i = searchContact(ab,1);
        t = 2; //if element found value t will not change so enter the second if condition
        if(i == -1)
        {
            //if element not found
            //printf("\nElement Not Found!!!\n");
            printf("\nPress 1 for serach again or 0 for Exit\n");
            scanf("%d",&t);
        }
        if(t == 2)
        {
            do
            {
                //printing edit menu
                printf("\n***********************EDIT CONTACT************************");
                printf("\nEdit\n1.Name\n2.Phone number\n3.Email\n4.Back\nEnter your option: ");
                //entering the option
                scanf("%d",&f);
                if(f == 1)
                {
                    do
                    {
                        printf("Enter the new name: ");
                        __fpurge(stdin);
                        scanf("%49[^\n]",n);//read name
                        //validate name
                        i = valname(n);
                        l = 0;
                        if(i != 0) 
                        {
                            printf("\nInvalid Name !!!");
                            printf("\npress 1 to Enter name again or 0 to exit\n");
                            scanf("%d",&l);
                        }
                        else
                        {
                            strcpy(ab->c[i].name,n);
                        }
                    }while(l != 0);
                }
                //if name is valid read phone number
                if(f == 2)
                {
                    do
                    {
                        printf("\nEnter the Phone number: ");
                        __fpurge(stdin);
                        //read phone number
                        scanf("%11[^\n]",p);
                        //validate the phone number
                        i = valp(ab,p);
                        l = 0;
                        if(i == 1)
                        {
                            //error message for invalid phone
                            printf("\nInvalid Phone number");
                        }
                        else  if (i == 2)
                        {
                            //error message for phone is not unique
                            printf ("\nPhone Number already exits");
                            i = 1;
                        }
                        if(i == 1 || i == 2)
                        {
                        printf("\nPress 1 to enter the phone again or 0 to Exit\n");
                        scanf("%d",&l);
                        }
                        else
                        {
                            strcpy(ab->c[i].phone,p);
                        }
                    }while(l != 0);
                }
                //enter email
                if(f == 3)
                {
                    
                    do
                    {
                        printf("\nEnter the email: ");
                        __fpurge(stdin);
                        //enter email id
                        scanf("%49[^\n]",e);
                        //validate email address
                        i = vale(ab,e);
                        if(i == 1)
                        {
                            //error message for invalid email
                            printf("\nInvalid email id");
                        }
                        else  if (i == 2)
                        {
                            //error message for email is not unique
                            printf ("\nEmail Id already exits");
                            i = 1;
                        }
                        l = 0;
                        if(i == 1 || i == 2)
                        {
                            printf("\nPress 1 to enter the phone again or 0 to Exit\n");
                            scanf("%d",&l);
                        }
                        else
                        {
                            strcpy(ab->c[i].email,e);
                        }
                    }while(l != 0);
                }
            
                if(f != 4)
                {
                    printf ("\nPress 1 to Edit any other element and 4 to go back\n");
                    __fpurge(stdin);
                    scanf("%d",&f);
                }
            }while(f != 4);
        }
        if(t != 0 )
        {
            if(t != 1)
            {
                if(f == 4)
                {
                    t = 0;
                }
                else
                {
                    printf ("\nPress 1 to Edit agian and 0 to go back\n");
                    __fpurge(stdin);
                    scanf("%d",&t);
                }
            }
        }

    }while(t != 0);
}


   
