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
                          FILE *fr, *fw; //declares pointer for file which is used to communicate between program and file
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
                          while(ch!=EOF) // while there are still characters in the file, do not exit the file
                            {
                              op=(int)ch; // assigns op to the ASCII value of the charachter "ch"
                              if(op>=97 && op<=122) // if the charachter is between 97 and 122 (a-z) add the shift value to the charachter
                                {
                                  op=op+sv; //add shift value to give encrypted text
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
                          char word2[100]; //assigns memory value of 100 to "word2", used for user input
                          printf("\nEnter a string to encrypt: ");
                          scanf(" %[^\n]s", word2); // scans user input for string and assigns it to word2, [^\n] allows the program to not stop at whitespace
                          char ch;
                          int n, sv;
                          printf("\nEnter the key value: ");
                          scanf("%d", &sv); //scans user input for key value and assigns it to 'sv'
                          for(n=0; n<strlen(word2); n++) //cycles through every char in the string
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
                              word2[n]=ch;//assigns 'ch' back to word 2
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
                          printf("Sorry this feature is yet to be implemented");
                          return 0;
                        }
                      case 2:
                        {
                          //lower and upper chars is assigned a memory value of 26 and the alphabet is initialised for both upper and lower case letters
                          char lowerchars[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                          char upperchars[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
                          char key[27]; //key value is assigned memory value of 27 (doesnt interfere with the upper and lower chars)
                          char msg[1024]; //assigns memory value of 1024 to "msg", which is the user input
                          printf("\nEnter text to encode: ");
                          scanf(" %[^\n]",msg); //scans user input for string, [^\n] allows the string to store whitespace
                          int k,j; //k and j are used in the for loops to increment the values
                          printf("\nEnter the 26 characters for encryption: ");
                          scanf("%s",key); //users key value is stored as "key"
                          for(k=0;k<strlen(msg);k++) //cycles through every letter in the string
                            {
                              for(j=0;j<26;j++) //cycles through every letter in upper and lower chars
                                {
                                  if(upperchars[j]==msg[k]) // if a letter in "upper chars"=a letter in "msg"
                                    {
                                      msg[k]=key[j]; //the letter of the "msg" is substituted for the letter in the "key"
                                      break;//exits back to the loop
                                    }
                                  if(lowerchars[j]==msg[k])// if a letter in "lower chars"=a letter in "msg"
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
          scanf("%d", &op4); //scans user input and stores the value as op4
          switch(op4) //takes user input from options and execute the number they typed in
            {
              case 1:
                {
                  printf("\nHow would you like to decode the text?\n");
                  printf("1. From a .txt file\n");
                  printf("2. From inside the console\n");
                  printf("3. From inside the console with NO KEY\n");
                  printf("Enter your option: ");
                  scanf("%d", &op3); //scans user input and stores value as op3
                  switch(op3)//takes user input from options and execute the number they typed in
                    {
                      case 1:
                        {
                          FILE *fr, *fw; //declares pointer for file which is used to communicate between program and file
                          char ch, fileread[700], filewrite[700];// assigns memory to fileread and filewrite which is used to read the text file
                          int op, sv;
                          printf("Enter the name of the file to be encoded (.txt file): ");
                          scanf("%s", fileread); //takes user input for the file they want to read the text from
                          printf("Enter the key value: ");
                          scanf("%d", &sv); //scans user input for their key value and stores the value as "sv"
                          printf("Enter the name of the output file (.txt file): ");
                          scanf("%s", filewrite);//takes user input for what they would like their new encrypted file to be saved as
                          fr=fopen(fileread, "r");//opens fr(fileread pointer) in read mode ("r")
                          fw=fopen(filewrite, "w");//opens fw(filewrite pointer) in write mode ("w")
                          if (fr==NULL)//if the file cannot be opened produce an error message and exit the program
                            {
                              perror("");
                              return 0;
                            }
                          ch=fgetc(fr);//fgetc obtains a charachter from the file and assigns it to "ch"
                          while(ch!=EOF) // while there are still characters in the file, do not exit the file
                            {
                              op=(int)ch;// assigns op to the ASCII value of the charachter "ch"
                              if(op>=97 && op<=122)// if the charachter is between 97 and 122 (a-z) subtract the shift value from the charachter
                                {
                                  op=op-sv;//subtract shift value to give decrypted text
                                  if(op<97)// if the charachter is less than 97 (a) add 26, which, rotates the charachters back to z
                                    {
                                      op=op+26;
                                    }
                                }
                              if(op>=65 && op<=90)// if the charachter is between 65 and 90 (A-Z) add the shift value to the charachter
                                {
                                  op=op-sv;//subtract shift value to give decrypted text
                                  if(op<65) // if the charachter is less than 65 (A) subtract 26, which, rotates the charachters back to Z
                                    {
                                      op=op+26;
                                    }
                                  if(op>=91)//if the charachter is greater than or equal to special char ([), rotate back to A
                                    {
                                      op=op+26;
                                    }
                                }
                              if(op>=0 && op<=64)//if the char is between 0 and 64(special chars), just leave them (dont decrypt)
                                {
                                  op=op;
                                }
                              fprintf(fw, "%c", op); //prints the decrypted char to the file
                              ch=fgetc(fr);//gets a new char from the file and assigns it to "ch"
                            }
                          fclose(fr);//closes the file "fr" so it is no longer "read"
                          fclose(fw);//closes the file "fw" so it is no longer written to
                          printf("\nThe file has sucessfully been decoded and saved as %s\n", filewrite); // lets user know their code has been encoded and saved
                          return 0; //exits program
                        }
                      case 2:
                        {
                          char word[700];//assigns memory value of 700 to "word", used for user input
                          char ch;
                          int n, sv;
                          printf("Enter a string to decrypt: ");
                          scanf(" %[^\n]s", word); // scans user input for string and assigns it to word, [^\n] allows the program to not stop at whitespace
                          printf("\nEnter the key value: ");
                          scanf("%d", &sv);//scans user input for key value and assigns it to 'sv'
                          for(n=0; n<strlen(word); n++)//cycles through every char in the string
                            {
                              ch=word[n]; // assigns 'ch' to a charachter in 'word'
                              if(ch>=97 && ch<=122)// if the charachter is between 97 and 122 (a-z) add the shift value to the charachter
                                {
                                  ch=ch-sv;//subtracts the shift value from the char to give decrypted text
                                  if(ch<97)// if ch is less than 97, rotate the cipher back to "z"
                                    {
                                      ch=ch+26;
                                    }
                                }
                              if(ch>=65 && ch<=90)// if the charachter is between 65 and 90 (A-Z) add the shift value to the charachter
                                {
                                  ch=ch-sv;//subtracts the shift value from the char to give decrypted text
                                  if(ch<65)// if the charachter is less than 65 (A) subtract 26, which, rotates the charachters back to Z
                                    {
                                      ch=ch+26;
                                    }
                                  if(ch>=91)//if the charachter is greater than or equal to special char ([), rotate back to A
                                    {
                                      ch=ch+26;
                                    }
                                }
                              if(ch>=0 && ch<=64)//if the char is between 0 and 64(special chars), just leave them (dont decrypt)
                                {
                                  ch=ch;
                                }
                              word[n]=ch; //assigns ch back to word
                            }
                          printf("\nThe decrypted message is: %s", word);//shows the user what their encrypted text is
                          return 0; //exits the program
                        }
                      case 3:
                        {
                          char word[100]; //assigns memory value of 100 to word, used for user input
                          char ch, dec[100]; //assigns memory value of 100 dec, used to brute force the text
                          int n, sv, chlen, option;//initialised variables used to decrypt the text
                          char pftpr;
                          printf("Enter the text to decrypt: ");
                          scanf(" %[^\n]s", word);//takes user input and stores it as word, [^\n] allows the user to enter whitespace
                          chlen=strlen(word);//assigns chlen to the length of the string
                          printf("\nThe string has %d characters\n", chlen);//prints the length of the string
                          for(sv=1; sv<27; sv++)//cycles through every possible rotation cipher
                              {
                                for(n=0; word[n]!='\0'; n++)//loop to decrypt each letter
                                  {
                                    ch=word[n];//assigns ch to a charachter of the string word
                                    if(ch>='a' && ch<='z') //if ch is between a and z
                                      {
                                        ch=ch-sv; //subtract the shift value from ch
                                        if(ch<'a') //if ch is less than a
                                          {
                                            ch=ch+26; // add 26 to rotate the cipher back to z
                                          }
                                        dec[n]=ch; //assign ch to dec so word remains unchanged
                                      }
                                    else if(ch>='A' && ch<='Z') // if ch is between A and Z
                                      {
                                        ch=ch-sv; //subtract the shift value from ch
                                        if(ch<'A') //if ch is less than A
                                          {
                                            ch=ch+26; //rotate the cipher back to Z
                                          }
                                        dec[n]=ch; //assign ch to dec so word remains unchanged
                                      }
                                    else if (ch>=32 && ch<=64) //if ch is equal to special chars
                                      {
                                        ch=ch; //dont decrypt them
                                        dec[n]=ch;//assign ch to dec so word remains unchanged
                                      }
                                  }
                                printf("\n----------------------\nThe possible decrypted message is:\n %s\nKey value = %d\n", dec, sv); //prints possible decrytion to console
                                printf("\n\nDoes this decrypted message make sense?\n");
                                printf("1. Yes\n");
                                printf("2. No\n");
                                printf("Enter your option: ");
                                scanf("%d", &option);
                                printf("\n----------------------\n");
                                if(option==1) //the code does make sense and the program has decrypted the text
                                  {
                                    printf("\nThe code was sucessfully decoded\n");
                                    return 0;
                                  }
                                if (option==2)// if the text does not make sense the program than completes the loop again for a another key value
                                  {

                                  }
                              }
                          printf("\n\nYour code could not be decoded.... Press F to pay respects\n");
                          scanf(" %c", &pftpr);
                          if(pftpr=='F'||pftpr=='f') //user has paid respects
                            {
                              printf("Respects given\n");
                            }
                          else //user has not paid respects
                            {
                              printf("Disrespectful\n");
                              return 0;
                            }
                        }
                      default: //invlaid option, prints error message
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
                          //lower and upper chars is assigned a memory value of 26 and the alphabet is initialised for both upper and lower case letters
                          char lowerchars[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                          char upperchars[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
                          char key[27];//key value is assigned memory value of 27 (doesnt interfere with the upper and lower chars)
                          char msg[1024];//assigns memory value of 1024 to "msg", which is the user input
                          printf("\nEnter text to decode: ");
                          scanf(" %[^\n]s", msg); //scans user input for string, [^\n] allows the string to store whitespace
                          int k,j; //k and j are used in for loops to increment values
                          printf("\nEnter the 26 characters for decryption (capital letters only): ");
                          scanf("%s",key); //users key value is stored as "key"
                          for(k=0;k<strlen(msg);k++)//cycles through every letter in the string
                            {
                              for(j=0;j<26;j++)//cycles through every letter in upper and lower chars
                                {
                                  if(msg[k]==key[j])// if a letter in "upper chars"=a letter in "msg"
                                    {
                                      msg[k]=upperchars[j];//the letter of the "msg" is substituted for the letter in the "key"
                                      break;//exits back to loop
                                    }
                                  if(msg[k]==key[j])// if a letter in "lower chars"=a letter in "msg"
                                    {
                                      msg[k]=lowerchars[j];//the letter of the "msg" is substituted for the letter in the "key"
                                      break;//exits back to loop
                                    }
                                  else//special chars
                                    {
                                      msg[k]=msg[k];//dont decrypt
                                    }
                                }
                            }
                          printf("\nYour decrypted message is: %s", msg);//prints to the console the decrypted message
                          return 0;//exit program
                        }
                      case 2:
                        {
                          printf("\nWord Analysis\n");
                          char string[1024]; //assigns memory value of 1024 to string
                          int c = 0, count[26] = {0}, x; // initialises variables
                          printf("Enter a string: ");
                          scanf(" %[^\n]s", string); //scans user input, [^\n] allows the program to read past whitespace
                          while (string[c] != '\0') //while the string value is not equal to a new line
                          {
                             if (string[c] >= 'a' && string[c] <= 'z') //if the string value is between a and z
                             {
                                x = string[c] - 'a'; //x is equal to the character scanned
                                count[x]++; //every time the charachter occurs increment x
                             }
                             if(string[c]>='A' && string[c]<='Z') //if the string value is between A and Z
                               {
                                 x=string[c]-'A'; //x is equal to the charachter scanned
                                 count[x]++; //every time the charachter occurs increment x
                               }
                             c++; //increment c to the next charachter
                           }

                          for (c = 0; c < 26; c++)
                           {
                             printf("%c occurs %d times in the string.\n", c + 'A', count[c]); //prints out how many times each letter occured
                           }
                          return 0;
                        }
                      default://invalid option
                        {
                          printf("\nInvalid option\n");
                          return 0;
                        }
                    }
                }
            }
        }
      case 3://exit program option
        {
          return 0;
        }
      default://invalid option
        {
          printf("\nInvalid option\n");
          return 0;
        }
    }
}
