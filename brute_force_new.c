#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char word[700];
  char ch, dec[700];
  int n, sv, chlen;
  printf("Enter a word to decrypt: ");
  gets(word);
  chlen=strlen(word);
  printf("The word has %d characters\n", chlen);
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
        printf("The possible decrypted message is %s\nKey value = %d\n\n", dec, sv);
      }
  return 0;
}
