#include<stdio.h>
int main()
{
int Max1=40,Max2=60,Min1=20,Min2=50,i;
printf("\n");
	for(i=Min1;i<=Max1;i++)
	{
		if(i%2==0)printf(" %d ",i);
	}
	printf("\n");
	for(i=Min2;i<=Max2;i++)
	{
        	if(i%2!=0)printf(" %d ",i);
	}
printf("\n");




return 0;
}
