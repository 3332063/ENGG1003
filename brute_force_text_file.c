#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *fr, *fw;
  char word[700], fileread[700], filewrite[700];
  char ch;
  int n, sv, op;
  printf("Enter the name of the file to be decoded (.txt file): ");
  scanf("%s", fileread);
  printf("Enter the name of the output file (.txt file): ");
  scanf("%s", filewrite);
  fr=fopen(fileread, "r");
  fw=fopen(filewrite, "w");
  if (fr==NULL)
    {
      perror("");
      return 0;
    }
  for(sv=1; sv<27; sv++)
    {
      ch=fgetc(fr);
      while(ch!=EOF)
        {
          op=(int)ch;
          if(op>=97 && op<=122)
            {
              op=op-sv;
              if(ch<97)
                {
                  op=op+26;
                }
            }
          else if(op>=65 && op<=90)
            {
              op=op-sv;
              if(op<65)
                {
                  op=op+26;
                }
              if(op>=91)
                {
                  op=op+26;
                }
            }
          else if (op>=0 && op<=64)
            {
              op=op;
            }
          fprintf(fw, "%c", op);
          ch=fgetc(fr);
        }
    }
  fclose(fr);
  fclose(fw);
  return 0;
}
