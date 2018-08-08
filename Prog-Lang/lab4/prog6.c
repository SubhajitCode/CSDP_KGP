#include<stdio.h>
int main()
{
	int n,mult=1,i;
	printf("Enter A number Buddy :\n");
	scanf("%d",&n);
	if(n==0)
	{
		printf("factorial of %d is : %d\n",n,1);
	}
	else
	{
	for(i=1;i<=n;i++)
	{
		mult=mult*i;
	}
	printf("factorial of %d is : %d\n",n,mult);
	}
	
return 0;
}
