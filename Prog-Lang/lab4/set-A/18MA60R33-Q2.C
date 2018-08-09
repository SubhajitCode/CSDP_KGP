#include<stdio.h>
int  main()
{
	int n,temp,temp2,result;
	printf("Please Enter A number\n");
	scanf("%d",&n);
	temp=n%10;
	temp2=n/10;
	n=n/100;
	n=n*10+temp;
	result=n*temp2;
	
	printf("Your Output is %d\n",result);

return 0;
}
