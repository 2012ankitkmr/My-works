#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int tab[2002][2002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w+",stdout);
	
	int t,x,y,ans1,ans2,p;
	char s[200];
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		scanf("%s",s);
	memset(tab,0,sizeof(tab));
x=0;

for(int i=0;s[i]!='-';i++)
{
x=x*10;
x+=((int)(s[i]-'0'));
}	
y=0;
p=0;
while(s[p++]!='-');
//printf("%d\n",p);
for(;s[p];p++)
{
y=y*10;
y+=((int)(s[p]-'0'));
}	
	
//	printf("x=%d,y=%d\n",x,y);
for(int i=0;i<=y;i++)
tab[i][x]=1;
/*
	for(int i=0;i<=y+1;i++)
	{
		for(int j=0;j<=x+1;j++)
		{
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}
printf("\n");*/

//upper triangular ,matrix of stress free
	for(int i=y;i>=0;i--)
	{
		for(int j=x;j>=0;j--)
		{
			if(i==y&&j==x)
			continue;
			else if(i<j||(i==0&&j==0))
			{
				tab[i][j]=(tab[i][j+1]+tab[i+1][j])%MOD;
				
			}
		}
	}
/*	printf("\n");
		for(int i=0;i<=y+1;i++)
	  {
		for(int j=0;j<=x+1;j++)
		{
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	  }*/
	  ans1=tab[0][0];
	memset(tab,0,sizeof(tab));

    for(int i=0;i<=x;i++)
	tab[y][i]=1;
  /*  printf("\n");
	for(int i=0;i<=y+1;i++)
	{
		for(int j=0;j<=x+1;j++)
		{
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
*/

//lower triangle or stressful
	for(int i=y;i>=0;i--)
	{
		for(int j=x;j>=0;j--)
		{
			if(i==y&&j==x)
			continue;
			else if(i>=j||(i==0&&j==0))
			{
				tab[i][j]=(tab[i][j+1]+tab[i+1][j])%MOD;
				
			}
		}
	}
/*	printf("\n");
		for(int i=0;i<=y+1;i++)
	{
		for(int j=0;j<=x+1;j++)
		{
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}*/
	ans2=tab[0][0];
	printf("Case #%d: %d %d\n",test,ans1,ans2);		
	
	}	
	return 0;
}
