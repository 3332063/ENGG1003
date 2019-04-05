#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fr;
  char ch, fileRead[50], filewrite[50];
  scanf("%s", fileRead);
  fr=fopen(fileRead, "r");
  fw=fopen(filewrite, "w");
  if(fr==NULL)
    {
      perror("");
      return 0;
    }
  printf("Enter a word: ");
  scanf("%s", ch);
  ch=fgetc(fr);
  while (ch!=EOF)


  return 0;
}
