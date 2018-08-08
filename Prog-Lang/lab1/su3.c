#include<stdio.h>
int main()
{
	int X,Y,Z,result;
	printf("Please Enter Value of X\n");
	scanf("%d",&X);
	printf("Please enter the value of Y\n");
	scanf("%d",&Y);
	printf("Please enter the value of Z\n");
	scanf("%d",&Z);
	if(X==0)
	{
		result=Y+Z;
	}
	else if(X==1)
	{
		result=Y-Z;
	}
	else if(X==2)
	{
		result=Y*Z;
	}
	else if(X==3)
	{
		result = Y/Z;
	}
	else
	{
		printf("You ware not Suppose to put more than 3!!!!! I dont know What to do \n");
		return 0;
	}
	printf("Your answer is   %d\n",result);
	return 0;
}
