#include <stdio.h>
#include "file.h"
#include "contact.h"

void saveContactsToFile(AddressBook *ab)
{
    //to save to file
    int i;
    FILE *fp; // creating file pointer
    char ch;
    fp = fopen("data.csv","w");//open the file
    for(i = 0;i < ab->contactCount ;i++)
    {
        fprintf(fp,"%s",ab->c[i].name);//copy name to file
        putc(',',fp);  //separte it by ','
        fprintf(fp,"%s",ab->c[i].phone);//copy phone number to file 
        putc(',',fp);//separte it by ','
        fprintf(fp,"%s",ab->c[i].email);//copy email id to file
        if(i != ab->contactCount - 1);
        {
            ch = putc('\n',fp);//this is to not put '\n' to last element
        }
    }
  
}

void loadContactsFromFile(AddressBook *ab) {
    int i;
    //delcation of file pointer
    FILE *fp;
    char ch;
    //open file
    fp = fopen("data.csv","r");
    for(i = 0;ch != EOF;i++)
    {
        fscanf(fp,"%[^,]",ab->c[i].name);//load name
        ch = getc(fp);//ignore ','
        fscanf(fp,"%[^,]",ab->c[i].phone);//load phone
        ch = getc(fp);//ignore ','
        fscanf(fp,"%[^\n]",ab->c[i].email);//load email
        ch = getc(fp);//ignore '\n'
    }
    fclose(fp);   
    ab->contactCount = i - 1;     
}
