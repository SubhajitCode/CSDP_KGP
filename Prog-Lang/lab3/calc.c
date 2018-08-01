#include<stdio.h>
void main()
{
	int a,b;
	printf("Please Enter Two Operand\n");
	scanf("%d %d",&a,&b);
	int operator;
	printf("Enter 1 for addition 2 for multiplication 3 for Division\n");
	scanf("%d",&operator);
	int result;
	switch(operator)
	{
		case 1: result=(a+b);break;
		case 2: result=(a*b);break;
		case 3: result=(a/b);break;
		default:printf("Please Enter Between 1,2,3\n");result=99;break;
	}
	if(result<88)
	{
		printf("Your Output is : %d\n",result);
	}

}
