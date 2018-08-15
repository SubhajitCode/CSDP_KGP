/*
Name:-Subhajit Barh
Dept - Mathematics
Discipline :- computer science And Dataprocessing
Roll- 18MA60R33
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char encryptedtext[240],keystring[9];
	int size,size2;
			printf("Please Enter The Encrypted text Not more than 30 bits\n");
			gets(encryptedtext);
			size = strlen(encryptedtext);
	printf("Please Enter 64 bit Key(8 charecter Exactly)\n");
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
		printf("Encrypted Text :");
		printArray2(encryptedtext,sizewithpadd);			//Encrypted text printing
		plaintextToBinary(encryptedtext,binary,size);    //encrypted text converted to binary
		printf("Encrypted Binary :");
		printArray(binary,sizewithpadd*8);		//Printing Encrypted binary array
		 Decrypt(binary,binaryout,(sizewithpadd)); //Decrypt Function calling
		printf("Decrypted Binary :");
		printArray(binaryout,sizewithpadd*8);	//printing Decrypted Binary
		binaryToText(binaryout,outstring,(sizewithpadd));
        printf("Decrypted Text :");
		printArray2(outstring,(sizewithpadd)); //Decrypted text = Plain Text
	

}

