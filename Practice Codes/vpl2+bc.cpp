#include<bits/stdc++.h>
using namespace std;
char ank[6145][6145];

char update(char s)
{
	if(s=='*')
	return s;
	char p;
	p='1';
	if(s=='-')
	return p;
	p='2';	
	if(s=='1')
	return p;
	p='3';
	if(s=='2')
	return p;
	p='4';
    if(s=='3')
    return p;
	p='5';
	if(s=='4')
	return p;
	p='6';
	if(s=='5')
return p;
p='7';
if(s=='6')
return p;
p='8';
if(s=='7')
return p;

return s;	
}
int main()
{
	int t;
	long int n,m,k,x,y;
	for(scanf("%d",&t);t--;)
	{
		memset(ank,'-',sizeof(ank));
		scanf("%ld%ld%ld",&n,&m,&k);
		
		while(k--)
		{
			scanf("%ld%ld",&x,&y);
			ank[x][y]='*';
			if(x-1>=0&&y-1>=0)
			{
				//	printf("here1\n");
			ank[x-1][y-1]=update(ank[x-1][y-1]);
		}
			if(x-1>=0)
			{//	printf("here2\n");
			ank[x-1][y]=update(ank[x-1][y]);
		}
			if(y-1>=0)
			{
			//printf("here3\n");	
			ank[x][y-1]=update(ank[x][y-1]);
		}
			if(y+1<=m-1)
			{
			ank[x][y+1]=update(ank[x][y+1]);
//		printf("here4\n");
		}
			if(y+1<=m-1&&x+1<=n-1)
			{	//printf("here5\n");
			ank[x+1][y+1]=update(ank[x+1][y+1]);
		}
			if(x+1<=n-1)
			{	//printf("here6\n");
			ank[x+1][y]=update(ank[x+1][y]);
		}
			if(x-1>=0&&y+1<=m-1)
			{	//printf("here7\n");
			ank[x-1][y+1]=update(ank[x-1][y+1]);
		}
			if(y-1>=0&&x+1<=n-1)
			{	//printf("here8\n");
			ank[x+1][y-1]=update(ank[x+1][y-1]);
		}
		}
		
		long int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		printf("%c",ank[i][j]);
		printf("\n");
	}	
		
	}
	
	return 0;
}
