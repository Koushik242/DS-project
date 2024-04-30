/*
Name:Venkata Sai Kowshiknath Reddy Chemikela
Date:
Description:
Sample input:
Sample output:
*/


#include <stdio.h>
#include "inverted_search.h"

int search_DB(main_node_t **hash_table,char *search_word) 
{
    printf("Index \tword \tfilecount \tfilename \twordcount\n");
    int found = 0;
    for (int index = 0; index < 27; index++) 
    {
        if (hash_table[index] != NULL) 
	{
            main_node_t *search_main = hash_table[index];
            while (search_main != NULL) 
	    {
                if (strcmp(search_main->word, search_word) == 0) 
		{
                    found = 1;
                    printf("%d\t%s\t%d\t\t", index, search_main->word, search_main->file_count);
                    sub_node_t *search_sub = search_main->sublink;
                    while (search_sub != NULL) 
		    {
                        printf("%s\t\t%d\t", search_sub->sub_filename, search_sub->word_count);
                        search_sub = search_sub->next_sub_link;
                    }
                    printf("\n");
                }
                search_main = search_main->next_main_link;
            }
        }
    }
    if (!found)
    {
        printf("Word '%s' not found in the database.\n", search_word);
        return 0; 
    } 
    else 
    {
        return 1; 
    }
}

