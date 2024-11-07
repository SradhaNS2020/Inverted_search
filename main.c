#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};
    //validation 

    if(argc <= 1)
    {
	printf("Enter the valid no. of arg\n");
	printf("./slist.exe file1.exe file2.exe .......\n");
	return 0;
    }

    //validate the file

    //declare head pointer

    Flist *f_head = NULL;

    file_validation_n_file_list(&f_head , argv);

    if(f_head == NULL)
    {
	printf("No files are available in file LL\n");
	printf("Hence th eprocess got terminated\n");
	return 1;
    }
    /*
       ........TODO..........
       prompt the user for choice 
   */
   
   char ch='y';
   do
   {
       char word[WORD_SIZE];
       int index;
       char choice;
       printf(" Select your choice among following options:\n1. Create DATABASE\n2. Display Database\n3. Update DATABASE\n4. Search\n5. Save Database\nEnter your choice \n");
       scanf (" %c",&choice);
       switch (choice)
       {
          case '1':create_database (f_head,head);
          break;
          case '2':display_database (head);
          break;
          case '3':update_database(head,&f_head);
          break;
          case '4':printf("Enter the word you want to search: \n");
                 scanf("%s",word);
                 index=hash_function(word);
                 if (head[index])
                 {
                     search(head[index],word);
                 }
                 else
                 printf("Word not found\n");
                 
          break;
          case '5':save_database(head);
          break;
          default:printf("Inavlid hoice\n");
       }
     printf("Do you want to continue?\nEnter Y/y to continue and n/N to discontinue\n ");
     scanf(" %c",&ch);
    }while(ch == 'y'||ch=='Y');
}
int hash_function(const char *word)
{
     int index = tolower(word[0]) % 97;

	//other than alphabets 
	if(!(index >= 0 && index <= 25))
	    index = 26;
     return index;
}




















