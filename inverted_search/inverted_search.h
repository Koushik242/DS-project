#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1


typedef struct file_table
{
        char filename[30];
        struct file_table *link;
}Slist;

typedef struct sub_node
{
    int word_count;
    char  sub_filename[10];
    struct sub_node * next_sub_link;
}sub_node_t;

typedef struct main_node
{
    int file_count;
    char word[100];
    sub_node_t * sublink;
    struct main_node * next_main_link;
}main_node_t;


int read_and_validate(int argc,char *argv[],Slist **head);
int insert_at_last(char *filename,Slist **head);
int create_data_base(Slist **head, main_node_t * hashtable[]);
void display_DB(main_node_t ** hash_table);
int search_DB(main_node_t ** hashtable,char *search_word);
int save_DB(main_node_t *hash_table[],char *filename);
int update_DB( main_node_t *hash_table[], Slist **head,char *filename);

#endif
