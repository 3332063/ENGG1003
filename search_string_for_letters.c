#include <stdio.h>
#include <string.h>

int main()
{
	char* string="Mitchell";
  char c = string[1];
	char search[20];
  printf("Enter some letters to search in the word: ");
  scanf("%s", search);
	char *pntr = strstr(string, search);
	if (pntr != NULL)
	{
		printf("'%s' contains '%s'\n", string, search);
	}
	else
	{
		printf("'%s' doesn't contain '%s'\n", string, search);
	}
  printf("The second letter in 'Mitchell' is %c\n", string[1]);
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
	return 0;
}
