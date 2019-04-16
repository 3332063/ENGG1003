#include<stdio.h>
#include<string.h>

int main()
{
  char lowerchars[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char upperchars[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char key[26];
  char msg[255];
  printf("Enter text to decode: ");
  scanf("%[^\n]",msg);
  int k,j;
  printf("Enter the 26 characters for decryption: ");
  scanf("%s",key);
  for(k=0;k<strlen(msg);k++)
    {
      for(j=0;j<26;j++)
        {
          if(msg[k]==key[j])
            {
              msg[k]=upperchars[j];
              break;
            }
          if(msg[k]==key[j])
            {
              msg[k]=lowerchars[j];
              break;
            }
          else
            {
              msg[k]=msg[k];
            }
        }
    }
  printf("\nYour decrypted message is: %s",msg);
  return 0;
}
