#include<stdio.h>
void main()
{
	int n,m;
	printf("Enter A Number \n");
	scanf("%d",&n);
	printf("Enter 1 or 2\n");
	scanf("%d",&m);			
	int i;
	i=n%2;
	switch(m)
	{
		case 1:{
			switch(i)
			 {
			 	case 0: printf("The Even number is : %d\n",n);break;
				default:printf("-1\n");
			 }
			break;
			}
		case 2:{
			switch(i)
			{
				case 1:printf("The Odd number is : %d\n",n);break;
				default:printf("-1\n");
			}
		
			}
			break;
	
	}
	

}
