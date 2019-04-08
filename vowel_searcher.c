#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  int num =0;
  char word[100] = {0};
	FILE *in_file = fopen("dictionary.txt", "r");
  if (in_file == NULL)
    {
      printf("Error file missing\n");
      return 0;
    }
  char string[50];
  printf("Enter a word: ");
  scanf("%99s", word);
  char c=word[1];
  printf("The second letter in %s is %c\n", word, c);
  if (word[1]=='a'||word[1]=='A'||word[1]=='e'||word[1]=='E'||word[1]=='i'||word[1]=='I'||word[1]=='o'||word[1]=='O'||word[1]=='u'||word[1]=='U')
  {
    printf("The letter '%c' is a vowel\n", c);
  }
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
  //int i;
  //for(i=0; i<='z'; i++)
  //{

  //}
  return 0;
}
