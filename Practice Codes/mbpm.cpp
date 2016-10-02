#include<bits/stdc++.h>
using namespace std;
bool matrix[100][100];
int v,e,w;
void readedges()
{
	int i,x,y;
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);
		matrix[x][y]=1;		
	}
	
}

bool bpm(int u,bool seen[],int match[])
{
	for(int i=0;i<w;i++)
	{
	if(matrix[u][i]&&!seen[i])
	{
		seen[i]=true;
		
		if(match[i]<0||bpm(match[i],seen,match))
		{
			match[i]=u;
			return true;
		}
	}	
	}
	return false;
}
int maxbpm()
{
	int match[101];
	memset(match,-1,sizeof match);
	
	int result=0;
	for(int i=0;i<v;i++)
	{
		bool seen[100];
	memset(seen,0,sizeof seen);
	if(bpm(i,seen,match))
	result++;	
	}
	return result;
}

int main()
{
	scanf("%d%d%d",&v,&w,&e);
	memset(matrix,0,sizeof matrix);
	readedges();

printf("max matching %d\n",maxbpm());
	return 0;
}
