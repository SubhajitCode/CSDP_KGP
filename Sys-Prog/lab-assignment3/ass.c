#include<stdio.h>
int f(char t[])
{
	if(strcmp(t,"al")==0)
		return 0;
	if(strcmp(t,"cl")==0)
		return 1;
	if(strcmp(t,"dl")==0)
		return 2;
	if(strcmp(t,"bh")==0)
		return 7;
	if(strcmp(t,"bl")==0)
		return 3;
	if(strcmp(t,"ah")==0)
		return 4;
	if(strcmp(t,"ch")==0)
		return 5;
	if(strcmp(t,"dh")==0)
		return 6;
return 200;	
}
int main()
{
	char t[10],u[10],v[0],sy[200];int i=0,g;
	do
	{
		scanf("%s",t);
		if(t[1]==':')
			sy[t[0]]=1;
		if(strcmp(t,"int")==0)
		{
			scanf("%d",&g);
			i=i+2;printf("205 %d ",g);
		}
		if(strcmp(t,"jc")==0)
		{
			scanf("%s",u);i=i+2;printf("114 %d ",sy[u[0]]-i);
		}
		if(strcmp(t,"add")==0)
		{
			scanf("%s%d",u,&g);i=i+3;printf("128 %d %d ",192+f(u),g);
		}
		if(strcmp(t,"cmp")==0)
		{
			scanf("%s%d",u,&g);i=i+3;printf("128 %d %d ",248+f(u),g);
		}
		if(strcmp(t,"mov")==0)
		{
			scanf("%s%s",u,v);i=i+2;
			if(f(v)<200)
			{
				printf("138 %d ",192+8*f(u)+f(v));								
			}
			else 
			{
				printf("%d %d ",176+f(u),atoi(v));			
			}
		}
	}
	while(strcmp(t,"end")!=0);
return 0;
	
}
