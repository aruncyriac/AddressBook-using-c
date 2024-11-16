#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
void swap(AddressBook *ab,int i,int j)
{
    char n[50];
    //swaping namr 
    strcpy(n,ab->c[i].name);
    strcpy(ab->c[i].name,ab->c[j].name);
    strcpy(ab->c[j].name,n);
    //swaping phone
    strcpy(n,ab->c[i].phone);
    strcpy(ab->c[i].phone,ab->c[j].phone);
    strcpy(ab->c[j].phone,n);
    //swaping email
    strcpy(n,ab->c[i].email);
    strcpy(ab->c[i].email,ab->c[j].email);
    strcpy(ab->c[j].email,n);



}


void sort(AddressBook *ab)
{
    int i,j;
    i = 0;
    for(i = 0;i < ab->contactCount-1;i++)
    {
        for(j = i + 1;j < ab->contactCount;j++)
        {
            if(strcasecmp(ab->c[i].name,ab->c[j].name) > 0)
            {
                swap(ab,i,j);
            }
        }
    }

}