#include "inverted_search.h"
char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through this file linked list 

    while(f_head)
    {
	read_datafile(f_head , head , f_head->file_name);
	f_head = f_head->link;
    }
}

//read contents of file
 Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    //open the file in r mode
    FILE *fptr = fopen(filename , "r");
    if (fptr==NULL)
    {
       printf("failed to open file %s",filename);
       return NULL;
    }
    fname = filename;
    //declare an array to store the word
    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
	//index
	int index = hash_function(word);
        int flag=1;
	//check whether words are repeated or not 
	if(head[index] != NULL)
	{
	    Wlist *temp = head[index];
	    //compare new word with each node words 
	    while(temp)
	    {
		if(!strcmp(temp->word , word))
		{
		    update_word_count(&temp , filename);
		    flag = 0;
		    break;
		}
                temp=temp->link;
	    }
	    if(flag == 1)
	    {
		//if words are not repeated
		insert_at_last(&head[index] , word);
	    }
	}
        else
        {
            insert_at_last(&head[index] , word);
        }  

    }
  fclose(fptr);
}

 int update_word_count(Wlist ** head, char * file_name)
{
    //.................TODO.............
    //check file names are same or not 
    
    //filenames are same = > increment word_count
       
    //filenames are different -> increment file_count , create new Ltable node
    Ltable *temp = (*head)->Tlink;
    while(temp != NULL)
    {
        if (!strcmp(temp->file_name, file_name))
        {
            temp->word_count++;
            return SUCCESS;
        }
        temp = temp->table_link;
    }
    (*head)->file_count++;
    Ltable *new = malloc(sizeof(Ltable));
    if (new == NULL)
    {
        return FAILURE;
    }
    new->word_count = 1;
    strcpy(new->file_name, file_name);
    new->table_link = NULL;
    if ((*head)->Tlink == NULL)
    {
        (*head)->Tlink = new;
    }
    else
    {
        temp = (*head)->Tlink;
        while(temp->table_link != NULL)
        {
            temp = temp->table_link;
        }
        temp->table_link = new;
    }
    return SUCCESS;  
}





























