#include<stdio.h>
void makezero(int b[])
{
	int i;
	for(i=0;i<5;i++)
	{
		b[i]=0;
	}
	
}
void main()
{
	int i=0,j=0;
	int a[4][5];
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			a[i][j]=i+j;
		}
	}
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	makezero(a[1]);
		for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	
}