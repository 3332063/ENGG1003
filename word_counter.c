#include <stdio.h>
#include <stdlib.h>

int main()
{
	// This program reads a file from its arguments and prints a word by word. Additionally, it counts the words in the file.
	FILE * fp;
  char fileread[40];
  printf("Enter the name of the file: ");
  scanf("%s", fileread);
  fp=fopen(fileread, "r");
	if (fp == NULL) return 1;
	char c;
  char w;
  scanf("%s", w);
	int count = 0;
	while((c = fgetc(fp)) != EOF)
	{
		if (c == ' ' || c == '\n')
		{
			printf("\n");
			++count;
		}
    else if (c == w)
    {
      printf("\n\nThe word found is %s\n\n", w);
      ++count;
    }
		else
		{
			printf("%c", c);
		}
	}
	fclose(fp);

	printf("\nThis file has %d words in it.", count);
	return 0;
}
