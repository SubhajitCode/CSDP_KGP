#include<stdio.h>
#include<string.h>
void main()
{
	char Grade[3];
	int marks;
	printf("please Enter Your Marks\n");
	scanf("%d",&marks);
	if(marks>=90)
	{
		strcpy(Grade,"Ex");
		
	}
	else if(marks<=90&&marks>79)
	{
		strcpy(Grade,"A");
	}
	else if(marks>69&&marks<=79)
	{
		strcpy(Grade,"B");
	}
        else if(marks>59&&marks<=69)
        {
                strcpy(Grade,"C");
        }
        else if(marks>49&&marks<=59)
        {
                strcpy(Grade,"D");
        }
	else if(marks>39&&marks<=49)
        {
                strcpy(Grade,"P");
        }
	else
	{
	        strcpy(Grade,"F");
	}
	printf("Your Grade is    ");
	puts(Grade);
}

