#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void deleteContact(AddressBook *ab)
{
	int i,f,iter;
    char str[50];//dummy string to seacrch element to print
    do
    {
        //print menu
        printf("\n******************DELECT CONTACT*******************");
        printf("\n\nSearch the element to be Delected");
        if(ab->contactCount >= 0)
        {
            //if n the file not empty secarch the element
            i = searchContact(ab,1);
        }
        else
        {
            printf("\nEmpty Address Book: Please create new contacts");
        }

        if(i != -1)
        {
            //if element found
            for(iter = i;iter < (ab->contactCount);iter++)
            {
                //for delecting overwirte the element to delected with the next elements 
                strcpy(ab->c[iter-1].name,ab->c[iter].name);
                strcpy(ab->c[iter-1].phone,ab->c[iter].phone);
                strcpy(ab->c[iter-1].email,ab->c[iter].email);

            }
            //decrement the total contact count
            printf("\nDo you delect contact(0/1)?");
            scanf("%d",&f);
            if(f == 1)
            {
                ab->contactCount--;
                printf("\nDelected Successfully");
                f = 0;
            }
        }
        printf("\nPress 0 for go back and 1 to continue:");
        scanf("%d",&f);
    } while (f != 0);
    
   
}