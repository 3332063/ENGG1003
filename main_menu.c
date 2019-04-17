#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int op1, op2, op3, op4, op5, op6; //options for switch statements

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
  scanf("%d", &op1); //scans for user input and assigns the input to int op1
  switch (op1) //takes user input from options and executes the number they typed in
    {
      case 1:
        {
          clrscr();
          printf("\nIs the code\n");
          printf("1. Rotation Cipher\n");
          printf("2. Substitution Cipher\n");
          printf("Enter your option: ");
          scanf("%d", &op4); //scans for user input and assigns the input to int op4
          switch(op4) //takes user input from options and execute the number they typed in
            {
              case 1:
                {
                  printf("\nHow would you like to encode the text?\n");
                  printf("1. From a .txt file\n");
                  printf("2. From inside the console\n");
                  printf("Enter your option: ");
                  scanf("%d", &op2); //scans for user input and assigns the input to int op2
                  switch(op2) //takes user input from options and execute the number they typed in
                    {
                      case 1:
                        {
                          FILE *fr, *fw; //decalres pointer for file which is used to communicate between program and file
                          char ch, fileread[700], filewrite[700]; // assigns memory to fileread and filewrite which is used to read the text file
                          int op, sv;
                          printf("\nEnter the name of the file to be encoded (.txt file): ");
                          scanf("%s", fileread); //takes user input for the file they want to read the text from
                          printf("Enter the key value: ");
                          scanf("%d", &sv); //user input for their key value is stored
                          printf("Enter the name of the output file (.txt file): ");
                          scanf("%s", filewrite); //takes user input for what they would like their new encrypted file to be saved as
                          fr=fopen(fileread, "r"); //opens fr(fileread pointer) in read mode ("r")
                          fw=fopen(filewrite, "w"); //opens fw(filewrite pointer) in write mode ("w")
                          if (fr==NULL) //if the file cannot be opened produce an error message and exit the program
                            {
                              perror("");
                              return 0;
                            }
                          ch=fgetc(fr); //fgetc obtains a charachter from the file and assigns it to "ch"
                          while(ch!=EOF) // while there are still characters do not exit the file
                            {
                              op=(int)ch; // assigns op to the ASCII value of the charachter "ch"
                              if(op>=97 && op<=122) // if the charachter is between 97 and 122 (a-z) add the shift value to the charachter
                                {
                                  op=op+sv;
                                  if(op<97) // if the charachter is less than 97 (a) subtract 26, which, rotates the charachters back to z
                                    {
                                      op=op-26;
                                    }
                                }
                              if(op>=65 && op<=90) // if the charachter is between 65 and 90 (A-Z) add the shift value to the charachter
                                {
                                  op=op+sv;
                                  if(op<65) // if the charachter is less than 65 (A) subtract 26, which, rotates the charachters back to Z
                                    {
                                      op=op-26;
                                    }
                                  if(op>=91) //if the charachter is greater than or equal to special char ([), rotate back to A
                                    {
                                      op=op-26;
                                    }
                                }
                              if(op>=0 && op<=64) //if the char is between 0 and 64(special chars), just leave them (dont encrypt)
                                {
                                  op=op;
                                }
                              fprintf(fw, "%c", op); //prints the encrypted char to the file
                              ch=fgetc(fr); //gets a new char from the file and assigns it to "ch"
                            }
                          fclose(fr); //closes the file "fr" so it is no longer "read"
                          fclose(fw); //closes the file "fw" so it is no longer written to
                          printf("\nThe file has sucessfully been encoded and saved as %s\n", filewrite); // lets user know their code has been encoded and saved
                          return 0; //exits program
                        }
                      case 2:
                        {
                          char word2[100]; //assigns memory value of 100 to "word2"
                          printf("\nEnter a string to encrypt: ");
                          scanf(" %[^\n]s", word2); // scans user input for string and assigns it to word2, [^\n] allows the program to not stop at whitespace
                          char ch;
                          int n, sv;
                          printf("\nEnter the key value: ");
                          scanf("%d", &sv); //scans user input for key value and assigns it to 'sv'
                          for(n=0; n<strlen(word2); n++) //initialises n to 0, while n is less than the length of the string, keep incrementing the value of n by 1
                            {
                              ch=word2[n]; //assigns "ch" to a letter of the string "word2"
                              if(ch>=97 && ch<=122) // if the charachter is between 97 and 122 (a-z) add the shift value to the charachter
                                {
                                  ch=ch+sv;
                                  if(ch<97) // if ch is less than 97, rotate the cipher back to "z"
                                    {
                                      ch=ch-26;
                                    }
                                }
                              if(ch>=65 && ch<=90) // if the charachter is between 65 and 90 (A-Z) add the shift value to the charachter
                                {
                                  ch=ch+sv;
                                  if(ch<65)// if the charachter is less than 65 (A) subtract 26, which, rotates the charachters back to Z
                                    {
                                      ch=ch-26;
                                    }
                                  if(ch>=91)//if the charachter is greater than or equal to special char ([), rotate back to A
                                    {
                                      ch=ch-26;
                                    }
                                }
                              if(ch>=0 && ch<=64)//if the char is between 0 and 64(special chars), just leave them (dont encrypt)
                                {
                                  ch=ch;
                                }
                              word2[n]=ch;
                            }
                          printf("\nThe encrypted message is: %s", word2); //shows the user what their encrypted text is
                          return 0; //exits the program
                        }
                      default: printf("Invalid option....\n"); //if the user has selected an invalid option an error message will appear and the program will exit
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
                  scanf("%d", &op5);//scans for user input and assigns the input to int op5
                  switch(op5)//takes user input from options and execute the number they typed in
                    {
                      case 1:
                        {
                          //do some code;
                        }
                      case 2:
                        {
                          //lower and upper chars is assigned a memory value of 26 and the alphabet is initialised for both upper and lower case letters
                          char lowerchars[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                          char upperchars[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
                          char key[27]; //key value is assigned memory value of 27 (doesnt interfere with the upper and lower chars)
                          char msg[255]; //assigns memory value of 255 to "msg", which is the user input
                          printf("\nEnter text to encode: ");
                          scanf(" %[^\n]",msg); //scans user input for string, [^\n] allows the string to store whitespace
                          int k,j; //k and j are used in the for loops to increment the values
                          printf("\nEnter the 26 characters for encryption: ");
                          scanf("%s",key); //users key value is stored as "key"
                          for(k=0;k<strlen(msg);k++) //k is initialised to 0, while k is less than the string length of the text in "msg", keep incrementing k by 1
                            {
                              for(j=0;j<26;j++) //j is initialised to 0, while j is less than 26 (letters in the alphabet, it just cylces through the alphabet), keep incrementing j
                                {
                                  if(upperchars[j]==msg[k]) // if the message to be encrypted is uppercase, the message will be encrypted will equal the key value of that letter
                                    {
                                      msg[k]=key[j]; //the letter of the "msg" is substituted for the letter in the "key"
                                      break;//exits the loop
                                    }
                                  if(lowerchars[j]==msg[k])// if the message to be encrypted is lowercase, the message will be encrypted will equal the key value of that letter
                                    {
                                      msg[k]=key[j]; //the letter of the "msg" is substituted for the letter in the "key"
                                      break; //exits the loop
                                    }
                                }
                            }
                          printf("\nYour encrypted message is: %s",msg); //shows user their encrypted message
                          return 0; //exits program
                        }
                    }
                }
              default: //if an invalid option is entered exit the program
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
                          char key[27];
                          char msg[1024];
                          printf("\nEnter text to decode: ");
                          scanf(" %[^\n]s", msg);
                          int k,j;
                          printf("\nEnter the 26 characters for decryption (capital letters only): ");
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
                          printf("\nYour decrypted message is: %s", msg);
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
      case 3:
        {
          printf("Aightttt bro (¬_¬)");
          return 0;
        }
      default:
        {
          printf("\nInvalid option\n");
          return 0;
        }
    }
}
