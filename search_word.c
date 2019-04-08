#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
  int num =0;
  char string[50];
  char word[100] = {0};
	FILE *in_file = fopen("dictionary.txt", "r");
  if (in_file == NULL)
    {
      printf("Error file missing\n");
      exit(-1);
    }
  printf("Please enter a word\n");
  scanf("%s", word);
  while ( fscanf(in_file,"%s", string) == 1)
    {
      if(strstr(string, word)!=0)
				{
          num++;
        }
    }
  printf("The word %s was found in the file dictionary.txt %d times\n",word,num );
  num = 0;
  fclose(in_file);
  return 0;
}
