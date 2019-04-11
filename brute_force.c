#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char word[100]="vtgg";
  char ch;
  char dec[100];
  int n=0, sv=1;
  while(sv<27)
    {
      for(n=0; word[n]!='\0'; n++)
        {
          ch=word[n];
          if(ch>='a' && ch<='z')
            {
              ch=ch-sv;
              if(ch<'a')
                {
                  ch=ch+26;
                }
              dec[n]=ch;
            }
          else if(ch>='A' && ch<='Z')
            {
              ch=ch-sv;
              if(ch<'A')
                {
                  ch=ch+26;
                }
              dec[n]=ch;
            }
        }
  		printf("The possible decrypted message is %s\n", dec);
  		sv++;
    }
  return 0;
}
