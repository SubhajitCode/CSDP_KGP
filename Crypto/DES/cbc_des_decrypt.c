/*
Name:-Subhajit Barh
Dept - Mathematics
Discipline :- computer science And Dataprocessing
Roll- 18MA60R33
*/


#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "des.h"
#include "bmp.h"
BMPImage *Decryptimage(BMPImage *image);
void xor_cbc(int input1[],int input2[],int output[] );
void xor_cbc(int input1[],int input2[],int output[] )
{
    for(int i=0;i<64;i++)
    {
        output[i]=input1[i]^input2[i];
    }
}
BMPImage *Decryptimage(BMPImage *image)
{
    BMPImage *encrypted_image=malloc(sizeof(*image));
    encrypted_image->header = image->header;
    encrypted_image->header.width_px = image->header.width_px;
    encrypted_image->header.height_px = image->header.height_px;
    encrypted_image->header.image_size_bytes = _get_image_size_bytes(&encrypted_image->header);
    encrypted_image->header.size = BMP_HEADER_SIZE + encrypted_image->header.image_size_bytes;
    // Allocate memory for image data
    encrypted_image->data = malloc(sizeof(*encrypted_image->data) * encrypted_image->header.image_size_bytes);
    int binary[64],binaryout[64],binary2[64],binary3[64],iv[64],i,j;
    int size =image-> header.image_size_bytes;
    //printf("Size =  %d ",size);
    for(i=0;i<64;i++)
    {
        iv[i]=(i%2);
    }
    
    for( i = 0; i < size; i=i+8)
    {
        for(j=0;j<64;j++)
        {
            binary3[j]=binary[j];
        }
        plaintextToBinary((image->data+i),binary,8);
       // printf("Original image Data :  ");
        //printArray(binary,64);
        Decrypt(binary,binaryout,8);
        //printf("Encrypted image Data : ");
        //printArray(binaryout,64);
        if(i==0)
        {
            xor_cbc(binaryout,iv,binary2);
        }
        else
        {
            xor_cbc(binaryout,binary3,binary2);

        }
        binaryToText(binary2,(encrypted_image->data+i),8);
    }
    return encrypted_image;

}
int main(void)
{
    
	char keystring[9];
	int size2;
	printf("Please Enter 64 bit Key(8 charecter Exactly)\n");
	gets(keystring);
	size2 = strlen(keystring);
	int sizewithpadd2;
	if((size2%8)!=0)
	{
		 sizewithpadd2 = size2 + (8-(size2%8));
	}
	else
	{
		 sizewithpadd2 = size2 ;
	}
	int key64[sizewithpadd2*8];
	plaintextToBinary(keystring,key64,sizewithpadd2); //Key string converted to binary 64 bit	
	keySchedule(key64);									//Key  scheduling 
    char *error = NULL;
    BMPImage *encrypted_image = read_image("cbc_Encrypted_Tux.bmp", &error);
    BMPImage *decrypted_image=Decryptimage(encrypted_image);
    write_image("cbc_Decrypted_Tux.bmp", decrypted_image, &error);
    _clean_up(NULL, decrypted_image, &error);
    _clean_up(NULL, encrypted_image, &error);
      printf("--------------------------Decryption Done---------------------------\n");
    return EXIT_SUCCESS;
}