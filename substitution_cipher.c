#include<stdio.h>
#include<strings.h>
char *encryption(char []);
void *decryption(char []);
char chars[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char key[26];
void main()
{
int i,key,choice,flag=0;
char *text,msg[255];
printf("\n --- Monocharsbetic Cipher Code ---\n");
printf("Enter plain text :");
scanf("%[^\n]",msg);
printf("\n Your plain text message is : %s",msg);
do{
printf("\npress 1 for encryption \npress 2 for decryption \npress '0' for exit \n");
scanf("%d",&choice);
switch(choice){
case 1 :
text=encryption(msg);
flag=1;
break;
case 2 :
if(flag==1)
decryption(text);
else
printf("first perform encryption process");
break;
case 0 :
break;
default :
printf("\nplease enter valid choice\n");
break;
}
}while(choice!=0);
}
char *encryption(char cipher_text[]){
int i,val,j;
printf("enter the unique key of 26 characters for encryption :");
scanf("%s",key);
printf("\ncharacter replaced\n");
printf("\nabcdefghijklmnopqrstuvwxyz\n");
printf("||||||||||||||||||||||||||");
printf("\n%s\n",key);
for(i=0;i<strlen(cipher_text);i++){
for(j=0;j<26;j++)
{
if(chars[j]==cipher_text[i]){
cipher_text[i]=key[j];
break;
}
}
}
printf("\nYour encrypted msg is : %s",cipher_text);
return cipher_text;
}
void *decryption(char cipher_text[]){
int i,val,j;
char cipher[255];
strcpy(cipher,cipher_text);
printf("\n Decryption Process \n ");
for(i=0;i<strlen(msg);i++){
for(j=0;j<26;j++)
{
if(msg[i]==key[j])
{
msg[i]=upperchars[j];
break;
}
}
}
printf("\nDecrypted Text %s",cipher);
}
