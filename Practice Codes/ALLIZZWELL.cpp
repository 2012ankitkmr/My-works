#include<bits/stdc++.h>
char s[102][102];
int visited[102][102],r,c;
char checkstring[12]="ALLIZZWELL";
int dfs(int a,int b,int k)
{
	if(a<0||b<0||b>r-1||a>c-1)
	return 0;
	
	if(k==9&&checkstring[k]==s[a][b]&&!visited[a][b])
	return 1;
	if(visited[a][b]==1 || checkstring[k]!=s[a][b])
	return 0;
	visited[a][b]=1;
	if(dfs(a-1,b-1,k+1));
	return 1;
	if(dfs(a-1,b,k+1));
	return 1;
	if(dfs(a-1,b+1,k+1));
	return 1;
	if(dfs(a,b-1,k+1));
	return 1;
	if(dfs(a,b+1,k+1));
	return 1;
	if(dfs(a+1,b-1,k+1));
	return 1;
	if(dfs(a+1,b,k+1));
	return 1;
	if(dfs(a+1,b+1,k+1));
	return 1;
	visited[a][b]=0;
return 0;
	
}


int main()
{
int t,i,j,m;
for(scanf("%d",&t);t--;)
{
	scanf("%d%d",&r,&c);

	for(i=0;i<r;i++)
	scanf("%s",s[i]);
	
	m=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		if(s[i][j]=='A')
		{memset(visited,0,sizeof visited);
		m=dfs(i,j,0);
		if(m==1)
		break;
    	}
	
		}
		if(m==1)
		break;
	}
	
	if(m==1)
	printf("YES\n");
	else
	printf("NO\n");
	
}
	return 0;
}
