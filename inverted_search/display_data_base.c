/*
Name:Venkata Sai Kowshiknath Reddy Chemikela
Date:
Description:
Sample input:
Sample output:
*/

#include <stdio.h>
#include "inverted_search.h"

void display_DB(main_node_t **hash_table)
{
        printf("Index \tword \tfilecount \tfilename \twordcount\n");
        for(int index = 0; index<27; index++)
        {
                if(hash_table[index] != NULL)
                {
                        main_node_t *disp_main = hash_table[index];
                        while(disp_main)
                        {
                                printf("%d\t%s\t%d\t\t",index,disp_main->word, disp_main->file_count);
                                sub_node_t *disp_sub = disp_main->sublink;
                                while(disp_sub)
                                {
                                        printf("%s\t\t%d\t",disp_sub->sub_filename, disp_sub->word_count);
                                        disp_sub = disp_sub->next_sub_link;
                                }
                                printf("\n");
                                disp_main = disp_main->next_main_link;
                        }
                }
        }
}

