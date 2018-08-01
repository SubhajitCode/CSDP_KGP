#include<stdio.h>
void main()
{
	int salary;
	printf("Please Enter salary\n");
	scanf("%d",&salary);
	int hra ,da;
	if(salary>0&&salary<=4000)
	{
		hra=.1*salary;
		da=.5*salary;
	}
	else if(salary>4000&&salary<=8000)
	{
		hra =.2*salary;
		da  =.6*salary;
	}
        else if(salary>8000&&salary<=12000)
        {
                hra =.25*salary;
                da  =.7*salary;
        }
        else if(salary>12000)
        {
                hra =.3*salary;
                da  =.8*salary;
        }
	else
	{
		hra =-1;
		da=-1;
		printf("Salary Can not Be Negetive Bro\n");
	}
	getchar();
	char ch;
	printf("Please Enter a For HRA and b For DA\n");
	scanf("%c",&ch);
	switch(ch)
	{
		case 'a':printf("HRA is : %d\n",hra);break;
		case 'b':printf("DA is : %d\n",da);break;
		default: printf("Please Enter a or b Please \n");
	}

	
	

}
