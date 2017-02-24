#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define MOD 1000000007LL
int f[N];

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
int A[N];

void KMP(char T[],int n,char prefix[],int m)
{
	int i=0,j=0;
	prefix_table(prefix,m);

	while(i<n)
	{
		if(T[i]==prefix[j])
		{
			i++;
			j++;
			
			if(j==m)
		     {
			A[i-j]=1;
			j = f[j-1];
	    	} 
		}
		else if(j>0)
		j=f[j-1];
		else i++;
	}
	
}

char T[N];
char prefix[N];
long long F[N];

int main()
{
	
	int test;
	cin>>test;
	while(test--)
	{
	scanf(" %s %s",T,prefix);
	
	
	KMP(T,strlen(T),prefix,strlen(prefix));
	int n=strlen(T),m=strlen(prefix);
	
	//for(int i=0;i<n;i++)
	//printf("%d ",A[i]);
	
	for(int i=0;i<m;i++)
	F[i]=0;
	
    for(int i = m-1 ; i < n; i++)
	    {
	        F[i+1] = F[i];
 
	        if(A[i - m + 1])
	        {
	            F[i+1] = (F[i+1] + F[i+1 - m] + 1) % MOD;
	        }
	    }
 
        cout << F[n] << "\n";
 
	  for(int i = 0 ; i < N ; i++)
	 {
	 	if(i<n)
	cout<<F[i];
	  	A[i] = 0;	
	  }

}
	return 0;
}


