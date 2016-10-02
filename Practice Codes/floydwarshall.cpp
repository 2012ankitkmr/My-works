#include<bits/stdc++.h>
#define INF 100000
int c[100][100],a[100][100];

void readedges(int size)
{
	int i,x,y,z;
	for(i=0;i<size;i++)
{
	scanf("%d%d%d",&x,&y,&z);
	c[x][y]=z;

}	
	
}

void floyd(int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	a[i][i]=0;
	
for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][k]+a[k][j]<a[i][j])//min{a(i,j),a(i,k)+a(k,j) over n, i.e taking n at a time 
				a[i][j]=a[i][k]+a[k][j];
			}
			
		}
		
	}
	
}

int main()
{
	int v,e;
	scanf("%d",&v);
	scanf("%d",&e);
	
	memset(c,INF,sizeof c);
	memset(a,INF,sizeof a);
	readedges(e);
	floyd(v);
	
	return 0;
}
