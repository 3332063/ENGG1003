#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char word[100], ch;
	char string[50];
	int n, sv, num=0;
	printf("Enter a message to decrypt: ");
	gets(word);
  for(sv=1; sv<25; sv++)
    {
    	for(n = 0; word[n] != '\0'; n++)
        {
      		ch = word[n];
      		if(ch >= 'a' && ch <= 'z')
						{
	      			ch = ch - sv;
	      			if(ch < 'a')
								{
	      					ch = ch + 'z' - 'a' + 1;
	      				}
	      			word[n] = ch;
	      		}
      		else if(ch >= 'A' && ch <= 'Z')
						{
	      			ch = ch - sv;

	      			if(ch < 'A')
								{
	      						ch = ch + 'Z' - 'A' + 1;
	      				}
							word[n] = ch;
	      		}
    	 	}
    	printf("\nPossible decrypted message: %s\n", word);
			FILE *fr;
			fr = fopen("dictionary.txt", "r");
		  if (fr==NULL)
			 	{
				 	perror("");
				 	return 0;
			 	}
			while(fscanf(fr, "%s", string)==1);
				{
					if (strstr(string, word)!=0)
						{
							printf("The word %s was found\n");
							num++;
						}
					printf("The word was found %d times\n\n", num);
				}
			fclose(fr);
		}
	return 0;
}
