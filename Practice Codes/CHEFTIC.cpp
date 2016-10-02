#include<bits/stdc++.h>
using namespace std;

struct block //    tic tac toe block
{	
int left,left_up,up,right_up,right,right_down,down,down_left;	
};

char s[25][25];
int main()
{
	int test,n,k,a,b,flag;
	freopen("in.txt","r",stdin);
	for(scanf("%d",&test);test--;)
	{
		scanf("%d%d",&n,&k);
		block node[n][n];
		for(int i=0;i<n;i++)
		scanf("%s",s[i]);		
		
		memset(node,0,sizeof node);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(s[i][j]=='X')
				{
					if(i-1>=0&&j-1>=0)
					node[i][j].left_up=node[i-1][j-1].left_up+1;
					else
					node[i][j].left_up=1;
					if(i-1>=0)
					node[i][j].up=node[i-1][j].up+1;
					else
					node[i][j].up=1;
					if(i-1>=0&&j+1<n)
					node[i][j].right_up=node[i-1][j+1].right_up+1;
					else
					node[i][j].right_up=1;
					if(j-1>=0)
					node[i][j].left=node[i][j-1].left+1;
					else
					node[i][j].left=1;	
				}		
			}	
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=n-1;j>=0;j--)
			{
				if(s[i][j]=='X')
				{
					if(j+1<n)
					node[i][j].right=node[i][j+1].right+1;
					else
					node[i][j].right=1;
					if(j+1<n&&i+1<n)
					node[i][j].right_down=node[i+1][j+1].right_down+1;
					else
					node[i][j].right_down=1;
					if(i+1<n)
					node[i][j].down=node[i+1][j].down+1;
					else
					node[i][j].down=1;
					if(i+1<n&&j-1>=0)
					node[i][j].down_left=node[i+1][j-1].down_left+1;
					else
					node[i][j].down_left=1;	
				}		
			}
			
		}
	
	flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[i][j]=='.')
			{
				if(j-1>=0)
				a=node[i][j-1].left;
				else
				a=0;
				if(j+1<n)
				b=node[i][j+1].right;
				else
				b=0;
				if(a+b+1>=k)
				{
				flag=1;
	           	break;
		      	}
		      	
		      	if(j-1>=0&&i-1>=0)
				a=node[i-1][j-1].left_up;
				else
				a=0;
				if(j+1<n&&i+1<n)
				b=node[i+1][j+1].right_down;
				else
				b=0;
				if(a+b+1>=k)
				{
				flag=1;
	           	break;
		      	}
		      	
				if(i-1>=0&&j+1<n)
				a=node[i-1][j+1].right_up;
				else
				a=0;
				if(i+1<n&&j-1>=0)
				b=node[i+1][j-1].down_left;
				else
				b=0;
				if(a+b+1>=k)
				{
				flag=1;
	           	break;
		      	}
		      	
				if(i-1>=0)
				a=node[i-1][j].up;
				else
				a=0;
				if(i+1<n)
				b=node[i+1][j].down;
				else
				b=0;
				if(a+b+1>=k)
				{
				flag=1;
	           	break;
		      	}
			}		
		}
		if(flag)
		break;	
	}
	if(flag)
	printf("YES\n");
	else
	printf("NO\n");
}
	
	return  0;
}
