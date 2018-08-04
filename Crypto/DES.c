#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int IPMatrix[64] = {
	    58, 50, 42, 34, 26, 18, 10,  2,
	    60, 52, 44, 36, 28, 20, 12,  4,
	    62, 54, 46, 38, 30, 22, 14,  6,
	    64, 56, 48, 40, 32, 24, 16,  8,
	    57, 49, 41, 33, 25, 17,  9,  1,
	    59, 51, 43, 35, 27, 19, 11,  3,
	    61, 53, 45, 37, 29, 21, 13,  5,
	    63, 55, 47, 39, 31, 23, 15,  7
};

const int FPMatrix[64] = {
    40,  8, 48, 16, 56, 24, 64, 32,
    39,  7, 47, 15, 55, 23, 63, 31,
    38,  6, 46, 14, 54, 22, 62, 30,
    37,  5, 45, 13, 53, 21, 61, 29,
    36,  4, 44, 12, 52, 20, 60, 28,
    35,  3, 43, 11, 51, 19, 59, 27,
    34,  2, 42, 10, 50, 18, 58, 26,
    33,  1, 41,  9, 49, 17, 57, 25
};

const int PC1Matrix[56] = {
   57, 49, 41, 33, 25, 17,  9,
    1, 58, 50, 42, 34, 26, 18,
   10,  2, 59, 51, 43, 35, 27,
   19, 11,  3, 60, 52, 44, 36,
   63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
   14,  6, 61, 53, 45, 37, 29,
   21, 13,  5, 28, 20, 12,  4
};

const int RotationsMatrix[16] = {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

const int PC2Matrix[48] = {
   14, 17, 11, 24,  1,  5,
    3, 28, 15,  6, 21, 10,
   23, 19, 12,  4, 26,  8,
   16,  7, 27, 20, 13,  2,
   41, 52, 31, 37, 47, 55,
   30, 40, 51, 45, 33, 48,
   44, 49, 39, 56, 34, 53,
   46, 42, 50, 36, 29, 32
};

const int ExpansionMatrix[48] = {
    32,  1,  2,  3,  4,  5,  4,  5,
     6,  7,  8,  9,  8,  9, 10, 11,
    12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21,
    22, 23, 24, 25, 24, 25, 26, 27,
    28, 29, 28, 29, 30, 31, 32,  1
};
const int SboxMatrix[8][4][16] = {
   {
   {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
   { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
   { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
   {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
   },
 
   {
   {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
   { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
   { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
   {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
   },
 
   {
   {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
   {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
   {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
   { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
   },
 
   {
   { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
   {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
   {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
   { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
   },
 
   {
   { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
   {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
   { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
   {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
   },
 
   {
   {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
   {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
   { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
   { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
   },
 
   {
   { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
   {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
   { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
   { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
   },
 
   {
   {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
   { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
   { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
   { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11},
   },
};

const int PboxMatrix[32] = {
    16,  7, 20, 21, 29, 12, 28, 17,
     1, 15, 23, 26,  5, 18, 31, 10,
     2,  8, 24, 14, 32, 27,  3,  9,
    19, 13, 30,  6, 22, 11,  4, 25
};
int IPtext[64],ExpText[48],XorText[48],X2[32],R[32],Encrypted[64];
int LEFT[17][32],RIGHT[17][32];
int Key48[16][48];
int mode;
void plaintextToBinary(char plaintext[],int binary[],int size)
{
	int i,j=0,k=0;
	int ch;
	int padd =0;
	if((size%8)!=0)
	{
		padd= (8 - size%8);
	}
	for(i=0;i<size;i++)
	{
		ch = (int) plaintext[i];
		int  temp=-1;
		int mask = 128;
		for(k=0;k<8;k++)
		{
			
			temp = ch & mask;
			if(temp==0)
			{
				binary[k+(8*i)]=0;	
				
			}
			else 
			{
				binary[k+(8*i)]=1;
			}
			mask = mask >> 1;
				
		}
	}
	for(i=0;i<padd;i++)
	{
		//padding loop
		j=0;
		for(k=0;k<8;k++)
		{
			binary[(7-k)+(size+i)*8]=0;			
		}
	}
}
void binaryToText(int binary[],char Outstring[],int size)
{
	int ch=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<8;j++)
		{
			ch = ch*2;
			ch = ch + binary[i*8+j];
		}
		Outstring[i]=ch;
	}


}
void printArray(int array[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
}
void printArray2(char array[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%c",array[i]);
	}
	printf("\n");
}
void InitialPermute(int binary[],int i)
{
	
	int j;
		for(j=0;j<64;j++)
		{
			IPtext[j]=binary[i+IPMatrix[j]-1];
		}
		//printf("I am at leas her");
}
void expand(int round)
{
	int i;
	for(i=0;i<48;i++)
	{
		ExpText[i]=RIGHT[round-1][ExpansionMatrix[i]-1];
		//printf("I am at expand : %d    %d   %d  times \n",RIGHT[round-1][i],i,round-1);
		
	}
}
void xor(int round,int decrypt )
{
	int i;
	for(i=0;i<48;i++)
	{
		switch(decrypt)
		{
			case 0:{
				XorText[i]=ExpText[i]^Key48[round-1][i];break;}

			case 1:{
				XorText[i]=ExpText[i]^Key48[16-round][i];break;}

			default:break;
		}
		
	}
}
void sBox(int round)
{
	int row,column,hex;
	int x[8][6];
	int k=0,m=0;
	for(int i=0;i<8;i++)
	{
		
		
		for(int j=0;j<6;j++)
		{
			x[i][j] = XorText[k++];
			
		}
		
		row =x[i][0]*2+x[i][5];
		column = 8*x[i][1]+ 4*x[i][2]+ 2*x[i][3]+ 1*x[i][4];
		
		hex = SboxMatrix[i][row][column];
		
		for(int l=0;l<4;l++)
		{
			
			X2[(3-m)+4*i]=hex%2;
			hex = hex/2;
			m++;
			
		}
		
	}
	
}
void pBox(int round)
{
	for(int i=0;i<32;i++)
	{
		R[i]=X2[PboxMatrix[i]-1];
	}
	
}
void f(int round,int decrypt)
{
	
	expand(round);
	xor(round,decrypt); 
	sBox(round);
	pBox(round);
	
	
}
void doRounds(int round,int decrypt)
{
	
	f(round,decrypt);
	for(int i=0;i<32;i++)
	{
		RIGHT[round][i]=R[i]^LEFT[round-1][i];
		LEFT[round][i]=RIGHT[round-1][i];

	}
	
}
void FinalPermute(int binary[],int binaryout[],int i)
{
	int j;
	for(j=0;j<64;j++)
	{
		binaryout[i+j]=Encrypted[FPMatrix[j]-1];
		//printf("I am at FinalPermute : %d    %d   times \n",Encrypted[j],j);		
	}
}
void  Encrypt(int binary[],int binaryout[],int sizewithpadd)
{
	int i=0,j=0,k=0;
	for(i=0;i<sizewithpadd*8;i=i+64)
	{
		InitialPermute(binary,i);
				

		for(j=0;j<64;j++)
		{
			if(j<32)
			{
				LEFT[0][j]=IPtext[j];
			}
			else
			{
				RIGHT[0][j-32]=IPtext[j];
			}
			
		}
		for(k=1;k<=16;k++)
		{
			
			doRounds(k,0);
			
		}
		for(j=0;j<64;j++)
		{
			if(j<32)
			{
				Encrypted[j]=RIGHT[16][j];
			}
			else
			{
				Encrypted[j]=LEFT[16][j-32];
			}
			
			
		}
		
		FinalPermute(binary,binaryout,i);
		
		
	}
}
void  Decrypt(int binary[],int binaryout[],int sizewithpadd)
{
	
	int i=0,j=0,k=0;
	for(i=0;i<sizewithpadd*8;i=i+64)
	{
		InitialPermute(binary,i);
				

		for(j=0;j<64;j++)
		{
			if(j<32)
			{
				LEFT[0][j]=IPtext[j];
			}
			else
			{
				RIGHT[0][j-32]=IPtext[j];
			}
			
		}
		for(k=1;k<=16;k++)
		{
			
			doRounds(k,1);
			
		}
		for(j=0;j<64;j++)
		{
			if(j<32)
			{
				Encrypted[j]=RIGHT[16][j];
			}
			else
			{
				Encrypted[j]=LEFT[16][j-32];
			}
			
			
		}
		
		FinalPermute(binary,binaryout,i);
		
		
	}
}
void permuteCombine1(int key64[],int Key56[])
{
	int i=0;
	for(i=0;i<56;i++)
	{
		Key56[i]=key64[PC1Matrix[i]-1];
	}
}
void left_shift(int a[16][28])
{
	int i=0,j=0,k=0;
	for(i=0;i<16;i++)
	{
		int shift=0;
		shift = RotationsMatrix[i];
		for(j=0;j<shift;j++)
		{
			int temp;
			temp=a[i][0];
			for(k=0;k<27;k++)
			{
				a[i][k]=a[i][k+1];
			}
			a[i][27]=temp;
		}
		
	}
	
}
void permuteCombine2(int RL[],int j )
{
	int i=0;
	for(i=0;i<48;i++)
	{
		Key48[j][i]=RL[PC2Matrix[i]-1];
	}
}

void keySchedule(int key64[])
{
	int Key56[56];
	int i,j;
	int RL[16][56];
	int R[16][28],L[16][28];
	permuteCombine1(key64,Key56);
	for(j=0;j<16;j++)
	{
		for(i=0;i<56;i++)
		{
			if(i<28)
			{
				L[j][i]=Key56[i];
			}
			else
			{
				R[j][i-28]=Key56[i];
			}

		}		
	}

	left_shift(L);
	left_shift(R);
	for(j=0;j<16;j++)
	{
		for(i=0;i<56;i++)
		{
			if(i<28)
			{
				RL[j][i]=L[j][i];
			}
			else
			{
				RL[j][i]=R[j][i-28];
			}

		}	
		
	}
	for(j=0;j<16;j++)
	{
		permuteCombine2(RL[j],j);
	}		
}

void main()
{
	char plaintext[30],encryptedtext[240],keystring[9],keystring2[9];
	int size,size2;
	printf("Please Enter 1 for Encryption mode 2 for Decryption Mode\n");
	scanf(" %d",&mode);
	getchar();
	switch(mode)
	{
		case 1:{
			printf("Please Enter The Plaintext in text Not more than 30 charecter\n");
			gets(plaintext);
			size = strlen(plaintext);	
			break;

		}
		case 2:{
			printf("Please Enter The Encrypted text Not more than 30 bits\n");
			gets(encryptedtext);
			size = strlen(encryptedtext);
			break;

		}
		default:{
			printf("There is Only Two Mode 1 and 2");exit(1);
		}

	}

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
	keySchedule(key64);
	if(mode == 1)
	{
		plaintextToBinary(plaintext,binary,size);    //plain text converted to binary
		printf("Plain text Binary :");
		printArray(binary,sizewithpadd*8);		//Printing plaintext binary array
		Encrypt(binary,binaryout,sizewithpadd);		//Encrytion Process
		binaryToText(binaryout,outstring,sizewithpadd);    //Encrypted Bin to Char array
		printf("Encrypted Binary :");
		printArray(binaryout,sizewithpadd*8);					//Printing The Encrypted bin array
		printf("Encrypted Text :");
		printArray2(outstring,sizewithpadd);
	}
	else
	{
		printf("Encrypted Text :");
		printArray2(encryptedtext,sizewithpadd);
		plaintextToBinary(encryptedtext,binary,size);    //encrypted text converted to binary
		printf("Encrypted Binary :");
		printArray(binary,sizewithpadd*8);		//Printing Encrypted binary array
		 Decrypt(binary,binaryout,(sizewithpadd));
		printf("Decrypted Binary :");
		printArray(binaryout,sizewithpadd*8);
		binaryToText(binaryout,outstring,(sizewithpadd));
		printArray2(outstring,(sizewithpadd));
	
	
	}
	

}

