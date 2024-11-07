#include "inverted_search.h"

void search( Wlist *head, char *word)
{
    //head is empty or not 
    if(head == NULL)
    {
	printf("Search not possible , as the list is empty\n");
	return ;
    }


    //traverse and compare 
    while(head)
    {
	//compare the search word with each node word
	if(!strcmp(head->word , word))
	{
	    printf("Word %s is present in %d file / s\n" , word , head->file_count);

	    Ltable *Thead = head->Tlink;

	    while(Thead)
	    {
		printf("In file : %s  %d time\n" ,Thead->file_name , Thead->word_count);
		Thead = Thead->table_link;
	    }
	    printf("\n");
	    return ;
	}
	head = head->link;
    }

    printf("Search word not found\n");
}


  











	


