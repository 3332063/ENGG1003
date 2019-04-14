#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op1, op2, op3, op4;

int main(int argc, char const *argv[])
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
          printf("How would you like to encode the text?\n");
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
                  printf("Enter the name of the file to be encoded (.txt file): ");
                  scanf("%s", fileread);
                  printf("Enter the key value: ");
                  scanf("%d", &sv);
                  printf("Enter the name of the output file (.txt file): ");
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
                      op=(int)ch;
                      if(op>=97 && op<=122)
                        {
                          op=op+sv;
                          if(op<97)
                            {
                              op=op-26;
                            }
                        }
                      if(op>=65 && op<=90)
                        {
                          op=op+sv;
                          if(op<65)
                            {
                              op=op-26;
                            }
                          if(op>=91)
                            {
                              op=op-26;
                            }
                        }
                      if(op>=0 && op<=64)
                        {
                          op=op;
                        }
                      fprintf(fw, "%c", op);
                      ch=fgetc(fr);
                    }
                  fclose(fr);
                  fclose(fw);
                  printf("\nThe file has sucessfully been encoded and saved as %s\n", filewrite);
                  return 0;
                }
              case 2:
                {
                  char word2[700];
                  char ch;
                  int n, sv=7;
                  printf("Enter a string to encrypt: ");
                  gets(word2);
                  for(n=0; n<strlen(word2); n++)
                    {
                      ch=word2[n];
                      if(ch>=97 && ch<=122)
                        {
                          ch=ch+sv;
                          if(ch<97)
                            {
                              ch=ch-26;
                            }
                        }
                      if(ch>=65 && ch<=90)
                        {
                          ch=ch+sv;
                          if(ch<65)
                            {
                              ch=ch-26;
                            }
                          if(ch>=91)
                            {
                              ch=ch-26;
                            }
                        }
                      if(ch>=0 && ch<=64)
                        {
                          ch=ch;
                        }
                      word2[n]=ch;
                    }
                  printf("\nThe encrypted message is: %s", word2);
                  return 0;
                }
              default: printf("Invalid option....\n");
                {
                  return 0;
                }
            }
        }
      case 2:
        {
          printf("How would you like to decode the text?\n");
          printf("1. From a .txt file\n");
          printf("2. From inside the console\n");
          printf("3. From a .txt file with no key\n");
          printf("4. From inside the console with no key\n");
          printf("Enter your option: ");
          scanf("%d", &op3);
          switch(op3)
            {
              case 1:
                {
                  FILE *fr, *fw;
                  char ch, fileread[700], filewrite[700];
                  int op, sv;
                  printf("Enter the name of the file to be encoded (.txt file): ");
                  scanf("%s", fileread);
                  printf("Enter the key value: ");
                  scanf("%d", &sv);
                  printf("Enter the name of the output file (.txt file): ");
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
                      op=(int)ch;
                      if(op>=97 && op<=122)
                        {
                          op=op-sv;
                          if(op<97)
                            {
                              op=op+26;
                            }
                        }
                      if(op>=65 && op<=90)
                        {
                          op=op-sv;
                          if(op<65)
                            {
                              op=op+26;
                            }
                          if(op>=91)
                            {
                              op=op+26;
                            }
                        }
                      if(op>=0 && op<=64)
                        {
                          op=op;
                        }
                      fprintf(fw, "%c", op);
                      ch=fgetc(fr);
                    }
                  fclose(fr);
                  fclose(fw);
                  printf("\nThe file has sucessfully been decoded and saved as %s\n", filewrite);
                  return 0;
                }
              case 2:
                {
                  char word[700];
                  char ch;
                  int n, sv=7;
                  printf("Enter a string to decrypt: ");
                  gets(word);
                  for(n=0; n<strlen(word); n++)
                    {
                      ch=word[n];
                      if(ch>=97 && ch<=122)
                        {
                          ch=ch-sv;
                          if(ch<97)
                            {
                              ch=ch+26;
                            }
                        }
                      if(ch>=65 && ch<=90)
                        {
                          ch=ch-sv;
                          if(ch<65)
                            {
                              ch=ch+26;
                            }
                          if(ch>=91)
                            {
                              ch=ch+26;
                            }
                        }
                      if(ch>=0 && ch<=64)
                        {
                          ch=ch;
                        }
                      word[n]=ch;
                    }
                  printf("\nThe decrypted message is: %s", word);
                  return 0;
                }
              case 3:
                {
                  /*case 3*/
                  printf("No option yet\n");
                }
              case 4:
                {
                  char word[700];
                  char ch, dec[700];
                  int n, sv, chlen;
                  printf("Enter a word to decrypt: ");
                  gets(word);
                  chlen=strlen(word);
                  printf("The word has %d characters\n", chlen);
                  for(sv=1; sv<27; sv++)
                      {
                        for(n=0; word[n]!='\0'; n++)
                          {
                            ch=word[n];
                            if(ch>='a' && ch<='z')
                              {
                                ch=ch-sv;
                                if(ch<'a')
                                  {
                                    ch=ch+26;
                                  }
                                dec[n]=ch;
                              }
                            else if(ch>='A' && ch<='Z')
                              {
                                ch=ch-sv;
                                if(ch<'A')
                                  {
                                    ch=ch+26;
                                  }
                                dec[n]=ch;
                              }
                            else if (ch>=32 && ch<=64)
                              {
                                ch=ch;
                                dec[n]=ch;
                              }
                          }
                        printf("\nThe possible decrypted message is: %s\nKey value = %d\n\n---------------------------------\n", dec, sv);
                      }
                  return 0;
                }
            }
        }
    }
}
