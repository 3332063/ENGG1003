#include <stdio.h>
#include <stdlib.h>

#define LOG_DIR "C:\\Users\\mitch\\Desktop\\Eng1003\\ENGG1003\\Dictionary.txt"
char ch;
FILE *fr;
void getchara();

int main()
{
  int i;
  char *search= "the";
  fr=fopen(LOG_DIR, "r");
  getchara();
  while(!feof(fr))
    {
      for(i=0; search[i]!='\0'; i++)
        {
          if(search[i]==ch)
            {
              putchar(ch);
              getchara();
            }
          else
            {
              i=-1;
              putchar(ch);
              getchar();
            }
        }
      getch();
    }
  return 0;
}

void getchara()
  {
    ch = fgetc(fr);
    if(feof(fr))
      {
        printf("\n\n\n\nEnd of file\n");
        exit(EXIT_FAILURE);
      }
  }
