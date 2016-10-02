#include<bits/stdc++.h>
using namespace std;

char s1[10004][1003],s2[10004][1003];
int n,m,len;
int has1[10004][27],has2[10004][27];



bool stc(int a[],int b[])
{
	for(int i = 0;i<26;i++)
	{
		if(!(a[i]||b[i]))		
		return false;	
	}
	return true;	
}

int main()
{
//freopen("in.txt","r+",stdin);

scanf("%d%d",&n,&m);
for(int i = 0;i<n;i++)
	{
	scanf(" %s",s1[i]);

	for(int j = 0;s1[i][j];j++)
	{
		has1[i][s1[i][j]-'A']=1;
	}
 }
for(int i = 0;i<m;i++)
{
	scanf(" %s",s2[i]);
	for(int j = 0;s2[i][j];j++)
	{
		has2[i][s2[i][j]-'A']=1;
	}
}

int ans=0;
for(int i =0;i<n;i++)
{
	for(int j = 0;j<m;j++)
	{
	if(stc(has1[i],has2[j]))
	ans++;
	}	
}	
	printf("%d\n",ans);
	return 0;
}
