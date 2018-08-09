#include<stdio.h>
int main()
{
int Max1=100,result,temp=0,Min1=0,i;
printf("\n");
	for(i=Min1;i<=Max1;i++)
	{
		
		if(((i%7)==0 || (i%3)==0 )&& (i%21 !=0))printf(" %d ",i);
	}
	
printf("\n");




return 0;
}
