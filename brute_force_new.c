#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char word[100];
  char ch, dec[50];
  int n, sv, chlen, op1;
  printf("Enter a word to decrypt: ");
  scanf("%s", word);
  chlen=strlen(word);
  printf("The word has %d characters\n", chlen);
  if(chlen==3)
    {
      dec[50] = dec[4];
    }
  else if (chlen==2)
    {
      dec[50] = dec[3];
    }
  else if (chlen==1)
    {
      dec[50] = dec[2];
    }
  else if (chlen>3)
    {
      dec[50];
    }
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
            else if (ch==32)
              {
                ch=ch;
                dec[n]=ch;
                printf("This value is %c\n", dec);
              }
          }
        printf("The possible decrypted message is %s\n", dec);
      }
  return 0;
}
