#include<stdio.h>
int main()
{
	int i=0,n,temp;
	printf("Please enter The Number n :\n");
	scanf("%d",&n);
	temp=n;
	while(temp!=0)
	{
		temp=temp/10;
		i++;
	}
	printf("The Number of Digits In %d is :%d\n",n,i);

return 0;
}
