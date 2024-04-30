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


int save_DB(main_node_t *hashtable[], char *filename)
{
    if(strcmp(strstr(filename, "."), ".txt") != 0)
    {
        return FAILURE;
    }
    
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        return FAILURE; 
    }

    for(int i = 0; i < 27; i++)
    {
        if(hashtable[i] != NULL)
        {
            main_node_t *temp = hashtable[i];
            while(temp != NULL)
            {
                fprintf(fptr, "%d : %s : %d :", i, temp->word, temp->file_count);
                sub_node_t *sub_temp = temp->sublink;
                while(sub_temp != NULL)
                {
                    fprintf(fptr, "%s : %d :", sub_temp->sub_filename, sub_temp->word_count);
                    sub_temp = sub_temp->next_sub_link;
                }
                fprintf(fptr, "\n");
                temp = temp->next_main_link;
            }
        }
    } 
    return 0; 
}

