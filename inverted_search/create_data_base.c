/*
Name:Venkata Sai Kowshiknath Reddy Chemikela
Date:
Description:
Sample input:
Sample output:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inverted_search.h"

int create_data_base(Slist **head, main_node_t *hash_table[])
{
        int index;
      
        int word_flag = 0,file_name_flag = 0;
        Slist *temp = *head;
        while(temp != NULL)
        {
                FILE*fptr = fopen(temp->filename, "r");
                char word[20];
                while(fscanf(fptr, "%s", word) != EOF)
                {
                        if(word[0] >= 'a' && word[0] <= 'z' || word[0] >= 'A' && word[0] <= 'Z')
                        {
                                index = tolower(word[0]) % 97;
                        }
                        else
                        {
                                index = 26;
                        }
                        if(hash_table[index] == NULL)
                        {
                                main_node_t *m_new = malloc(sizeof(main_node_t));
                                if(m_new == NULL)
                                {
                                        return FAILURE;
                                }
                                sub_node_t * s_new = malloc(sizeof(sub_node_t));
                                if(s_new == NULL)
                                {
                                        return FAILURE;
                                }
                                hash_table[index] = m_new;
                                m_new->file_count =1;

                                strcpy(m_new->word, word);

                                m_new->sublink = s_new;
                                m_new->next_main_link = NULL;
                                s_new->word_count = 1;

                                strcpy(s_new->sub_filename,temp->filename);

                                s_new->next_sub_link = NULL;
                                hash_table[index] = m_new;
                        }
                        else if(hash_table[index] != NULL)
                        {
                                main_node_t * main_prev;
                                main_node_t * main_temp = hash_table[index];
                                while(main_temp)
                                {
                                        if(strcmp(main_temp->word, word) != 0)
                                        {
                                                main_prev = main_temp;
                                               // main_temp = main_temp->next_main_link;
                                                word_flag = 1;
                                        }
                                        else
                                        {
                                                word_flag = 0;
                                                sub_node_t * sub_prev;
                                                sub_node_t * sub_temp = main_temp->sublink;

                                                while(sub_temp)
                                                {
                                                        if(strcmp(sub_temp->sub_filename,temp->filename) != 0)
                                                        {
                                                                sub_prev = sub_temp;
                                                                file_name_flag = 1;
                                                                file_name_flag = 1;
                                                                sub_temp = sub_temp->next_sub_link;
                                                        }
                                                        else
                                                        {
                                                                file_name_flag = 0;     //file name is same.
                                                                (sub_temp->word_count)++;
                                                                break;
                                                        }
                                                }
                                                if(file_name_flag)
                                                {
                                                        sub_node_t * new_sub = malloc(sizeof(sub_node_t));
                                                        if(new_sub == NULL)
                                                                return FAILURE;
                                                        new_sub->word_count = 1;
                                                        strcpy(new_sub->sub_filename,temp->filename);
                                                        new_sub->next_sub_link = NULL;
                                                        sub_prev->next_sub_link = new_sub;
                                                        (main_temp->file_count)++;
                                                        file_name_flag = 0;
                                                        
                                                }
						break;
                                        }

                                       main_temp = main_temp->next_main_link;
                                }
                                if(word_flag)   //words are not same.
                                {
                                        // check if the  main & sub node are created or not.

                                        main_node_t * new_word_main = malloc(sizeof(main_node_t));
                                        if(new_word_main == NULL)
                                        {
                                                return FAILURE;
                                        }

                                        sub_node_t * new_file_sub = malloc(sizeof(sub_node_t));
                                        if(new_file_sub == NULL)
                                        {
                                                return FAILURE;
                                        }

                                        //update all the data.
                                        new_word_main->file_count = 1;
                                        strcpy(new_word_main->word, word);
                                        new_word_main->sublink = new_file_sub;
                                        new_word_main->next_main_link = NULL;

                                        new_file_sub->word_count = 1;
                                        strcpy(new_file_sub->sub_filename, temp->filename);
                                        new_file_sub->next_sub_link = NULL;

                                        main_prev->next_main_link = new_word_main;

                                        word_flag = 0;
                                }
                        }
                }
		//fclose(fptr);
		temp=temp->link;
        }

        return SUCCESS;
}
