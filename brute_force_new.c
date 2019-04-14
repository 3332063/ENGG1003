#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char word[600];
  char ch, dec[600];
  int n, sv, chlen, option;
  printf("Enter a word to decrypt: ");
  gets(word);
  for(sv=1; sv<27; sv++)
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
            else if (ch>=32 && ch<=64)
              {
                ch=ch;
                dec[n]=ch;
              }
          }
          printf("\nThe possible decrypted message is:\n %s\nKey value = %d\n----------------------", dec, sv);
          printf("\n\nDoes this decrypted message make sense?\n");
          printf("1. Yes\n");
          printf("2. No\n");
          printf("Enter your option: ");
          scanf("%d", &option);
          if(option==1)
            {
              printf("The code was sucessfully decoded\n");
              return 0;
            }
          if (option==2)
            {

            }
      }
  printf("Your code could not be docoded... Sorry\n");
  return 0;
}
