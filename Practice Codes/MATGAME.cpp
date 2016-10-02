#include<bits/stdc++.h>
using namespace std;

int mat[55][55];
int grundy[55][55];
int main()
{
	int test,xornum,n,m;
	for(scanf("%d",&test);test--;)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			scanf("%d",&mat[i][j]);
			
		}		
		memset(grundy,0,sizeof grundy);
		for(int i=0;i<n;i++)
		{
			grundy[i][m-1]=mat[i][m-1];
			for(int j=m-1;j>=1;j--)
			{
			grundy[i][j-1]=(mat[i][j-1]<=grundy[i][j])?(mat[i][j-1]-1):mat[i][j-1];
			}
			
		}
		 xornum=0;
		for(int i=0;i<n;i++)
		{
			//for(int j=0;j<m;j++)
			//{
			xornum^=grundy[i][0];	
		//	}
		}
		if(xornum)
		printf("FIRST\n");
		else
		printf("SECOND\n");
	}	
	return  0;
}
