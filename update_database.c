#include "inverted_search.h"

 void update_database( Wlist *head[], Flist **f_head)
{
    //prompt the user for new file

    char file_name[FNAME_SIZE];
    printf("Enter the new file for updating the database\n");
    scanf("%s" , file_name);

    // validation 
    int empty = isFileEmpty(file_name);

	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File ; %s is not available\n" , file_name);
	    printf("Hence we are not adding that file\n");
	    
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("File ; %s is not having contents in it\n" , file_name);
	    printf("Hence we are not adding that file\n");
	    
	}
	else
	{
	     int ret_val = to_create_list_of_files(f_head , file_name);

	     if(ret_val == SUCCESS)
	     {
		 printf("Successfull : inserting the file %s into file LL \n" , file_name);
	     }
	     else if(ret_val == REPEATATION)
	     {
		 printf("This file %s is repeated , hence we are not adding that file\n" , file_name);
	     } 
	     else
	     {
		 printf("Failure\n");
	     }
	
	}
     
    
    while(*f_head)
    {
	if(!strcmp((*f_head)->file_name , file_name))
	{
	    create_database(*f_head , head);
	}
	*f_head = (*f_head)->link;
    }
}


