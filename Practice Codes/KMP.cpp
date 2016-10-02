#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int f[MAX];

void prefixtable(char s[],int m)
{
	int i=1,j=0;
	f[0]=0;
	while(i<m)
	{
		if(s[i]==s[j])
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
int KMP(char t[],int n,char p[],int m)
{
	int i=0,j=0;
	
	prefixtable(p,m);
while(i<n)
{
	if(t[i]==p[j])
	{
		if(j==m-1)
		return i-j;
		else{
			i++;
			j++;
		}
	}
	else if(j>0)
	j=f[j-1];
	else i++;
}
return -1;
}
int main()
{
	char t[MAX]="abcde";
	char p[MAX]="c";
	int n=5,m=2;
	int ans=KMP(t,n,p,m);
	printf("ans=%d\n",ans);
	int i;
	for(i=0;i<m;i++)
	printf("%d ",f[i]);
	
	
	return 0;
}
