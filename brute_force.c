#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[40]="qmxgl";

int main()
{
  int n;
  for (int kv=1; kv<25; kv++)
    {
      for(n=0; n<strlen(word); n++)
        {
          word[n]=word[n]-kv;
        }
      printf("%s\n", word);
    }
  return 0;
}
