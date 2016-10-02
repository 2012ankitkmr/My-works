#include<bits/stdc++.h>
#include<string.h>
#include<queue>
using namespace std;
char s[100];
bool matrix[100][100],visited[100];
int len,counter[100];

void bfs(int src)
{
	memset(visited,0,sizeof visited);
	int i;
	queue<int>q;
		for(i=1;i<=len;i++)
		{
			if(matrix[src][i])
			{
				q.push(i);
			}
		}
		counter[src]=0;
		while(!q.empty())
		{
		
			int p=q.front();
			q.pop();
			visited[p]=1;
			for(i=1;i<=len;i++)
			{
				if(matrix[p][i]&&i!=src&&!visited[i]&&!matrix[src][i])
			{
				//	if(src==2)
			//printf("here\n");
				visited[i]=1;
				counter[src]++;
			}
			}
		}

	
}

int main()
{
	int t,i,j;
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		len=strlen(s);
	memset(matrix,0,sizeof matrix);	
	    for(i=0;i<len;i++)
	    {
	    	if(s[i]=='Y')
	    	matrix[1][i+1]=1;
	    }
	    len--;
		for(i=0;i<len;i++)
		{
             scanf("%s",s);       
        for(j=0;j<=len;j++)
	    {
	    	if(s[j]=='Y')
	    	matrix[i+2][j+1]=1;
	    }       
	    }
	    len++;
	    /*for(i=1;i<=len;i++)
	    {
	    	for(j=1;j<=len;j++)
	    	printf("%d ",matrix[i][j]);
	    	printf("\n");
	    }*/
	    for(i=1;i<=len;i++)
	    bfs(i);
	    int max=-1;
	    for(i=1;i<=len;i++)
	    {
	    	if(counter[i]>max)
	    	{
	    	max=counter[i];
	j=i-1;
	}
		}
		printf("%d %d\n",j,max);
	}
	
	return 0;
}
