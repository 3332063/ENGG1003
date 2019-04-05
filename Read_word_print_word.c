#include <stdio.h>

int main()
{
  char dictionary[10] [2] [15]={
      "Tree",
      "car",
      "Mouse",
      "game",
      "laptop",
      "compute",
      "penis",
      "licker"
  };
  char english[15];
  printf("Enter an English word: ");
  gets(english);
  int i;
  int c=0;
  for(i=0; i<8; i++)
    {
      if(strcmp(english, dictionary[i][0])==0)
        {
          printf("The word you entered is %s\n",dictionary[i][0]);
        }
      else c++;
    }
  if(c==8) printf("Not a word in the dictionary\n");
  return 0;
}
