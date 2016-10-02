#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,j,k,c,p;
	scanf("%d",&t);
	char s[4],ch[4];
	float f[26][26],a,sum;
	long int n,u;
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&u);
		
		scanf("%s",s);
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				scanf("%f",&f[j][k]);
			}
			
		}
		a=1;
		sum=0;
		for(j=0;j<n;j++)
		{
			scanf("%s",ch);
			if(strlen(ch)==3)
			{
			for(k=0;k<3;k++)
			{
				c=(int)ch[k]-97;
				p=(int)s[k]-97;
				a=a*f[p][c];
			}
			sum=sum+a;
		}
		}
		printf("%f\n",sum);
		
		
	}
return 0;
}

