#include<stdio.h>
int  main()
{
	int n,temp;
	printf("Please Enter A number\n");
	scanf("%d",&n);
	temp=n%10;
	n=n/100;
	n=n*10+temp;
	printf("Your Output is %d\n",n);

return 0;
}
