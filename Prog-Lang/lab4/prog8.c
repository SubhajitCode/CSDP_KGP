#include<stdio.h>
int main()
{
	int m,n,result=1,i;
	printf("Please enter a number m and n\n");
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++)
	{
		result=result*m;
					
	}
	printf("%d Power of %d is :%d\n",m,n,result);

return 0;
}
