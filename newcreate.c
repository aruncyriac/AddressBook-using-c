#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
//*****************************************
int vale(AddressBook *ab,char *ch)
{
    //this function will validate the email
    //if it not a valide email the function will return 1
    //if it not a unique email  in file it will return 2
    int i; 
    char str[20] = "@gmail.com";  
    char *s;
    if(strcmp(ch,str) == 0)
    {
        return 1;   //checking for ch = @gmail.com
    }
    //checking ch is valid email
    s = strstr(ch,str);
    //we will get address of the '@'
    if(s == NULL)
    {
        return 1;
    }
    else if(strcmp(s,str) != 0)   //comparing s is @gmail.com
    {
        return 1;
    }
    
//checking the entered email is unique in file
    for(i = 0;i < ab->contactCount;i++)
    {
        if(strcmp(ab->c[i].email,ch) == 0)
        {
            return 2;
        }
    }
    return 0; 
}
//****************************************************************
int valp(AddressBook *ab,char *ch)
{
    //this function will validate the phone number
    //if it not a valide number the function will return 1
    //if it not a unique number in file it will return 2
    int i;
    for(i = 0;ch[i] != '\0';i++)
    {
        //checking enter number is from 0-9
        if(ch[i] >= '0' && ch[i] <= '9')
        {
            continue;
        }
        else
        {
            return 1;
        }
    }
    //checking the number contain 10 digits
    if(strlen(ch) != 10)
    {
        return 1;
    }
    //checking the number is unique in file
    for(i = 0;i < ab->contactCount;i++)
    {
        if(strcmp(ab->c[i].phone,ch) == 0)
        {
            return 2;
        }
    }
    return 0;
}
//**************************************************** 
int valname(char *ch)
{
    //function to validate namr
    int i;
    //to check wheathe string contain alpa. and space
    for(i = 0;ch[i] != '\0';i++)
    {
        if((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <='Z') || ch[i] == ' ')
        {
            continue;
        }
        else
        {
            return 1;
        }

    }
    return 0;
}
//______________________________________
//______________________________________
void createContact(AddressBook *ab)
{
    //function to create contacts
    int i = 0;
    int l = 0;
    char n[50],p[20],e[50]; //creating dummy variable for name, phone, email
    do
    {
        printf("\n**************CREATE CONTACT***************\n");
        do
        {
            printf("Enter the name: ");
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
        }while(l != 0);
            //if name is valid read phone number
        if(i == 0)
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
            }while(l != 0);
            //if phone number is valid enter email
            if(i != 1)
            {
                if(i != 2)
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
                    }while(l != 0);
                }
            }
        }
        if(i != 1)
        {
            //if name, phone, email are valid copy value in dummy string to file
            write(ab,n,p,e);
            //print the saved element
            printele(ab,ab->contactCount);
        }
       
        
        printf ("\nPress 1 to create contact again and 0 to go back\n");
        __fpurge(stdin);
        scanf("%d",&i);
    } while (i != 0);
    
}