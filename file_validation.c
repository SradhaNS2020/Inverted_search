#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1;
    while (argv[i] != NULL)
    {
	int empty = isFileEmpty(argv[i]);

	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File : %s is not available\n" , argv[i]);
	    printf("Hence we are not adding that file\n");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("File ; %s is not having contents in it\n" , argv[i]);
	    printf("Hence we are not adding that file\n");
	    i++;
	    continue;
	}
	else
	{
	     int ret_val = to_create_list_of_files(f_head , argv[i]);

	     if(ret_val == SUCCESS)
	     {
		 printf("Successfull : inserting the file %s into file LL \n" , argv[i]);
	     }
	     else if(ret_val == REPEATATION)
	     {
		 printf("This file %s is repeated , hence we are not adding that file\n" , argv[i]);
	     } 
	     else
	     {
		 printf("Failure\n");
	     }
	     i++;
	     continue;
	
	}
    }

}
//this fun() is used to check for file availability and for file contents
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r" );
    if(fptr == NULL)
    {
	if(errno == ENOENT)
	{
	    return FILE_NOTAVAILABLE;
	}
      return FAILURE;
    }

    fseek(fptr , 0 , SEEK_END);
    if(ftell(fptr) == 0)
    {
	return FILE_EMPTY;
    }
    fclose(fptr);
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    //............TODO...........
    //check for duplicancy 
     Flist *temp=*f_head;
     while (temp!=NULL)
     {
        if (!strcmp(temp->file_name,name))
        {
              return REPEATATION;
        }
        temp=temp->link;
     } 
    // Create a new node
    Flist *new = malloc(sizeof(Flist));
    if (new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->file_name, name);
    new->link = NULL;
    //......insert_last()....
    if (*f_head == NULL) // If the list is empty
    {
        *f_head = new;
    }
    else
    {
        temp = *f_head;
        while (temp->link)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    
    return SUCCESS;
}











