#include <stdio.h>
#include <string.h>

int main()
{
  char string[100];
  printf("Enter a word: ");
  scanf("%99s", string);
  char c=string[1];
  printf("The second letter in %s is %c\n", string, c);
  char vowels=
  if (string[1]=='a')
  {
    printf("The letter 'a' is a vowel\n");
  }
  else if (string[1]=='e')
  {
    printf("The letter 'e' is a vowel\n");
  }
  else if (string[1]=='i')
  {
    printf("The letter 'i' is a vowel\n");
  }
  else if (string[1]=='o')
  {
    printf("The letter 'o' is a vowel\n");
  }
  else if (string[1]=='u')
  {
    printf("The letter 'u' is a vowel\n");
  }
  else
  printf("The second letter is not a vowel\n");
  return 0;
}
