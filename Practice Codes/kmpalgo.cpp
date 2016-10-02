#include<bits/stdc++.h>
using namespace std;
int f[100]={0};
void prefix_table(char prefix[],int m)
{
	int i=1,j=0;
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

int KMP(char T[],int n,char prefix[],int m)
{
	int i=0,j=0;
	prefix_table(prefix,m);
	while(i<n)
	{
		if(T[i]==prefix[j])
		{
			if(j==m-1)
			return i-j; 
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
	return -1;
}
int main()
{
	char T[]="abcde";
    char prefix[]="cd";
	int ans=KMP(T,strlen(T),prefix,strlen(prefix));
	printf("ans=%d",ans);
	return 0;
}
