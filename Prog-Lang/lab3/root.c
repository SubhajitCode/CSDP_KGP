#include<stdio.h>
#include<math.h>
void main()
{
	float  a,b,c,r1,r2,D;
	printf("Please Enter Cofficient a,b,c of ax^2+bx+c=0\n");
	scanf("%f%f%f",&a,&b,&c);
	D=((b*b)-(4*a*c));
	if(D>=0)
	{
		r1=((-1)*b+sqrt(D))/(2*a);
		r2=((-1)*b-sqrt(D))/(2*a);
		printf("Root of the Given Equation are : %f   %f\n",r1,r2);
	}
	else
	{
		 r1=((-1)*b/(2*a));
                 r2=sqrt((-1)*D)/(2*a);
		 printf("Root of the Given Equation are : %f+i%f and  %f-i%f\n",r1,r2,r1,r2);
	}
	
	


}
