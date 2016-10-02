#include<bits/stdc++.h>
using namespace std;
long int id[1000005];
bool matrix[10006][10006];
bool tmatrix[10006][10006];
bool visited[10006];
long int n;
void make_set()
{long int i; 
	for(i=0;i<n;i++)
	id[i]=i;
}

stack<long int>mystack;
void dfs(long int a)
{
	visited[a]=1;
	mystack.push(a);
	for(long int i=0;i<n;i++)
	{
		if(!visited[i]&&matrix[a][i])
		dfs(i);
	}
	
}
void transpose()
{
	memset(tmatrix,0,sizeof tmatrix);
for(int i=0;i<n;i++)for(int j=0;j<n;j++)tmatrix[i][j]=matrix[j][i];	
}
long int minv;
void dfsutil(long int a)
{
	visited[a]=1;
	if(minv>a)
	minv=a;
		//cout<<a<<" ";
	for(int i=0;i<n;i++)
	{
		if(!visited[i]&&matrix[a][i])
		dfsutil(i);
	}	
//	printf("min=%ld ",minv);
	id[a]=minv;
}
void solve()
{
	memset(visited,0,sizeof visited);
	dfs(0);
	transpose();
	memset(visited,0,sizeof visited);
	
	while(!mystack.empty())
	{
		long int p=mystack.top();
		mystack.pop();
		
		if(!visited[p])
		{
		//	printf("here\n");
			minv=p;
			dfsutil(p);
		//	printf("\n");
		}
				
	}
}
int main()
{
	long int i,a,b,m;
	scanf("%ld%ld",&n,&m);
	make_set();
	memset(matrix,0,sizeof matrix);
	for(i=0;i<m;i++)
	{scanf("%ld%ld",&a,&b);
matrix[a][b]=1;
}
solve();

	for(i=0;i<n;i++)
	printf("%ld\n",id[i]);
	return 0;
}

