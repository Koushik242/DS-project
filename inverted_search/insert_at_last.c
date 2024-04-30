/*
Name:Venkata Sai Kowshiknath Reddy Chemikela
Date:
Description:
Sample input:
Sample output:
*/

#include "inverted_search.h"

int insert_at_last(char *filename,Slist **head)
{
    Slist *new=malloc(sizeof(Slist));
    strcpy(new->filename,filename);
    new->link=NULL;
    if(*head == NULL)
    {
	*head=new;
	return SUCCESS;
    }
        Slist *temp = *head;
        Slist *prev = NULL;
        while(temp != NULL)
        {
                if(strcmp(temp->filename, filename) == 0)
                {
                        printf("Duplicate value");
                        return FAILURE;
                }
                prev = temp;
                temp = temp->link;
        }
        prev->link = new;
        return SUCCESS;
    
}

