#include<stdio.h>
int main()
{
	int x,y;
	printf("please enter a integer of your choice\n");
	scanf("%d",&x);
	if(x<=30&&x>=10)
	{
		y=x+15;
	}
	else if(x>=50&&x<=70)
	{
		y=3*x;
	}
	else
	{
		y=x-5;
	}
	printf("\n your answer is = %d\n",y);
	
}
