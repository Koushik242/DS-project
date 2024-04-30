/*
Name:Venkata Sai Kowshiknath Reddy Chemikela
Date:
Description:
Sample input:
Sample output:
*/

#include<stdio.h>
#include "inverted_search.h"

// file should be .txt
// file should be present
// file should be non empty.

int read_and_validate(int argc, char *argv[], Slist **head)
{
        int i;
        for(i = 1; i < argc; i++)
        {
                if(strcmp(strstr(argv[i], "."), ".txt") == 0)
                {
                        FILE *fptr = fopen(argv[i], "r");
                        if(fptr != NULL)
                        {
                                fseek(fptr, 0, SEEK_END);
                                if(ftell(fptr) != 0)
                                {
                                        //validation success.
                                        insert_at_last(argv[i], head);
                                }
                        }
                }
        }
}
