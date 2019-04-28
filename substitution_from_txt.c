#include<stdio.h>
#include<string.h>

int main()
{
  FILE *fr, *fw;
  char lowerchars[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char upperchars[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char key[27], fileread[200], filewrite[200], msg;
  int k,j, op;
  int flag=0;
  printf("Enter the name of the file to be encoded: ");
  scanf("%s", fileread);
  printf("Enter the name of the ouput file: ");
  scanf("%s", filewrite);
  fr=fopen(fileread, "r");
  fw=fopen(filewrite, "w");
  if(fr==NULL)
    {
      perror("");
      return 0;
    }
  printf("Enter the 26 characters for encryption: ");
  scanf("%s",key);
  msg=fgetc(fr);
  while (msg!=EOF)
    {
      for(k=0;k<strlen();k++)
        {
          for(j=0;j<26;j++)
            {
              if(upperchars[j]==msg[k])
                {
                  msg[k]=key[j];
                  break;
                }
              if(lowerchars[j]==msg[k])
                {
                  msg[k]=key[j];
                  break;
                }
            }
        }
      fprintf(fw, "%c", op);
      msg=fgetc(fr);
    }
  }
  fclose(fr);
  fclose(fw);
  printf("\nThe file has sucessfully been encoded and saved as %s\n", filewrite);
  return 0;
}
