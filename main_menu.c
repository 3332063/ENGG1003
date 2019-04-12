#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op1, op2, op3, op4;

int main()
{
  printf("---Welcome to the encoder and decoder program---\n\n");
  printf("Main Menu\n");
  printf("1. Encode text\n");
  printf("2. Decode text\n");
  printf("3. Exit program\n");
  printf("Enter your option: ");
  scanf("%d", &op1);
  switch (op1)
    {
      case 1:
        {
          printf("How would you like to decode the text?\n");
          printf("1. From a .txt file\n");
          printf("2. From inside the console\n");
          printf("Enter your option: ");
          scanf("%d", &op2);
          switch(op2)
            {
              case 1:
                {
                  FILE *fr, *fw;
                  char ch, fileread[700], filewrite[700];
                  int op, sv;
                  printf("Enter the name of the file to be decoded: ");
                  scanf("%s", fileread);
                  printf("Enter the key value: ");
                  scanf("%d", &sv);
                  printf("Enter the name of the output file: ");
                  scanf("%s", filewrite);
                  fr=fopen(fileread, "r");
                  fw=fopen(filewrite, "w");
                  if (fr==NULL)
                    {
                      perror("");
                      return 0;
                    }
                  ch=fgetc(fr);
                  while(ch!=EOF)
                    {
                      ch=ch+sv;
                      fprintf(fw, "%c", ch);
                      ch=fgetc(fr);
                    }
                  fclose(fr);
                  fclose(fw);
                  printf("\nThe file has sucessfully been encoded and saved as %s\n", filewrite);
                  return 0;
                }
            }
        }
    }
}
