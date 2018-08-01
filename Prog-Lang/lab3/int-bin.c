#include<stdio.h>
void main()
{
	int i=0,k=0;
	printf("Please Enter a integer less Than 8\n");
	scanf("%d",&i);
	k=i%2;
	i=i/2;
	k=k+10*(i%2);
	i=i/2;
	k=k+10*10*(i%2);
	i=i/2;
	k=k+10*10*10*(i%2);
	printf("\n");
	
	printf("Binariry value is : %d",k);
	printf("\n");
	
}
