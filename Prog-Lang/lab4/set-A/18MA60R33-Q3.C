#include<stdio.h>
int main()
{
	int n;
	unsigned long long int a;
	printf("Please Enter A five Digit Number\n");
	scanf("%d",&n);
	if((n%7)==0)
	{
		printf("Given number is %d\n",n);
	}
	if((n%2)==0)
	{
		a=n*n;
		a=a*n;
		printf("Cube of The given Number is %lld\n",a);
	}
	else
	{
		a=n*n;
		printf("Square of The given Number is %lld\n",a);
	}
return 0;
}
