/*
Name:Venkata Sai Kowshiknath Reddy Chemikela
Date:
Description:
Sample input:
Sample output:
*/

#include <stdio.h>
#include <string.h>
#include "inverted_search.h"

int update_DB( main_node_t *hash_table[], Slist **head,char *filename)
{
        Slist *temp = *head;
        Slist *new = malloc(sizeof(Slist));
        strcpy(new->filename ,filename);
        new->link = NULL;

        if(strstr(filename,".txt") != NULL)
        {
                FILE *fptr = fopen(filename,"r");

                if(fptr != NULL)
                {
                        fseek(fptr,0,SEEK_END);

                        if(ftell(fptr) != 0)
                        {
                                while(temp != NULL)
                                {
                                        if(strcmp(temp->filename,filename ) == 0)
                                        {
                                                return FAILURE;
                                        }
                                        else
                                        {
                                                *head = (*head)->link;
                                                free(temp);
                                                temp = *head;
                                        }
                                }
                                if(*head == NULL)
                                {
                                        *head = new;
                                }
                        }
                }
        }
        create_data_base(head,hash_table);
}
