#include<bits/stdc++.h>
using namespace std;
long int f[1000000]={0};
long int ans[1000000];
void prefix_table(char prefix[],long int m)
{
	long int i=1,j=0;
	f[0]=0;
	while(i<m)
	{
		if(prefix[i]==prefix[j])
		{
			f[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
		j=f[j-1];
		else
		{
			f[i]=0;
			i++;
		}
	}
	
}
long int l;
void KMP(char T[],long int n,char prefix[],long int m)
{
	long int i=0,j=0;
	l=0;
	prefix_table(prefix,m);
	while(i<n)
	{//prlong intf("%d\n",i);
		if(T[i]==prefix[j])
		{
			if(j==m-1)
			{
			ans[l++]=i-j; 
			j=f[j-1];
		}
			else
			{
				i++;
				j++;
			}
		}
		else if(j>0)
		j=f[j-1];
		else i++;
}
}
char T[1000000],prefix[1000000];
 int main()
{
	long int n,m;
//freopen("in.txt","r",stdin);
	//memset(ans,-1,sizeof(ans));
	while(scanf("%d",&m)!=EOF)
	{
		l=0;
		scanf(" %s",prefix);
		scanf(" %s",T);
		n=strlen(T);
		if(n<m)
		printf("\n");
		else
	{
	KMP(T,n,prefix,m);
	for(long int i=0;i<l;i++)
	printf("%d\n",ans[i]);
}
}
	return 0;
}
