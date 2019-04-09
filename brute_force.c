#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[40]="Mitchell";

int main()
{
  int n;
  for(n=0; n<strlen(word); n++)
    {
      for (int kv=1; kv<25; kv++)
        {
          word[n]=word[n]+kv;
          kv++;
        }
      printf("%s\n", word);
    }
  return 0;
}
