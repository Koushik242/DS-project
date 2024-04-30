/*
Name:Venkata Sai Kowshiknath Reddy Chemikela
Date:
Description:
Sample input:
Sample output:
*/

#include <stdio.h>
#include "inverted_search.h"

int main(int argc, char * argv[])
{
    Slist *head = NULL;
    FILE *file;
    char search_word[20];
    main_node_t *hash_table[27];
    char fname[30];
    for(int i = 0; i < 27; i++)
    {
        hash_table[i] = NULL;
    }

    if(argc < 2)
    {
        printf("The arguments should be more than 2\n");
    }
    else
    {
        read_and_validate(argc, argv, &head);
    }

    int choice;
    char ch;
    do
    {
        printf("Enter the option:\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Save Database\n");
        printf("5. Update Database\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("1. Create Database\n");
                create_data_base(&head, hash_table);
                break;
            case 2:
                printf("2. Display Database\n");
                display_DB(hash_table);
                break;
            case 3:
                printf("3. Search Database\n");
                printf("Enter the word to search: ");
                scanf("%s", search_word);
                if (search_DB(hash_table, search_word) == 1)
                {
                    printf("The word '%s' was found in the database.\n", search_word);
                }
                break;
            case 4:
                printf("4. Save Database\n");
                char filename[20];
                scanf("%s", filename);
                save_DB(hash_table, filename);
                break;
            case 5:
                printf("5. Update Database\n");
                printf("Enter the filename : \n");
		scanf("%s",fname);
                update_DB(hash_table,&head,fname);
		break;
               
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Continue (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

