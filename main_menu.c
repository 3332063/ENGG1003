#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op1, op2, op3, op4, op5, op6;

int main(int argc, char const *argv[])
{
  printf("          _ _ _ _____ __    _____ _____ _____ _____    _____ _____    _____ _____ _____\n");
  printf("         | | | |   __|  |  |     |     |     |   __|  |_   _|     |  |_   _|  |  |   __|\n");
  printf("         | | | |   __|  |__|   --|  |  | | | |   __|    | | |  |  |    | | |     |   __|\n");
  printf("         |_____|_____|_____|_____|_____|_|_|_|_____|    |_| |_____|    |_| |__|__|_____|\n\n");
  printf(" _____ _____ _____ _____ ____  _____ _____    _| |_    ____  _____ _____ _____ ____  _____ _____\n");
  printf("|   __|   | |     |     |    \\|   __| __  |  |   __|  |    \\|   __|     |     |    \\|   __| __  |\n");
  printf("|   __| | | |   --|  |  |  |  |   __|    -|  |   __|  |  |  |   __|   --|  |  |  |  |   __|    -|\n");
  printf("|_____|_|___|_____|_____|____/|_____|__|__|  |_   _|  |____/|_____|_____|_____|____/|_____|__|__|\n");
  printf("                                               |_|                                               \n\n");
  printf("                            _____ _____ _____ _____ _ _ _ _____ _____ _____\n");
  printf("                           |   __|     |   __|_   _| | | |  _  | __  |   __|\n");
  printf("                           |__   |  |  |   __| | | | | | |     |    -|   __|\n");
  printf("                           |_____|_____|__|    |_| |_____|__|__|__|__|_____|\n");
  printf("\nMain Menu\n");
  printf("1. Encode text\n");
  printf("2. Decode text\n");
  printf("3. Exit program\n");
  printf("Enter your option: ");
  scanf("%d", &op1);
  switch (op1)
    {
      case 1:
        {
          printf("\nIs the code\n");
          printf("1. Rotation Cipher\n");
          printf("2. Substitution Cipher\n");
          printf("Enter your option: ");
          scanf("%d", &op4);
          switch(op4)
            {
              case 1:
                {
                  printf("\nHow would you like to encode the text?\n");
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
                          printf("\nEnter the name of the file to be encoded (.txt file): ");
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
                          char word2[100];
                          printf("\nEnter a string to encrypt: ");
                          scanf(" %[^\n]s", word2);
                          char ch;
                          int n, sv;
                          printf("\nEnter the key value: ");
                          scanf("%d", &sv);
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
                  printf("\nHow would you like to encode the text?\n");
                  printf("1. From a .txt file\n");
                  printf("2. From inside the console\n");
                  printf("Enter your option: ");
                  scanf("%d", &op5);
                  switch(op5)
                    {
                      case 1:
                        {
                          //do some code;
                        }
                      case 2:
                        {
                          char lowerchars[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                          char upperchars[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
                          char key[26];
                          int flag=0;
                          char msg[255];
                          printf("Enter text to encode: ");
                          scanf(" %[^\n]",msg);
                          flag=1;
                          int k,j;
                          printf("Enter the 26 characters for encryption: ");
                          scanf("%s",key);
                          for(k=0;k<strlen(msg);k++)
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
                          printf("\nYour encrypted message is: %s",msg);
                          return 0;
                        }
                    }
                }
              default:
                {
                  printf("\nInvalid option\n");
                  return 0;
                }
            }
        }
      case 2:
        {
          printf("\nIs the code\n");
          printf("1. Rotation Cipher\n");
          printf("2. Substitution Cipher\n");
          printf("Enter your option: ");
          scanf("%d", &op4);
          switch(op4)
            {
              case 1:
                {
                  printf("\nHow would you like to decode the text?\n");
                  printf("1. From a .txt file\n");
                  printf("2. From inside the console\n");
                  printf("3. From inside the console with NO KEY\n");
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
                          int n, sv;
                          printf("Enter a string to decrypt: ");
                          scanf(" %[^\n]s", word);
                          printf("\nEnter the key value: ");
                          scanf("%d", &sv);
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
                          char word[100];
                          char ch, dec[100];
                          int n, sv, chlen, option;
                          char pftpr;
                          printf("Enter the text to decrypt: ");
                          scanf(" %[^\n]s", word);
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
                                printf("\nThe possible decrypted message is:\n %s\nKey value = %d\n----------------------", dec, sv);
                                printf("\n\nDoes this decrypted message make sense?\n");
                                printf("1. Yes\n");
                                printf("2. No\n");
                                printf("Enter your option: ");
                                scanf("%d", &option);
                                if(option==1)
                                  {
                                    printf("\nThe code was sucessfully decoded\n");
                                    return 0;
                                  }
                                if (option==2)
                                  {

                                  }
                              }
                          printf("\n\nYour code could not be decoded.... Press F to pay respects\n");
                          scanf(" %c", &pftpr);
                          if(pftpr=='F'||pftpr=='f')
                            {
                              printf("Respects given\n");
                            }
                          else
                            {
                              printf("Disrespectful c*nt\n");
                              return 0;
                            }
                        }
                      default:
                        {
                          printf("\nInvalid option\n");
                          return 0;
                        }
                    }
                }
              case 2:
                {
                  printf("\n1. Decrypt with a key\n");
                  printf("2. Decrypt with NO key\n");
                  printf("Enter your option: ");
                  scanf("%d", &op6);
                  switch(op6)
                    {
                      case 1:
                        {
                          char lowerchars[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                          char upperchars[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
                          char key[26];
                          char msg[10240];
                          printf("\nEnter text to decode: ");
                          scanf(" %[^\n]s", msg);
                          int k,j;
                          printf("Enter the 26 characters for decryption (capital letters only): ");
                          scanf("%s",key);
                          for(k=0;k<strlen(msg);k++)
                            {
                              for(j=0;j<26;j++)
                                {
                                  if(msg[k]==key[j])
                                    {
                                      msg[k]=upperchars[j];
                                      break;
                                    }
                                  if(msg[k]==key[j])
                                    {
                                      msg[k]=lowerchars[j];
                                      break;
                                    }
                                  else
                                    {
                                      msg[k]=msg[k];
                                    }
                                }
                            }
                          printf("\nYour decrypted message is: %s",msg);
                          return 0;
                        }
                      case 2:
                        {
                          printf("case 2\n");
                        }
                      default:
                        {
                          printf("\nInvalid option\n");
                          return 0;
                        }
                    }
                }
            }
        }
      default:
        {
          printf("\nInvalid option\n");
          return 0;
        }
    }
}
