/*
Name:-Subhajit Barh
Dept - Mathematics
Discipline :- computer science And Dataprocessing
Roll- 18MA60R33
*/


#include <stdio.h>
#include "AES.h"

void readKey(char filename[],unsigned char key[]);
void readPlaintext(char filename[],unsigned char Plaintext[]);
void writeCiphertext(char filename[],unsigned char CipherText[]);

void readKey(char filename[],unsigned char key[])
{
    char ch;
    FILE *fp;

    printf("Reading The file %s\n",filename);
    fp = fopen(filename, "r"); // read mode

    if (fp == NULL)
    {
        printf("Error while opening the file.\n");
        return;
        
    }

    printf("Sucessfully Read  %s file\n", filename);
    printf("Content of  %s file is :----\n",filename);
    int i=0;
    while ((ch = fgetc(fp)) != EOF)
    {
        key[i]=ch;
        i++;
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);
}

void readPlaintext(char filename[],unsigned char Plaintext[] )
{
    char ch;
    FILE *fp;

    printf("Reading The file %s\n",filename);
    fp = fopen(filename, "r"); // read mode

    if (fp == NULL)
    {
        printf("Error while opening the file.\n");
        
    }

    printf("Sucessfully Read  %s file\n", filename);
    printf("Content of  %s file is :----\n",filename);
    int i=0;
    while ((ch = fgetc(fp)) != EOF)
    {
        Plaintext[i]=ch;
        i++;
        printf("%c", ch);
    }
    printf("\n--------------------------\n");
    fclose(fp);

}
void writeCiphertext(char filename[], unsigned char CipherText[])
{
    char ch;
    FILE  *target;

    printf("-------------------Wrinting to the file %s  ---------\n",filename);
    target = fopen(filename, "w");

    if (target == NULL)
    {
        printf("Cannot Read %s ... .....\n",filename);
    }
    int i;
    for(i=0;i<16;i++)
    {
        printf("%c",CipherText[i]);
        fputc(CipherText[i], target);
    }
    printf("\n");
    printf("File Written successfully.\n");
    fclose(target);

    return;
}

void main()
{
    int No_of_round =1;
    unsigned char key[16],RoundKey[176],Plaintext[16],Ciphertext[16];
    readKey("key.key",key);
    readPlaintext("Plaintext.txt",Plaintext);
    KeyExpansion(key,RoundKey);
    aes_Encrypt(Plaintext,RoundKey,No_of_round);
    writeCiphertext("Ciphertext.txt",Plaintext);
    
}
