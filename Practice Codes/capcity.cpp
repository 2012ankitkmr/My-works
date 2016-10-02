#include<bits/stdc++.h>
using namespace std;
bool matrix[100005][100005];
bool tmatrix[100005][100005];
long int v, e;
bool visited[100005];
void readedges()
{
	long int i,x,y;
	for(i=0;i<e;i++)
	{
		scanf("%ld%ld",&x,&y);
		matrix[x][y]=1;	
	}
	
}
stack<long int>mystack;
void dfs(long int a)
{
	
	visited[a]=1;
	for(long int i=1;i<=v;i++)
	if(!visited[i]&&matrix[a][i])
	dfs(i);
	mystack.push(a);
}

void transpose()
{
	memset(tmatrix,0,sizeof tmatrix);
	for(int i=1;i<=v;i++)for(int j=1;j<=v;j++)tmatrix[i][j]=matrix[j][i];	
}
long arr[100005];
long int y;
long int cnt;
void dfsutil(long int a)
{
	visited[a]=1;
	arr[++y]=a;
	cnt++;	
	//cout<<a<<" ";
for(long int i=1;i<=v;i++)
{if(!visited[i]&&tmatrix[a][i])
dfsutil(i);	
}
}


void find_SCC()
{
	memset(visited,0,sizeof visited);
	for(int i=1;i<=v;i++)
	if(!visited[i])
	dfs(i);
	transpose();
	memset(visited,0,sizeof visited);
	while(!mystack.empty())
	{
		long int p=mystack.top();
		
		mystack.pop();
		//printf("stack=%d",p);
		if(!visited[p])
		{cnt=0;
		dfsutil(p);
		//printf("\n");
		if(cnt==1)
		{
		arr[y]=0;
		y--;
	}
	}
	}
}


int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%ld%ld",&v,&e);
memset(matrix,0,sizeof matrix);
	readedges();
	find_SCC();
	printf("%ld\n",y);
	arr[0]=0;
	sort(arr,arr+y);	
	for(int i=1;i<=y;i++)
	printf("%ld ",arr[i]);
	return 0;
}
