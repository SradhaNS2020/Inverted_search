#include "inverted_search.h"

void save_database( Wlist *head[])
{
    int i;
    char file_name[FNAME_SIZE];
     //prompt the user to enter the file
    printf("Enter the filename\n");
    scanf("%s",file_name);
     

    FILE *fptr=fopen(file_name,"w");
    if (fptr==NULL)
    {
        return;
    }
    for (i=0;i<27;i++)
    {
         if (head[i]!=NULL)
         {
               fprintf(fptr,"#:[%d]\n",i);
               write_databasefile(head[i],fptr);
         }
    }
    fclose(fptr);
    printf ("Database is saved\n");
}
void write_databasefile(Wlist *head, FILE* databasefile)
{
    fprintf(databasefile,"Word is [%s]:file count is %dfile/s:",head->word,head->file_count);
    Ltable *temp=head->Tlink;
    while (temp!=NULL)
    {
        fprintf(databasefile,"file is %s :word count is %d#\n",temp->file_name,temp->word_count);
        temp=temp->table_link;
    }
}
       
       
    

