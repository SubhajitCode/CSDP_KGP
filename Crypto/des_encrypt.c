/*
Name:-Subhajit Barh
Dept - Mathematics
Discipline :- computer science And Dataprocessing
Roll- 18MA60R33
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "des.h"
void main()
{
	char plaintext[30],keystring[9];
	int size,size2;

	printf("Please Enter The Plaintext in text Not more than 30 charecter\n");
    gets(plaintext);
	size = strlen(plaintext);	

	printf("Please Enter 64 bit Key(PUT 8 charecter Exactly)\n");
	gets(keystring);
	size2 = strlen(keystring);
	int sizewithpadd;
	int sizewithpadd2;
	if((size%8)!=0)
	{
		 sizewithpadd = size + (8-(size%8));
	}
	else
	{
		sizewithpadd = size ;
	}
	if((size2%8)!=0)
	{
		 sizewithpadd2 = size2 + (8-(size2%8));
	}
	else
	{
		 sizewithpadd2 = size2 ;
	}
	
	char outstring[sizewithpadd];
	int binary[sizewithpadd*8];
	int binaryout[sizewithpadd*8];
	int key64[sizewithpadd2*8];
	plaintextToBinary(keystring,key64,sizewithpadd2); //Key string converted to binary 64 bit	
	keySchedule(key64);									//Key  scheduling 
	plaintextToBinary(plaintext,binary,size);    //plain text converted to binary
	printf("Plain text Binary :");
	printArray(binary,sizewithpadd*8);		//Printing plaintext binary array
    Encrypt(binary,binaryout,sizewithpadd);		//Encrytion Process
	binaryToText(binaryout,outstring,sizewithpadd);    //Encrypted Bin to Char array
	printf("Encrypted Binary :");
    printArray(binaryout,sizewithpadd*8);					//Printing The Encrypted bin array
	printf("Encrypted Text :");
	printArray2(outstring,sizewithpadd);					//prints Encrypted Text

}

