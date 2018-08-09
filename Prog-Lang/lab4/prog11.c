#include<stdio.h>
int main()
{
int Max1=100,result,temp=0,Min1=0,i;
printf("\n");
	for(i=Min1;i<=Max1;i++)
	{
		temp =i/10;
		if((temp%10)>=5 && (temp%10)<=8 )printf(" %d ",i);
	}
	
printf("\n");




return 0;
}
